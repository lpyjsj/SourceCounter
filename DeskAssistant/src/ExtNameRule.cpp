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

    CategorizationFileInfo* pFileInfo = 0;
    wxString strExtName;
    int nCntExtName = 0;

    for (int i=0; i<nCntFileInfo; i++)
    {
        // Get file modification time
        pFileInfo = arrFileInfo[i];
        if (!pFileInfo->m_bCategorized)
        {
            strExtName = pFileInfo->m_pFileName->GetExt();

            nCntExtName = m_arrStrExtName.GetCount();
            for (int j=0; j<nCntExtName; j++)
            {

                if (strExtName.CmpNoCase( m_arrStrExtName[j] ) == 0)
                {
                    pFileInfo->m_strFullDestPath = m_strBaseDestPath + _T("\\") + pFileInfo->m_pFileName->GetFullName();
                    pFileInfo->m_bCategorized = true;
                }
            }
        }
    }
}
