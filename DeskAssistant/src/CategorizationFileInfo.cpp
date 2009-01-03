#include "CategorizationFileInfo.h"

CategorizationFileInfo::CategorizationFileInfo(wxString& strPath):
        m_pFileName( 0 ),
        m_bPreProcessed( false ),
        m_bProcessed(false),
        m_strFullDestPath(_T("")),
        m_strDestFolderPath(_T("")),
        m_strDestFolderName(_T(""))
{
    //ctor
    m_pFileName = new wxFileName(strPath);
}

CategorizationFileInfo::~CategorizationFileInfo()
{
    //dtor
    if (m_pFileName)
    {
        delete m_pFileName;
        m_pFileName = 0;
    }
}

wxString CategorizationFileInfo::GetDestFolderPath()
{
	getFileNameAndDirFromFullPath(m_strFullDestPath, m_strDestFolderPath);
    return m_strDestFolderPath; // + _T("\\") + m_strDestFolderName;
}

void CategorizationFileInfo::getFileNameAndDirFromFullPath( wxString& strFullPath, wxString& strDir )
{
    //
    // strFileName.Empty();
    strDir.Empty();

    if ( strFullPath.IsEmpty())
    {
        return;
    }

    //
    int nLastSlashPos = strFullPath.Find( _T( '\\' ), true);
    if ( nLastSlashPos != wxNOT_FOUND )
    {
        strDir			= strFullPath.Left( nLastSlashPos );
        // strFileName 	= strFullPath.Right( strFullPath.Length() - nLastSlashPos - 1 );
    }

}
