#ifndef COUNTERRULE_H
#define COUNTERRULE_H

//////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////

class FileExtension
{
public:
    FileExtension(wxString& strName, wxString& strCounterType = _T(""), wxString& strDesc = _T(""), bool bSel = false);
    virtual ~FileExtension();

    wxString m_strName;
    wxString m_strCounterType;
    wxString m_strDesc;
    bool m_bSel;

};

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////


//WX_DECLARE_STRING_HASH_MAP( Counter*, MapStrToCounter);

///////////////////////////////////////////////////////////////////////

class CounterRule
{
public:
	CounterRule() {}
    CounterRule(wxString& strType, wxString& strDesc = _T(""));
    virtual ~CounterRule();

    // Rult propertise
    wxString m_strType;
    wxString m_strDesc;

	// Script signs
    wxString m_strScriptBegin;
    wxString m_strScriptEnd;
    // Comment
    wxString m_strSglLnComm;
    wxString m_strMltLnCommBegin;
    wxString m_strMltLnCommEnd;

protected:
private:
};

///////////////////////////////////////////////////////////////////////

#endif // COUNTERRULE_H
