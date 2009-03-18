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
        m_strDesc(strDesc)
{
    //ctor
}

CounterRule::~CounterRule()
{
    //dtor
}

FileExtension* CounterRule::FindFileExtension(wxString& strFileExt)
{
    FileExtension* pFileExt = 0;
    MapStrToFileExtension::iterator it;

    it = m_mapStrToFileExtension.find( strFileExt );
    if (it != m_mapStrToFileExtension.end())
    { // Find instance in map
        pFileExt = it->second;
    }

    return pFileExt;
}
