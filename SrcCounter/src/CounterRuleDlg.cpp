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

CounterRuleDlg::CounterRuleDlg(wxWindow* parent, RuleMode nMode, wxWindowID id,const wxPoint& pos,const wxSize& size):
        m_nMode(nMode),
        m_pMapCounterRule(0),
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
    m_txtExtDesc->SetMaxLength(128);
    BoxSizer4->Add(m_txtExtDesc, 3, wxTOP|wxLEFT|wxRIGHT|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer1->Add(BoxSizer4, 1, wxLEFT|wxRIGHT|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer6 = new wxBoxSizer(wxHORIZONTAL);
    StaticText2 = new wxStaticText(this, ID_STATICTEXT2, _("&Source style:"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT2"));
    BoxSizer6->Add(StaticText2, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    m_cmbMethod = new wxComboBox(this, ID_COMBOBOX1, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, 0, wxCB_READONLY, wxDefaultValidator, _T("ID_COMBOBOX1"));
    m_cmbMethod->SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_INFOBK));
    BoxSizer6->Add(m_cmbMethod, 3, wxTOP|wxLEFT|wxRIGHT|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer1->Add(BoxSizer6, 0, wxLEFT|wxRIGHT|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer9 = new wxBoxSizer(wxHORIZONTAL);
    StaticText7 = new wxStaticText(this, ID_STATICTEXT7, _("Description:"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT7"));
    BoxSizer9->Add(StaticText7, 1, wxALL|wxALIGN_TOP|wxALIGN_CENTER_HORIZONTAL, 5);
    m_txtRuleDesc = new wxTextCtrl(this, ID_TEXTCTRL6, wxEmptyString, wxDefaultPosition, wxSize(0,48), wxTE_MULTILINE, wxDefaultValidator, _T("ID_TEXTCTRL6"));
    m_txtRuleDesc->SetMaxLength(128);
    m_txtRuleDesc->SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_INFOBK));
    BoxSizer9->Add(m_txtRuleDesc, 3, wxTOP|wxLEFT|wxRIGHT|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer1->Add(BoxSizer9, 0, wxLEFT|wxRIGHT|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer5 = new wxBoxSizer(wxHORIZONTAL);
    BoxSizer5->Add(-1,-1,0, wxLEFT|wxRIGHT|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    m_txtSLComm = new wxStaticText(this, ID_STATICTEXT4, _("Single line comment:"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT4"));
    BoxSizer5->Add(m_txtSLComm, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    m_txtSlgLnComm = new wxTextCtrl(this, ID_TEXTCTRL3, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL3"));
    m_txtSlgLnComm->SetMaxLength(4);
    m_txtSlgLnComm->SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_INFOBK));
    BoxSizer5->Add(m_txtSlgLnComm, 1, wxTOP|wxLEFT|wxRIGHT|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer1->Add(BoxSizer5, 0, wxLEFT|wxRIGHT|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer7 = new wxBoxSizer(wxHORIZONTAL);
    BoxSizer7->Add(-1,-1,0, wxLEFT|wxRIGHT|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticText5 = new wxStaticText(this, ID_STATICTEXT5, _("Multi-line comment begin:"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT5"));
    BoxSizer7->Add(StaticText5, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    m_txtMltLnCommBegin = new wxTextCtrl(this, ID_TEXTCTRL4, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL4"));
    m_txtMltLnCommBegin->SetMaxLength(4);
    m_txtMltLnCommBegin->SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_INFOBK));
    BoxSizer7->Add(m_txtMltLnCommBegin, 1, wxTOP|wxLEFT|wxRIGHT|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer1->Add(BoxSizer7, 0, wxLEFT|wxRIGHT|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer8 = new wxBoxSizer(wxHORIZONTAL);
    BoxSizer8->Add(-1,-1,0, wxLEFT|wxRIGHT|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticText6 = new wxStaticText(this, ID_STATICTEXT6, _("Multi-line comment endl:"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT6"));
    BoxSizer8->Add(StaticText6, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    m_txtMltLnCommEnd = new wxTextCtrl(this, ID_TEXTCTRL5, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL5"));
    m_txtMltLnCommEnd->SetMaxLength(4);
    m_txtMltLnCommEnd->SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_INFOBK));
    BoxSizer8->Add(m_txtMltLnCommEnd, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
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

    Connect(ID_COMBOBOX1,wxEVT_COMMAND_COMBOBOX_SELECTED,(wxObjectEventFunction)&CounterRuleDlg::OnCmbMethodSelect);
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
    // Append string to cmbMethod
    MapStrToCounterRule::iterator it;
    CounterRule* pRule = 0;
    for ( it = m_pMapCounterRule->begin(); it != m_pMapCounterRule->end(); ++it )
    {
        pRule = it->second;
        m_cmbMethod->AppendString(pRule->m_strType);
    }

	// Init new mode
    if (m_nMode == RuleModeNew)
    {
        m_cmbMethod->Select(0);
    }

	// Init edit mode
    if (m_nMode == RuleModeEdit)
    {
        m_txtExtName->SetValue(m_pFileExt->m_strName);
        m_txtExtName->Enable(false);
        m_txtExtDesc->SetValue(m_pFileExt->m_strDesc);

        m_cmbMethod->SetValue(m_pFileExt->m_strCounterType);

    }

	// Finally update rule ctrls
    updateRuleCtrls();
}

void CounterRuleDlg::OnCmbMethodSelect(wxCommandEvent& event)
{
    updateRuleCtrls();
}

void CounterRuleDlg::updateRuleCtrls()
{
    MapStrToCounterRule::iterator it;
    it = m_pMapCounterRule->find(m_cmbMethod->GetValue());

    CounterRule* pRule = 0;
    if (it != m_pMapCounterRule->end())
    { // Find instance in the pCount map
        pRule = it->second;
    }

    m_txtRuleDesc->SetValue(pRule->m_strDesc);
}

void CounterRuleDlg::OnBtnOKClick(wxCommandEvent& event)
{
	// Check input info
	wxString strExtDesc = m_txtExtDesc->GetValue();
	if(strExtDesc.IsEmpty())
	{
		wxMessageBox(_("Please input file extension description!"));
		return;
	}

	if(m_nMode == RuleModeNew)
	{
		wxString strExtName = m_txtExtName->GetValue();
		if(strExtName.IsEmpty())
		{
			wxMessageBox(_("Please input file extension!"));
			return;
		}

        m_pFileExt->m_strName = strExtName;
	}

    if (m_nMode == RuleModeEdit)
    {// m_txtExtName can not changed

    }

	m_pFileExt->m_strDesc = strExtDesc;
	m_pFileExt->m_strCounterType = m_cmbMethod->GetValue();

	//
    EndModal(wxID_OK);
}

void CounterRuleDlg::OnBtnCancelClick(wxCommandEvent& event)
{
    EndModal(wxID_CANCEL);
}
