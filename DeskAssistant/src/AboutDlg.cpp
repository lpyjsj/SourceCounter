/**
 * About dialog implement file.
 *
 * $Author: $
 * $id: $
 */

#ifndef WX_PRECOMP
	//(*InternalHeadersPCH(AboutDlg)
	#include <wx/intl.h>
	#include <wx/string.h>
	//*)
#endif
//(*InternalHeaders(AboutDlg)
#include <wx/bitmap.h>
#include <wx/image.h>
//*)

#include "wx_pch.h"
#include "AboutDlg.h"
#include "version.h"

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////

//helper functions
enum wxbuildinfoformat {
    short_f, long_f };

wxString wxbuildinfo(wxbuildinfoformat format)
{
    wxString wxbuild(wxVERSION_STRING);

    if (format == long_f )
    {
#if defined(__WXMSW__)
        wxbuild << _T("-Windows");
#elif defined(__UNIX__)
        wxbuild << _T("-Linux");
#endif

#if wxUSE_UNICODE
        wxbuild << _T("-Unicode build");
#else
        wxbuild << _T("-ANSI build");
#endif // wxUSE_UNICODE
    }

    return wxbuild;
}

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////

//(*IdInit(AboutDlg)
const long AboutDlg::ID_STATICBITMAP1 = wxNewId();
const long AboutDlg::ID_STATICTEXT1 = wxNewId();
const long AboutDlg::ID_STATICTEXT2 = wxNewId();
const long AboutDlg::ID_STATICTEXT3 = wxNewId();
const long AboutDlg::ID_STATICTEXT5 = wxNewId();
const long AboutDlg::ID_STATICTEXT4 = wxNewId();
const long AboutDlg::ID_STATICTEXT7 = wxNewId();
const long AboutDlg::ID_STATICTEXT6 = wxNewId();
//*)

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////

const long AboutDlg::ID_LINK_BMW_HP = wxNewId();
const long AboutDlg::ID_LINK_BMW_MAIL = wxNewId();

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////

BEGIN_EVENT_TABLE(AboutDlg,wxDialog)
	//(*EventTable(AboutDlg)
	//*)
END_EVENT_TABLE()

AboutDlg::AboutDlg(wxWindow* parent,wxWindowID id)
{
	//(*Initialize(AboutDlg)
	wxBoxSizer* BoxSizer4;
	wxBoxSizer* BoxSizer2;
	wxBoxSizer* BoxSizer1;
	wxBoxSizer* BoxSizer3;
	
	Create(parent, id, _("About..."), wxDefaultPosition, wxDefaultSize, wxDEFAULT_DIALOG_STYLE, _T("id"));
	BoxSizer1 = new wxBoxSizer(wxHORIZONTAL);
	StaticBitmap1 = new wxStaticBitmap(this, ID_STATICBITMAP1, wxBitmap(wxImage(_T("img\\DesktopAssistant.ico"))), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICBITMAP1"));
	BoxSizer1->Add(StaticBitmap1, 0, wxALL|wxALIGN_TOP|wxALIGN_CENTER_HORIZONTAL, 5);
	BoxSizer2 = new wxBoxSizer(wxVERTICAL);
	StaticText1 = new wxStaticText(this, ID_STATICTEXT1, _("Desktop Assistant"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT1"));
	BoxSizer2->Add(StaticText1, 0, wxTOP|wxLEFT|wxRIGHT|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	m_pLblVersion = new wxStaticText(this, ID_STATICTEXT2, _("Unicode versin 1.0.1.0"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT2"));
	BoxSizer2->Add(m_pLblVersion, 0, wxTOP|wxLEFT|wxRIGHT|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticText3 = new wxStaticText(this, ID_STATICTEXT3, _("(C) 1999 - 2009 BoomWorks.Net"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT3"));
	BoxSizer2->Add(StaticText3, 0, wxTOP|wxLEFT|wxRIGHT|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	m_pLblWxBuildInfo = new wxStaticText(this, ID_STATICTEXT5, _("wx-build-info"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT5"));
	BoxSizer2->Add(m_pLblWxBuildInfo, 0, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer3 = new wxBoxSizer(wxHORIZONTAL);
	StaticText2 = new wxStaticText(this, ID_STATICTEXT4, _("Homepage:"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT4"));
	BoxSizer3->Add(StaticText2, 1, wxTOP|wxLEFT|wxRIGHT|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer2->Add(BoxSizer3, 0, wxTOP|wxRIGHT|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer4 = new wxBoxSizer(wxHORIZONTAL);
	StaticText5 = new wxStaticText(this, ID_STATICTEXT7, _("E-mail:"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT7"));
	BoxSizer4->Add(StaticText5, 1, wxTOP|wxLEFT|wxRIGHT|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticText4 = new wxStaticText(this, ID_STATICTEXT6, _("boomworks@hotmail.com"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT6"));
	BoxSizer4->Add(StaticText4, 1, wxTOP|wxLEFT|wxRIGHT|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer2->Add(BoxSizer4, 1, wxRIGHT|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer2->Add(-1,-1,0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	Button1 = new wxButton(this, wxID_OK, _("&OK"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("wxID_OK"));
	BoxSizer2->Add(Button1, 0, wxALL|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer1->Add(BoxSizer2, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	SetSizer(BoxSizer1);
	BoxSizer1->Fit(this);
	BoxSizer1->SetSizeHints(this);
	Center();
	//*)

	// Set link to boomworks.net
	m_pLinkBmwHp = new wxHyperLink(this, ID_LINK_BMW_HP, _T("http://www.boomworks.net"));
	BoxSizer3->Add(m_pLinkBmwHp, 0, wxTOP|wxLEFT|wxRIGHT|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);

//	m_pLinkBmwMail = new wxHyperLink(this, ID_LINK_BMW_MAIL, _T("mailto:boomworks@gmail.com"));
//	BoxSizer4->Add(m_pLinkBmwMail, 0, wxTOP|wxLEFT|wxRIGHT|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);

	// Set Version by AutoVersioning tool
	wxString strVersion(AutoVersion::FULLVERSION_STRING, wxConvUTF8);
	wxString strStatus(AutoVersion::STATUS, wxConvUTF8);
	m_pLblVersion->SetLabel(_T("Unicode version ") + strVersion + _T(" ") + strStatus);

	// Get wx version infomation//
	wxString msg = wxbuildinfo(long_f);
	m_pLblWxBuildInfo->SetLabel(msg);



}

AboutDlg::~AboutDlg()
{
	//(*Destroy(AboutDlg)
	//*)
}

