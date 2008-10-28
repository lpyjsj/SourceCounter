#include "wx_pch.h"
#include "CntSettingDlg.h"

#ifndef WX_PRECOMP
	//(*InternalHeadersPCH(CntSettingDlg)
	#include <wx/intl.h>
	#include <wx/string.h>
	//*)
#endif
//(*InternalHeaders(CntSettingDlg)
//*)

//(*IdInit(CntSettingDlg)
const long CntSettingDlg::ID_STATICTEXT2 = wxNewId();
const long CntSettingDlg::ID_RADIOBUTTON1 = wxNewId();
const long CntSettingDlg::ID_RADIOBUTTON2 = wxNewId();
const long CntSettingDlg::ID_RADIOBUTTON3 = wxNewId();
const long CntSettingDlg::ID_STATICLINE1 = wxNewId();
const long CntSettingDlg::ID_BUTTON1 = wxNewId();
const long CntSettingDlg::ID_BUTTON2 = wxNewId();
//*)

BEGIN_EVENT_TABLE(CntSettingDlg,wxDialog)
	//(*EventTable(CntSettingDlg)
	//*)
END_EVENT_TABLE()

//
CntSettingDlg::CntSettingDlg(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size)
{
	//(*Initialize(CntSettingDlg)
	wxBoxSizer* BoxSizer2;
	wxBoxSizer* BoxSizer1;
	
	Create(parent, id, _("More settings"), wxDefaultPosition, wxDefaultSize, wxDEFAULT_DIALOG_STYLE, _T("id"));
	SetClientSize(wxDefaultSize);
	Move(wxDefaultPosition);
	BoxSizer1 = new wxBoxSizer(wxVERTICAL);
	StaticText2 = new wxStaticText(this, ID_STATICTEXT2, _("When code and comment in same line, please select one counting method:"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT2"));
	BoxSizer1->Add(StaticText2, 1, wxTOP|wxLEFT|wxRIGHT|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	RadioButton1 = new wxRadioButton(this, ID_RADIOBUTTON1, _("Code lines +1, comment lines +1"), wxDefaultPosition, wxDefaultSize, wxRB_GROUP, wxDefaultValidator, _T("ID_RADIOBUTTON1"));
	BoxSizer1->Add(RadioButton1, 1, wxTOP|wxLEFT|wxRIGHT|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	RadioButton2 = new wxRadioButton(this, ID_RADIOBUTTON2, _("Code lines +1, comment lines +0"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_RADIOBUTTON2"));
	BoxSizer1->Add(RadioButton2, 1, wxTOP|wxLEFT|wxRIGHT|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	RadioButton3 = new wxRadioButton(this, ID_RADIOBUTTON3, _("Code lines +0, comment lines +1"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_RADIOBUTTON3"));
	BoxSizer1->Add(RadioButton3, 1, wxTOP|wxLEFT|wxRIGHT|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticLine1 = new wxStaticLine(this, ID_STATICLINE1, wxDefaultPosition, wxSize(10,-1), wxLI_HORIZONTAL, _T("ID_STATICLINE1"));
	BoxSizer1->Add(StaticLine1, 0, wxTOP|wxLEFT|wxRIGHT|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer2 = new wxBoxSizer(wxHORIZONTAL);
	Button1 = new wxButton(this, ID_BUTTON1, _("&Ok"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON1"));
	BoxSizer2->Add(Button1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	Button2 = new wxButton(this, ID_BUTTON2, _("&Cancel"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON2"));
	BoxSizer2->Add(Button2, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer1->Add(BoxSizer2, 0, wxTOP|wxBOTTOM|wxRIGHT|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	SetSizer(BoxSizer1);
	BoxSizer1->Fit(this);
	BoxSizer1->SetSizeHints(this);
	Center();
	
	Connect(ID_BUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&CntSettingDlg::OnBtnOkClick);
	Connect(ID_BUTTON2,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&CntSettingDlg::OnBtnCancelClick);
	//*)
}

CntSettingDlg::~CntSettingDlg()
{
	//(*Destroy(CntSettingDlg)
	//*)
}

void CntSettingDlg::GetSettingParam(SettingParam& param)
{
    //
    param.m_nCountingMethodType = m_settingParam.m_nCountingMethodType;
}

void CntSettingDlg::OnBtnOkClick(wxCommandEvent& event)
{
    m_settingParam.m_nCountingMethodType = 0; //WaitCursor
    Close();
}

void CntSettingDlg::OnBtnCancelClick(wxCommandEvent& event)
{
    Close();
}
