/**
 * Categorization management class.
 *
 */

#include <wx/config.h>
#include <wx/filename.h>

#include "CategorizeMgr.h"
#include "BasicRule.h"

const wxString CSZ_EXCLUDING_FILE_EXT = _T("lnk"); ///< excluding file type

CategorizeMgr::CategorizeMgr():
        m_pObserver( 0 )
{
    //ctor
    Rule* pRule = new BasicRule();
    m_arrRule.Add(pRule);
}

CategorizeMgr::~CategorizeMgr()
{
    //dtor

    int nCnt = m_arrCategorizationFileInfo.GetCount();
    CategorizationFileInfo* pFileInfo = 0;
    for (int i=0; i<nCnt; i++)
    {
        pFileInfo = m_arrCategorizationFileInfo[i];
        delete pFileInfo;
        pFileInfo = 0;
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
    while (!strDirName.IsEmpty())
    {

        //if (!strDirName.Contains(CSZ_EXCLUDING_FILE_EXT))
        //{
            CategorizationFileInfo* pFileInfo = new CategorizationFileInfo(strDirName);
            arrFileInfo.Add(pFileInfo);

            strDirName = wxFindNextFile();
        //}
    }//while
}

/**
 *
 *
 */
void CategorizeMgr::Categorize(wxString& strPathForCategorize, bool bPreview)
{
    // Get sub folder path for categorize path
    m_arrStrSubFolder.Add(strPathForCategorize);
    getSubFolder(strPathForCategorize, m_arrStrSubFolder, bPreview);

    int nCnt = m_arrStrSubFolder.GetCount();
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
    for (int i=0; i<nCntRule; i++)
    {
        pRule = m_arrRule[i];

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
