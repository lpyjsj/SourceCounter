/**
 * @file CountingInfo.cpp
 * @brief implementation of the CountingInfo class.
 * @author Boom( boomworks@gmail.com )
 * @author Copyright(C) 2004-2005 boomworks.org , All right reserved.
 * @date 2005-12-10
 * $Revision: $
 */

#include "CountingInfo.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CountingInfo::CountingInfo() :
		m_nTotalFile( 0 ),
		m_nTotalSize( 0 ),
		m_nTotalStatement( 0 ),
		m_nTotalCodeStatement( 0 ),
		m_nTotalCommentStatement( 0 ),
		m_nTotalBlankStatement( 0 ),
		m_fTotalManMonth(0.0),
		m_fTotalCost(0.0),
		m_fTotalUtCases(0.0),
		m_fTotalUtDefects(0.0),
		m_fTotalItCases(0.0),
		m_fTotalItDefects(0.0)
{}

CountingInfo::~CountingInfo()
{
	clearArrCountingFileInfo();
}

void CountingInfo::Clear()
{
    m_nTotalFile = 0;
    m_nTotalSize = 0;

    m_nTotalStatement			= 0;
    m_nTotalCodeStatement		= 0;
    m_nTotalCommentStatement	= 0;
    m_nTotalBlankStatement		= 0;

    m_fTotalManMonth		= 0.0;
    m_fTotalCost			= 0.0;

	// Boom: add UT and IT counting information on 2009-3-3
	m_fTotalUtCases			= 0.0;
	m_fTotalUtDefects		= 0.0;
	m_fTotalItCases			= 0.0;
	m_fTotalItDefects		= 0.0;

	// Clear fileinfo array
	clearArrCountingFileInfo();
}

void CountingInfo::clearArrCountingFileInfo()
{
	// Clear counting file info objs
    int nCount = m_arrCountingFileInfo.GetCount();
    CountingFileInfo* pInfo = 0;
    for(int i=0; i<nCount; i++)
    {
        pInfo = m_arrCountingFileInfo[i];
        delete pInfo;
        pInfo = 0;
        //wxMessageBox(_T("delete fileinfo"));
    }

    m_arrCountingFileInfo.Clear();
}
