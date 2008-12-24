#ifndef RULEDLG_H
#define RULEDLG_H

#ifndef WX_PRECOMP
//(*HeadersPCH(MainDlg)
#include <wx/listctrl.h>
#include <wx/sizer.h>
#include <wx/stattext.h>
#include <wx/radiobox.h>
#include <wx/checklst.h>
#include <wx/statbmp.h>
#include <wx/button.h>
#include <wx/dialog.h>
//*)
#endif
//(*Headers(MainDlg)
#include <wx/notebook.h>
//*)

#include <wx/listctrl.h>

#include "CategorizeMgr.h"
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

class MainDlg: public wxDialog, CategorizationObserver
{
public:

    MainDlg(wxWindow* parent,wxWindowID id=wxID_ANY,const wxPoint& pos=wxDefaultPosition,const wxSize& size=wxDefaultSize);
    virtual ~MainDlg();

    //(*Declarations(MainDlg)
    wxNotebook* Notebook1;
    wxStaticBitmap* StaticBitmap1;
    wxListCtrl* m_pLcFolderSize;
    wxButton* m_btnQuit;
    wxButton* m_btnPreview;
    wxStaticText* StaticText1;
    wxCheckListBox* m_pLbxCustRules;
    wxButton* Button2;
    wxButton* Button6;
    wxRadioBox* m_pRbxBaseRules;
    wxButton* m_btnCheckUpdate;
    wxButton* Button9;
    wxButton* m_btnNew;
    wxListCtrl* m_pLcResult;
    wxButton* m_btnRun;
    wxButton* Button8;
    wxButton* m_btnAbout;
    wxButton* m_btnTest;
    //*)

	///////////////////////////////////////////////////////////////////////

	virtual void UpdateCategorizationCtrls(void);

protected:

    //(*Identifiers(MainDlg)
    static const long ID_STATICBITMAP1;
    static const long ID_STATICTEXT1;
    static const long ID_BUTTON1;
    static const long ID_BUTTON2;
    static const long ID_BUTTON6;
    static const long ID_BUTTON8;
    static const long ID_BUTTON9;
    static const long ID_CHECKLISTBOX1;
    static const long ID_RADIOBOX1;
    static const long ID_BUTTON7;
    static const long ID_BUTTON4;
    static const long ID_BUTTON5;
    static const long ID_LISTCTRL1;
    static const long ID_LISTCTRL2;
    static const long ID_NOTEBOOK1;
    static const long ID_BUTTON3;
    //*)

private:

    //(*Handlers(MainDlg)
    void OnBtnQuitClick(wxCommandEvent& event);
    void OnBtnAboutClick(wxCommandEvent& event);
    void OnBtnPreviewClick(wxCommandEvent& event);
    void OnBtnCheckUpdateClick(wxCommandEvent& event);
    void OnBtnRunClick(wxCommandEvent& event);
    void OnInit(wxInitDialogEvent& event);
    void OnBtnNewClick(wxCommandEvent& event);
    void OnListbook1PageChanged(wxNotebookEvent& event);
    void OnBtnTestClick(wxCommandEvent& event);
    //*)

    ///////////////////////////////////////////////////////////////////

	CategorizeMgr 		m_categorizeMgr;

	wxXmlDocumentEx 	m_docWords;
	wxXmlNode*			m_pRoot;

    ///////////////////////////////////////////////////////////////////

    void getDesktopPath(wxString& strPath);
//	void categorizeByTime(bool bPreview);
	void updateUICtrls();


	///////////////////////////////////////////////////////////////////

    DECLARE_EVENT_TABLE()
};

#endif
