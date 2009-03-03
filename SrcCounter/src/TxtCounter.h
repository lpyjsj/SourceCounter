/**
 * @file TxtCounter.h
 * @brief interface for the TxtCounter class.
 * @author Boom( boomworks@gmail.com )
 * @author Copyright(C) 2004-2005 boomworks.org , All right reserved.
 * @date 2005-12-10
 * $Revision: $
 */

#if !defined(AFX_TXTCOUNTER_H__1F68A35F_E30B_4222_AFA3_4F6E39142801__INCLUDED_)
#define AFX_TXTCOUNTER_H__1F68A35F_E30B_4222_AFA3_4F6E39142801__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Counter.h"

/**
 * @class TxtCounter
 * txt counter class.
 *
 * @author Boom( boomworks@gmail.com )
 */
class TxtCounter : public Counter
{
public:
	/**
	 * construtor.
	 */
	TxtCounter();
	/**
	 * distructor.
	 */
	virtual ~TxtCounter();

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
};

#endif // !defined(AFX_TXTCOUNTER_H__1F68A35F_E30B_4222_AFA3_4F6E39142801__INCLUDED_)
