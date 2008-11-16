#include "version.h"
#include "aboutdlg.h"

//(*InternalHeaders(AboutDlg)
#include <wx/bitmap.h>
#include <wx/intl.h>
#include <wx/image.h>
#include <wx/string.h>
//*)

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


//(*IdInit(AboutDlg)
const long AboutDlg::ID_STATICBITMAP1 = wxNewId();
const long AboutDlg::ID_STATICBITMAP2 = wxNewId();
const long AboutDlg::ID_STATICTEXT1 = wxNewId();
const long AboutDlg::ID_STATICTEXT2 = wxNewId();
const long AboutDlg::ID_STATICTEXT3 = wxNewId();
const long AboutDlg::ID_STATICTEXT5 = wxNewId();
const long AboutDlg::ID_STATICTEXT6 = wxNewId();
const long AboutDlg::ID_STATICTEXT4 = wxNewId();
const long AboutDlg::ID_STATICBITMAP3 = wxNewId();
//*)

BEGIN_EVENT_TABLE(AboutDlg,wxDialog)
	//(*EventTable(AboutDlg)
	//*)
END_EVENT_TABLE()

AboutDlg::AboutDlg(wxWindow* parent,wxWindowID id)
{
	//(*Initialize(AboutDlg)
	Create(parent, id, _("About"), wxDefaultPosition, wxDefaultSize, 0, _T("id"));
	SetClientSize(wxSize(17,16));
	BoxSizer1 = new wxBoxSizer(wxVERTICAL);
	StaticBitmap1 = new wxStaticBitmap(this, ID_STATICBITMAP1, wxBitmap(wxImage(_T("img\\bmw_logo.bmp"))), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICBITMAP1"));
	BoxSizer1->Add(StaticBitmap1, 0, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 0);
	BoxSizer2 = new wxBoxSizer(wxHORIZONTAL);
	StaticBitmap2 = new wxStaticBitmap(this, ID_STATICBITMAP2, wxBitmap(wxImage(_T("img\\SourceCounter.ico"))), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICBITMAP2"));
	BoxSizer2->Add(StaticBitmap2, 1, wxTOP|wxBOTTOM|wxALIGN_TOP|wxALIGN_CENTER_HORIZONTAL, 5);
	BoxSizer3 = new wxBoxSizer(wxVERTICAL);
	StaticText1 = new wxStaticText(this, ID_STATICTEXT1, _("SourceCounter"), wxDefaultPosition, wxSize(214,14), 0, _T("ID_STATICTEXT1"));
	BoxSizer3->Add(StaticText1, 0, wxTOP|wxLEFT|wxRIGHT|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticText2 = new wxStaticText(this, ID_STATICTEXT2, _("Unicode version 1.0.1.0"), wxDefaultPosition, wxSize(214,14), 0, _T("ID_STATICTEXT2"));
	BoxSizer3->Add(StaticText2, 0, wxTOP|wxLEFT|wxRIGHT|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticText3 = new wxStaticText(this, ID_STATICTEXT3, _("(C) 1999 - 2008 B O O M (BoomWorks.Net)"), wxDefaultPosition, wxSize(214,13), 0, _T("ID_STATICTEXT3"));
	BoxSizer3->Add(StaticText3, 0, wxTOP|wxLEFT|wxRIGHT|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticText5 = new wxStaticText(this, ID_STATICTEXT5, _("mailto:boomworks@hotmail.com"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT5"));
	BoxSizer3->Add(StaticText5, 0, wxTOP|wxLEFT|wxRIGHT|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticText6 = new wxStaticText(this, ID_STATICTEXT6, _("http://www.boomworks.net"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT6"));
	BoxSizer3->Add(StaticText6, 0, wxTOP|wxLEFT|wxRIGHT|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer3->Add(-1,-1,0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticText4 = new wxStaticText(this, ID_STATICTEXT4, _("Label"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT4"));
	BoxSizer3->Add(StaticText4, 0, wxTOP|wxLEFT|wxRIGHT|wxEXPAND|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	StaticBitmap3 = new wxStaticBitmap(this, ID_STATICBITMAP3, wxBitmap(wxImage(_T("W:\\boomworks\\SrcCounter\\src\\img\\powered-by-wxwidgets.png"))), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICBITMAP3"));
	BoxSizer3->Add(StaticBitmap3, 0, wxTOP|wxLEFT|wxRIGHT|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer3->Add(-1,-1,0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	Button1 = new wxButton(this, wxID_OK, _("&Ok"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("wxID_OK"));
	BoxSizer3->Add(Button1, 0, wxALL|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer2->Add(BoxSizer3, 2, wxTOP|wxBOTTOM|wxRIGHT|wxALIGN_TOP|wxALIGN_CENTER_HORIZONTAL, 5);
	BoxSizer1->Add(BoxSizer2, 1, wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	SetSizer(BoxSizer1);
	BoxSizer1->SetSizeHints(this);
	Center();
	
	Connect(wxID_OK,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&AboutDlg::OnButton1Click);
	//*)

	// Set Version by AutoVersioning tool
	wxString strVersion(AutoVersion::FULLVERSION_STRING, wxConvUTF8);
	wxString strStatus(AutoVersion::STATUS, wxConvUTF8);

	StaticText2->SetLabel(_T("Unicode version ") + strVersion + _T(" ") + strStatus);

	// Get wx version infomation//
	wxString msg = wxbuildinfo(long_f);
	StaticText4->SetLabel(msg);

}

AboutDlg::~AboutDlg()
{
	//(*Destroy(AboutDlg)
	//*)
}


void AboutDlg::OnButton1Click(wxCommandEvent& event)
{
	Close();
}
