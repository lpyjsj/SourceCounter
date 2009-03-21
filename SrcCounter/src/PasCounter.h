/**
 * @file PasCounter.h
 * @brief interface for the PascalCounter class.
 * @author Boom( boomworks@hotmail.com )
 * @author Copyright(C) 2004-2005 boomworks.org , All right reserved.
 * @date 2005-12-10
 * $Revision: $
 */

#if !defined(AFX_PASCOUNTER_H__0849CEC0_88C4_4F29_8591_0AEDFA9DD605__INCLUDED_)
#define AFX_PASCOUNTER_H__0849CEC0_88C4_4F29_8591_0AEDFA9DD605__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Counter.h"

/**
 * @class PascalCounter
 * pascal source file counting class.
 *
 * @author Boom( boomworks@hotmail.com )
 */
class PascalCounter : public Counter
{
public:

	/**
	 * constructor.
	 */
	PascalCounter();

	/**
	 * distructor.
	 */
	virtual ~PascalCounter();

	/**
	 * counting source file.
	 *
	 * @param strFilePath source file path
	 * @param nLines total lines
	 * @param nCodeLines total code lines
	 * @param nCommentLines comment lines
	 * @param nBlankLines blank lines
	 */
	virtual void countingSourceFile( wxTextFile& file, int& nLines, int& nCodeLines, int& nCommentLines, int& nBlankLines );

	static wxString ms_strType;
};

#endif // !defined(AFX_PASCOUNTER_H__0849CEC0_88C4_4F29_8591_0AEDFA9DD605__INCLUDED_)
