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

    wxString m_strBaseDestDir;		///< In this program, it is mean Desktop
    wxString m_strDestFolderName;	///< It is mean Desktop\FolderName

    ///////////////////////////////////////////////////////////////


    wxString GetCurFullPath()
    {
        return m_pFileName->GetFullPath();
    }

    wxString GetDestFolderPath()
    {
        return m_strBaseDestDir + _T("\\") + m_strDestFolderName;
    }

    wxString GetDestFullPath()
    {
        return m_strBaseDestDir + _T("\\") + m_strDestFolderName + _T("\\") + m_pFileName->GetFullName();
    }


protected:
private:

};

#endif // CATEGORIZATIONFILEINFO_H
