#include <wx/filename.h>

#include "Rule.h"

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////

Rule::Rule() :
	m_bSelected( false )
{
	//ctor
}

Rule::~Rule()
{
	//dtor
}


///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////


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

void BasicRule::Execute( CategorizationFileInfo* pFileInfo )
{
    //

//    int nCntFileInfo = arrFileInfo.GetCount();
//    if (0 == nCntFileInfo)
//    {
//        return;
//    }

    //CategorizationFileInfo* pFileInfo = 0; // = pArrFileInfo[]
    wxDateTime timeModification;

    int nYear, nMonth;
    wxString strM;
    wxString strTemp;

//    for (int i=0; i<nCntFileInfo; i++)
//    {
        // Get file modification time
       // pFileInfo = arrFileInfo[i];

        if (!pFileInfo->m_bPreProcessed)
        {
            timeModification = pFileInfo->m_pFileName->GetModificationTime();

            nYear = timeModification.GetYear();
            nMonth = timeModification.GetMonth(); //wxDateTime::Now().FormatDate();

            strM.Printf(_T("___%d-%d"), nYear, nMonth + 1);
            pFileInfo->m_strDestFolderName = strM;
            pFileInfo->m_strFullDestPath = m_strBaseDestPath + _T('\\') + strM + _T('\\') + pFileInfo->m_pFileName->GetFullName();

            //
            pFileInfo->m_bPreProcessed = true;
        }
 //   }
}


///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////

wxString NameIncludeRule::ms_strType = _T("BY_FILENAME");


///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////


ExtNameRule::ExtNameRule()
{
    //ctor
}

ExtNameRule::~ExtNameRule()
{
    //dtor
}

void ExtNameRule::Execute( CategorizationFileInfo* pFileInfo )
{
    wxString strExtName;

    if (!pFileInfo->m_bPreProcessed)
    {
        strExtName = pFileInfo->m_pFileName->GetExt();

        int nCntExtName = m_arrStrExtName.GetCount();
        for (int j=0; j<nCntExtName; j++)
        {
            if (strExtName.CmpNoCase( m_arrStrExtName[j] ) == 0)
            {
                pFileInfo->m_strFullDestPath = m_strBaseDestPath + _T('\\') + pFileInfo->m_pFileName->GetFullName();
                pFileInfo->m_bPreProcessed = true;
            }
        }
    }

}



///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
