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
const long CntSettingDlg::ID_STATICTEXT2 = wxNewId();
const long CntSettingDlg::ID_COMBOBOX1 = wxNewId();
const long CntSettingDlg::ID_STATICTEXT3 = wxNewId();
const long CntSettingDlg::ID_SPINCTRL1 = wxNewId();
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
	wxBoxSizer* BoxSizer2;
	wxBoxSizer* BoxSizer1;
	wxStaticBoxSizer* StaticBoxSizer1;
	
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
	StaticBoxSizer1 = new wxStaticBoxSizer(wxVERTICAL, this, _("Effort and cost analysis setting"));
	StaticText2 = new wxStaticText(this, ID_STATICTEXT2, _("Code production of one man-month(coding lines per man-month):"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT2"));
	StaticBoxSizer1->Add(StaticText2, 0, wxTOP|wxLEFT|wxRIGHT|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	m_cmbLinesPerMM = new wxComboBox(this, ID_COMBOBOX1, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, 0, 0, wxDefaultValidator, _T("ID_COMBOBOX1"));
	m_cmbLinesPerMM->Append(_("6000"));
	m_cmbLinesPerMM->SetSelection( m_cmbLinesPerMM->Append(_("4000")) );
	m_cmbLinesPerMM->Append(_("3000"));
	m_cmbLinesPerMM->Append(_("2000"));
	StaticBoxSizer1->Add(m_cmbLinesPerMM, 1, wxTOP|wxLEFT|wxRIGHT|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	StaticText3 = new wxStaticText(this, ID_STATICTEXT3, _("Man-days of one man-month:"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT3"));
	StaticBoxSizer1->Add(StaticText3, 0, wxTOP|wxLEFT|wxRIGHT|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	m_spinDays = new wxSpinCtrl(this, ID_SPINCTRL1, _T("20"), wxDefaultPosition, wxDefaultSize, 0, 10, 31, 20, _T("ID_SPINCTRL1"));
	m_spinDays->SetValue(_T("20"));
	StaticBoxSizer1->Add(m_spinDays, 1, wxTOP|wxLEFT|wxRIGHT|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	StaticText4 = new wxStaticText(this, ID_STATICTEXT4, _("Cost of one man-month:"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT4"));
	StaticBoxSizer1->Add(StaticText4, 0, wxTOP|wxLEFT|wxRIGHT|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	m_txtCost = new wxTextCtrl(this, ID_TEXTCTRL1, _("10000"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL1"));
	StaticBoxSizer1->Add(m_txtCost, 1, wxTOP|wxLEFT|wxRIGHT|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer1->Add(StaticBoxSizer1, 0, wxTOP|wxLEFT|wxRIGHT|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer2 = new wxBoxSizer(wxHORIZONTAL);
	Button1 = new wxButton(this, wxID_OK, _("&Ok"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("wxID_OK"));
	BoxSizer2->Add(Button1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	Button2 = new wxButton(this, wxID_CANCEL, _("&Cancel"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("wxID_CANCEL"));
	BoxSizer2->Add(Button2, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer1->Add(BoxSizer2, 0, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
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

    wxString strTemp;

    strTemp.Printf(_T("%d"), m_settingParam.m_nLinesPerMM);
    m_cmbLinesPerMM->SetValue(strTemp);

    strTemp.Printf(_T("%d"), m_settingParam.m_nDaysPerMM);
    m_spinDays->SetValue(strTemp);

    strTemp.Printf(_T("%d"), m_settingParam.m_nCostPerMM);
    m_txtCost->SetValue(strTemp);

}

void CntSettingDlg::SetSettingParam(SettingParam* pParam)
{
    m_settingParam.m_nCountingMethodType = pParam->m_nCountingMethodType;

    m_settingParam.m_nLinesPerMM    = pParam->m_nLinesPerMM;
    m_settingParam.m_nDaysPerMM     = pParam->m_nDaysPerMM;
    m_settingParam.m_nCostPerMM     = pParam->m_nCostPerMM;

}

void CntSettingDlg::GetSettingParam(SettingParam& param)
{
    //
    param.m_nCountingMethodType = m_settingParam.m_nCountingMethodType;

	unsigned long nTemp = 0;

	wxString strTemp = m_cmbLinesPerMM->GetValue();
	strTemp.ToULong(&nTemp, 10);
	param.m_nLinesPerMM = nTemp;

    param.m_nDaysPerMM = m_spinDays->GetValue(); //m_nDaysPerMM;

    strTemp = m_txtCost->GetValue();
    strTemp.ToULong(&nTemp, 10);
    param.m_nCostPerMM = nTemp;
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
