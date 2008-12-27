#ifndef CATEGORIZEMGR_H
#define CATEGORIZEMGR_H

#include "Rule.h"
#include "ruleinfo.h"
#include "CategorizationObserver.h"

////////////////////////////////////////////////////////////////////////////////
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

#include <wx/xml/xml.h>

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
WX_DEFINE_ARRAY(Rule*, ArrayRule);

///////////////////////////////////////////////////////////////////////

class CategorizeMgr
{
public:
    CategorizeMgr();
    virtual ~CategorizeMgr();

	///////////////////////////////////////////////////////////////////

	void Init(wxString& strPath);
	// void SetBaseDestPath(wxString& strPath) 						{ m_strDesktopPath = strPath; }

	ArrayCategorizationFileInfo*  GetCategorizationFileInfos()		{ return &m_arrCategorizationFileInfo; }

	//
	void AddRule(RuleInfo& RuleInfo);
	void DeleteRule(int nIndex);
	Rule* GetRule(int nIndex)			{ return m_arrRule[nIndex]; }

	ArrayRule* GetRuleArray()			{ return &m_arrRule; }

	//
	void Preview();
	void Categorize();

	///////////////////////////////////////////////////////////////////

    //
    // observer pattern method
    //

    /**
     * Add obvserver to subject.
     *
     * @param pObserver observer object
     */
    void			AttachObserver( CategorizationObserver* pObserver );

    /**
     * Notify the observers.
     * SubClass Object call this method.
     */
    void			Notify();


	///////////////////////////////////////////////////////////////////

	static unsigned int ms_nCurMaxIndex;

protected:
private:
    CategorizationObserver*			m_pObserver;		///< Observer for categorization

	ArrayRule 						m_arrRule;			///< Rules for categorization
	ArrayCategorizationFileInfo 	m_arrCategorizationFileInfo;	///< Files info for categorize

	wxArrayString 					m_arrStrSubFolder;	///<

	wxString						m_strDesktopPath;

	wxXmlDocumentEx 				m_docWords;
	wxXmlNode*						m_pRoot;
	///////////////////////////////////////////////////////////////////

    void getSubFolder(wxString& strFolderPath, wxArrayString& arrSubFolder, bool bRecursive = true);
	void getFolderAllFile(wxString& strFolderPath, ArrayCategorizationFileInfo& arrFileInfo );

	void clearFileInfos();
	void clearRules();

	void loadRuleInfo();
	void saveRuleInfo();
};

#endif // CATEGORIZEMGR_H
