#include "wx_pch.h"
#include "CounterRuleDlg.h"

#ifndef WX_PRECOMP
//(*InternalHeadersPCH(CounterRuleDlg)
#include <wx/intl.h>
#include <wx/string.h>
//*)
#endif
//(*InternalHeaders(CounterRuleDlg)
#include <wx/settings.h>
//*)

//(*IdInit(CounterRuleDlg)
const long CounterRuleDlg::ID_STATICTEXT1 = wxNewId();
const long CounterRuleDlg::ID_TEXTCTRL1 = wxNewId();
const long CounterRuleDlg::ID_STATICTEXT3 = wxNewId();
const long CounterRuleDlg::ID_TEXTCTRL2 = wxNewId();
const long CounterRuleDlg::ID_STATICTEXT2 = wxNewId();
const long CounterRuleDlg::ID_COMBOBOX1 = wxNewId();
const long CounterRuleDlg::ID_STATICTEXT7 = wxNewId();
const long CounterRuleDlg::ID_TEXTCTRL6 = wxNewId();
const long CounterRuleDlg::ID_STATICTEXT4 = wxNewId();
const long CounterRuleDlg::ID_TEXTCTRL3 = wxNewId();
const long CounterRuleDlg::ID_STATICTEXT5 = wxNewId();
const long CounterRuleDlg::ID_TEXTCTRL4 = wxNewId();
const long CounterRuleDlg::ID_STATICTEXT6 = wxNewId();
const long CounterRuleDlg::ID_TEXTCTRL5 = wxNewId();
//*)

BEGIN_EVENT_TABLE(CounterRuleDlg,wxDialog)
    //(*EventTable(CounterRuleDlg)
    //*)
END_EVENT_TABLE()

CounterRuleDlg::CounterRuleDlg(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size):
		m_pFileExt(0)
{
    //(*Initialize(CounterRuleDlg)
    wxBoxSizer* BoxSizer4;
    wxBoxSizer* BoxSizer6;
    wxBoxSizer* BoxSizer5;
    wxBoxSizer* BoxSizer7;
    wxBoxSizer* BoxSizer8;
    wxBoxSizer* BoxSizer2;
    wxBoxSizer* BoxSizer1;
    wxBoxSizer* BoxSizer9;
    wxBoxSizer* BoxSizer3;

    Create(parent, wxID_ANY, _("Counting rule setting dialog"), wxDefaultPosition, wxDefaultSize, wxDEFAULT_DIALOG_STYLE, _T("wxID_ANY"));
    BoxSizer1 = new wxBoxSizer(wxVERTICAL);
    BoxSizer3 = new wxBoxSizer(wxHORIZONTAL);
    StaticText1 = new wxStaticText(this, ID_STATICTEXT1, _("&Extension:"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT1"));
    BoxSizer3->Add(StaticText1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    m_txtExtName = new wxTextCtrl(this, ID_TEXTCTRL1, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL1"));
    m_txtExtName->SetMaxLength(5);
    BoxSizer3->Add(m_txtExtName, 3, wxTOP|wxLEFT|wxRIGHT|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer1->Add(BoxSizer3, 0, wxTOP|wxLEFT|wxRIGHT|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer4 = new wxBoxSizer(wxHORIZONTAL);
    StaticText3 = new wxStaticText(this, ID_STATICTEXT3, _("&Description:"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT3"));
    BoxSizer4->Add(StaticText3, 1, wxALL|wxALIGN_TOP|wxALIGN_CENTER_HORIZONTAL, 5);
    m_txtExtDesc = new wxTextCtrl(this, ID_TEXTCTRL2, wxEmptyString, wxDefaultPosition, wxSize(-1,48), wxTE_MULTILINE, wxDefaultValidator, _T("ID_TEXTCTRL2"));
    m_txtExtDesc->SetMaxLength(256);
    BoxSizer4->Add(m_txtExtDesc, 3, wxTOP|wxLEFT|wxRIGHT|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer1->Add(BoxSizer4, 1, wxLEFT|wxRIGHT|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer6 = new wxBoxSizer(wxHORIZONTAL);
    StaticText2 = new wxStaticText(this, ID_STATICTEXT2, _("&Source style:"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT2"));
    BoxSizer6->Add(StaticText2, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    m_cmbMethod = new wxComboBox(this, ID_COMBOBOX1, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, 0, 0, wxDefaultValidator, _T("ID_COMBOBOX1"));
    m_cmbMethod->SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_INFOBK));
    BoxSizer6->Add(m_cmbMethod, 3, wxTOP|wxLEFT|wxRIGHT|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer1->Add(BoxSizer6, 0, wxLEFT|wxRIGHT|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer9 = new wxBoxSizer(wxHORIZONTAL);
    StaticText7 = new wxStaticText(this, ID_STATICTEXT7, _("Description:"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT7"));
    BoxSizer9->Add(StaticText7, 1, wxALL|wxALIGN_TOP|wxALIGN_CENTER_HORIZONTAL, 5);
    TextCtrl4 = new wxTextCtrl(this, ID_TEXTCTRL6, wxEmptyString, wxDefaultPosition, wxSize(0,48), wxTE_MULTILINE, wxDefaultValidator, _T("ID_TEXTCTRL6"));
    TextCtrl4->SetMaxLength(256);
    TextCtrl4->SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_INFOBK));
    BoxSizer9->Add(TextCtrl4, 3, wxTOP|wxLEFT|wxRIGHT|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer1->Add(BoxSizer9, 0, wxLEFT|wxRIGHT|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer5 = new wxBoxSizer(wxHORIZONTAL);
    BoxSizer5->Add(-1,-1,0, wxLEFT|wxRIGHT|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticText4 = new wxStaticText(this, ID_STATICTEXT4, _("Single line comment:"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT4"));
    BoxSizer5->Add(StaticText4, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    TextCtrl1 = new wxTextCtrl(this, ID_TEXTCTRL3, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL3"));
    TextCtrl1->SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_INFOBK));
    BoxSizer5->Add(TextCtrl1, 1, wxTOP|wxLEFT|wxRIGHT|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer1->Add(BoxSizer5, 0, wxLEFT|wxRIGHT|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer7 = new wxBoxSizer(wxHORIZONTAL);
    BoxSizer7->Add(-1,-1,0, wxLEFT|wxRIGHT|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticText5 = new wxStaticText(this, ID_STATICTEXT5, _("Multi-line comment begin:"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT5"));
    BoxSizer7->Add(StaticText5, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    TextCtrl2 = new wxTextCtrl(this, ID_TEXTCTRL4, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL4"));
    TextCtrl2->SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_INFOBK));
    BoxSizer7->Add(TextCtrl2, 1, wxTOP|wxLEFT|wxRIGHT|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer1->Add(BoxSizer7, 0, wxLEFT|wxRIGHT|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer8 = new wxBoxSizer(wxHORIZONTAL);
    BoxSizer8->Add(-1,-1,0, wxLEFT|wxRIGHT|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticText6 = new wxStaticText(this, ID_STATICTEXT6, _("Multi-line comment endl:"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT6"));
    BoxSizer8->Add(StaticText6, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    TextCtrl3 = new wxTextCtrl(this, ID_TEXTCTRL5, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL5"));
    TextCtrl3->SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_INFOBK));
    BoxSizer8->Add(TextCtrl3, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer1->Add(BoxSizer8, 0, wxLEFT|wxRIGHT|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer2 = new wxBoxSizer(wxHORIZONTAL);
    m_btnOK = new wxButton(this, wxID_OK, _("&OK"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("wxID_OK"));
    BoxSizer2->Add(m_btnOK, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    m_btnCancel = new wxButton(this, wxID_CANCEL, _("&Cancel"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("wxID_CANCEL"));
    BoxSizer2->Add(m_btnCancel, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer1->Add(BoxSizer2, 0, wxBOTTOM|wxLEFT|wxRIGHT|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    SetSizer(BoxSizer1);
    BoxSizer1->Fit(this);
    BoxSizer1->SetSizeHints(this);
    Center();

    Connect(wxID_OK,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&CounterRuleDlg::OnBtnOKClick);
    Connect(wxID_CANCEL,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&CounterRuleDlg::OnBtnCancelClick);
    Connect(wxID_ANY,wxEVT_INIT_DIALOG,(wxObjectEventFunction)&CounterRuleDlg::OnInit);
    //*)
}

CounterRuleDlg::~CounterRuleDlg()
{
    //(*Destroy(CounterRuleDlg)
    //*)
}

void CounterRuleDlg::OnInit(wxInitDialogEvent& event)
{
	m_txtExtName->SetValue(m_pFileExt->m_strName);
	m_txtExtDesc->SetValue(m_pFileExt->m_strDesc);
	m_cmbMethod->AppendString(m_pFileExt->m_strCounterType);
	m_cmbMethod->Select(0);
}

void CounterRuleDlg::OnBtnOKClick(wxCommandEvent& event)
{
	m_pFileExt->m_strName = m_txtExtName->GetValue();
	m_pFileExt->m_strDesc = m_txtExtDesc->GetValue();

	EndModal(wxID_OK);
}

void CounterRuleDlg::OnBtnCancelClick(wxCommandEvent& event)
{
	EndModal(wxID_CANCEL);
}

