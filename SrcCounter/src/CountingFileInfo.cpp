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

CountingFileInfo::CountingFileInfo(CountingFileInfo& fileInfo) :
        m_strFileFullPath   (fileInfo.m_strFileFullPath),
        m_strFolderPath		(fileInfo.m_strFolderPath),
        m_strFileName		(fileInfo.m_strFileName),
        m_strFileExtName    (fileInfo.m_strFileExtName),
        m_nSize				(fileInfo.m_nSize),
        m_nTotalStatement	(fileInfo.m_nTotalStatement),
        m_nCodeStatement	(fileInfo.m_nCodeStatement),
        m_nCommentStatement	(fileInfo.m_nCommentStatement),
        m_nBlankStatement	(fileInfo.m_nBlankStatement)
{}

CountingFileInfo::~CountingFileInfo()
{}
