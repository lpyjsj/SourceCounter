#ifndef COUNTER_H
#define COUNTER_H

#include <wx/textfile.h>

#include "CountingFileInfo.h"
#include "CountingParam.h"

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

    int GetnLineCountingType()
    {
        return m_nLineCountingType;
    }
    void SetnLineCountingType(int val)
    {
        m_nLineCountingType = val;
    }

    //
    // method
    //

    /**
     * Counting source file method.
     *
     * @param countingFileInfo CCountingFileInfo Objcet Preserver Counting file infomation
     * @param nLineCountingType couting method type
     */
    void Counting( CountingFileInfo* countingFileInfo, CountingParam& countingParam);

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
    virtual void countingSourceFile( wxTextFile& file, int& nLines, int& nCodeLines, int& nCommentLines, int& nBlankLines ) = 0;

    //////////////////////////////////////////////////////////////////////////

    int m_nLineCountingType;    ///<
};

#endif // COUNTER_H
