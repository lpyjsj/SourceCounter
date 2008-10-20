/**
 * @file CountingFileInfo.cpp
 * @brief implementation of the CountingFileInfo class.
 * @author Boom( boomworks@gmail.com )
 * @author Copyright(C) 2004-2005 BoomWorks.Net , All right reserved.
 * @date 2005-12-12
 * $Revision: $
 */

#include "CountingFileInfo.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CountingFileInfo::CountingFileInfo() :
        m_strFileFullPath   (_T("")),
        m_strFolderPath		(_T( "" )),
        m_strFileName		(_T( "" )),
        m_strFileExtName    (_T("")),
        m_nSize				( 0 ),
        m_nTotalStatement	( 0 ),
        m_nCodeStatement	( 0 ),
        m_nCommentStatement	( 0 ),
        m_nBlankStatement	( 0 )
{}

CountingFileInfo::~CountingFileInfo()
{}
