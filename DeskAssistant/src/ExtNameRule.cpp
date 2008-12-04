#include "ExtNameRule.h"

ExtNameRule::ExtNameRule()
{
	//ctor
}

ExtNameRule::~ExtNameRule()
{
	//dtor
}

void ExtNameRule::Execute(ArrayCategorizationFileInfo& arrFileInfo)
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

    }

}
