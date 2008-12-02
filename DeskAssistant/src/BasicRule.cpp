
#include <wx/filename.h>
#include "BasicRule.h"



BasicRule::BasicRule()
{
    //ctor
}

BasicRule::~BasicRule()
{
    //dtor
}


void BasicRule::Execute(ArrayCategorizationFileInfo& arrFileInfo, bool bPreview)
{
    //

    int nCntFileInfo = arrFileInfo.GetCount();
    if (0 == nCntFileInfo)
    {
        return;
    }

    CategorizationFileInfo* pFileInfo = 0; // = pArrFileInfo[]
    wxDateTime timeModification;

    int nYear, nMonth;
    wxString strM;
    wxString strTemp;

    for (int i=0; i<nCntFileInfo; i++)
    {
        // Get file modification time
        pFileInfo = arrFileInfo[i];


        timeModification = pFileInfo->m_pFileName->GetModificationTime();

        nYear = timeModification.GetYear();
        nMonth = timeModification.GetMonth(); //wxDateTime::Now().FormatDate();


        strM.Printf(_T("___%d-%d"), nYear, nMonth + 1);
        pFileInfo->m_strDestFolderName = strM;

        if (!bPreview)
        {
            strTemp = pFileInfo->m_strBaseDestDir + _T("\\") + strM;

            if (!wxDirExists(strTemp))
            {
                wxMkdir(strTemp);
            }

            // Move file to dest dir
            wxRenameFile(pFileInfo->m_pFileName->GetFullPath(), strTemp + _T("\\") + pFileInfo->m_pFileName->GetFullName() );
        }



    }

}
