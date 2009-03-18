#ifndef COUNTERRULE_H
#define COUNTERRULE_H

//////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////

class FileExtension
{
public:
    FileExtension(wxString& strName, wxString& strCounterType = _T("txt"), wxString& strDesc = _T(""), bool bSel = false);
    virtual ~FileExtension();

    wxString m_strName;
    wxString m_strCounterType;
    wxString m_strDesc;
    bool m_bSel;

};

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////

WX_DECLARE_STRING_HASH_MAP(FileExtension*, MapStrToFileExtension);
//WX_DECLARE_STRING_HASH_MAP( Counter*, MapStrToCounter);

///////////////////////////////////////////////////////////////////////

class CounterRule
{
public:
	CounterRule() {}
    CounterRule(wxString& strType, wxString& strDesc = _T(""));
    virtual ~CounterRule();

    //
    wxString m_strType;
    wxString m_strDesc;
    MapStrToFileExtension m_mapStrToFileExtension;

    //
    void AddFileExtension(FileExtension* pFileExt)
    {
        m_mapStrToFileExtension[pFileExt->m_strName] = pFileExt;
    }
    FileExtension* FindFileExtension(wxString& strFileExt);

protected:
private:
};

///////////////////////////////////////////////////////////////////////

#endif // COUNTERRULE_H
