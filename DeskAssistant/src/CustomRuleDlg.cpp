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

    Create(parent, id, _("Custom Rule Dialog"), wxDefaultPosition, wxDefaultSize, wxDEFAULT_DIALOG_STYLE, _T("id"));
    BoxSizer1 = new wxBoxSizer(wxVERTICAL);
    wxString __wxRadioBoxChoices_1[2] =
    {
    _("by extend name"),
    _("by filename include")
    };
    m_rdbRuleType = new wxRadioBox(this, ID_RADIOBOX2, _("Select rule type"), wxDefaultPosition, wxDefaultSize, 2, __wxRadioBoxChoices_1, 1, wxRA_SPECIFY_ROWS, wxDefaultValidator, _T("ID_RADIOBOX2"));
    BoxSizer1->Add(m_rdbRuleType, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer2 = new wxBoxSizer(wxHORIZONTAL);
    StaticText1 = new wxStaticText(this, ID_STATICTEXT1, _("File extend name:"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT1"));
    BoxSizer2->Add(StaticText1, 1, wxTOP|wxLEFT|wxRIGHT|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    m_txtCondition = new wxTextCtrl(this, ID_TEXTCTRL1, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL1"));
    BoxSizer2->Add(m_txtCondition, 4, wxTOP|wxLEFT|wxRIGHT|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer1->Add(BoxSizer2, 0, wxLEFT|wxRIGHT|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer3 = new wxBoxSizer(wxHORIZONTAL);
    StaticText2 = new wxStaticText(this, ID_STATICTEXT2, _("Destination dir:"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT2"));
    BoxSizer3->Add(StaticText2, 1, wxTOP|wxLEFT|wxRIGHT|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    m_txtDestPath = new wxTextCtrl(this, ID_TEXTCTRL2, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL2"));
    BoxSizer3->Add(m_txtDestPath, 3, wxTOP|wxLEFT|wxRIGHT|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    Button3 = new wxButton(this, ID_BUTTON3, _("&Select..."), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON3"));
    BoxSizer3->Add(Button3, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer1->Add(BoxSizer3, 0, wxLEFT|wxRIGHT|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer4 = new wxBoxSizer(wxHORIZONTAL);
    m_btnOK = new wxButton(this, wxID_OK, _("&OK"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("wxID_OK"));
    BoxSizer4->Add(m_btnOK, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    Button2 = new wxButton(this, wxID_CANCEL, _("&Cancel"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("wxID_CANCEL"));
    BoxSizer4->Add(Button2, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer1->Add(BoxSizer4, 0, wxBOTTOM|wxLEFT|wxRIGHT|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    SetSizer(BoxSizer1);
    BoxSizer1->Fit(this);
    BoxSizer1->SetSizeHints(this);
    Center();

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
    switch (m_nMode)
    {
    case RuleModeNew:
    {

        break;
    }
    case RuleModeEdit:
    {
		m_rdbRuleType->Enable(false);
		m_txtCondition->SetValue(m_pRule->GetCondition());
        m_txtDestPath->SetValue(m_pRule->m_strBaseDestPath);
        break;
    }

    default:
    {
        break;
    }
    }




}

void CustomRuleDlg::OnBtnOKClick(wxCommandEvent& event)
{
	wxString strCondition = m_txtCondition->GetValue();
	strCondition.Trim();
	if(strCondition.IsEmpty())
	{
		wxMessageBox(_("Please input conditon."));
		return;
	}

	wxString strDestPath = m_txtDestPath->GetValue();
	strDestPath.Trim();
	if(strDestPath.IsEmpty())
	{
		wxMessageBox(_("Please select dest path."));
		return;
	}

	//m_pRule->SetType(m_rdbRuleType->GetValue());
    // Set ctrl value to m_pRule
    m_pRule->SetCondition(m_txtCondition->GetValue());
    m_pRule->SetDestPath(m_txtDestPath->GetValue());
    //
    EndModal(wxID_OK);
}
