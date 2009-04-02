#include "CounterRule.h"

///////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////

FileExtension::FileExtension(wxString& strName, wxString& strCounterType, wxString& strDesc, bool bSel):
        m_strName(strName),
        m_strCounterType(strCounterType),
        m_strDesc(strDesc),
        m_bSel(bSel)
{
    //ctor
}

FileExtension::~FileExtension()
{
    //dtor
}

///////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////

CounterRule::CounterRule(wxString& strType, wxString& strDesc):
        m_strType(strType),
        m_strDesc(strDesc),
        m_strScriptBegin(_T("")),
        m_strScriptEnd(_T("")),
        m_strSglLnComm(_T("")),
        m_strMltLnCommBegin(_T("")),
        m_strMltLnCommEnd(_T(""))
{
    //ctor
}

CounterRule::~CounterRule()
{
    //dtor
}


