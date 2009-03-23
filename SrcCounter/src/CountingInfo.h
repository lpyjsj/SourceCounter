//////////////////////////////////////////////////////////////////////
// CountingInfo.h: interface for the CountingInfo class.
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_STATISTICINFO_H__67AF96E2_A74A_41C2_BBE5_4D529F218B2E__INCLUDED_)
#define AFX_STATISTICINFO_H__67AF96E2_A74A_41C2_BBE5_4D529F218B2E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "CountingFileInfo.h"

///////////////////////////////////////////////////////////////////////
WX_DEFINE_ARRAY(CountingFileInfo*, ArrayCountingFileInfo);
///////////////////////////////////////////////////////////////////////

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

public:

    // total statistic info
    int			m_nTotalFile;		///< total of source files
    int			m_nTotalSize;		///< total of source files size

    int			m_nTotalStatement;			///< total of statement
    int			m_nTotalCodeStatement;		///< total of code statement
    int			m_nTotalCommentStatement;	///< total of comment statement
    int			m_nTotalCodeCommentStatement;
    int			m_nTotalBlankStatement;		///< total of blank of statement

    float		m_fTotalManMonth;		///<
    float		m_fTotalCost;			///<

    // Boom: add UT and IT cases, defects on 2009-3-3
    float		m_fTotalUtCases;		///<
    float		m_fTotalUtDefects;		///<
    float		m_fTotalItCases;		///<
    float		m_fTotalItDefects;		///<

    ///////////////////////////////////////////////////////////////////

    /**
     * clear statistic infomation.
     */
    void Clear();

	// Add counting file info to array
    void AddCountingFileInfo(CountingFileInfo* pFileInfo)	{ m_arrCountingFileInfo.Add(pFileInfo); }

	// Get last counting file informaiton
    CountingFileInfo* GetLastCountingFileInfo(void)			{ return m_arrCountingFileInfo.Last(); }

	// Get counting file info array
    ArrayCountingFileInfo* GetCountingFileInfoArr(void)		{ return &m_arrCountingFileInfo; }

private:

    ArrayCountingFileInfo   m_arrCountingFileInfo;      ///< Array for store counting file info

    ///////////////////////////////////////////////////////////////////

	// clear counting file information array
    void clearArrCountingFileInfo();
};

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////

// TODO: implement operator =
inline CountingInfo& CountingInfo::operator =( CountingInfo& srcInfo)
{
	//
    m_nTotalFile		= srcInfo.m_nTotalFile;
    m_nTotalSize		= srcInfo.m_nTotalSize;
    //
    m_nTotalStatement			= srcInfo.m_nTotalStatement;
    m_nTotalCodeStatement		= srcInfo.m_nTotalCodeStatement;
    m_nTotalCommentStatement	= srcInfo.m_nTotalCommentStatement;
    m_nTotalCodeCommentStatement = srcInfo.m_nTotalCodeCommentStatement;
    m_nTotalBlankStatement		= srcInfo.m_nTotalBlankStatement;

    m_fTotalManMonth		= srcInfo.m_fTotalManMonth;
    m_fTotalCost			= srcInfo.m_fTotalCost;

    // Boom: add UT and IT counting information
    m_fTotalUtCases			= srcInfo.m_fTotalUtCases;
    m_fTotalUtDefects		= srcInfo.m_fTotalUtDefects;
	m_fTotalItCases			= srcInfo.m_fTotalItCases;
    m_fTotalItDefects		= srcInfo.m_fTotalItDefects;

    return *this;
}

#endif // !defined(AFX_STATISTICINFO_H__67AF96E2_A74A_41C2_BBE5_4D529F218B2E__INCLUDED_)
