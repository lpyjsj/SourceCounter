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

wxString BasicRule::ms_strType = _T("BASIC");

void BasicRule::Execute( CategorizationFileInfo* pFileInfo )
{
    wxDateTime timeModification;

    int nYear, nMonth;
    wxString strM;
    wxString strTemp;

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
}

void BasicRule::GetDispStr(wxString& strDisp )
{
    strDisp = ms_strType;
}
///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////

wxString NameIncludeRule::ms_strType = _T("BY_FILENAME");

void NameIncludeRule::Execute( CategorizationFileInfo* pFileInfo )
{
    wxString strName;

    if (!pFileInfo->m_bPreProcessed)
    {
        strName = pFileInfo->m_pFileName->GetName();

        if (strName.Find( m_strInclude ) != wxNOT_FOUND)
        {
            pFileInfo->m_strFullDestPath = m_strBaseDestPath + _T('\\') + pFileInfo->m_pFileName->GetFullName();
            pFileInfo->m_bPreProcessed = true;
        }
    }
}

void NameIncludeRule::GetDispStr(wxString& strDisp )
{
    strDisp = ms_strType + _T(": ") + m_strInclude + _T(" -> ") + m_strBaseDestPath;
}

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////

wxString ExtNameRule::ms_strType = _T("BY_EXTNAME");

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

void ExtNameRule::GetDispStr(wxString& strDisp )
{
    strDisp = ms_strType + _T(": ");

    int nCntExtName = m_arrStrExtName.GetCount();
    for (int j=0; j<nCntExtName; j++)
    {
        strDisp += m_arrStrExtName[j];
    }

    strDisp += _T(" -> ") + m_strBaseDestPath;
}


wxString ExtNameRule::GetCondition()
{
	wxString strRet;
	int nCntExtName = m_arrStrExtName.GetCount();
    for (int j=0; j<nCntExtName; j++)
    {
        strRet += m_arrStrExtName[j] + _T(';');
    }

	return strRet;
}
