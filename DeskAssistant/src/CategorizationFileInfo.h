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

    bool m_bCategorized;		///< Whether this file be categorized
    bool m_bProcessed;

    wxString m_strBaseDestPath;		///< In this program, it is mean Desktop
    wxString m_strDestFolderName;	///< It is mean Desktop\FolderName
    wxString m_strFullDestPath;


    ///////////////////////////////////////////////////////////////


    wxString GetCurFullPath()
    {
        return m_pFileName->GetFullPath();
    }

    wxString GetDestFolderPath()
    {
        return m_strBaseDestPath + _T("\\") + m_strDestFolderName;
    }

    wxString GetDestFullPath()
    {
    	m_strFullDestPath = m_strBaseDestPath + _T("\\") + m_strDestFolderName + _T("\\") + m_pFileName->GetFullName();
        return m_strFullDestPath;
    }


protected:
private:

};

#endif // CATEGORIZATIONFILEINFO_H
