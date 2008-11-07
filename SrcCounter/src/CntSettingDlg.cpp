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
const long CntSettingDlg::ID_RADIOBOX1 = wxNewId();
const long CntSettingDlg::ID_STATICTEXT1 = wxNewId();
const long CntSettingDlg::ID_LISTBOX1 = wxNewId();
const long CntSettingDlg::ID_STATICTEXT2 = wxNewId();
const long CntSettingDlg::ID_COMBOBOX1 = wxNewId();
const long CntSettingDlg::ID_STATICTEXT3 = wxNewId();
const long CntSettingDlg::ID_TEXTCTRL2 = wxNewId();
const long CntSettingDlg::ID_STATICTEXT4 = wxNewId();
const long CntSettingDlg::ID_TEXTCTRL1 = wxNewId();
//*)

BEGIN_EVENT_TABLE(CntSettingDlg,wxDialog)
	//(*EventTable(CntSettingDlg)
	//*)
END_EVENT_TABLE()

//
CntSettingDlg::CntSettingDlg(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size)
{
	//(*Initialize(CntSettingDlg)
	wxBoxSizer* BoxSizer4;
	wxBoxSizer* BoxSizer6;
	wxBoxSizer* BoxSizer2;
	wxBoxSizer* BoxSizer1;
	wxStaticBoxSizer* StaticBoxSizer1;
	wxBoxSizer* BoxSizer3;
	
	Create(parent, wxID_ANY, _("More settings"), wxDefaultPosition, wxDefaultSize, wxDEFAULT_DIALOG_STYLE, _T("wxID_ANY"));
	BoxSizer1 = new wxBoxSizer(wxVERTICAL);
	wxString __wxRadioBoxChoices_1[3] = 
	{
	_("Code lines +1, comment lines +1"),
	_("Code lines +1, comment lines +0"),
	_("Code lines +0, comment lines +1")
	};
	m_rdbCountingMethod = new wxRadioBox(this, ID_RADIOBOX1, _("When code and comment in same line, please select one counting method"), wxDefaultPosition, wxDefaultSize, 3, __wxRadioBoxChoices_1, 1, 0, wxDefaultValidator, _T("ID_RADIOBOX1"));
	BoxSizer1->Add(m_rdbCountingMethod, 1, wxTOP|wxLEFT|wxRIGHT|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticBoxSizer1 = new wxStaticBoxSizer(wxVERTICAL, this, _("Effort and  Cost analysis setting"));
	BoxSizer3 = new wxBoxSizer(wxHORIZONTAL);
	BoxSizer6 = new wxBoxSizer(wxVERTICAL);
	StaticText1 = new wxStaticText(this, ID_STATICTEXT1, _("Select Project type:"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT1"));
	BoxSizer6->Add(StaticText1, 0, wxTOP|wxLEFT|wxRIGHT|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	ListBox1 = new wxListBox(this, ID_LISTBOX1, wxDefaultPosition, wxDefaultSize, 0, 0, 0, wxDefaultValidator, _T("ID_LISTBOX1"));
	BoxSizer6->Add(ListBox1, 1, wxTOP|wxLEFT|wxRIGHT|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer3->Add(BoxSizer6, 1, wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer4 = new wxBoxSizer(wxVERTICAL);
	StaticText2 = new wxStaticText(this, ID_STATICTEXT2, _("Code Production of one man-month:"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT2"));
	BoxSizer4->Add(StaticText2, 0, wxTOP|wxLEFT|wxRIGHT|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	ComboBox1 = new wxComboBox(this, ID_COMBOBOX1, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, 0, 0, wxDefaultValidator, _T("ID_COMBOBOX1"));
	BoxSizer4->Add(ComboBox1, 0, wxTOP|wxLEFT|wxRIGHT|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticText3 = new wxStaticText(this, ID_STATICTEXT3, _("Days of one man-month:"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT3"));
	BoxSizer4->Add(StaticText3, 0, wxTOP|wxLEFT|wxRIGHT|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	TextCtrl2 = new wxTextCtrl(this, ID_TEXTCTRL2, _("Text"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL2"));
	BoxSizer4->Add(TextCtrl2, 0, wxTOP|wxLEFT|wxRIGHT|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticText4 = new wxStaticText(this, ID_STATICTEXT4, _("Cost of one man-month:"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT4"));
	BoxSizer4->Add(StaticText4, 0, wxTOP|wxLEFT|wxRIGHT|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	TextCtrl1 = new wxTextCtrl(this, ID_TEXTCTRL1, _("Text"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL1"));
	BoxSizer4->Add(TextCtrl1, 0, wxTOP|wxLEFT|wxRIGHT|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer3->Add(BoxSizer4, 1, wxRIGHT|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticBoxSizer1->Add(BoxSizer3, 0, wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer1->Add(StaticBoxSizer1, 0, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer2 = new wxBoxSizer(wxHORIZONTAL);
	Button1 = new wxButton(this, wxID_OK, _("&Ok"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("wxID_OK"));
	BoxSizer2->Add(Button1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	Button2 = new wxButton(this, wxID_CANCEL, _("&Cancel"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("wxID_CANCEL"));
	BoxSizer2->Add(Button2, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer1->Add(BoxSizer2, 0, wxTOP|wxBOTTOM|wxRIGHT|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	SetSizer(BoxSizer1);
	BoxSizer1->Fit(this);
	BoxSizer1->SetSizeHints(this);
	Center();
	
	Connect(ID_RADIOBOX1,wxEVT_COMMAND_RADIOBOX_SELECTED,(wxObjectEventFunction)&CntSettingDlg::OnRdbCountingMethodSelect);
	Connect(wxID_OK,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&CntSettingDlg::OnBtnOkClick);
	Connect(wxID_CANCEL,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&CntSettingDlg::OnBtnCancelClick);
	Connect(wxID_ANY,wxEVT_INIT_DIALOG,(wxObjectEventFunction)&CntSettingDlg::OnInit);
	//*)
}

CntSettingDlg::~CntSettingDlg()
{
	//(*Destroy(CntSettingDlg)
	//*)
}

void CntSettingDlg::OnInit(wxInitDialogEvent& event)
{
    m_rdbCountingMethod->SetSelection(m_settingParam.m_nCountingMethodType);
}

void CntSettingDlg::SetSettingParam(SettingParam* pParam)
{
    m_settingParam.m_nCountingMethodType = pParam->m_nCountingMethodType;
}

void CntSettingDlg::GetSettingParam(SettingParam& param)
{
    //
    param.m_nCountingMethodType = m_settingParam.m_nCountingMethodType;
}

void CntSettingDlg::OnBtnOkClick(wxCommandEvent& event)
{
	EndModal(wxID_OK);
}

void CntSettingDlg::OnBtnCancelClick(wxCommandEvent& event)
{
	EndModal(wxID_CANCEL);
}

void CntSettingDlg::OnRdbCountingMethodSelect(wxCommandEvent& event)
{
    // wxMessageBox( event.GetString() );
    m_settingParam.m_nCountingMethodType = event.GetSelection();
}
