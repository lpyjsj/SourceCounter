// JspCounter.h: interface for the JspCounter class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_JSPCOUNTER_H__BF0BF2A8_B755_4584_A951_0E06761ADC5A__INCLUDED_)
#define AFX_JSPCOUNTER_H__BF0BF2A8_B755_4584_A951_0E06761ADC5A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Counter.h"

class JspCounter : public Counter
{
public:

	JspCounter();

	virtual ~JspCounter();

	/**
	 * counting source file.
	 *
	 * @param strFilePath source file path
	 * @param nLines total lines
	 * @param nCodeLines total code lines
	 * @param nCommentLines comment lines
	 * @param nBlankLines blank lines
	 */
	virtual void countingSourceFile(wxTextFile& file, int& nLines, int& nCodeLines,
                                     int& nCommentLines, int& nCodeCommentLines, int& nBlankLines );

    static wxString ms_strType;
};

#endif // !defined(AFX_JSPCOUNTER_H__BF0BF2A8_B755_4584_A951_0E06761ADC5A__INCLUDED_)
