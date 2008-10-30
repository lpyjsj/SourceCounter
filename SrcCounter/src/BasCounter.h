/**
 * @file BasCounter.h
 * @brief VbsCounter.h: interface for the CVbsCounter class.
 * @author Boom( boomworks@hotmail.com )
 * @author Copyright(C) 2004-2005 BoomWorks.Net , All right reserved.
 * @date 2005-11-25
 * $Revision: $
 */

#if !defined(AFX_VBSCOUNTER_H__55AB328C_2715_4250_8C1C_F3A3DC4DFB34__INCLUDED_)
#define AFX_VBSCOUNTER_H__55AB328C_2715_4250_8C1C_F3A3DC4DFB34__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Counter.h"

/**
 * @class BasicCounter
 * bas souce file counter class.
 *
 * @author Boom( boomworks@hotmail.com )
 */
class BasicCounter : public Counter
{
public:

	/**
	 * get BasicCounter 's Instance.
	 *
	 * @return BasicCounter Instance
	 */
	static BasicCounter* GetInstance();


	/**
	 * distructor.
	 */
	virtual ~BasicCounter();

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


private:

	static BasicCounter* ms_instance;		///< static instance

	//////////////////////////////////////////////////////////////////////////

	/**
	 * constructor.
	 */
	BasicCounter();
};

inline BasicCounter* BasicCounter::GetInstance()
{
	if ( ms_instance == 0 )
	{
		ms_instance = new BasicCounter;
	}

	return ms_instance;
}

#endif // !defined(AFX_VBSCOUNTER_H__55AB328C_2715_4250_8C1C_F3A3DC4DFB34__INCLUDED_)
