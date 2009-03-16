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

//////////////////////////////////////////////////////////////////////

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

//////////////////////////////////////////////////////////////////////

CountingManager::CountingManager() :
        m_pObserver( 0 ),
        m_countingStatus( NManagerStatusNormal )
{}

CountingManager::~CountingManager()
{
    // Clear counter objs
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
Counter* CountingManager::CreateCounter(wxString strFileExtName)
{
    Counter* pCounter = 0;
    MapStrToCounter::iterator it;

    // TxtConter
    if (0 == strFileExtName.CmpNoCase(_T(".pas")))
    {
        it = m_mapStrToCounter.find(_T(".pas"));
        if (it != m_mapStrToCounter.end())
        { // Find instance in the pCount map
            pCounter = it->second;
        }
        else
        {
            // PasCounter
            pCounter = new PascalCounter;
            m_mapStrToCounter[_T(".pas")] = pCounter;
        }
    }
    else if (0 == strFileExtName.CmpNoCase(_T(".cpp")) || 0 == strFileExtName.CmpNoCase(_T(".cxx"))
			 || 0 == strFileExtName.CmpNoCase(_T(".cc") ) || 0 == strFileExtName.CmpNoCase(_T(".c"))
			 || 0 == strFileExtName.CmpNoCase(_T(".hhp") ) || 0 == strFileExtName.CmpNoCase(_T(".hh"))
             || 0 == strFileExtName.CmpNoCase(_T(".h") ) || 0 == strFileExtName.CmpNoCase(_T(".java"))
             || 0 == strFileExtName.CmpNoCase(_T(".tlh")) || 0 == strFileExtName.CmpNoCase(_T(".tli"))
             || 0 == strFileExtName.CmpNoCase(_T(".cs")) )
    {
        it = m_mapStrToCounter.find(_T(".cpp"));
        if (it != m_mapStrToCounter.end())
        { // Find instance in the pCount map
            pCounter = it->second;
        }
        else
        {
            // CppCounter
            pCounter = CppCounter::GetInstance();
            m_mapStrToCounter[_T(".cpp")] = pCounter;
        }
    }
    else if (0 == strFileExtName.CmpNoCase(_T(".vb")) || 0 == strFileExtName.CmpNoCase(_T(".bas"))
             || 0 == strFileExtName.CmpNoCase(_T(".ctl")) || 0 == strFileExtName.CmpNoCase(_T(".cls"))
             || 0 == strFileExtName.CmpNoCase(_T(".frm")) )
    {
        //
        it = m_mapStrToCounter.find(_T(".vb"));
        if (it != m_mapStrToCounter.end())
        { // Find instance in the pCount map
            pCounter = it->second;
        }
        else
        {
            // BasicCounter
            pCounter = BasicCounter::GetInstance();
            m_mapStrToCounter[_T(".vb")] = pCounter;
        }
    }
    else if ( 0 == strFileExtName.CmpNoCase(_T(".php")) || 0 == strFileExtName.CmpNoCase(_T(".php3")) )
    {
        it = m_mapStrToCounter.find(_T(".php"));
        if (it != m_mapStrToCounter.end())
        { // Find instance in the pCount map
            pCounter = it->second;
        }
        else
        {
            pCounter = new PhpCounter;
            m_mapStrToCounter[_T(".php")] = pCounter;
        }
    }
    else if (0 == strFileExtName.CmpNoCase(_T(".asp")) || 0 == strFileExtName.CmpNoCase(_T(".aspx"))  )
    {
        it = m_mapStrToCounter.find(_T(".aspx"));
        if (it != m_mapStrToCounter.end())
        { // Find instance in the pCount map
            pCounter = it->second;
        }
        else
        {
            pCounter = new AspxCounter;
            m_mapStrToCounter[_T(".aspx")] = pCounter;
        }
    }
    else if (0 == strFileExtName.CmpNoCase(_T(".jsp")) )
    { // JSP Counter
        it = m_mapStrToCounter.find(_T(".jsp"));
        if (it != m_mapStrToCounter.end())
        { // Find instance in the pCount map
            pCounter = it->second;
        }
        else
        {
            pCounter = new JspCounter;
            m_mapStrToCounter[_T(".jsp")] = pCounter;
        }
    }
    else
    { // TxtCounter for the other type files
    	// rc, txt,
        it = m_mapStrToCounter.find(_T(".txt"));
        if (it != m_mapStrToCounter.end())
        { // Find instance in the pCount map
            pCounter = it->second;
        }
        else
        {
            pCounter = new TxtCounter;
            m_mapStrToCounter[_T(".txt")] = pCounter;
        }
    }

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
            if (isCountingFile(strFileExtName))
            {
                pCountingFileInfoCur = new CountingFileInfo();

                pCountingFileInfoCur->m_strFileExtName = strFileExtName;
                pCountingFileInfoCur->m_strFileFullPath = fname;

                getFileNameAndDirFromFullPath(fname,
                                              pCountingFileInfoCur->m_strFileName,
                                              pCountingFileInfoCur->m_strFolderPath);

                // Create pCounter
                pCounter = CreateCounter(strFileExtName);
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

bool CountingManager::isCountingFile(wxString& strFileExtName)
{
    bool bRet = false;

    int nItemCount = m_countingParam.m_arrSrcType.GetCount();
    wxString strTemp;
    for (int i=0; i<nItemCount; i++)
    {
        strTemp = m_countingParam.m_arrSrcType.Item(i);
        if (0 == strTemp.CmpNoCase(strFileExtName))
        {
            bRet = true;
            break;
        }
    }

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
