/**
 * Categorization management class.
 *
 */

#include <wx/config.h>
#include <wx/filename.h>

#include "BasicRule.h"
#include "CategorizeMgr.h"


//const wxChar* CSZ_EXCLUDING_FILE_EXT[] = { _T("lnk")}; ///< excluding file type
const wxString CSZ_EXCLUDING_FILE_EXT = _T("lnk");

CategorizeMgr::CategorizeMgr():
        m_pObserver( 0 )
{
    //ctor
    Rule* pRule = new BasicRule();
    m_arrRule.Add(pRule);
}

CategorizeMgr::~CategorizeMgr()
{
    // Delete rule
    int nCnt = m_arrRule.GetCount();
    Rule* pRule = 0;
    for (int i=0; i<nCnt; i++)
    {
        pRule = m_arrRule.Item(i);
        if (pRule)
        {
            delete pRule;
            pRule = 0;
        }
    }

    // Delete categorizationFileInfo
    nCnt = m_arrCategorizationFileInfo.GetCount();
    CategorizationFileInfo* pFileInfo = 0;
    for (int i=0; i<nCnt; i++)
    {
        pFileInfo = m_arrCategorizationFileInfo.Item(i);
        if (pFileInfo)
        {
            delete pFileInfo;
            pFileInfo = 0;
        }
    }

}

/**
 *
 *
 */
void CategorizeMgr::getSubFolder(wxString& strParentFolderPath, wxArrayString& arrSubFolderPath, bool bRecursive)
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

    wxString strDirName;
    wxString strTempFolder, strTempDir;
    int nRecursiveFolderCount = 0;

    wxArrayString arrRecursiveFolder;
    do
    {
        ///////////////////////////////////////////////////////

        // Get first dir
        strDirName = ::wxFindFirstFile(strValidPath, wxDIR);
        while (!strDirName.IsEmpty())
        {
            if (strDirName.Contains(_T("___")))
            {
                arrSubFolderPath.Add(strDirName);
                if (bRecursive)
                {
                    arrRecursiveFolder.Add(strDirName);
                }
            }

            strDirName = wxFindNextFile();
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

void CategorizeMgr::getFolderAllFile(wxString& strFolderPath, ArrayCategorizationFileInfo& arrFileInfo )
{
    //
    wxString strValidPath;

    // add *
    if ( strFolderPath[strFolderPath.Length() - 1] == '\\' )
    {
        strValidPath = strFolderPath + _T( "*" );
    }
    else
    {
        strValidPath = strFolderPath + _T( "\\*" );
    }

    ///////////////////////////////////////////////////////////////////

    wxString strDirName = ::wxFindFirstFile(strValidPath, wxFILE);
    wxString strFileExt;
    wxString strDesktopPath;
    while (!strDirName.IsEmpty())
    {
        wxFileName fileName(strDirName);
        strFileExt = fileName.GetExt();

        if (strFileExt.CmpNoCase( CSZ_EXCLUDING_FILE_EXT ) != 0)
        {// Excluding .lnk file(shortcut files)
            CategorizationFileInfo* pFileInfo = new CategorizationFileInfo(strDirName);

            pFileInfo->m_strBaseDestDir = m_strDesktopPath;
            arrFileInfo.Add(pFileInfo);
        }

        // Next file
        strDirName = ::wxFindNextFile();
    }//while

}

/**
 *
 *
 */
void CategorizeMgr::Categorize(wxString& strPathForCategorize, bool bPreview)
{
    // Clear
    int nCnt = m_arrStrSubFolder.GetCount();
    if (nCnt > 0)
    {
        m_arrStrSubFolder.Empty();
    }

    nCnt = m_arrCategorizationFileInfo.GetCount();
    CategorizationFileInfo* pFileInfo = 0;

    while (!m_arrCategorizationFileInfo.IsEmpty())
    {
        pFileInfo = m_arrCategorizationFileInfo.Last();
        m_arrCategorizationFileInfo.Remove(pFileInfo);
        if (pFileInfo)
        {
            delete pFileInfo;
            pFileInfo = 0;
        }
    }


    // Get sub folder path for categorize path
    m_arrStrSubFolder.Add(strPathForCategorize);
    getSubFolder(strPathForCategorize, m_arrStrSubFolder, false);

    nCnt = m_arrStrSubFolder.GetCount();
    if (0 == nCnt)
    {
        return;
    }

    for (int i=0; i<nCnt; i++)
    {
        // Get all file in folder
        getFolderAllFile(m_arrStrSubFolder[i], m_arrCategorizationFileInfo);
    }

    // For each rule
    int nCntRule = m_arrRule.GetCount();
    Rule* pRule = 0;
    for (int j=0; j<nCntRule; j++)
    {
        pRule = m_arrRule[j];

        if (pRule)
        {
            pRule->Execute(m_arrCategorizationFileInfo, bPreview);
        }

        Notify();
    }// END FOR RULES

}

///////////////////////////////////////////////////////////////////////
// observer pattern method
///////////////////////////////////////////////////////////////////////

void CategorizeMgr::AttachObserver( CategorizationObserver* pObserver )
{
    if (!m_pObserver)
        m_pObserver	= pObserver;
}

void CategorizeMgr::Notify()
{
    m_pObserver->UpdateCategorizationCtrls();
}
