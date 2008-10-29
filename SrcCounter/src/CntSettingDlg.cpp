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
	wxString __wxRadioBoxChoices_1[3] = 
	{
		_("Code lines +1, comment lines +1"),
		_("Code lines +1, comment lines +0"),
		_("Code lines +0, comment lines +1")
	};
	m_rdbCountingMethod = new wxRadioBox(this, ID_RADIOBOX1, _("When code and comment in same line, please select one counting method:"), wxDefaultPosition, wxDefaultSize, 3, __wxRadioBoxChoices_1, 1, 0, wxDefaultValidator, _T("ID_RADIOBOX1"));
	BoxSizer1->Add(m_rdbCountingMethod, 1, wxTOP|wxLEFT|wxRIGHT|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer2 = new wxBoxSizer(wxHORIZONTAL);
	Button1 = new wxButton(this, wxID_OK, _("&Ok"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("wxID_OK"));
	BoxSizer2->Add(Button1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	Button2 = new wxButton(this, wxID_CANCEL, _("&Cancel"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("wxID_CANCEL"));
	BoxSizer2->Add(Button2, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer1->Add(BoxSizer2, 0, wxTOP|wxBOTTOM|wxRIGHT|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
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
