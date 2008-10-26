// CountingInfo.h: interface for the CountingInfo class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_STATISTICINFO_H__67AF96E2_A74A_41C2_BBE5_4D529F218B2E__INCLUDED_)
#define AFX_STATISTICINFO_H__67AF96E2_A74A_41C2_BBE5_4D529F218B2E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "CountingFileInfo.h"

/**
 * @class CountingInfo
 * statistic infomation class.
 *
 * @author Boom( boomworks@gmail.com )
 */
class CountingInfo
{
public:

	/**
	 * construtor.
	 */
	CountingInfo();

	/**
	 * distrutor.
	 */
	virtual ~CountingInfo();

	/**
	 * operator reload.
	 *
	 * @param srcInfo Source CountingInfo Object
	 * @return CountingInfo& Des CStatistic Object
	 */
	CountingInfo& operator=( CountingInfo& srcInfo );

	/**
	 * clear statistic infomation.
	 */
	void Clear();

//	private:

	CountingFileInfo* m_pCountingFileInfo;		///< current counting file infomation

	//
	// total statistic info
	//
	int			m_nTotalFile;		///< total of source files
	int			m_nTotalSize;		///< total of source files size

	int			m_nTotalStatement;			///< total of statement
	int			m_nTotalCodeStatement;		///< total of code statement
	int			m_nTotalCommentStatement;	///< total of comment statement
	int			m_nTotalBlankStatement;		///< total of blank of statement


};

inline void CountingInfo::Clear()
{
	m_nTotalFile = 0;
	m_nTotalSize = 0;

	m_nTotalStatement			= 0;
	m_nTotalCodeStatement		= 0;
	m_nTotalCommentStatement	= 0;
	m_nTotalBlankStatement		= 0;

	// TODO:
	//	m_pCountingFileInfo.Clear();
}


inline CountingInfo& CountingInfo::operator =( CountingInfo& srcInfo)
{
	//
	m_nTotalFile		= srcInfo.m_nTotalFile;
	m_nTotalSize		= srcInfo.m_nTotalSize;
	//
	m_nTotalStatement			= srcInfo.m_nTotalStatement;
	m_nTotalCodeStatement		= srcInfo.m_nTotalCodeStatement;
	m_nTotalCommentStatement	= srcInfo.m_nTotalCommentStatement;
	m_nTotalBlankStatement		= srcInfo.m_nTotalBlankStatement;

	return *this;
}

#endif // !defined(AFX_STATISTICINFO_H__67AF96E2_A74A_41C2_BBE5_4D529F218B2E__INCLUDED_)
