/**
 * @file CountingManager.cpp
 * @brief CountingManager.cpp: implementation of the CountingManager class.
 * @author Boom( boomworks@gmail.com )
 * @author Copyright(C) 2004-2005 boomworks.org , All right reserved.
 * @date 2005-11-23
 * $Revision: $
 */

#include <wx/dir.h>
#include <wx/hashmap.h>

#include "version.h"
#include "CountingManager.h"

/* Include ounter header files */
#include "TxtCounter.h"
#include "CppCounter.h"
#include "PasCounter.h"
#include "BasCounter.h"
#include "PhpCounter.h"
#include "JspCounter.h"
#include "AspxCounter.h"


#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
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

    wxMBConv *convMem = NULL, *convFile;

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

/* Source types number */
const int N_COLUMN_NUM = 14;

/* Source type */
const wxChar* CSZ_COLUMN_NAMES[N_COLUMN_NUM] =
{
    _("File"),              // 0
    _("Type"),              // 1
    _("Folder"),            // 2
    _("Lines"),             // 3
    _("Code lines"),        // 4
    _("Comment lines"),     // 5
    _("Blank lines"),       // 6
    _("Size"),              // 7
    _("Man-Day"),			// 8
    _("Cost"),				// 9
    _("UT Cases"),			// 10
    _("UT Defects"),		// 11
    _("IT Cases"),			// 12
    _("IT Defects")			// 13
};

const wxString CSZ_CSV_HEADER_FORMAT = _T( "%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s\n" );

/* Counter rule data file */
const wxString CSZ_RULES_DATA_XML = _T("rules.xml");

//////////////////////////////////////////////////////////////////////

CountingManager::CountingManager() :
        m_pObserver( 0 ),
        m_countingStatus( NManagerStatusNormal ),
        m_pRoot(0)
{}

CountingManager::~CountingManager()
{
    //
    // Save rule info to xml file
    //
    saveRules();

    //
    // Clear counter objs
    //
    MapStrToCounter::iterator it;
    Counter* pCounter = 0;
    for ( it = m_mapStrToCounter.begin(); it != m_mapStrToCounter.end(); ++it )
    {
        pCounter = it->second;
        delete pCounter;
        pCounter = 0;
    }
    //
    m_mapStrToCounter.clear();

    //
    // Clear CounterRule map
    //
    MapStrToCounterRule::iterator itRule;
    CounterRule* pRule = 0;
    for ( itRule = m_mapCounterRule.begin(); itRule != m_mapCounterRule.end(); ++itRule )
    {
        pRule = itRule->second;
        delete pRule ;
        pRule = 0;
    }
    //
    m_mapCounterRule.clear();

    //
    // Clear FileExtension map
    //
    MapStrToFileExtension::iterator itExt;
    FileExtension* pExt = 0;
    for ( itExt = m_mapFileExtension.begin(); itExt != m_mapFileExtension.end(); ++itExt )
    {
        pExt = itExt->second;
        delete pExt ;
        pExt = 0;
    }
    //
    m_mapFileExtension.clear();
}

void CountingManager::Init()
{
    //
    loadRules();
}

void CountingManager::loadRules()
{
    if (!m_docRules.Load(CSZ_RULES_DATA_XML))
        return;

    // start processing the XML file
    m_pRoot = m_docRules.GetRoot();
    if (m_pRoot->GetName() != _T("rules"))
        return;

    wxXmlNode* pChild = m_pRoot->GetChildren();
    wxXmlNode* pChildChild 			= 0;
    wxXmlNode* pChildChildChild 	= 0;
    CounterRule* pRule 				= 0;
    FileExtension* pFileExt 		= 0;
    while (pChild)
    {
        if (pChild->GetName() != _T("rule"))
            break;

        pChildChild = pChild->GetChildren();
        wxString strType, strDesc;
        wxString strSlgLnComm, strMltLnCommBegin, strMltLnCommEnd;
        wxString strExtName, strExtDesc, strExtRuleType;
        while (pChildChild)
        {
            if (pChildChild->GetName() == _T("type"))
            {// Type
                strType = pChildChild->GetNodeContent();
            }

            if (pChildChild->GetName() == _T("desc"))
            {// Desc
                strDesc = pChildChild->GetNodeContent();
            }

            if (pChildChild->GetName() == _T("single-line-comment"))
            {// Single line comment
				strSlgLnComm = pChildChild->GetNodeContent();
            }

            if (pChildChild->GetName() == _T("multi-line-comment-begin"))
            {// Single line comment
				strMltLnCommBegin = pChildChild->GetNodeContent();
            }

            if (pChildChild->GetName() == _T("multi-line-comment-end"))
            {// Single line comment
				strMltLnCommEnd = pChildChild->GetNodeContent();
            }

            if (pChildChild->GetName() == _T("extension"))
            {// Extensions
                pChildChildChild = pChildChild->GetChildren();

                while (pChildChildChild)
                {
                    if (pChildChildChild->GetName() == _T("name"))
                    {
                        strExtName = pChildChildChild->GetNodeContent();
                    }

                    if (pChildChildChild->GetName() == _T("desc"))
                    {
                        strExtDesc = pChildChildChild->GetNodeContent();
                    }

                    if (pChildChildChild->GetName() == _T("ruletype"))
                    {
                        strExtRuleType = pChildChildChild->GetNodeContent();
                    }

                    // Next
                    pChildChildChild = pChildChildChild->GetNext();
                }// End while

                // New fileExtension pointer
                pFileExt = new FileExtension(strExtName, strExtRuleType, strExtDesc);
                m_mapFileExtension[strExtName] = pFileExt;
            }

            //
            pChildChild = pChildChild->GetNext();
        }

		//
        // New rule point and add to map
        //
		pRule = new CounterRule();
		// Rule propertise
        pRule->m_strType = strType;
        pRule->m_strDesc = strDesc;
        // Comment
        pRule->m_strSlgLnComm = strSlgLnComm;
        pRule->m_strMltLnCommBegin = strMltLnCommBegin;
        pRule->m_strMltLnCommEnd = strMltLnCommEnd;
        // Add to map
        m_mapCounterRule[strType] = pRule;

        // Next
        pChild = pChild->GetNext();
    }
}

void CountingManager::saveRules()
{
    //
    // Delete all current nodes
    //
    wxXmlNode* pChild = m_pRoot->GetChildren();

    wxXmlNode* pChildTemp 			= 0;
    wxXmlNode* pChildChild 			= 0;
    wxXmlNode* pChildChildTemp 		= 0;
    wxXmlNode* pChildChildChild		= 0;
    wxXmlNode* pChildChildChildTemp	= 0;

    while (pChild)
    {
        // <rule>
        if (pChild->GetName() != _T("rule"))
            break;

        pChildTemp = pChild->GetNext();
        pChildChild = pChild->GetChildren();
        while (pChildChild)
        {
            // <index>
            // <type>
            // <desc>
            // <extension>
            // <single-line-comment>
            // <multi-line-comment-begin>
            // <multi-line-comment-end>
            pChildChildTemp = pChildChild->GetNext();
            pChildChildChild = pChildChild->GetChildren();
            while (pChildChildChild)
            {
                if (pChildChildChild->GetName() != _T("extension"))
                    break;

                // <name>
                // <desc>
                // <ruletype>
                pChildChildChildTemp = pChildChildChild->GetNext();

                pChildChild->RemoveChild(pChildChildChild);
                delete pChildChildChild;

                pChildChildChild = pChildChildChildTemp;
            }

            // Delete childchild
            pChild->RemoveChild(pChildChild);
            delete pChildChild;
            pChildChild = 0;

            // Next
            pChildChild = pChildChildTemp;
        }

        // Delete child
        m_pRoot->RemoveChild(pChild);
        delete pChild;
        pChild = 0;

        // Next
        pChild = pChildTemp;
    }

    //
    // Add nodes from CounterRuleMap and FileExtensionMap and save to xml file
    //
    wxXmlNode* pNRuleTag = 0;

    MapStrToCounterRule::iterator it;
    CounterRule* pRule = 0;
    MapStrToFileExtension::iterator ite;
    FileExtension* pExt = 0;
    wxString strCounterType;
    for (it = m_mapCounterRule.begin(); it != m_mapCounterRule.end(); ++it)
    {
        pRule = it->second;
        strCounterType = pRule->m_strType;

        // <rule>
        pNRuleTag = new wxXmlNode(m_pRoot, wxXML_ELEMENT_NODE, _T("rule"));
        // <type>
        wxXmlNode* pNTypeTag = new wxXmlNode(pNRuleTag, wxXML_ELEMENT_NODE, _T("type"));
        wxXmlNode* pNTypeVal = new wxXmlNode(pNTypeTag, wxXML_TEXT_NODE, _T(""), strCounterType);
        // <desc>
        wxXmlNode* pNDescTag = new wxXmlNode(pNRuleTag, wxXML_ELEMENT_NODE, _T("desc"));
        wxXmlNode* pNDescVal = new wxXmlNode(pNDescTag, wxXML_TEXT_NODE, _T(""), pRule->m_strDesc);
        // <single-line-comment>
        wxXmlNode* pNSlgLnCommTag = new wxXmlNode(pNRuleTag, wxXML_ELEMENT_NODE, _T("single-line-comment"));
        wxXmlNode* pNSlgLnCommVal = new wxXmlNode(pNSlgLnCommTag, wxXML_TEXT_NODE, _T(""), pRule->m_strSlgLnComm);
        // <multi-line-comment-begin>
        wxXmlNode* pNMltLnBeginTag = new wxXmlNode(pNRuleTag, wxXML_ELEMENT_NODE, _T("multi-line-comment-begin"));
        wxXmlNode* pNMltLnBeginVal = new wxXmlNode(pNMltLnBeginTag, wxXML_TEXT_NODE, _T(""), pRule->m_strMltLnCommBegin);
		// <multi-line-comment-end>
        wxXmlNode* pNMltLnEndTag = new wxXmlNode(pNRuleTag, wxXML_ELEMENT_NODE, _T("multi-line-comment-end"));
        wxXmlNode* pNMltLnEndVal = new wxXmlNode(pNMltLnEndTag, wxXML_TEXT_NODE, _T(""), pRule->m_strMltLnCommEnd);

        //
        // Create extension tags
        //
        for (ite = m_mapFileExtension.begin(); ite != m_mapFileExtension.end(); ++ite)
        {
            pExt = ite->second;
            if (strCounterType.CmpNoCase(pExt->m_strCounterType) == 0)
            {
                // <extension>
                wxXmlNode* pNExtTag = new wxXmlNode(pNRuleTag, wxXML_ELEMENT_NODE, _T("extension"));
                // <name>
                wxXmlNode* pNNameTag = new wxXmlNode(pNExtTag, wxXML_ELEMENT_NODE, _T("name"));
                wxXmlNode* pNNameVal = new wxXmlNode(pNNameTag, wxXML_TEXT_NODE, _T(""), pExt->m_strName);
                // <desc>
                wxXmlNode* pNExtDescTag = new wxXmlNode(pNExtTag, wxXML_ELEMENT_NODE, _T("desc"));
                wxXmlNode* pNExtDescVal = new wxXmlNode(pNExtDescTag, wxXML_TEXT_NODE, _T(""), pExt->m_strDesc);
                // <ruletype>
                wxXmlNode* pNExtRuleTypeTag = new wxXmlNode(pNExtTag, wxXML_ELEMENT_NODE, _T("ruletype"));
                wxXmlNode* pNExtRuleTypeVal = new wxXmlNode(pNExtRuleTypeTag, wxXML_TEXT_NODE, _T(""), pExt->m_strCounterType);
            }
        }
    }

    //
    // Save to file.
    //
    bool bRet = m_docRules.Save(CSZ_RULES_DATA_XML);
}

FileExtension* CountingManager::FindFileExtension(wxString& strFileExt)
{
    FileExtension* pFileExt = 0;
    MapStrToFileExtension::iterator it;

    it = m_mapFileExtension.find( strFileExt );
    if (it != m_mapFileExtension.end())
    { // Find instance in map
        pFileExt = it->second;
    }

    return pFileExt;
}

void CountingManager::SetCountingParam( CountingParam* pParam )
{
    m_countingParam.m_arrSrcFolderPath		    = pParam->m_arrSrcFolderPath;
    m_countingParam.m_arrSrcType		        = pParam->m_arrSrcType;

    m_countingParam.m_bRecursiveCounting		= pParam->m_bRecursiveCounting;

    m_countingParam.m_settingParam.m_nCountingMethodType	= pParam->m_settingParam.m_nCountingMethodType;
}

/**
 * Add support source code type
 */
Counter* CountingManager::CreateCounter(wxString& strCounterType)
{
    Counter* pCounter = 0;

    MapStrToCounter::iterator it;
    it = m_mapStrToCounter.find(strCounterType);
    if (it != m_mapStrToCounter.end())
    {// Find already created instance in the pCount map
        pCounter = it->second;
        return pCounter;
    }
    else
    {// Not found in map, create
        if (0 == strCounterType.CmpNoCase(BasicCounter::ms_strType))
        {// BasCounter
            pCounter = BasicCounter::GetInstance();
        }

        if (0 == strCounterType.CmpNoCase(CppCounter::ms_strType))
        {// CppCounter
            pCounter = CppCounter::GetInstance();
        }

        if (0 == strCounterType.CmpNoCase(PascalCounter::ms_strType))
        {// PascalCounter
            pCounter = new PascalCounter;
        }

        if (0 == strCounterType.CmpNoCase(PhpCounter::ms_strType))
        {// PhpCounter
            pCounter = new PhpCounter;
        }

        if (0 == strCounterType.CmpNoCase(AspxCounter::ms_strType))
        {// AspxCounter
            pCounter = new AspxCounter;
        }

        if (0 == strCounterType.CmpNoCase(JspCounter::ms_strType))
        {// JspCounter
            pCounter = new JspCounter;
        }

        if (0 == strCounterType.CmpNoCase(TxtCounter::ms_strType))
        {// TxtCounter
            pCounter = new TxtCounter;
        }

        // Store to map
        m_mapStrToCounter[strCounterType] = pCounter;
    }

    //
    return pCounter;
}

CountingInfo* CountingManager::GetCountingInfo( void )
{
    return &m_countingInfo;
}

void CountingManager::Clear()
{
    // Clear counting file info objs
    m_countingInfo.Clear();

    //	m_bStopCounting = FALSE;
    m_countingStatus = NManagerStatusNormal;
}

void CountingManager::StopCounting()
{
    //	m_bStopCounting = TRUE;
    m_countingStatus = NManagerStatusStop;
}

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////

void CountingManager::addSubSrcFolder()
{
    wxArrayString arrSubSrcFolderPath;
    wxArrayString arrRecursiveFolder;

    int nFolderCount = m_countingParam.m_arrSrcFolderPath.GetCount();

    for (int i=0; i<nFolderCount; i++)
    {
        ///////////////////////////////////////////////////////////////
        // Prepare counting path
        ///////////////////////////////////////////////////////////////
        wxString strTempPath(m_countingParam.m_arrSrcFolderPath.Item(i));
        wxString strValidPath;

        // add *
        if ( strTempPath[strTempPath.Length() - 1] == '\\' )
        {
            strValidPath = strTempPath + _T( "*" );
        }
        else
        {
            strValidPath = strTempPath + _T( "\\*" );
        }

        ///////////////////////////////////////////////////////////////
        // Enum dirs
        ///////////////////////////////////////////////////////////////

        wxString fname;
        wxString strTempFolder, strTempDir;
        int nRecursiveFolderCount = 0;

        do
        {
            ///////////////////////////////////////////////////////
            ///////////////////////////////////////////////////////
            ///////////////////////////////////////////////////////
            if ( m_countingStatus == NManagerStatusStop )
            {
                break;
            }
            ///////////////////////////////////////////////////////
            MSG	msg;
            if ( ::PeekMessage( &msg, NULL, 0, 0, PM_REMOVE ))
            {
                ::DispatchMessage( &msg );
            }
            ///////////////////////////////////////////////////////
            ///////////////////////////////////////////////////////
            ///////////////////////////////////////////////////////

            // Get first dir
            fname = ::wxFindFirstFile(strValidPath, wxDIR);
            while (!fname.IsEmpty())
            {
                ///////////////////////////////////////////////////////
                ///////////////////////////////////////////////////////
                ///////////////////////////////////////////////////////
                if ( m_countingStatus == NManagerStatusStop )
                {
                    break;
                }
                ///////////////////////////////////////////////////////

                if ( ::PeekMessage( &msg, NULL, 0, 0, PM_REMOVE ))
                {
                    ::DispatchMessage( &msg );
                }
                ///////////////////////////////////////////////////////
                ///////////////////////////////////////////////////////
                ///////////////////////////////////////////////////////

                arrSubSrcFolderPath.Add(fname);
                arrRecursiveFolder.Add(fname);

                fname = wxFindNextFile();
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
        while (m_countingStatus == NManagerStatusRunning);


        ///////////////////////////////////////////////////////////////
        ///////////////////////////////////////////////////////////////
        ///////////////////////////////////////////////////////////////
    }//for

    ///////////////////////////////////////////////////////////////////
    // Add sub folders to counting folders
    ///////////////////////////////////////////////////////////////////
    int nSubFolderCount = arrSubSrcFolderPath.GetCount();
    for (int i=0; i<nSubFolderCount; i++)
    {
        m_countingParam.m_arrSrcFolderPath.Add(arrSubSrcFolderPath.Item(i));
    }

    m_countingParam.m_arrSrcFolderPath.Sort();
}

void CountingManager::StartCounting()
{

    ///////////////////////////////////////////////////////////////////
    // Add sub folder to arrSrcFolderPath, When recursive counting
    if (m_countingParam.m_bRecursiveCounting)
    {
        addSubSrcFolder();
    }

    ///////////////////////////////////////////////////////////////////

    int nFolderCount = m_countingParam.m_arrSrcFolderPath.GetCount();
    Counter* pCounter = 0;
    CountingFileInfo* pCountingFileInfoCur = 0;

    for (int i = 0; i < nFolderCount; i++)
    {
        ///////////////////////////////////////////////////////////

        if ( m_countingStatus == NManagerStatusStop )
        {
            break;
        }
        ///////////////////////////////////////////////////////////

        MSG	msg;
        if ( ::PeekMessage( &msg, NULL, 0, 0, PM_REMOVE ))
        {
            ::DispatchMessage( &msg );
        }

        ///////////////////////////////////////////////////////////
        ///////////////////////////////////////////////////////////

        ///////////////////////////////////////////////////////////////
        // Prepare counting path
        wxString strTempPath(m_countingParam.m_arrSrcFolderPath.Item(i));
        wxString strValidPath;
        wxString strFileExtName;

        // add *
        if ( strTempPath[strTempPath.Length() - 1] == '\\' )
        {
            strValidPath = strTempPath + _T( "*" );
        }
        else
        {
            strValidPath = strTempPath + _T( "\\*" );
        }

        ///////////////////////////////////////////////////////////////
        // Enum files
        wxString fname = ::wxFindFirstFile(strValidPath, wxFILE);
        if (fname.IsEmpty())
        {
            continue;
        }

        while (!fname.IsEmpty())
        {
            //CWaitCursor wait;

            ///////////////////////////////////////////////////////////

            if ( m_countingStatus == NManagerStatusStop )
            {
                break;
            }

            ///////////////////////////////////////////////////////////

            if ( ::PeekMessage( &msg, NULL, 0, 0, PM_REMOVE ))
            {
                ::DispatchMessage( &msg );
            }

            ///////////////////////////////////////////////////////////
            // Collect counting info
            getFileExtName(fname, strFileExtName);

            // Check whether counting strFileExtName type source code file
            wxString strCounterType;
            if (isCountingFile(strFileExtName, strCounterType))
            {
                pCountingFileInfoCur = new CountingFileInfo();

                pCountingFileInfoCur->m_strFileExtName = strFileExtName;
                pCountingFileInfoCur->m_strFileFullPath = fname;

                getFileNameAndDirFromFullPath(fname,
                                              pCountingFileInfoCur->m_strFileName,
                                              pCountingFileInfoCur->m_strFolderPath);

                // Create pCounter
                pCounter = CreateCounter(strCounterType);
                assert(pCounter);

                // Counting start...
                pCounter->Counting( pCountingFileInfoCur, m_countingParam);

                ///////////////////////////////////////////////////////
                m_countingInfo.AddCountingFileInfo(pCountingFileInfoCur);

                // total statistic infomation
                m_countingInfo.m_nTotalFile					+= 1;
                m_countingInfo.m_nTotalSize					+= pCountingFileInfoCur->m_nSize / 1000; // kb
                m_countingInfo.m_nTotalStatement			+= pCountingFileInfoCur->m_nTotalStatement;
                m_countingInfo.m_nTotalCodeStatement		+= pCountingFileInfoCur->m_nCodeStatement;
                m_countingInfo.m_nTotalCommentStatement		+= pCountingFileInfoCur->m_nCommentStatement;
                m_countingInfo.m_nTotalBlankStatement	    += pCountingFileInfoCur->m_nBlankStatement;

                m_countingInfo.m_fTotalManMonth				+= (float)pCountingFileInfoCur->m_nManDay / (float)m_countingParam.m_settingParam.m_nDaysPerMM;
                m_countingInfo.m_fTotalCost					+= (float)pCountingFileInfoCur->m_nCost;

                // Boom: add UT and IT counting information
                m_countingInfo.m_fTotalUtCases				+= pCountingFileInfoCur->m_fUtCase;
                m_countingInfo.m_fTotalUtDefects			+= pCountingFileInfoCur->m_fUtDefect;
                m_countingInfo.m_fTotalItCases				+= pCountingFileInfoCur->m_fItCase;
                m_countingInfo.m_fTotalItDefects			+= pCountingFileInfoCur->m_fItDefect;
                ///////////////////////////////////////////////////////

                // Notify UI to update counting info
                Notify();
            }// if
            // Next file
            fname =::wxFindNextFile();
        }// While
    }

    ///////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////

    if ( m_countingStatus == NManagerStatusRunning )
    {
        m_countingStatus = NManagerStatusComplete;
    }
    else if ( m_countingStatus == NManagerStatusStop )
    { // do nothing
    }
}

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////

bool CountingManager::isCountingFile(wxString& strFileExtName, wxString& strCounterType)
{
    bool bRet = false;

    MapStrToFileExtension::iterator it;
    it = m_mapFileExtension.find(strFileExtName);
    FileExtension* pExt = 0;
    if (it != m_mapFileExtension.end())
    {
        pExt = it->second;
        if (pExt->m_bSel)
        {
            strCounterType = pExt->m_strCounterType;
            bRet = true;
        }
    }

//    int nItemCount = m_countingParam.m_arrSrcType.GetCount();
//    wxString strTemp;
//    for (int i=0; i<nItemCount; i++)
//    {
//        strTemp = m_countingParam.m_arrSrcType.Item(i);
//        if (0 == strTemp.CmpNoCase(strFileExtName))
//        {
//            bRet = true;
//            break;
//        }
//    }

    return bRet;
}

void CountingManager::getFileExtName( wxString& strFileName, wxString& strExt )
{
    strExt.Empty();

    int nDotPos = strFileName.Find( _T( '.' ), true);
    if ( nDotPos != wxNOT_FOUND )
    {
        strExt = strFileName.Right( strFileName.Length() - nDotPos );
    }
}

void CountingManager::getFileNameAndDirFromFullPath( wxString& strFullPath, wxString& strFileName, wxString& strDir )
{
    //
    strFileName.Empty();
    strDir.Empty();

    if ( strFullPath.IsEmpty())
    {
        return;
    }

    //
    int nLastSlashPos = strFullPath.Find( _T( '\\' ), true);
    if ( nLastSlashPos != wxNOT_FOUND )
    {
        strDir			= strFullPath.Left( nLastSlashPos );
        strFileName 	= strFullPath.Right( strFullPath.Length() - nLastSlashPos - 1 );
    }

}

///////////////////////////////////////////////////////////////////////
// observer pattern method
///////////////////////////////////////////////////////////////////////

void CountingManager::AttachObserver( CCounterObserver* pObserver )
{
    m_pObserver	= pObserver;
}

void CountingManager::Notify()
{
    m_pObserver->UpdateCountingInfoCtrls();
}

///////////////////////////////////////////////////////////////////////
// Save counting result to csv file.
///////////////////////////////////////////////////////////////////////

/**
 * Save counting result to CSV file.
 */
void CountingManager::SaveCountingResultToCSV( wxString filename )
{
    wxTextFile file;
    file.Create( filename );
    wxString strText;

    wxString strVersion(AutoVersion::FULLVERSION_STRING, wxConvUTF8);
    strText = _T("# *** Generated by BoomWorks.Org(C) SourceCounter ") + strVersion + _T(" *** ");

    file.AddLine(strText);
    file.AddLine(_T("# *** Author: boomworks@hotmail.com *** "));
    file.AddLine(_T( "\n" ));

    // Header
    strText.Printf( CSZ_CSV_HEADER_FORMAT, CSZ_COLUMN_NAMES[2], CSZ_COLUMN_NAMES[0], CSZ_COLUMN_NAMES[1],
                    CSZ_COLUMN_NAMES[3], CSZ_COLUMN_NAMES[4], CSZ_COLUMN_NAMES[5], CSZ_COLUMN_NAMES[6],
                    CSZ_COLUMN_NAMES[7], CSZ_COLUMN_NAMES[8], CSZ_COLUMN_NAMES[9], CSZ_COLUMN_NAMES[10],
                    CSZ_COLUMN_NAMES[11], CSZ_COLUMN_NAMES[12], CSZ_COLUMN_NAMES[13], CSZ_COLUMN_NAMES[14]
                  );
    file.AddLine( strText );

    ///////////////////////////////////////////////////////////////////
    ArrayCountingFileInfo* pArrFileInfo = m_countingInfo.GetCountingFileInfoArr();

    int nItemCount = pArrFileInfo->GetCount();
    CountingFileInfo* pFileInfo = 0;
    wxString strTemp;
    for ( int i=0; i<nItemCount; i++ )
    {
//        strText.Printf( CSZ_CSV_FORMAT_STR,
//                        m_lstResult->GetItemText( i), m_lstResult->GetItemText( i ),
//                        m_lstResult->GetItemText( i ), m_lstResult->GetItemText( i),
//                        m_lstResult->GetItemText( i ), m_lstResult->GetItemText( i ),
//                        m_lstResult->GetItemText( i )
//                      );
        pFileInfo = pArrFileInfo->Item(i);
        strText.Empty();
        strText = pFileInfo->m_strFolderPath +_T(",")+  pFileInfo->m_strFileName +_T(",")+ pFileInfo->m_strFileExtName;

        strTemp.Empty();
        strTemp.Printf(_T(",%d,%d,%d,%d,%d,%2.2f,%2.2f,%2.2f,%2.2f,%2.2f,%2.2f"), pFileInfo->m_nTotalStatement, pFileInfo->m_nCodeStatement,
                       pFileInfo->m_nCommentStatement, pFileInfo->m_nBlankStatement, pFileInfo->m_nSize,
                       pFileInfo->m_nManDay, pFileInfo->m_nCost,
                       pFileInfo->m_fUtCase, pFileInfo->m_fUtDefect, pFileInfo->m_fItCase, pFileInfo->m_fItDefect);

//        strText.Printf( CSZ_CSV_FORMAT_STR,
//                        pFileInfo->m_strFileName, pFileInfo->m_strFileExtName, pFileInfo->m_strFolderPath,
//                        pFileInfo->m_nTotalStatement, pFileInfo->m_nCodeStatement, pFileInfo->m_nCommentStatement,
//                        pFileInfo->m_nBlankStatement
//                      );

        file.AddLine( strText+strTemp );
    }

    file.AddLine( _T( "\n" ));
    file.AddLine( _("# *** Total ***"));

    wxString strTotal;

    strTotal.Printf( _T( "# %s,%d" ), CSZ_COLUMN_NAMES[0], m_countingInfo.m_nTotalFile);
    file.AddLine( strTotal );

    strTotal.Printf( _T( "# %s,%d" ), CSZ_COLUMN_NAMES[7], m_countingInfo.m_nTotalSize);
    file.AddLine( strTotal );

    strTotal.Printf( _T( "# %s,%d,100%%" ), CSZ_COLUMN_NAMES[3], m_countingInfo.m_nTotalStatement );
    file.AddLine( strTotal );

    strTotal.Printf( _T( "# %s,%d,%2.1f%%" ), CSZ_COLUMN_NAMES[4], m_countingInfo.m_nTotalCodeStatement, 100. * m_countingInfo.m_nTotalCodeStatement / m_countingInfo.m_nTotalStatement );
    file.AddLine( strTotal );

    strTotal.Printf( _T( "# %s,%d,%2.1f%%" ), CSZ_COLUMN_NAMES[5], m_countingInfo.m_nTotalCommentStatement, 100. * m_countingInfo.m_nTotalCommentStatement / m_countingInfo.m_nTotalStatement );
    file.AddLine( strTotal );

    strTotal.Printf( _T( "# %s,%d,%2.1f%%" ), CSZ_COLUMN_NAMES[6], m_countingInfo.m_nTotalBlankStatement, 100. * m_countingInfo.m_nTotalBlankStatement / m_countingInfo.m_nTotalStatement  );
    file.AddLine( strTotal );

    strTotal.Printf(_T("# %s, %2.2f"), CSZ_COLUMN_NAMES[8], m_countingInfo.m_fTotalManMonth);
    file.AddLine(strTotal);

    strTotal.Printf(_T("# %s, %2.2f"), CSZ_COLUMN_NAMES[9], m_countingInfo.m_fTotalCost);
    file.AddLine(strTotal);

    // Boom: add UT and IT counint info on 2009-3-3
    strTotal.Printf(_T("# %s, %2.2f"), CSZ_COLUMN_NAMES[10], m_countingInfo.m_fTotalUtCases);
    file.AddLine(strTotal);
    strTotal.Printf(_T("# %s, %2.2f"), CSZ_COLUMN_NAMES[11], m_countingInfo.m_fTotalUtDefects);
    file.AddLine(strTotal);
    strTotal.Printf(_T("# %s, %2.2f"), CSZ_COLUMN_NAMES[12], m_countingInfo.m_fTotalItCases);
    file.AddLine(strTotal);
    strTotal.Printf(_T("# %s, %2.2f"), CSZ_COLUMN_NAMES[13], m_countingInfo.m_fTotalItDefects);
    file.AddLine(strTotal);

    // Save and close
    file.Write();
}
