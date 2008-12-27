/**
 * Categorization management class.
 *
 */

#include <wx/config.h>
#include <wx/filename.h>

#include "Rule.h"
#include "CategorizeMgr.h"

///////////////////////////////////////////////////////////////////////

bool wxXmlDocumentEx::Save(const wxString& filename, int indentstep) const
{
    wxFileOutputStream stream(filename);
    if (!stream.Ok())
        return false;
    return Save(stream, indentstep);
}

bool wxXmlDocumentEx::Save(wxOutputStream& stream, int indentstep) const
{
    if ( !IsOk() )
        return false;

    wxString s;

    wxMBConv *convMem = NULL,
                        *convFile;

#if wxUSE_UNICODE
    convFile = new wxCSConv(GetFileEncoding());
    convMem = NULL;
#else
    if ( GetFileEncoding().CmpNoCase(GetEncoding()) != 0 )
    {
        convFile = new wxCSConv(GetFileEncoding());
        convMem = new wxCSConv(GetEncoding());
    }
    else // file and in-memory encodings are the same, no conversion needed
    {
        convFile =
            convMem = NULL;
    }
#endif

    s.Printf(wxT("<?xml version=\"%s\" encoding=\"%s\"?>\n"),
             GetVersion().c_str(), GetFileEncoding().c_str());
    OutputString(stream, s);

    OutputNode(stream, GetRoot(), 0, convMem, convFile, indentstep);
    OutputString(stream, wxT("\n"));

    delete convFile;
    delete convMem;

    return true;
}

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////

const wxString CSZ_RULE_TAG_NAMES[] =
{
    _T("index"),
    _T("type"),
    _T("selected"),
    _T("condition"),
    _T("dest"),
};


const wxString CSZ_RULES_DATA_XML = _T("rules.xml");
//const wxChar* CSZ_EXCLUDING_FILE_EXT[] = { _T("lnk")}; ///< excluding file type
const wxString CSZ_EXCLUDING_FILE_EXT = _T("lnk");

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////

unsigned int CategorizeMgr::ms_nCurMaxIndex = 0;

CategorizeMgr::CategorizeMgr():
        m_pObserver( 0 ),
        m_pRoot(0)
{
    //ctor

}

CategorizeMgr::~CategorizeMgr()
{
    // Save rule info to xml file
    saveRuleInfo();

    // Delete rule
    clearRules();

    // Delete categorizationFileInfo
    clearFileInfos();
}

void CategorizeMgr::clearRules()
{
    Rule* pRule = 0;
    while (!m_arrRule.IsEmpty())
    {
        pRule = m_arrRule.Last();
        m_arrRule.Remove(pRule);

        if (pRule)
        {
            delete pRule;
            pRule = 0;
        }
    }

}

void CategorizeMgr::clearFileInfos()
{
    CategorizationFileInfo* pFileInfo = 0;
    while (!m_arrCategorizationFileInfo.IsEmpty())
    {
        pFileInfo = m_arrCategorizationFileInfo.Last();
        m_arrCategorizationFileInfo.Remove(pFileInfo);
        if (pFileInfo)
        {
            delete pFileInfo;
            pFileInfo = 0;
        }
    }
}

void CategorizeMgr::Init(wxString& strPath)
{
    m_strDesktopPath = strPath;
    // TODO: load rule from conf file, the last is basic rule
    loadRuleInfo();
}

/**
 *
 *
 */
void CategorizeMgr::getSubFolder(wxString& strParentFolderPath, wxArrayString& arrSubFolderPath, bool bRecursive)
{
    ///////////////////////////////////////////////////////////////
    wxString strValidPath;

    // add *
    if ( strParentFolderPath[strParentFolderPath.Length() - 1] == '\\' )
    {
        strValidPath = strParentFolderPath + _T( "*" );
    }
    else
    {
        strValidPath = strParentFolderPath + _T( "\\*" );
    }

    ///////////////////////////////////////////////////////////////
    // Enum dirs
    ///////////////////////////////////////////////////////////////

    wxString strDirName;
    wxString strTempFolder, strTempDir;
    int nRecursiveFolderCount = 0;

    wxArrayString arrRecursiveFolder;
    do
    {
        ///////////////////////////////////////////////////////

        // Get first dir
        strDirName = ::wxFindFirstFile(strValidPath, wxDIR);
        while (!strDirName.IsEmpty())
        {
            if (strDirName.Contains(_T("___")))
            {
                arrSubFolderPath.Add(strDirName);
                if (bRecursive)
                {
                    arrRecursiveFolder.Add(strDirName);
                }
            }

            strDirName = wxFindNextFile();
        }//while

        if (arrRecursiveFolder.IsEmpty())
        {
            break;
        }

        strTempFolder = arrRecursiveFolder.Last();
        nRecursiveFolderCount = arrRecursiveFolder.GetCount();
        arrRecursiveFolder.RemoveAt(nRecursiveFolderCount - 1);
        strValidPath = strTempFolder + _T( "\\*" );
    }
    while (true);

    // Sort
    arrSubFolderPath.Sort();

}

void CategorizeMgr::getFolderAllFile(wxString& strFolderPath, ArrayCategorizationFileInfo& arrFileInfo )
{
    //
    wxString strValidPath;

    // add *
    if ( strFolderPath[strFolderPath.Length() - 1] == '\\' )
    {
        strValidPath = strFolderPath + _T( "*" );
    }
    else
    {
        strValidPath = strFolderPath + _T( "\\*" );
    }

    ///////////////////////////////////////////////////////////////////

    wxString strDirName = ::wxFindFirstFile(strValidPath, wxFILE);
    wxString strFileExt;
    wxString strDesktopPath;
    while (!strDirName.IsEmpty())
    {
        wxFileName fileName(strDirName);
        strFileExt = fileName.GetExt();

        if (strFileExt.CmpNoCase( CSZ_EXCLUDING_FILE_EXT ) != 0)
        {// Excluding .lnk file(shortcut files)
            CategorizationFileInfo* pFileInfo = new CategorizationFileInfo(strDirName);

            // pFileInfo->m_strBaseDestPath = m_strDesktopPath;
            arrFileInfo.Add(pFileInfo);
        }

        // Next file
        strDirName = ::wxFindNextFile();
    }//while

}

void CategorizeMgr::Categorize()
{
    //
    int nCnt = m_arrCategorizationFileInfo.GetCount();
    if (nCnt < 0)
    {
        return;
    }

    //
    CategorizationFileInfo* pFileInfo = 0;
    wxString strTemp;
    for (int i=0; i< nCnt; i++)
    {
        //
        pFileInfo = m_arrCategorizationFileInfo.Item(i);

        if (pFileInfo)
        {
            strTemp = pFileInfo->GetDestFolderPath();

            if (!wxDirExists(strTemp))
            {
                wxMkdir(strTemp);
            }

            // Move file to dest dir
            if (pFileInfo->GetCurFullPath().CmpNoCase(pFileInfo->GetDestFullPath()) != 0 )
            {
                wxRenameFile(pFileInfo->GetCurFullPath(), pFileInfo->GetDestFullPath() );
            }

            pFileInfo->m_bProcessed = true;

        }
    }

    // Notify
    Notify();
}

/**
 * Preview categorizie files.
 */
void CategorizeMgr::Preview()
{
    // Clear
    int nCnt = m_arrStrSubFolder.GetCount();
    if (nCnt > 0)
    {
        m_arrStrSubFolder.Empty();
    }

    // Clear file info
    clearFileInfos();

    // Get sub folder path for categorize path
    m_arrStrSubFolder.Add(m_strDesktopPath);
    getSubFolder(m_strDesktopPath, m_arrStrSubFolder, false);

    nCnt = m_arrStrSubFolder.GetCount();
    if (0 == nCnt)
    {
        return;
    }

    for (int i=0; i<nCnt; i++)
    {
        // Get all file in folder
        getFolderAllFile(m_arrStrSubFolder[i], m_arrCategorizationFileInfo);
    }

    // For each rule
    int nCntRule = m_arrRule.GetCount();
    Rule* pRule = 0;
    CategorizationFileInfo* pFileInfo = 0;

    for (int j=0; j<nCntRule; j++)
    {
        pRule = m_arrRule[j];

        if (pRule)
        {

            int nCntFileInfo = m_arrCategorizationFileInfo.GetCount();
            if (0 == nCntFileInfo)
            {
                return;
            }

            for (int i=0; i<nCntFileInfo; i++)
            {
                pFileInfo = m_arrCategorizationFileInfo[i];

                pRule->Execute(pFileInfo);

                //

            }
        }

    }// END FOR RULES

    // Notify observer
    Notify();
}

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////

void CategorizeMgr::loadRuleInfo()
{
    if (!m_docWords.Load(CSZ_RULES_DATA_XML))
        return;

    // start processing the XML file
    m_pRoot = m_docWords.GetRoot();
    if (m_pRoot->GetName() != _T("rules"))
        return;

    wxXmlNode* pChild = m_pRoot->GetChildren();
    wxXmlNode* pChildChild = 0;
    while (pChild)
    {
        if (pChild->GetName() != _T("rule"))
            break;

        pChildChild = pChild->GetChildren();
        wxString strIndex, strType, strSel, strCondition, strDest;

        while (pChildChild)
        {
            if (pChildChild->GetName() == CSZ_RULE_TAG_NAMES[0])
            {// index
                strIndex = pChildChild->GetNodeContent();
            }

            if (pChildChild->GetName() == CSZ_RULE_TAG_NAMES[1])
            {// type
                strType = pChildChild->GetNodeContent();
            }

            if (pChildChild->GetName() == CSZ_RULE_TAG_NAMES[2])
            {// selected
                strSel = pChildChild->GetNodeContent();
            }

            if (pChildChild->GetName() == CSZ_RULE_TAG_NAMES[3])
            {// condition
                strCondition = pChildChild->GetNodeContent();
            }

            if (pChildChild->GetName() == CSZ_RULE_TAG_NAMES[4])
            {// dest
                strDest = pChildChild->GetNodeContent();
            }
            //
            pChildChild = pChildChild->GetNext();
        }

        unsigned long nIndex = 0;
        strIndex.ToULong(&nIndex);
        if (nIndex > ms_nCurMaxIndex)
            ms_nCurMaxIndex = nIndex;

        unsigned long nType = 0;
        strType.ToULong(&nType);

        unsigned long nSel = 0;
        strSel.ToULong(&nSel);

        if (nType == BasicRule::ms_nType)
        {
            BasicRule* pBasic = new BasicRule();

            pBasic->m_nIndex = 0; // Always 0
            pBasic->m_bSelected = nSel == 0 ? false : true;

            pBasic->m_strBaseDestPath = m_strDesktopPath; // Not strDest
            pBasic->SetCondition(strCondition);

            m_arrRule.Add(pBasic);
        }

        if (nType == ExtNameRule::ms_nType)
        {
            ExtNameRule* pRule1 = new ExtNameRule();

            pRule1->m_nIndex = nIndex;

            pRule1->m_bSelected = nSel == 0 ? false : true;

            pRule1->SetCondition( strCondition );
            pRule1->m_strBaseDestPath = strDest;  //___ZIP

            m_arrRule.Add(pRule1);
        }

        if (nType == NameIncludeRule::ms_nType)
        {
            NameIncludeRule* pRule = new NameIncludeRule();

            pRule->m_nIndex = nIndex;
            pRule->m_bSelected = nSel == 0 ? false : true;

            pRule->m_strInclude = strCondition;
            pRule->m_strBaseDestPath = strDest;  //___ZIP

            m_arrRule.Add(pRule);
        }

        //
        pChild = pChild->GetNext();
    }
}

void CategorizeMgr::saveRuleInfo()
{
    // Delete all current nodes
    wxXmlNode* pChild = m_pRoot->GetChildren();

    wxXmlNode* pChildTemp = 0;
    wxXmlNode* pChildChild = 0;
    wxXmlNode* pChildChildTemp = 0;
    while (pChild)
    {
        if (pChild->GetName() != _T("rule"))
            break;

        pChildTemp = pChild->GetNext();

        pChildChild = pChild->GetChildren();
        while (pChildChild)
        {
            pChildChildTemp = pChildChild->GetNext();

            pChild->RemoveChild(pChildChild);
            delete pChildChild;
            pChildChild = 0;
            //
            pChildChild = pChildChildTemp;
        }

        m_pRoot->RemoveChild(pChild);
        delete pChild;
        pChild = 0;

        //
        pChild = pChildTemp;
    }

    ///////////////////////////////////////////////////////////////////
    // Add nodes from m_arrRule array and save to xml file

    int nCnt = m_arrRule.GetCount();
    Rule* pRule = 0;
    wxXmlNode *pNodeRule;
    for (int i=0; i<nCnt; i++)
    {
        pRule = m_arrRule[i];

        pNodeRule = new wxXmlNode(m_pRoot, wxXML_ELEMENT_NODE, _T("rule"));
        // DestPath tag
        wxXmlNode* pNodeDestTag = new wxXmlNode(pNodeRule, wxXML_ELEMENT_NODE, CSZ_RULE_TAG_NAMES[4]);
        wxXmlNode* pNodeDestVal = new wxXmlNode(pNodeDestTag, wxXML_TEXT_NODE, _T(""), pRule->m_strBaseDestPath);
        // Condition tag
        wxXmlNode* pNodeConditionTag = new wxXmlNode(pNodeRule, wxXML_ELEMENT_NODE, CSZ_RULE_TAG_NAMES[3]);
        wxXmlNode* pNodeConditionVal = new wxXmlNode(pNodeConditionTag, wxXML_TEXT_NODE, _T(""), pRule->GetCondition());
        // Selected tag
        wxXmlNode* pNodeSelectedTag = new wxXmlNode(pNodeRule, wxXML_ELEMENT_NODE, CSZ_RULE_TAG_NAMES[2]);
        wxString strSel;
        strSel = pRule->m_bSelected == true ? _T('1') : _T('0');
        wxXmlNode* pNodeSelectedVal = new wxXmlNode(pNodeSelectedTag, wxXML_TEXT_NODE, _T(""), strSel);
        // Type tag
        wxXmlNode* pNodeTypeTag = new wxXmlNode(pNodeRule, wxXML_ELEMENT_NODE, CSZ_RULE_TAG_NAMES[1]);
        wxString strType;
        strType.Printf(_T("%d"), pRule->GetRuleType());
        wxXmlNode* pNodeTypeVal = new wxXmlNode(pNodeTypeTag, wxXML_TEXT_NODE, _T(""), strType);
        // Index tag
        wxXmlNode *pNodeIndexTag = new wxXmlNode(pNodeRule, wxXML_ELEMENT_NODE, CSZ_RULE_TAG_NAMES[0]);
        wxString strIndex;
        strIndex.Printf( _T("%d"), pRule->m_nIndex);
        wxXmlNode*  pNodeIndexVal = new wxXmlNode(pNodeIndexTag, wxXML_TEXT_NODE, _T(""), strIndex);

    }

    bool bRet = m_docWords.Save(CSZ_RULES_DATA_XML);
    if (bRet)
    {// TODO:
        // wxMessageBox(_("Save complete."));
    }
    else
    {// Error
        // wxMessageBox(wxT("Error!"));
    }
}

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////

void CategorizeMgr::AddRule(RuleInfo& info)
{
    // Cal index value
    ms_nCurMaxIndex++;
    info.m_nIndex = ms_nCurMaxIndex;

//    // Save info to xml
//    wxXmlNode *pNodeRule;
//    pNodeRule = new wxXmlNode(m_pRoot, wxXML_ELEMENT_NODE, _T("rule"));
//
//    // DestPath tag
//    wxXmlNode* pNodeDestTag = new wxXmlNode(pNodeRule, wxXML_ELEMENT_NODE, CSZ_RULE_TAG_NAMES[4]);
//    wxXmlNode* pNodeDestVal = new wxXmlNode(pNodeDestTag, wxXML_TEXT_NODE, _T(""), info.m_strDestPath);
//
//    // Condition tag
//    wxXmlNode* pNodeConditionTag = new wxXmlNode(pNodeRule, wxXML_ELEMENT_NODE, CSZ_RULE_TAG_NAMES[3]);
//    wxXmlNode* pNodeConditionVal = new wxXmlNode(pNodeConditionTag, wxXML_TEXT_NODE, _T(""), info.m_strCondition);
//
//    // Selected tag
//    wxXmlNode* pNodeSelectedTag = new wxXmlNode(pNodeRule, wxXML_ELEMENT_NODE, CSZ_RULE_TAG_NAMES[2]);
//    wxString strSel;
//    strSel = info.m_bSelected == true ? _T('1') : _T('0');
//    wxXmlNode* pNodeSelectedVal = new wxXmlNode(pNodeSelectedTag, wxXML_TEXT_NODE, _T(""), strSel);
//
//    // Type tag
//    wxXmlNode* pNodeTypeTag = new wxXmlNode(pNodeRule, wxXML_ELEMENT_NODE, CSZ_RULE_TAG_NAMES[1]);
//    wxString strType;
//    strType.Printf(_T("%d"), info.m_nType);
//    wxXmlNode* pNodeTypeVal = new wxXmlNode(pNodeTypeTag, wxXML_TEXT_NODE, _T(""), strType);
//
//    // Index tag
//    wxXmlNode *pNodeIndexTag = new wxXmlNode(pNodeRule, wxXML_ELEMENT_NODE, CSZ_RULE_TAG_NAMES[0]);
//    wxString strIndex;
//    strIndex.Printf( _T("%d"), info.m_nIndex);
//    wxXmlNode*  pNodeIndexVal = new wxXmlNode(pNodeIndexTag, wxXML_TEXT_NODE, _T(""), strIndex);



    //
    // New rule object
    //

    // No Basic Rule will be add, it is always load
//    if (info.m_nType == BasicRule::ms_nType)
//    {
//        BasicRule* pBasicRule = new BasicRule();
//        pBasicRule->m_nIndex = info.m_nIndex;
//        pBasicRule->m_bSelected = info.m_bSelected;
//        pBasicRule->m_strBaseDestPath = info.m_strDestPath;
//
//        m_arrRule.Add(pBasicRule);
//    }

    if (info.m_nType == ExtNameRule::ms_nType)
    {
        ExtNameRule* pRule1 = new ExtNameRule();
        pRule1->m_nIndex = info.m_nIndex;
        pRule1->m_bSelected = info.m_bSelected;
        pRule1->SetCondition(info.m_strCondition);
        pRule1->m_strBaseDestPath = info.m_strDestPath;

        m_arrRule.Add(pRule1);
    }

    if (info.m_nType == NameIncludeRule::ms_nType)
    {
        NameIncludeRule* pRule = new NameIncludeRule();
        pRule->m_nIndex = info.m_nIndex;
        pRule->m_bSelected = info.m_bSelected;
        pRule->SetCondition(info.m_strCondition);
        pRule->m_strBaseDestPath = info.m_strDestPath;

        m_arrRule.Add(pRule);
    }

    // Save to xml file
    saveRuleInfo();
}

void CategorizeMgr::DeleteRule(int nIndex)
{
    Rule* pRule = m_arrRule[nIndex];
    if (pRule)
    {
        delete pRule;
        pRule = 0;
    }
    m_arrRule.RemoveAt(nIndex);

	// Save to xml file
	saveRuleInfo();

}

///////////////////////////////////////////////////////////////////////
// observer pattern method
///////////////////////////////////////////////////////////////////////

void CategorizeMgr::AttachObserver( CategorizationObserver* pObserver )
{
    if (!m_pObserver)
        m_pObserver	= pObserver;
}

void CategorizeMgr::Notify()
{
    m_pObserver->UpdateCategorizationCtrls();
}
