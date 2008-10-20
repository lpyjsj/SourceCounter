/**
 * @file CountingInfo.cpp
 * @brief implementation of the CountingInfo class.
 * @author Boom( boomworks@gmail.com )
 * @author Copyright(C) 2004-2005 BoomWorks.Net , All right reserved.
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
		m_nTotalBlankStatement( 0 )
{
}


CountingInfo::~CountingInfo()
{
}
