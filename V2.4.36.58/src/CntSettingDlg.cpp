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
const long CntSettingDlg::ID_STATICTEXT5 = wxNewId();
const long CntSettingDlg::ID_SPINCTRL2 = wxNewId();
const long CntSettingDlg::ID_STATICTEXT6 = wxNewId();
const long CntSettingDlg::ID_STATICTEXT8 = wxNewId();
const long CntSettingDlg::ID_SPINCTRL3 = wxNewId();
const long CntSettingDlg::ID_STATICTEXT7 = wxNewId();
const long CntSettingDlg::ID_STATICTEXT11 = wxNewId();
const long CntSettingDlg::ID_SPINCTRL4 = wxNewId();
const long CntSettingDlg::ID_STATICTEXT13 = wxNewId();
const long CntSettingDlg::ID_STATICTEXT12 = wxNewId();
const long CntSettingDlg::ID_SPINCTRL5 = wxNewId();
const long CntSettingDlg::ID_STATICTEXT14 = wxNewId();
const long CntSettingDlg::ID_STATICTEXT2 = wxNewId();
const long CntSettingDlg::ID_COMBOBOX1 = wxNewId();
const long CntSettingDlg::ID_STATICTEXT1 = wxNewId();
const long CntSettingDlg::ID_STATICTEXT3 = wxNewId();
const long CntSettingDlg::ID_SPINCTRL1 = wxNewId();
const long CntSettingDlg::ID_STATICTEXT10 = wxNewId();
const long CntSettingDlg::ID_STATICTEXT4 = wxNewId();
const long CntSettingDlg::ID_TEXTCTRL1 = wxNewId();
const long CntSettingDlg::ID_STATICTEXT9 = wxNewId();
//*)

SettingParam CntSettingDlg::m_settingParam;

BEGIN_EVENT_TABLE(CntSettingDlg,wxDialog)
	//(*EventTable(CntSettingDlg)
	//*)
END_EVENT_TABLE()

//
CntSettingDlg::CntSettingDlg(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size)
{
	//(*Initialize(CntSettingDlg)
	wxBoxSizer* BoxSizer4;
	wxStaticBoxSizer* StaticBoxSizer2;
	wxBoxSizer* BoxSizer6;
	wxBoxSizer* BoxSizer5;
	wxBoxSizer* BoxSizer7;
	wxBoxSizer* BoxSizer8;
	wxBoxSizer* BoxSizer2;
	wxBoxSizer* BoxSizer1;
	wxBoxSizer* BoxSizer9;
	wxStaticBoxSizer* StaticBoxSizer1;
	wxBoxSizer* BoxSizer3;
	
	Create(parent, wxID_ANY, _("More settings dialog"), wxDefaultPosition, wxDefaultSize, wxDEFAULT_DIALOG_STYLE, _T("wxID_ANY"));
	BoxSizer1 = new wxBoxSizer(wxVERTICAL);
	wxString __wxRadioBoxChoices_1[3] = 
	{
	_("Code lines +1, comment lines +1"),
	_("Code lines +1, comment lines +0"),
	_("Code lines +0, comment lines +1")
	};
	m_rdbCountingMethod = new wxRadioBox(this, ID_RADIOBOX1, _("When code and comment in same line, please select one counting method"), wxDefaultPosition, wxDefaultSize, 3, __wxRadioBoxChoices_1, 1, 0, wxDefaultValidator, _T("ID_RADIOBOX1"));
	BoxSizer1->Add(m_rdbCountingMethod, 0, wxTOP|wxLEFT|wxRIGHT|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticBoxSizer2 = new wxStaticBoxSizer(wxVERTICAL, this, _("Quality index criteria setting"));
	BoxSizer6 = new wxBoxSizer(wxHORIZONTAL);
	StaticText5 = new wxStaticText(this, ID_STATICTEXT5, _("Unit testing case density:"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT5"));
	BoxSizer6->Add(StaticText5, 1, wxTOP|wxLEFT|wxRIGHT|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	m_spinUtCaseDensity = new wxSpinCtrl(this, ID_SPINCTRL2, _T("50"), wxDefaultPosition, wxDefaultSize, 0, 1, 150, 50, _T("ID_SPINCTRL2"));
	m_spinUtCaseDensity->SetValue(_T("50"));
	BoxSizer6->Add(m_spinUtCaseDensity, 0, wxTOP|wxLEFT|wxRIGHT|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticText6 = new wxStaticText(this, ID_STATICTEXT6, _("Cases/KLOC"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT6"));
	BoxSizer6->Add(StaticText6, 1, wxTOP|wxRIGHT|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticBoxSizer2->Add(BoxSizer6, 1, wxLEFT|wxRIGHT|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer7 = new wxBoxSizer(wxHORIZONTAL);
	StaticText8 = new wxStaticText(this, ID_STATICTEXT8, _("Unit testing defect density:"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT8"));
	BoxSizer7->Add(StaticText8, 1, wxTOP|wxLEFT|wxRIGHT|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	m_spinUtDefectDensity = new wxSpinCtrl(this, ID_SPINCTRL3, _T("10"), wxDefaultPosition, wxDefaultSize, 0, 1, 20, 10, _T("ID_SPINCTRL3"));
	m_spinUtDefectDensity->SetValue(_T("10"));
	BoxSizer7->Add(m_spinUtDefectDensity, 0, wxTOP|wxLEFT|wxRIGHT|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticText7 = new wxStaticText(this, ID_STATICTEXT7, _("Defects/KLOC"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT7"));
	BoxSizer7->Add(StaticText7, 1, wxTOP|wxRIGHT|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticBoxSizer2->Add(BoxSizer7, 1, wxLEFT|wxRIGHT|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer9 = new wxBoxSizer(wxHORIZONTAL);
	StaticText11 = new wxStaticText(this, ID_STATICTEXT11, _("Integration testing case density:"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT11"));
	BoxSizer9->Add(StaticText11, 1, wxTOP|wxLEFT|wxRIGHT|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	m_spinItCaseDensity = new wxSpinCtrl(this, ID_SPINCTRL4, _T("20"), wxDefaultPosition, wxDefaultSize, 0, 1, 100, 20, _T("ID_SPINCTRL4"));
	m_spinItCaseDensity->SetValue(_T("20"));
	BoxSizer9->Add(m_spinItCaseDensity, 0, wxTOP|wxLEFT|wxRIGHT|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticText13 = new wxStaticText(this, ID_STATICTEXT13, _("Cases/KLOC"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT13"));
	BoxSizer9->Add(StaticText13, 1, wxTOP|wxRIGHT|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticBoxSizer2->Add(BoxSizer9, 1, wxLEFT|wxRIGHT|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer8 = new wxBoxSizer(wxHORIZONTAL);
	StaticText12 = new wxStaticText(this, ID_STATICTEXT12, _("Integration testing defect density:"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT12"));
	BoxSizer8->Add(StaticText12, 1, wxTOP|wxLEFT|wxRIGHT|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	m_spinItDefectDensity = new wxSpinCtrl(this, ID_SPINCTRL5, _T("2"), wxDefaultPosition, wxDefaultSize, 0, 1, 10, 2, _T("ID_SPINCTRL5"));
	m_spinItDefectDensity->SetValue(_T("2"));
	BoxSizer8->Add(m_spinItDefectDensity, 0, wxTOP|wxLEFT|wxRIGHT|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticText14 = new wxStaticText(this, ID_STATICTEXT14, _("Defects/KLOC"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT14"));
	BoxSizer8->Add(StaticText14, 1, wxTOP|wxRIGHT|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticBoxSizer2->Add(BoxSizer8, 1, wxLEFT|wxRIGHT|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer1->Add(StaticBoxSizer2, 0, wxTOP|wxLEFT|wxRIGHT|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticBoxSizer1 = new wxStaticBoxSizer(wxVERTICAL, this, _("Effort and cost analysis setting"));
	BoxSizer3 = new wxBoxSizer(wxHORIZONTAL);
	StaticText2 = new wxStaticText(this, ID_STATICTEXT2, _("Coding production:"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT2"));
	BoxSizer3->Add(StaticText2, 0, wxTOP|wxLEFT|wxRIGHT|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	m_cmbLinesPerMM = new wxComboBox(this, ID_COMBOBOX1, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, 0, 0, wxDefaultValidator, _T("ID_COMBOBOX1"));
	m_cmbLinesPerMM->Append(_("6000"));
	m_cmbLinesPerMM->SetSelection( m_cmbLinesPerMM->Append(_("4000")) );
	m_cmbLinesPerMM->Append(_("3000"));
	m_cmbLinesPerMM->Append(_("2000"));
	BoxSizer3->Add(m_cmbLinesPerMM, 0, wxTOP|wxLEFT|wxRIGHT|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticText1 = new wxStaticText(this, ID_STATICTEXT1, _("lines per man-month"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT1"));
	BoxSizer3->Add(StaticText1, 0, wxTOP|wxRIGHT|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticBoxSizer1->Add(BoxSizer3, 1, wxLEFT|wxRIGHT|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer4 = new wxBoxSizer(wxHORIZONTAL);
	StaticText3 = new wxStaticText(this, ID_STATICTEXT3, _("Man-days of one man-month:"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT3"));
	BoxSizer4->Add(StaticText3, 0, wxTOP|wxLEFT|wxRIGHT|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	m_spinDays = new wxSpinCtrl(this, ID_SPINCTRL1, _T("20"), wxDefaultPosition, wxDefaultSize, 0, 10, 31, 20, _T("ID_SPINCTRL1"));
	m_spinDays->SetValue(_T("20"));
	BoxSizer4->Add(m_spinDays, 0, wxTOP|wxLEFT|wxRIGHT|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticText10 = new wxStaticText(this, ID_STATICTEXT10, _("days"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT10"));
	BoxSizer4->Add(StaticText10, 0, wxTOP|wxRIGHT|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticBoxSizer1->Add(BoxSizer4, 1, wxLEFT|wxRIGHT|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer5 = new wxBoxSizer(wxHORIZONTAL);
	StaticText4 = new wxStaticText(this, ID_STATICTEXT4, _("Cost of one man-month:"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT4"));
	BoxSizer5->Add(StaticText4, 0, wxTOP|wxLEFT|wxRIGHT|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	m_txtCost = new wxTextCtrl(this, ID_TEXTCTRL1, _("10000"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL1"));
	BoxSizer5->Add(m_txtCost, 0, wxTOP|wxLEFT|wxRIGHT|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticText9 = new wxStaticText(this, ID_STATICTEXT9, _("$"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT9"));
	BoxSizer5->Add(StaticText9, 0, wxTOP|wxRIGHT|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticBoxSizer1->Add(BoxSizer5, 1, wxLEFT|wxRIGHT|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer1->Add(StaticBoxSizer1, 0, wxTOP|wxLEFT|wxRIGHT|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer2 = new wxBoxSizer(wxHORIZONTAL);
	Button1 = new wxButton(this, wxID_OK, _("&OK"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("wxID_OK"));
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

void CntSettingDlg::SetSettingParam(SettingParam* pParam) //In
{
    m_settingParam.m_nCountingMethodType = pParam->m_nCountingMethodType;

	// Boom: Add UT and IT density param on 2009-3-3
	m_settingParam.m_nUtCaseDensity		= pParam->m_nUtCaseDensity;
	m_settingParam.m_nUtDefectDensity	= pParam->m_nUtDefectDensity;
	m_settingParam.m_nItCaseDensity		= pParam->m_nItCaseDensity;
	m_settingParam.m_nItDefectDensity	= pParam->m_nItDefectDensity;

    m_settingParam.m_nLinesPerMM    = pParam->m_nLinesPerMM;
    m_settingParam.m_nDaysPerMM     = pParam->m_nDaysPerMM;
    m_settingParam.m_nCostPerMM     = pParam->m_nCostPerMM;
}

void CntSettingDlg::OnInit(wxInitDialogEvent& event)
{
	// Counting method
    m_rdbCountingMethod->SetSelection(m_settingParam.m_nCountingMethodType);

    wxString strTemp;

	// Boom: add UT and IT density on 2009-3-3
	strTemp.Printf(_T("%d"), m_settingParam.m_nUtCaseDensity);
	m_spinUtCaseDensity->SetValue(strTemp);
	strTemp.Printf(_T("%d"), m_settingParam.m_nUtDefectDensity);
	m_spinUtDefectDensity->SetValue(strTemp);
	strTemp.Printf(_T("%d"), m_settingParam.m_nItCaseDensity);
	m_spinItCaseDensity->SetValue(strTemp);
	strTemp.Printf(_T("%d"), m_settingParam.m_nItDefectDensity);
	m_spinItDefectDensity->SetValue(strTemp);

	// Effort and Man-Month setting param
    strTemp.Printf(_T("%d"), m_settingParam.m_nLinesPerMM);
    m_cmbLinesPerMM->SetValue(strTemp);
    strTemp.Printf(_T("%d"), m_settingParam.m_nDaysPerMM);
    m_spinDays->SetValue(strTemp);
    strTemp.Printf(_T("%d"), m_settingParam.m_nCostPerMM);
    m_txtCost->SetValue(strTemp);
}

void CntSettingDlg::GetSettingParam(SettingParam& param) //Out
{
    //
    param.m_nCountingMethodType = m_settingParam.m_nCountingMethodType;

	// Boom: Add get UT and IT density code on 2009-3-3
	param.m_nUtCaseDensity 		= m_spinUtCaseDensity->GetValue();
	param.m_nUtDefectDensity	= m_spinUtDefectDensity->GetValue();
	param.m_nItCaseDensity 		= m_spinItCaseDensity->GetValue();
	param.m_nItDefectDensity	= m_spinItDefectDensity->GetValue();

	//
	unsigned long nTemp = 0;
	wxString strTemp;

	strTemp = m_cmbLinesPerMM->GetValue();
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
