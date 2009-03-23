#include "Counter.h"

Counter::Counter():
        m_pRule(0)
{
    //ctor
}

Counter::~Counter()
{
    //dtor
}

/**
 * Template method paterrn
 */
void Counter::Counting(CountingFileInfo* countingFileInfo, CountingParam& countingParam)
{
    int nSize			= 0;
    int nLines			= 0;
    int nCodeLines		= 0;
    int nCommentLines	= 0;
    int nCodeCommentLines = 0;
    int nBlankLines		= 0;

    ///////////////////////////////////////////////////////////////////
    wxFile file;
    if (!file.Open(countingFileInfo->m_strFileFullPath))
    {
        return;
    }
    nSize = file.Length();

    // Close
    file.Close();

    ///////////////////////////////////////////////////////////////////
    wxTextFile txtFile;
    if (!txtFile.Open(countingFileInfo->m_strFileFullPath, wxConvISO8859_1))
    {
        return;
    }

    //
    countingSourceFile( txtFile, nLines, nCodeLines, nCommentLines, nCodeCommentLines, nBlankLines );

    // Close
    txtFile.Close();

    ///////////////////////////////////////////////////////////////////
    //
    countingFileInfo->m_nSize				= nSize;
    countingFileInfo->m_nTotalStatement		= nLines;
    countingFileInfo->m_nCodeStatement		= nCodeLines;
    countingFileInfo->m_nCommentStatement	= nCommentLines;
    countingFileInfo->m_nCodeCommentStatement = nCodeCommentLines;
    countingFileInfo->m_nBlankStatement		= nBlankLines;

    ///////////////////////////////////////////////////////////////////
    // nCodeLines * m_nUtCaseDensity / 1000
    countingFileInfo->m_fUtCase		= 1.0 * (nCodeLines + nCodeCommentLines) * countingParam.m_settingParam.m_nUtCaseDensity / 1000.0;
    countingFileInfo->m_fUtDefect	= 1.0 * (nCodeLines + nCodeCommentLines) * countingParam.m_settingParam.m_nUtDefectDensity / 1000.0;

    countingFileInfo->m_fItCase		= 1.0 * (nCodeLines + nCodeCommentLines) * countingParam.m_settingParam.m_nItCaseDensity / 1000.0;
    countingFileInfo->m_fItDefect	= 1.0 * (nCodeLines + nCodeCommentLines) * countingParam.m_settingParam.m_nItDefectDensity / 1000.0;

    ///////////////////////////////////////////////////////////////////
    //      (CostMM/Man-Days)*
    // Man-Day = nCodeLines / (LinesPerMM / Man-DaysPerMM)
    countingFileInfo->m_nManDay 	= 1.0 * (nCodeLines + nCodeCommentLines) * countingParam.m_settingParam.m_nDaysPerMM /
                                   (countingParam.m_settingParam.m_nLinesPerMM * 1.0);

    countingFileInfo->m_nCost 		= 1.0 * (nCodeLines + nCodeCommentLines) *
                                  ( 1.0 * countingParam.m_settingParam.m_nCostPerMM / (1.0 * countingParam.m_settingParam.m_nLinesPerMM));
}

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////

/** This function analyses a given source file and count the lines of code, comments etc...
 */
void Counter::countLines(wxTextFile& file, CounterRule* language, int &total_lines, int &code_lines,
                         int &comment_lines, int &codecomments_lines, int &empty_lines)
{
    bool multi_line_comment = false;
    total_lines += file.GetLineCount();
    for (unsigned int i=0; i<file.GetLineCount(); ++i)
    {
        wxString line(file[i]);
        line = line.Trim(true);
        line = line.Trim(false);
        bool comment = false;
        bool code = false;
        if (line.IsEmpty())
            ++empty_lines;
        else
        {
            analyseLine(language, line, comment, code, multi_line_comment);
            if (comment&&code) ++codecomments_lines;
            else if (comment) ++comment_lines;
            else if (code) ++code_lines;
        }
    }
}

/** This function determines the caracteristics of a given line (code line, comment line etc...).
 *  It is called by the "CountLines" function.
 *  @see CountLines
 */
void Counter::analyseLine(CounterRule* language, wxString line, bool &comment, bool &code, bool &multi_line_comment)
{
    int first_single_line_comment, first_multi_line_comment_begin, first_multi_line_comment_end;

    // Delete first and trailing spaces
    line = line.Trim(true);
    line = line.Trim(false);

    if (line.IsEmpty())
        return;

    // Searching for single and multi-lines comment signs
    if (language->m_strSlgLnComm.Length() > 0)
        first_single_line_comment = line.Find(language->m_strSlgLnComm);
    else first_single_line_comment = -1;
    if (language->m_strMltLnCommBegin.Length() > 0)
        first_multi_line_comment_begin = line.Find(language->m_strMltLnCommBegin);
    else first_multi_line_comment_begin = -1;
    if (language->m_strMltLnCommEnd.Length() > 0)
        first_multi_line_comment_end = line.Find(language->m_strMltLnCommEnd);
    else first_multi_line_comment_end = -1;

    // We are in a multiple line comment => finding the "end of multiple line comment" sign
    if (multi_line_comment)
    {
        comment = true;
        if (first_multi_line_comment_end > -1)
        {
            multi_line_comment = false;
            if (first_multi_line_comment_end+language->m_strMltLnCommEnd.Length() < line.Length())
                analyseLine(language, line.Mid(first_multi_line_comment_end+language->m_strMltLnCommEnd.Length()),
                            comment, code, multi_line_comment);
        }
    }
    // We are not in a multiple line comment
    else if (!multi_line_comment)
    {
        // First comment sign found is a single line comment sign
        if ( (first_single_line_comment>-1)
                &&((first_multi_line_comment_begin==-1)
                   ||((first_multi_line_comment_begin>-1)&&(first_single_line_comment<first_multi_line_comment_begin))) )
        {
            comment = true;
            if (first_single_line_comment > 0)
                code = true;
        }
        // First comment sign found is a multi-line comment begin sign
        else if (first_multi_line_comment_begin>-1)
        {
            multi_line_comment = true;
            comment = true;
            if (first_multi_line_comment_begin > 0)
                code = true;
            if (first_multi_line_comment_begin+language->m_strMltLnCommBegin.Length() < line.Length())
                analyseLine(language, line.Mid(first_multi_line_comment_begin+language->m_strMltLnCommBegin.Length()),
                            comment, code, multi_line_comment);
        }
        else
        {
            code = true;
        }
    }
}
