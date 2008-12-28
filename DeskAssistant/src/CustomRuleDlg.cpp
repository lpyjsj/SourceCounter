#include "wx_pch.h"
#include "CustomRuleDlg.h"

#ifndef WX_PRECOMP
//(*InternalHeadersPCH(CustomRuleDlg)
#include <wx/intl.h>
#include <wx/string.h>
//*)
#endif
//(*InternalHeaders(CustomRuleDlg)
//*)

//(*IdInit(CustomRuleDlg)
const long CustomRuleDlg::ID_RADIOBOX2 = wxNewId();
const long CustomRuleDlg::ID_STATICTEXT1 = wxNewId();
const long CustomRuleDlg::ID_TEXTCTRL1 = wxNewId();
const long CustomRuleDlg::ID_STATICTEXT2 = wxNewId();
const long CustomRuleDlg::ID_TEXTCTRL2 = wxNewId();
const long CustomRuleDlg::ID_BUTTON3 = wxNewId();
//*)

BEGIN_EVENT_TABLE(CustomRuleDlg,wxDialog)
    //(*EventTable(CustomRuleDlg)
    //*)
END_EVENT_TABLE()

CustomRuleDlg::CustomRuleDlg(wxWindow* parent, RuleMode nMode,wxWindowID id):
        m_nMode(nMode),
        m_pRule(0)
{
    //(*Initialize(CustomRuleDlg)
    wxBoxSizer* BoxSizer4;
    wxBoxSizer* BoxSizer2;
    wxBoxSizer* BoxSizer1;
    wxBoxSizer* BoxSizer3;

    Create(parent, id, _("Customize Rule Dialog"), wxDefaultPosition, wxDefaultSize, wxDEFAULT_DIALOG_STYLE, _T("id"));
    BoxSizer1 = new wxBoxSizer(wxVERTICAL);
    wxString __wxRadioBoxChoices_1[2] =
    {
    _("by file extend name"),
    _("by file name include")
    };
    m_rdbRuleType = new wxRadioBox(this, ID_RADIOBOX2, _("Select rule type"), wxDefaultPosition, wxDefaultSize, 2, __wxRadioBoxChoices_1, 1, wxRA_SPECIFY_ROWS, wxDefaultValidator, _T("ID_RADIOBOX2"));
    BoxSizer1->Add(m_rdbRuleType, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer2 = new wxBoxSizer(wxHORIZONTAL);
    m_pLblCondition = new wxStaticText(this, ID_STATICTEXT1, _("Condition:"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT1"));
    BoxSizer2->Add(m_pLblCondition, 1, wxTOP|wxLEFT|wxRIGHT|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    m_txtCondition = new wxTextCtrl(this, ID_TEXTCTRL1, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL1"));
    BoxSizer2->Add(m_txtCondition, 4, wxTOP|wxLEFT|wxRIGHT|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer1->Add(BoxSizer2, 0, wxLEFT|wxRIGHT|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer3 = new wxBoxSizer(wxHORIZONTAL);
    StaticText2 = new wxStaticText(this, ID_STATICTEXT2, _("Destination directory:"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT2"));
    BoxSizer3->Add(StaticText2, 1, wxTOP|wxLEFT|wxRIGHT|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    m_txtDestPath = new wxTextCtrl(this, ID_TEXTCTRL2, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_READONLY, wxDefaultValidator, _T("ID_TEXTCTRL2"));
    BoxSizer3->Add(m_txtDestPath, 3, wxTOP|wxLEFT|wxRIGHT|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    m_btnSelDir = new wxButton(this, ID_BUTTON3, _("&Select..."), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON3"));
    BoxSizer3->Add(m_btnSelDir, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer1->Add(BoxSizer3, 0, wxLEFT|wxRIGHT|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer4 = new wxBoxSizer(wxHORIZONTAL);
    m_btnOK = new wxButton(this, wxID_OK, _("&OK"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("wxID_OK"));
    BoxSizer4->Add(m_btnOK, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    Button2 = new wxButton(this, wxID_CANCEL, _("&Cancel"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("wxID_CANCEL"));
    BoxSizer4->Add(Button2, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer1->Add(BoxSizer4, 0, wxBOTTOM|wxLEFT|wxRIGHT|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    SetSizer(BoxSizer1);
    m_dirDlg = new wxDirDialog(this, _("Select directory"), wxEmptyString, wxDD_DEFAULT_STYLE, wxDefaultPosition, wxDefaultSize, _T("wxDirDialog"));
    BoxSizer1->Fit(this);
    BoxSizer1->SetSizeHints(this);
    Center();

    Connect(ID_RADIOBOX2,wxEVT_COMMAND_RADIOBOX_SELECTED,(wxObjectEventFunction)&CustomRuleDlg::OnRdbRuleTypeSelect);
    Connect(ID_BUTTON3,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&CustomRuleDlg::OnBtnSelDirClick);
    Connect(wxID_OK,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&CustomRuleDlg::OnBtnOKClick);
    Connect(wxID_ANY,wxEVT_INIT_DIALOG,(wxObjectEventFunction)&CustomRuleDlg::OnInit);
    //*)
}

CustomRuleDlg::~CustomRuleDlg()
{
    //(*Destroy(CustomRuleDlg)
    //*)
}

void CustomRuleDlg::OnInit(wxInitDialogEvent& event)
{
    if (m_nMode == RuleModeNew)
    {// New rule mode
        // Do nothing
    }
    else
    {// Edit rule mode
        m_rdbRuleType->SetSelection(m_pRule->GetRuleType() - 1);
        m_rdbRuleType->Enable(false);
        m_txtCondition->SetValue(m_pRule->GetCondition());
        m_txtDestPath->SetValue(m_pRule->m_strBaseDestPath);
    }
}

void CustomRuleDlg::OnBtnOKClick(wxCommandEvent& event)
{
    wxString strCondition = m_txtCondition->GetValue();
    strCondition.Trim();
    if (strCondition.IsEmpty())
    {
        wxMessageBox(_("Please input categorization condition."));
        return;
    }

    wxString strDestPath = m_txtDestPath->GetValue();
    strDestPath.Trim();
    if (strDestPath.IsEmpty())
    {
        wxMessageBox(_("Please select destination directory."));
        return;
    }

    if (m_nMode == RuleModeNew)
    {// Collect info and set to m_ruleInfo object
        m_ruleInfo.m_nType = m_rdbRuleType->GetSelection() + 1; // Rule type is 1 base.
        m_ruleInfo.m_strCondition = strCondition;
        m_ruleInfo.m_strDestPath = strDestPath;
    }
    else
    {
        // Set ctrl value to m_pRule
        m_pRule->SetCondition(strCondition);
        m_pRule->SetDestPath(strDestPath);
    }

    //
    EndModal(wxID_OK);
}

void CustomRuleDlg::GetRuleInfo(RuleInfo& info)
{
    info.m_nIndex 		= m_ruleInfo.m_nIndex;
    info.m_nType		= m_ruleInfo.m_nType;
    info.m_bSelected	= m_ruleInfo.m_bSelected;

    info.m_strCondition		= m_ruleInfo.m_strCondition;
    info.m_strDestPath		= m_ruleInfo.m_strDestPath;
}

void CustomRuleDlg::OnBtnSelDirClick(wxCommandEvent& event)
{
    if ( wxID_OK == m_dirDlg->ShowModal())
    {
        //
        wxString strPath = m_dirDlg->GetPath();
        m_txtDestPath->SetValue(strPath);
    }
}

void CustomRuleDlg::OnRdbRuleTypeSelect(wxCommandEvent& event)
{
	//
	int nSel = m_rdbRuleType->GetSelection();
	if(nSel == 0)
	{
		m_pLblCondition->SetLabel(_("File extend name:"));
	}
	else if(1 == nSel)
	{
		m_pLblCondition->SetLabel(_("Partion of file name:"));
	}
}
