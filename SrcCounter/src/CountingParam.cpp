/**
 * @file CountingParam.cpp
 * @brief implementation of the CountingParam class.
 * @author Boom( boomworks@gmail.com )
 * @author Copyright(C) 2004-2005 boomworks.org , All right reserved.
 * @date 2005-12-10
 * $Revision: $
 */

#include "CountingParam.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////

SettingParam::SettingParam():
            m_nUtCaseDensity(50),
            m_nUtDefectDensity(10),
            m_nItCaseDensity(20),
            m_nItDefectDensity(2),
            m_nLinesPerMM(4000),
            m_nDaysPerMM(20),
            m_nCostPerMM(10000)
{
}

SettingParam::~SettingParam()
{}

//////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////

CountingParam::CountingParam():
			m_bRecursiveCounting(true)
{
    m_arrSrcFolderPath.Clear();
    m_arrSrcType.Clear();
}

CountingParam::~CountingParam()
{
    m_arrSrcFolderPath.Clear();
    m_arrSrcType.Clear();
}
