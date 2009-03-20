
#ifndef WX_PRECOMP
//(*InternalHeadersPCH(SrcTypeSelDlg)
#include <wx/intl.h>
#include <wx/string.h>
//*)
#endif

#include "wx_pch.h"
#include "SrcTypeSelDlg.h"
#include "CounterRuleDlg.h"

//(*InternalHeaders(SrcTypeSelDlg)
//*)

/* Source types number */
const int N_SRC_TYPE_NUM = 28;

/* Source type */
const wxChar* CSZ_SRC_TYPES[N_SRC_TYPE_NUM] =
{
    // Cpp related
    _T(".cpp"), // 1
    _T(".cxx"), // 2
    _T(".cc"),
    _T(".c"),	// 4
    _T(".hpp"),	// 5
    _T(".hh"),
    _T(".h"),
    _T(".rc"),
    _T(".tlh"), // 9
    _T(".tli"),	// 10
    _T(".java"),
    _T(".cs"),

    // Script related
    _T(".aspx"),    // 13
    _T(".asp"),     // 14
    _T(".php"),
    _T(".php3"),
    _T(".jsp"),

    // Text related
    _T(".htm"),		// 18
    _T(".html"),	// 19

    // Basic related
    _T(".vb"),		// 20
    _T(".bas"),
    _T(".frm"),
    _T(".ctl"),
    _T(".cls"),		// 24

    // Pasic related
    _T(".pas"), // 25
    _T(".dfm"),

    // TODO: SqlCounter
    _T(".sql"), // 27

    _T(".txt"), // 28

};

//(*IdInit(SrcTypeSelDlg)
const long SrcTypeSelDlg::ID_STATICTEXT1 = wxNewId();
const long SrcTypeSelDlg::ID_CHECKLISTBOX1 = wxNewId();
const long SrcTypeSelDlg::ID_CHECKBOX1 = wxNewId();
const long SrcTypeSelDlg::ID_BUTTON1 = wxNewId();
const long SrcTypeSelDlg::ID_BUTTON2 = wxNewId();
const long SrcTypeSelDlg::ID_BUTTON3 = wxNewId();
const long SrcTypeSelDlg::ID_STATICLINE1 = wxNewId();
//*)

BEGIN_EVENT_TABLE(SrcTypeSelDlg,wxDialog)
    //(*EventTable(SrcTypeSelDlg)
    //*)
END_EVENT_TABLE()

SrcTypeSelDlg::SrcTypeSelDlg(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size)
{
    //(*Initialize(SrcTypeSelDlg)
    wxBoxSizer* BoxSizer2;
    wxBoxSizer* BoxSizer1;
    wxBoxSizer* BoxSizer3;

    Create(parent, wxID_ANY, _("Select types dialog"), wxDefaultPosition, wxDefaultSize, wxDEFAULT_DIALOG_STYLE, _T("wxID_ANY"));
    BoxSizer1 = new wxBoxSizer(wxVERTICAL);
    StaticText1 = new wxStaticText(this, ID_STATICTEXT1, _("&Select source file types for counting:"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT1"));
    BoxSizer1->Add(StaticText1, 0, wxTOP|wxLEFT|wxRIGHT|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    m_lbxSrcTypes = new wxCheckListBox(this, ID_CHECKLISTBOX1, wxDefaultPosition, wxSize(180,200), 0, 0, wxLB_HSCROLL, wxDefaultValidator, _T("ID_CHECKLISTBOX1"));
    BoxSizer1->Add(m_lbxSrcTypes, 0, wxTOP|wxLEFT|wxRIGHT|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer3 = new wxBoxSizer(wxHORIZONTAL);
    m_ckbSelAll = new wxCheckBox(this, ID_CHECKBOX1, _("&Select all file types"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_CHECKBOX1"));
    m_ckbSelAll->SetValue(false);
    BoxSizer3->Add(m_ckbSelAll, 0, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer3->Add(-1,-1,1, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    m_btnAdd = new wxButton(this, ID_BUTTON1, _("&Add"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON1"));
    BoxSizer3->Add(m_btnAdd, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    m_btnEdit = new wxButton(this, ID_BUTTON2, _("&Edit"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON2"));
    m_btnEdit->Disable();
    BoxSizer3->Add(m_btnEdit, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    m_btnDel = new wxButton(this, ID_BUTTON3, _("&Delete"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON3"));
    m_btnDel->Disable();
    BoxSizer3->Add(m_btnDel, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer1->Add(BoxSizer3, 0, wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticLine1 = new wxStaticLine(this, ID_STATICLINE1, wxDefaultPosition, wxSize(10,-1), wxLI_HORIZONTAL, _T("ID_STATICLINE1"));
    BoxSizer1->Add(StaticLine1, 0, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer2 = new wxBoxSizer(wxHORIZONTAL);
    m_btnOk = new wxButton(this, wxID_OK, _("&OK"), wxDefaultPosition, wxSize(-1,-1), 0, wxDefaultValidator, _T("wxID_OK"));
    BoxSizer2->Add(m_btnOk, 2, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    m_btnCancel = new wxButton(this, wxID_CANCEL, _("&Cancel"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("wxID_CANCEL"));
    BoxSizer2->Add(m_btnCancel, 2, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer1->Add(BoxSizer2, 0, wxBOTTOM|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    SetSizer(BoxSizer1);
    BoxSizer1->Fit(this);
    BoxSizer1->SetSizeHints(this);
    Center();

    Connect(ID_CHECKLISTBOX1,wxEVT_COMMAND_LISTBOX_SELECTED,(wxObjectEventFunction)&SrcTypeSelDlg::OnLbxSrcTypesSelect);
    Connect(ID_CHECKBOX1,wxEVT_COMMAND_CHECKBOX_CLICKED,(wxObjectEventFunction)&SrcTypeSelDlg::Onm_ckbSelAllClick);
    Connect(ID_BUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&SrcTypeSelDlg::OnBtnAddClick);
    Connect(ID_BUTTON2,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&SrcTypeSelDlg::OnBtnEditClick);
    Connect(ID_BUTTON3,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&SrcTypeSelDlg::OnBtnDelClick);
    Connect(wxID_OK,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&SrcTypeSelDlg::OnBtnOkClick);
    Connect(wxID_CANCEL,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&SrcTypeSelDlg::OnBtnCancelClick);
    Connect(wxID_ANY,wxEVT_INIT_DIALOG,(wxObjectEventFunction)&SrcTypeSelDlg::OnInit);
    //*)
}

SrcTypeSelDlg::~SrcTypeSelDlg()
{
    //(*Destroy(SrcTypeSelDlg)
    //*)
}

void SrcTypeSelDlg::OnInit(wxInitDialogEvent& event)
{
    //
//    for (int i = 0; i < N_SRC_TYPE_NUM; i++)
//    {
//        m_lbxSrcTypes->Append(CSZ_SRC_TYPES[i]);
//    }

	updateSrcTypeLbx();
}

void SrcTypeSelDlg::updateSrcTypeLbx()
{
	int nCnt = m_lbxSrcTypes->GetCount();
	if (nCnt > 0)
		m_lbxSrcTypes->Clear();

    MapStrToCounterRule::iterator it;
    CounterRule* pRule = 0;
    MapStrToFileExtension::iterator itFileExt;
    FileExtension* pFileExt = 0;
    for ( it = m_pMapRule->begin(); it != m_pMapRule->end(); ++it )
    {
        pRule = it->second;

        if (pRule)
        {
            for ( itFileExt = pRule->m_mapStrToFileExtension.begin(); itFileExt != pRule->m_mapStrToFileExtension.end(); ++itFileExt)
            {
                pFileExt = itFileExt->second;
                m_lbxSrcTypes->Append(pFileExt->m_strName + _T(" - ") + pFileExt->m_strDesc + _T(" => ") + pFileExt->m_strCounterType);
            }
        }
    }
}

void SrcTypeSelDlg::SetSrcTypes(wxString strSrcTypes)
{
    m_strSrcTypes = strSrcTypes;
}

void SrcTypeSelDlg::OnBtnOkClick(wxCommandEvent& event)
{
    // Get checked item list
    int nNum = m_lbxSrcTypes->GetCount();

    wxString strTemp;
    for (int i = 0; i < nNum; i++)
    {
        //
        if (m_lbxSrcTypes->IsChecked(i))
        {
            strTemp = m_lbxSrcTypes->GetString(i);
            int index = strTemp.Find(_T('-'));
            strTemp = strTemp.Left(index - 1); // .cpp - : .cpp
            // strcpy();
            m_strSrcTypes =  m_strSrcTypes + strTemp + _T(";");
        }
    }

    EndModal(wxID_OK);
}

void SrcTypeSelDlg::OnBtnCancelClick(wxCommandEvent& event)
{
    EndModal(wxID_CANCEL);
}

void SrcTypeSelDlg::Onm_ckbSelAllClick(wxCommandEvent& event)
{
    bool bChecked = m_ckbSelAll->IsChecked();
    int nNum = m_lbxSrcTypes->GetCount();

    for (int i = 0; i < nNum; i++)
    {
        m_lbxSrcTypes->Check(i, bChecked);
    }
}

void SrcTypeSelDlg::OnLbxSrcTypesSelect(wxCommandEvent& event)
{
    updateButtons();
}

void SrcTypeSelDlg::updateButtons()
{
    bool bEnable = false;
    if ( wxNOT_FOUND != m_lbxSrcTypes->GetSelection())
    {
        bEnable = true;
    }

    m_btnEdit->Enable(bEnable);
    m_btnDel->Enable(bEnable);
}

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////

void SrcTypeSelDlg::OnBtnAddClick(wxCommandEvent& event)
{
    CounterRuleDlg dlg(this);
    dlg.ShowModal();
}

void SrcTypeSelDlg::OnBtnEditClick(wxCommandEvent& event)
{
    // Get selected rule
    int nNum = m_lbxSrcTypes->GetCount();

    wxString strTemp;
    for (int i = 0; i < nNum; i++)
    {
        //
        if (m_lbxSrcTypes->IsSelected(i))
        {
            strTemp = m_lbxSrcTypes->GetString(i);
            int index = strTemp.Find(_T('-'));
            strTemp = strTemp.Left(index - 1); // .cpp - : .cpp
        }
    }

    // Find rule object in map
    MapStrToCounterRule::iterator it;
    CounterRule* pRule = 0;
    MapStrToFileExtension::iterator itFileExt;
    FileExtension* pFileExt = 0;
    bool bFound = false;
    for ( it = m_pMapRule->begin(); it != m_pMapRule->end(); ++it )
    {
        pRule = it->second;

        if (pRule)
        {
            for ( itFileExt = pRule->m_mapStrToFileExtension.begin(); itFileExt != pRule->m_mapStrToFileExtension.end(); ++itFileExt)
            {
                pFileExt = itFileExt->second;
                if (strTemp.CmpNoCase( pFileExt->m_strName) == 0 )
                {
                	bFound = true;
                    break;
                }
            }
        }

        if(bFound)
			break;
    }

    //
    if (pFileExt)
    {
        CounterRuleDlg dlg(this);
        dlg.SetRuleData(pFileExt);

        if (wxID_OK ==dlg.ShowModal())
        {// Refresh listbox content
			updateSrcTypeLbx();
        }

    }

}

void SrcTypeSelDlg::OnBtnDelClick(wxCommandEvent& event)
{
}
