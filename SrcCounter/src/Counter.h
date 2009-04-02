/**
 * $Author: $
 * $Date: $
 * $Revision: $
 * $ID: $*
 */


#ifndef COUNTER_H
#define COUNTER_H

#include <wx/textfile.h>

#include "CountingFileInfo.h"
#include "CountingParam.h"
#include "CounterRule.h"

///////////////////////////////////////////////////////////////////////

/** when code and comment in one statement */
enum
{
    NStatisticAll = 0,				///< statistic code and comment
    NStatisticCodeOnly,				///< statistic code only
    NStatisticCommentOnly,			///< statistic comment only
};

///////////////////////////////////////////////////////////////////////

class Counter
{
public:
    Counter();
    virtual ~Counter();

    //
    // method
    //

    void SetRule(CounterRule* pRule)
    {
        m_pRule = pRule;
    }

    /**
     * Counting source file method.
     *
     * @param countingFileInfo CCountingFileInfo Objcet Preserver Counting file infomation
     * @param nLineCountingType couting method type
     */
    void Counting( CountingFileInfo* countingFileInfo, CountingParam& countingParam);

    ///////////////////////////////////////////////////////////////////


protected:
    /**
     * counting source file.
     *
     * @param strFilePath source file path
     * @param nLines total lines
     * @param nCodeLines total code lines
     * @param nCommentLines comment lines
     * @param nBlankLines blank lines
     */
    virtual void countingSourceFile( wxTextFile& file, int& nLines, int& nCodeLines,
                                     int& nCommentLines, int& nCodeCommentLines, int& nBlankLines ) = 0;

	//
	//
	//
    void countLines(wxTextFile& file, CounterRule* language, int &total_lines, int &code_lines,
                         int &comment_lines, int &codecomments_lines, int &empty_lines);

    void analyseLine(CounterRule* language, wxString line, bool &comment, bool &code, bool &multi_line_comment);	//
	//
	//
    void countLines2(wxTextFile& file, CounterRule* language, int &total_lines, int &code_lines,
                         int &comment_lines, int &codecomments_lines, int &empty_lines);

    void analyseLine2(CounterRule* language, wxString line, bool& bScriptMode,  bool &comment, bool &code, bool &multi_line_comment);

    //////////////////////////////////////////////////////////////////////////

    CounterRule* m_pRule;

private:


};

#endif // COUNTER_H
