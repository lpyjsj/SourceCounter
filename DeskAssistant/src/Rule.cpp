#include <wx/filename.h>
#include <wx/tokenzr.h>

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
unsigned long BasicRule::ms_nType = 0;

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
    strDisp = CSZ_RULE_TYPE_NAMES[ms_nType];
}


///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
unsigned long ExtNameRule::ms_nType = 1;

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
    strDisp = CSZ_RULE_TYPE_NAMES[ms_nType] + _T(": ");

    int nCntExtName = m_arrStrExtName.GetCount();
    for (int j=0; j<nCntExtName; j++)
    {
        strDisp += m_arrStrExtName[j] + _T(';');
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

void ExtNameRule::SetCondition(wxString strCondition)
{
	//
	m_arrStrExtName.Clear();

	//
    wxStringTokenizer tkz(strCondition, _T(';'));
    while ( tkz.HasMoreTokens() )
    {
        wxString token = tkz.GetNextToken();
        token.Trim();
        if(!token.IsEmpty())
			m_arrStrExtName.Add(token);
    }
}

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////

unsigned long NameIncludeRule::ms_nType = 2;

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
    strDisp = CSZ_RULE_TYPE_NAMES[ms_nType] + _T(": ") + m_strInclude + _T(" -> ") + m_strBaseDestPath;
}
