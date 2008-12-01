#include "CategorizeMgr.h"

CategorizeMgr::CategorizeMgr()
{
    //ctor
}

CategorizeMgr::~CategorizeMgr()
{
    //dtor
}

/**
 *
 *
 */
void CategorizeMgr::getSubFolder(wxString& strParentFolderPath, wxArrayString& arrSubFolderPath)
{
    ///////////////////////////////////////////////////////////////
    wxString strValidPath;

    // add *
    if ( strParentFolderPath[strParentFolderPath.Length() - 1] == '\\' )
    {
        strValidPath = strParentFolderPath + _T( "*" );
    }
    else
    {
        strValidPath = strParentFolderPath + _T( "\\*" );
    }

    ///////////////////////////////////////////////////////////////
    // Enum dirs
    ///////////////////////////////////////////////////////////////

    wxString fname;
    wxString strTempFolder, strTempDir;
    int nRecursiveFolderCount = 0;

    wxArrayString arrRecursiveFolder;
    do
    {
        ///////////////////////////////////////////////////////

        // Get first dir
        fname = ::wxFindFirstFile(strValidPath, wxDIR);
        while (!fname.IsEmpty())
        {
            arrSubFolderPath.Add(fname);
            arrRecursiveFolder.Add(fname);

            fname = wxFindNextFile();
        }//while

        if (arrRecursiveFolder.IsEmpty())
        {
            break;
        }

        strTempFolder = arrRecursiveFolder.Last();
        nRecursiveFolderCount = arrRecursiveFolder.GetCount();
        arrRecursiveFolder.RemoveAt(nRecursiveFolderCount - 1);
        strValidPath = strTempFolder + _T( "\\*" );
    }
    while (true);

    // Sort
    arrSubFolderPath.Sort();

}


///////////////////////////////////////////////////////////////////////


void MainDlg::categorizeByTime(bool bPreview)
{
    wxRegKey *pRegKey = new wxRegKey(CSZ_DESKTOP_KEY_PATH);

    //will create the Key if it does not exist
    if ( !pRegKey->Exists() )
    {
        return;
    }

    wxString strDesktopFullPath;
    pRegKey->QueryValue(CSZ_DESKTOP_KEY_NAME, strDesktopFullPath);
    delete pRegKey;

    ///////////////////////////////////////////////////////////////////

    wxString strFilePath = ::wxFindFirstFile(strDesktopFullPath + _T("\\*"), wxFILE);
    if (strFilePath.IsEmpty())
    {
        return;
    }

    wxString strFileExtName;
    long nIndex = -1;
    wxString strTemp;
    while (!strFilePath.IsEmpty())
    {
        ///////////////////////////////////////////////////////////////
        MSG	msg;
        if ( ::PeekMessage( &msg, NULL, 0, 0, PM_REMOVE ))
        {
            ::DispatchMessage( &msg );
        }

        ///////////////////////////////////////////////////////////////

        wxFileName fnCur(strFilePath);
        strFileExtName = fnCur.GetExt();

        wxDateTime timeModification = fnCur.GetModificationTime();

        int nYear = timeModification.GetYear();
        int nMonth = timeModification.GetMonth(); //wxDateTime::Now().FormatDate();
        wxString strM;
        strM.Printf(_T("___%d-%d"), nYear, nMonth + 1);

        if (0 != strFileExtName.CmpNoCase(CSZ_EXCLUDING_FILE_EXT))
        {

            nIndex = m_pLcResult->InsertItem(m_pLcResult->GetItemCount(), fnCur.GetFullPath());
            m_pLcResult->SetItem(nIndex, 1, strM);

            if (!bPreview)
            {
                wxString strTemp(strDesktopFullPath + _T("\\") + strM);
                if (!wxDirExists(strTemp))
                {
                    wxMkdir(strTemp);
                }


                // Move file to dest dir
                wxRenameFile(fnCur.GetFullPath(), strTemp + _T("\\") + fnCur.GetFullName() );

                // Insert item
                m_pLcResult->SetItem(nIndex, 2, _T("Compeleted"));
            }

        }// END IF

       // Next file
        strFilePath =::wxFindNextFile();
    }//END WHILE

}
