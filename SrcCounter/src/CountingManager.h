/**
 * @file CountingManager.h
 * @brief CountingManager.h: interface for the CountingManager class.
 * @author Boom( boomworks@gmail.com )
 * @author Copyright(C) 2004-2005 boomworks.org , All right reserved.
 * @date 2005-11-23
 * $Revision: $
 */

#if !defined(AFX_STATISTICMANAGER_H__B44677A9_720F_4A8B_989B_492D20627458__INCLUDED_)
#define AFX_STATISTICMANAGER_H__B44677A9_720F_4A8B_989B_492D20627458__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Counter.h"
#include "CountingParam.h"
#include "CountingInfo.h"
#include "CounterObserver.h"
#include "CounterRule.h"

#include <wx/xml/xml.h>
#include <wx/wfstream.h>

// write string to output:
inline static void OutputString(wxOutputStream& stream, const wxString& str,
                                wxMBConv *convMem = NULL,
                                wxMBConv *convFile = NULL)
{
    if (str.empty())
        return;

#if wxUSE_UNICODE
    wxUnusedVar(convMem);

    const wxWX2MBbuf buf(str.mb_str(*(convFile ? convFile : &wxConvUTF8)));
    stream.Write((const char*)buf, strlen((const char*)buf));
#else // !wxUSE_UNICODE
    if ( convFile && convMem )
    {
        wxString str2(str.wc_str(*convMem), *convFile);
        stream.Write(str2.mb_str(), str2.Len());
    }
    else // no conversions to do
    {
        stream.Write(str.mb_str(), str.Len());
    }
#endif // wxUSE_UNICODE/!wxUSE_UNICODE
}

// flags for OutputStringEnt()
enum
{
    XML_ESCAPE_QUOTES = 1
};

// Same as above, but create entities first.
// Translates '<' to "&lt;", '>' to "&gt;" and '&' to "&amp;"
static void OutputStringEnt(wxOutputStream& stream, const wxString& str,
                            wxMBConv *convMem = NULL,
                            wxMBConv *convFile = NULL,
                            int flags = 0)
{
    wxString buf;
    size_t i, last, len;
    wxChar c;

    len = str.Len();
    last = 0;
    for (i = 0; i < len; i++)
    {
        c = str.GetChar(i);
        if (c == wxT('<') || c == wxT('>') ||
                (c == wxT('&') && str.Mid(i+1, 4) != wxT("amp;")) ||
                ((flags & XML_ESCAPE_QUOTES) && c == wxT('"')))
        {
            OutputString(stream, str.Mid(last, i - last), convMem, convFile);
            switch (c)
            {
            case wxT('<'):
                OutputString(stream, wxT("&lt;"));
                break;
            case wxT('>'):
                OutputString(stream, wxT("&gt;"));
                break;
            case wxT('&'):
                OutputString(stream, wxT("&amp;"));
                break;
            case wxT('"'):
                OutputString(stream, wxT("&quot;"));
                break;
            default:
                break;
            }
            last = i + 1;
        }
    }
    OutputString(stream, str.Mid(last, i - last), convMem, convFile);
}

inline static void OutputIndentation(wxOutputStream& stream, int indent)
{
    wxString str = wxT("\n");
    for (int i = 0; i < indent; i++)
        str << wxT(' ') << wxT(' ');
    OutputString(stream, str);
}

static void OutputNode(wxOutputStream& stream, wxXmlNode *node, int indent,
                       wxMBConv *convMem, wxMBConv *convFile, int indentstep)
{
    wxXmlNode *n, *prev;
    wxXmlProperty *prop;

    switch (node->GetType())
    {
    case wxXML_CDATA_SECTION_NODE:
        OutputString( stream, wxT("<![CDATA["));
        OutputString( stream, node->GetContent() );
        OutputString( stream, wxT("]]>") );
        break;

    case wxXML_TEXT_NODE:
        OutputStringEnt(stream, node->GetContent(), convMem, convFile);
        break;

    case wxXML_ELEMENT_NODE:
        OutputString(stream, wxT("<"));
        OutputString(stream, node->GetName());

        prop = node->GetProperties();
        while (prop)
        {
            OutputString(stream, wxT(" ") + prop->GetName() +  wxT("=\""));
            OutputStringEnt(stream, prop->GetValue(), convMem, convFile,
                            XML_ESCAPE_QUOTES);
            OutputString(stream, wxT("\""));
            prop = prop->GetNext();
        }

        if (node->GetChildren())
        {
            OutputString(stream, wxT(">"));
            prev = NULL;
            n = node->GetChildren();
            while (n)
            {
                if (indentstep >= 0 && n && n->GetType() != wxXML_TEXT_NODE)
                    OutputIndentation(stream, indent + indentstep);
                OutputNode(stream, n, indent + indentstep, convMem, convFile, indentstep);
                prev = n;
                n = n->GetNext();
            }
            if (indentstep >= 0 && prev && prev->GetType() != wxXML_TEXT_NODE)
                OutputIndentation(stream, indent);
            OutputString(stream, wxT("</"));
            OutputString(stream, node->GetName());
            OutputString(stream, wxT(">"));
        }
        else
            OutputString(stream, wxT("/>"));
        break;

    case wxXML_COMMENT_NODE:
        OutputString(stream, wxT("<!--"));
        OutputString(stream, node->GetContent(), convMem, convFile);
        OutputString(stream, wxT("-->"));
        break;

    default:
        wxFAIL_MSG(wxT("unsupported node type"));
    }
}

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////

class wxXmlDocumentEx: public wxXmlDocument
{
public:

    // Saves document as .xml file.
    virtual bool Save(const wxString& filename, int indentstep = 1) const;
    virtual bool Save(wxOutputStream& stream, int indentstep = 1) const;

};

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////

/** Source types number */
extern const int N_COLUMN_NUM;

/** Source type string list */
extern const wxChar* CSZ_COLUMN_NAMES[];

/** manager status flag */
enum NManagerStatus
{
    NManagerStatusNormal = 0,	///< normal
    NManagerStatusStop,			///< stop
    NManagerStatusRunning,		///< running status
    NManagerStatusComplete		///< compeletly
};

//typedef CMap<int, int, CCounter*, CCounter*&> MapStrToCounter;
WX_DECLARE_STRING_HASH_MAP( Counter*, MapStrToCounter);

//WX_DEFINE_ARRAY(CounterRule*, ArrayCounterRule);
WX_DECLARE_STRING_HASH_MAP(CounterRule*, MapStrToCounterRule);		///< Hashmap for CouterRule obj
WX_DECLARE_STRING_HASH_MAP(FileExtension*, MapStrToFileExtension);	///< Hashmap for FileExtension obj
///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////

/**
 * @class CountingManager
 * statistic mananger class.
 *
 * @author Boom( boomworks@gmail.com )
 */
class CountingManager
{
public:

    /**
     * constructor.
     */
    CountingManager();

    /**
     * distructor.
     */
    virtual ~CountingManager();

public:

    /**
     * Initiation
     */
    void Init();

    /**
     * set statistic condition.
     *
     * @param pParam statistic condition object
     */
    void    SetCountingParam( CountingParam* pParam );

    /**
     * Get counting parameters
     */
    CountingParam*    GetCountingParam(void)
    {
        return &m_countingParam;
    }

	MapStrToCounterRule* GetCounterRules() 			{ return &m_mapCounterRule; }
	MapStrToFileExtension* GetFileExtensions() 		{ return &m_mapFileExtension; }

	FileExtension* FindFileExtension(wxString& strFileExt);


    /**
     * Create counter by source file extend name.
     *
     * @param strFileExtendName counter identify name
     * @return counter object pointer
     */
    Counter*		CreateCounter( wxString& strCounterType );

    /**
     * Get counting information.
     * @return CountingInfo*
     */
    virtual CountingInfo*	GetCountingInfo(void);

    /**
     * clear manager status and preserver data.
     */
    void			Clear();

    /**
     * get manager status.
     *
     * @return status flag
     */
    NManagerStatus	GetStatus();

    /**
     * Set manager status.
     *
     * @param nStatus manager status
     */
    void SetStatus( NManagerStatus nStatus );

    //
    // Strating and stop counting method

    /**
     * start statistic source files.
     */
    void			StartCounting();

    /**
     * stop statistic source files.
     */
    void			StopCounting();

    //
    // observer pattern method
    //

    /**
     * Add obvserver to subject.
     *
     * @param pObserver observer object
     */
    void			AttachObserver( CCounterObserver* pObserver );

    /**
     * Notify the observers.
     * SubClass Object call this method.
     */
    void			Notify();

    //
    // Save counting result to file.
    //

    void SaveCountingResultToCSV(wxString strFilePath);

private:

    // Counter pointer section
    CCounterObserver*		m_pObserver;		///< Observer for counting
    MapStrToCounter		    m_mapStrToCounter;  ///< Hashmap for store counter pointer

    // Counting parameter and result information section
    CountingParam		    m_countingParam;	///< Counting parametera
    CountingInfo			m_countingInfo;		///< preserver statistic infomation

    // Counting status info
    BOOL					m_bStopCounting;	///< stop statistic flag
    NManagerStatus			m_countingStatus;	///< statistic status

    // Rule xml data
    wxXmlDocumentEx 		m_docRules;		///< Rule xml doc obj
    wxXmlNode*				m_pRoot;		///< Rule xml doc root obj

    // CounterRule
	MapStrToCounterRule		m_mapCounterRule; 		///< Hashmap for store counter rule obj
	MapStrToFileExtension	m_mapFileExtension;		///< Hashmap for store file extension obj


    //////////////////////////////////////////////////////////////////////////

    /**
     * Load rule data from xml file
     */
    void loadRules();

    /**
     * Save rule data to xml file
     */
    void saveRules();

    /**
     * Add sub folder to arraylist for counting.
     */
    void addSubSrcFolder();

    /**
     * Is counting file
     */
    bool isCountingFile(wxString& strFileExtName/*IN*/, wxString& strCounterType/*OUT*/);

    /**
     * get file ext name string.
     *
     * @param strFileName file name
     * @param strExt file ext name
     */
    void getFileExtName( wxString& strFileName, wxString& strExt );

    /**
     * get file name and dir form full path.
     *
     * @param strFullPath FullPath
     * @param strFileName FileName
     * @param strDir Dir
     */
    void getFileNameAndDirFromFullPath( wxString& strFullPath, wxString& strFileName, wxString& strDir );
};

inline NManagerStatus CountingManager::GetStatus()
{
    return m_countingStatus;
}

inline void CountingManager::SetStatus(NManagerStatus nStatus )
{
    m_countingStatus = nStatus;
}

#endif // !defined(AFX_STATISTICMANAGER_H__B44677A9_720F_4A8B_989B_492D20627458__INCLUDED_)
