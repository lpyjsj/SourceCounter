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

/** This function analyses a given source file and count the lines of bCode, comments etc...
 */
void Counter::countLines(wxTextFile& file, CounterRule* pRule, int &total_lines, int &code_lines,
                         int &comment_lines, int &codecomments_lines, int &empty_lines)
{
    bool bDelimitedCommentMode = false;
    total_lines += file.GetLineCount();
    for (unsigned int i=0; i<file.GetLineCount(); ++i)
    {
        // Trim space
        wxString strLine(file[i]);
        strLine = strLine.Trim(true);
        strLine = strLine.Trim(false);

        bool bComment = false;
        bool bCode = false;
        if (strLine.IsEmpty())
            ++empty_lines;
        else
        {
            analyseLine(pRule, strLine, bComment, bCode, bDelimitedCommentMode);
            if (bComment&&bCode) ++codecomments_lines;
            else if (bComment) ++comment_lines;
            else if (bCode) ++code_lines;
        }
    }// End for
}

/** This function determines the caracteristics of a given strLine (bCode strLine, bComment strLine etc...).
 *  It is called by the "CountLines" function.
 *  @see CountLines
 */
void Counter::analyseLine(CounterRule* pRule, wxString strLine, bool &bComment, bool &bCode, bool &bDelimitedCommentMode)
{
    int nIdxFirstSglLnComm, nIdxFirstMltLnCommBegin, nIdxFirstMltLnCommEnd;

    // Delete first and trailing spaces
    strLine = strLine.Trim(true);
    strLine = strLine.Trim(false);

    if (strLine.IsEmpty())
        return;

    // Searching for single and multi-lines bComment signs
    if (pRule->m_strSglLnComm.Len() > 0)
        nIdxFirstSglLnComm = strLine.Find(pRule->m_strSglLnComm);
    else nIdxFirstSglLnComm = -1;
    if (pRule->m_strMltLnCommBegin.Len() > 0)
        nIdxFirstMltLnCommBegin = strLine.Find(pRule->m_strMltLnCommBegin);
    else nIdxFirstMltLnCommBegin = -1;
    if (pRule->m_strMltLnCommEnd.Len() > 0)
        nIdxFirstMltLnCommEnd = strLine.Find(pRule->m_strMltLnCommEnd);
    else nIdxFirstMltLnCommEnd = -1;

    // We are in a multiple strLine bComment => finding the "end of multiple strLine bComment" sign
    if (bDelimitedCommentMode)
    {
        bComment = true;
        if (nIdxFirstMltLnCommEnd > -1)
        {
            bDelimitedCommentMode = false;
            if (nIdxFirstMltLnCommEnd+pRule->m_strMltLnCommEnd.Len() < strLine.Length())
                analyseLine(pRule, strLine.Mid(nIdxFirstMltLnCommEnd+pRule->m_strMltLnCommEnd.Length()),
                            bComment, bCode, bDelimitedCommentMode);
        }
    }
    // We are not in a multiple strLine bComment
    else if (!bDelimitedCommentMode)
    {
        // First bComment sign found is a single strLine bComment sign
        if ( (nIdxFirstSglLnComm>-1)
                &&((nIdxFirstMltLnCommBegin==-1)
                   ||((nIdxFirstMltLnCommBegin>-1)&&(nIdxFirstSglLnComm<nIdxFirstMltLnCommBegin))) )
        {
            bComment = true;
            if (nIdxFirstSglLnComm > 0)
                bCode = true;
        }
        // First bComment sign found is a multi-strLine bComment begin sign
        else if (nIdxFirstMltLnCommBegin>-1)
        {
            bDelimitedCommentMode = true;
            bComment = true;
            if (nIdxFirstMltLnCommBegin > 0)
                bCode = true;
            if (nIdxFirstMltLnCommBegin+pRule->m_strMltLnCommBegin.Len() < strLine.Length())
                analyseLine(pRule, strLine.Mid(nIdxFirstMltLnCommBegin+pRule->m_strMltLnCommBegin.Length()),
                            bComment, bCode, bDelimitedCommentMode);
        }
        else
        {
            bCode = true;
        }
    }
}

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////

/** This function analyses a given source file and count the lines of bCode, comments etc...
 */
void Counter::countLines2(wxTextFile& file, CounterRule* pRule, int &total_lines, int &code_lines,
                          int &comment_lines, int &codecomments_lines, int &empty_lines)
{
    bool bDelimitedCommentMode = false;
    bool bScriptMode = false;

    total_lines += file.GetLineCount();
    for (unsigned int i=0; i<file.GetLineCount(); ++i)
    {
        wxString strLine(file[i]);
        strLine = strLine.Trim(true);
        strLine = strLine.Trim(false);
        bool bComment = false;
        bool bCode = false;
        if (strLine.IsEmpty())
            ++empty_lines;
        else
        {
            analyseLine2(pRule, strLine, bScriptMode, bComment, bCode, bDelimitedCommentMode);
            if (bScriptMode)
            {
                if (bComment&&bCode) ++codecomments_lines;
                else if (bComment) ++comment_lines;
                else if (bCode) ++code_lines;
            }
        }
    }
}

/** This function determines the caracteristics of a given strLine (bCode strLine, bComment strLine etc...).
 *  It is called by the "CountLines" function.
 *  @see CountLines
 */
void Counter::analyseLine2(CounterRule* pRule, wxString strLine, bool& bScriptMode, bool &bComment, bool &bCode, bool &bDelimitedCommentMode)
{
    int nIdxFirstScriptBegin, nIdxFirstScriptEnd;
    int nIdxFirstSglLnComm, nIdxFirstMltLnCommBegin, nIdxFirstMltLnCommEnd;

    //
    // Delete first and trailing spaces
    //
    strLine = strLine.Trim(true);
    strLine = strLine.Trim(false);

    if (strLine.IsEmpty())
        return;

    //
    // Searching for script signs
    //
    if (pRule->m_strScriptBegin.Len() > 0)
        nIdxFirstScriptBegin = strLine.Find(pRule->m_strScriptBegin);
    else nIdxFirstScriptBegin = -1;
    if (pRule->m_strScriptEnd.Len() > 0)
        nIdxFirstScriptEnd = strLine.Find(pRule->m_strScriptEnd);
    else nIdxFirstScriptEnd = -1;

    //
    // Searching for single and multi-lines bComment signs
    //
    if (pRule->m_strSglLnComm.Len() > 0)
        nIdxFirstSglLnComm = strLine.Find(pRule->m_strSglLnComm);
    else nIdxFirstSglLnComm = -1;
    if (pRule->m_strMltLnCommBegin.Len() > 0)
        nIdxFirstMltLnCommBegin = strLine.Find(pRule->m_strMltLnCommBegin);
    else nIdxFirstMltLnCommBegin = -1;
    if (pRule->m_strMltLnCommEnd.Len() > 0)
        nIdxFirstMltLnCommEnd = strLine.Find(pRule->m_strMltLnCommEnd);
    else nIdxFirstMltLnCommEnd = -1;

    //
    // Analyse
    //


    if (bScriptMode)
    {
        // We are in a multiple strLine Comment => finding the "end of multiple Line Comment" sign
        if (bDelimitedCommentMode)
        {
            bComment = true;
            if (nIdxFirstMltLnCommEnd > -1)
            {
                bDelimitedCommentMode = false;
                if (nIdxFirstMltLnCommEnd + pRule->m_strMltLnCommEnd.Len() < strLine.Length())
                    analyseLine2(pRule, strLine.Mid(nIdxFirstMltLnCommEnd + pRule->m_strMltLnCommEnd.Length()),
                                 bScriptMode, bComment, bCode, bDelimitedCommentMode);
            }
        }
        // We are not in a multiple strLine bComment
        else if (!bDelimitedCommentMode)
        {
            // First bComment sign found is a single strLine bComment sign
            if ( (nIdxFirstSglLnComm>-1)
                    &&((nIdxFirstMltLnCommBegin==-1)
                       ||((nIdxFirstMltLnCommBegin>-1)&&(nIdxFirstSglLnComm<nIdxFirstMltLnCommBegin))) )
            {
                bComment = true;
                if (nIdxFirstSglLnComm > 0)
                    bCode = true;
            }
            // First bComment sign found is a multi-strLine bComment begin sign
            else if (nIdxFirstMltLnCommBegin>-1)
            {
                bDelimitedCommentMode = true;
                bComment = true;
                if (nIdxFirstMltLnCommBegin > 0)
                    bCode = true;
                if (nIdxFirstMltLnCommBegin+pRule->m_strMltLnCommBegin.Len() < strLine.Length())
                    analyseLine2(pRule, strLine.Mid(nIdxFirstMltLnCommBegin + pRule->m_strMltLnCommBegin.Length()),
                                 bScriptMode, bComment, bCode, bDelimitedCommentMode);
            }
            else
            {
                bCode = true;
            }
        }

    }
    else if (!bScriptMode)
    {
        if (nIdxFirstScriptBegin > -1)
        {
            bScriptMode = true;

            if (nIdxFirstScriptEnd > -1)
            {
                bScriptMode = false;
                if (nIdxFirstScriptEnd + pRule->m_strScriptEnd.Len() < strLine.Len())
                {
                    analyseLine2(pRule, strLine.Mid(nIdxFirstScriptEnd + pRule->m_strScriptEnd.Length()),
                                 bScriptMode, bComment, bCode, bDelimitedCommentMode);
                }
            }
        }
    }


}
