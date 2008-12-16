#include "ExtNameRule.h"

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
