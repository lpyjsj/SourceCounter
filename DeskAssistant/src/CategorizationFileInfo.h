#ifndef CATEGORIZATIONFILEINFO_H
#define CATEGORIZATIONFILEINFO_H

#include <wx/filename.h>

class CategorizationFileInfo
{
public:

    CategorizationFileInfo( wxString& strPath);
    virtual ~CategorizationFileInfo();

    ///////////////////////////////////////////////////////////////

    wxFileName* m_pFileName;	///<

    bool m_bPreProcessed;		///< Whether this file be categorized
    bool m_bProcessed;

    wxString m_strFullDestPath;
    wxString m_strDestFolderPath;		///< In this program, it is mean Desktop
    wxString m_strDestFolderName;	///< It is mean Desktop\FolderName

    ///////////////////////////////////////////////////////////////

    wxString GetCurFullPath()
    {
        return m_pFileName->GetFullPath();
    }

    wxString GetDestFullPath()
    {
        // m_strFullDestPath = m_strBaseDestPath + _T("\\") + m_strDestFolderName + _T("\\") + m_pFileName->GetFullName();
        return m_strFullDestPath;
    }

    wxString GetDestFolderPath();


protected:

private:

	void getFileNameAndDirFromFullPath( wxString& strFullPath, wxString& strDir );
};

#endif // CATEGORIZATIONFILEINFO_H
