/**
 * Main dialog
 */

#ifndef WX_PRECOMP
//(*InternalHeadersPCH(MainDlg)
#include <wx/intl.h>
#include <wx/string.h>
//*)
#endif
//(*InternalHeaders(MainDlg)
#include <wx/bitmap.h>
#include <wx/image.h>
//*)

#include <wx/config.h>
#include <wx/msgdlg.h>
#include <wx/filename.h>
#include <wx/file.h>
#include <wx/config.h>

#include "wx_pch.h"
#include "wx/chooselang.h"
#include "Rule.h"

#include "MainDlg.h"
#include "AboutDlg.h"
#include "CustomRuleDlg.h"


///////////////////////////////////////////////////////////////////////

//(*IdInit(MainDlg)
const long MainDlg::ID_STATICBITMAP1 = wxNewId();
const long MainDlg::ID_STATICTEXT1 = wxNewId();
const long MainDlg::ID_BUTTON1 = wxNewId();
const long MainDlg::ID_BUTTON2 = wxNewId();
const long MainDlg::ID_BUTTON6 = wxNewId();
const long MainDlg::ID_BUTTON8 = wxNewId();
const long MainDlg::ID_BUTTON9 = wxNewId();
const long MainDlg::ID_CHECKLISTBOX1 = wxNewId();
const long MainDlg::ID_RADIOBOX1 = wxNewId();
const long MainDlg::ID_BUTTON7 = wxNewId();
const long MainDlg::ID_BUTTON4 = wxNewId();
const long MainDlg::ID_BUTTON5 = wxNewId();
const long MainDlg::ID_LISTCTRL1 = wxNewId();
const long MainDlg::ID_LISTCTRL2 = wxNewId();
const long MainDlg::ID_NOTEBOOK1 = wxNewId();
const long MainDlg::ID_BUTTON3 = wxNewId();
const long MainDlg::ID_BUTTON10 = wxNewId();
//*)

///////////////////////////////////////////////////////////////////////

enum NBaseRuleType
{
    NBaseRuleTypeTime = 0,			///< Categorize by file modification time
    NBaseRuleTypeNone,				///< None rule
};

const int N_COL_NUM = 3;	///< Result listctrl column number
/** Result listctrl column names */
const wxString CSZ_COL_NAMES[] =
{
	_("Status"),
    _("Source directory"),
    _("Destination directory"),

};
const int N_COL_WIDTH[] = { 80, 340, 340 };

/** Folder size listctrl */
const int N_FOLDER_SIZE_LC_COL_NUM = 2;
const wxString CSZ_FOLDER_SIZE_LC_COL_NAMES[] =
{
    _("Folder"),
    _("Size(KB)"),
};
const int N_FOLDER_SIZE_LC_COL_WIDTH[] = { 480, 80 };

const wxChar* CSZ_DESKTOP_KEY_NAME = _T("Desktop");   ///<
/** Desktop register path */
const wxString CSZ_DESKTOP_KEY_PATH =
    _T("HKEY_CURRENT_USER\\Software\\Microsoft\\Windows\\CurrentVersion\\Explorer\\Shell Folders");


const wxString CSZ_TODAY = _("___Today");
const wxString CSZ_YESTERDAY = _("___Yesterday");

///////////////////////////////////////////////////////////////////////

BEGIN_EVENT_TABLE(MainDlg,wxDialog)
    //(*EventTable(MainDlg)
    //*)
END_EVENT_TABLE()

MainDlg::MainDlg(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size)
{


    //(*Initialize(MainDlg)
    wxBoxSizer* BoxSizer4;
    wxBoxSizer* BoxSizer6;
    wxBoxSizer* BoxSizer5;
    wxBoxSizer* BoxSizer2;
    wxBoxSizer* BoxSizer1;
    wxStaticBoxSizer* StaticBoxSizer1;
    wxBoxSizer* BoxSizer3;
    
    Create(parent, wxID_ANY, _("Desktop Assistant"), wxDefaultPosition, wxDefaultSize, wxDEFAULT_DIALOG_STYLE|wxRESIZE_BORDER|wxMAXIMIZE_BOX|wxMINIMIZE_BOX, _T("wxID_ANY"));
    BoxSizer1 = new wxBoxSizer(wxVERTICAL);
    BoxSizer5 = new wxBoxSizer(wxHORIZONTAL);
    StaticBitmap1 = new wxStaticBitmap(this, ID_STATICBITMAP1, wxBitmap(wxImage(_T("img\\DesktopAssistant.ico"))), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICBITMAP1"));
    BoxSizer5->Add(StaticBitmap1, 0, wxTOP|wxLEFT|wxRIGHT|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    StaticText1 = new wxStaticText(this, ID_STATICTEXT1, _("Desktop Assistant is a tool for Desktop file categorization.\nThis tool can categorize files to folders by using the rule defined beforehand. \nThe folders that stores the files is automatically created."), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT1"));
    BoxSizer5->Add(StaticText1, 1, wxTOP|wxLEFT|wxRIGHT|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer1->Add(BoxSizer5, 0, wxTOP|wxLEFT|wxRIGHT|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticBoxSizer1 = new wxStaticBoxSizer(wxVERTICAL, this, _("Select customize categorization rules"));
    BoxSizer3 = new wxBoxSizer(wxHORIZONTAL);
    m_btnNew = new wxButton(this, ID_BUTTON1, _("&New..."), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON1"));
    BoxSizer3->Add(m_btnNew, 0, wxTOP|wxLEFT|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    m_btnEdit = new wxButton(this, ID_BUTTON2, _("&Edit..."), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON2"));
    m_btnEdit->Disable();
    BoxSizer3->Add(m_btnEdit, 0, wxTOP|wxLEFT|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    m_btnDelete = new wxButton(this, ID_BUTTON6, _("&Delete"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON6"));
    m_btnDelete->Disable();
    BoxSizer3->Add(m_btnDelete, 0, wxTOP|wxLEFT|wxRIGHT|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    m_btnUp = new wxButton(this, ID_BUTTON8, _("&Up"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON8"));
    m_btnUp->Disable();
    BoxSizer3->Add(m_btnUp, 1, wxTOP|wxLEFT|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    m_btnDown = new wxButton(this, ID_BUTTON9, _("Dow&n"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON9"));
    m_btnDown->Disable();
    BoxSizer3->Add(m_btnDown, 1, wxTOP|wxLEFT|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer3->Add(-1,-1,1, wxTOP|wxLEFT|wxRIGHT|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer3->Add(-1,-1,1, wxTOP|wxLEFT|wxRIGHT|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticBoxSizer1->Add(BoxSizer3, 0, wxBOTTOM|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 2);
    m_pLbxCustRules = new wxCheckListBox(this, ID_CHECKLISTBOX1, wxDefaultPosition, wxSize(-1,80), 0, 0, wxLB_SINGLE|wxLB_NEEDED_SB, wxDefaultValidator, _T("ID_CHECKLISTBOX1"));
    StaticBoxSizer1->Add(m_pLbxCustRules, 0, wxBOTTOM|wxLEFT|wxRIGHT|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer1->Add(StaticBoxSizer1, 0, wxTOP|wxLEFT|wxRIGHT|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    wxString __wxRadioBoxChoices_1[2] = 
    {
    _("By file modified time"),
    _("None(Do nothing)")
    };
    m_pRbxBaseRules = new wxRadioBox(this, ID_RADIOBOX1, _("Select base categorization rules"), wxDefaultPosition, wxDefaultSize, 2, __wxRadioBoxChoices_1, 1, wxRA_VERTICAL, wxDefaultValidator, _T("ID_RADIOBOX1"));
    BoxSizer1->Add(m_pRbxBaseRules, 0, wxTOP|wxLEFT|wxRIGHT|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer2 = new wxBoxSizer(wxHORIZONTAL);
    m_btnPreview = new wxButton(this, ID_BUTTON7, _("&Preview"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON7"));
    BoxSizer2->Add(m_btnPreview, 0, wxTOP|wxLEFT|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    m_btnRun = new wxButton(this, ID_BUTTON4, _("&Run"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON4"));
    m_btnRun->Disable();
    BoxSizer2->Add(m_btnRun, 0, wxTOP|wxLEFT|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    m_btnTest = new wxButton(this, ID_BUTTON5, _("test"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON5"));
    m_btnTest->Hide();
    BoxSizer2->Add(m_btnTest, 1, wxTOP|wxLEFT|wxRIGHT|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer1->Add(BoxSizer2, 0, wxTOP|wxRIGHT|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer6 = new wxBoxSizer(wxVERTICAL);
    Notebook1 = new wxNotebook(this, ID_NOTEBOOK1, wxDefaultPosition, wxSize(600,256), wxNB_BOTTOM, _T("ID_NOTEBOOK1"));
    Notebook1->SetMaxSize(wxSize(320,200));
    m_pLcResult = new wxListCtrl(Notebook1, ID_LISTCTRL1, wxDefaultPosition, wxDefaultSize, wxLC_REPORT|wxLC_HRULES|wxLC_VRULES, wxDefaultValidator, _T("ID_LISTCTRL1"));
    m_pLcFolderSize = new wxListCtrl(Notebook1, ID_LISTCTRL2, wxDefaultPosition, wxDefaultSize, wxLC_REPORT, wxDefaultValidator, _T("ID_LISTCTRL2"));
    Notebook1->AddPage(m_pLcResult, _("Preview and run result"), false);
    Notebook1->AddPage(m_pLcFolderSize, _("Folder size analysis"), false);
    BoxSizer6->Add(Notebook1, 1, wxTOP|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 2);
    BoxSizer1->Add(BoxSizer6, 1, wxLEFT|wxRIGHT|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer4 = new wxBoxSizer(wxHORIZONTAL);
    m_btnCheckUpdate = new wxButton(this, ID_BUTTON3, _("C&heck for update..."), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON3"));
    BoxSizer4->Add(m_btnCheckUpdate, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    m_btnUiLang = new wxButton(this, ID_BUTTON10, _("U&I Language..."), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON10"));
    BoxSizer4->Add(m_btnUiLang, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    m_btnAbout = new wxButton(this, wxID_ABOUT, _("&About..."), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("wxID_ABOUT"));
    BoxSizer4->Add(m_btnAbout, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    m_btnQuit = new wxButton(this, wxID_EXIT, _("&Quit"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("wxID_EXIT"));
    BoxSizer4->Add(m_btnQuit, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer1->Add(BoxSizer4, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    SetSizer(BoxSizer1);
    BoxSizer1->Fit(this);
    BoxSizer1->SetSizeHints(this);
    Center();
    
    Connect(ID_BUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&MainDlg::OnBtnNewClick);
    Connect(ID_BUTTON2,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&MainDlg::OnBtnEditClick);
    Connect(ID_BUTTON6,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&MainDlg::OnBtnDeleteClick);
    Connect(ID_BUTTON8,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&MainDlg::OnBtnUpClick);
    Connect(ID_BUTTON9,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&MainDlg::OnBtnDownClick);
    Connect(ID_CHECKLISTBOX1,wxEVT_COMMAND_LISTBOX_DOUBLECLICKED,(wxObjectEventFunction)&MainDlg::OnBtnEditClick);
    Connect(ID_BUTTON7,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&MainDlg::OnBtnPreviewClick);
    Connect(ID_BUTTON4,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&MainDlg::OnBtnRunClick);
    Connect(ID_BUTTON5,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&MainDlg::OnBtnTestClick);
    Connect(ID_BUTTON3,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&MainDlg::OnBtnCheckUpdateClick);
    Connect(ID_BUTTON10,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&MainDlg::OnBtnUiLangClick);
    Connect(wxID_ABOUT,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&MainDlg::OnBtnAboutClick);
    Connect(wxID_EXIT,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&MainDlg::OnBtnQuitClick);
    Connect(wxID_ANY,wxEVT_INIT_DIALOG,(wxObjectEventFunction)&MainDlg::OnInit);
    //*)

    // BoxSizer1->Hide(BoxSizer5);
    Connect(ID_CHECKLISTBOX1, wxEVT_COMMAND_LISTBOX_SELECTED, (wxObjectEventFunction)&MainDlg::OnLbxRuleItemSelect);

}

MainDlg::~MainDlg()
{
    //(*Destroy(MainDlg)
    //*)
}

void MainDlg::OnBtnQuitClick(wxCommandEvent& event)
{
    Close();
}

void MainDlg::OnBtnAboutClick(wxCommandEvent& event)
{
    AboutDlg dlg(this);
    dlg.ShowModal();
}

void MainDlg::OnBtnCheckUpdateClick(wxCommandEvent& event)
{
    wxLaunchDefaultBrowser(_T("http://down.boomworks.net/"));
}

/**
 * Get desktop full path
 *
 */
void MainDlg::getDesktopPath(wxString& strPath)
{
    wxRegKey *pRegKey = new wxRegKey(CSZ_DESKTOP_KEY_PATH);

    //will create the Key if it does not exist
    if ( !pRegKey->Exists() )
    {
        return;
    }

    pRegKey->QueryValue(CSZ_DESKTOP_KEY_NAME, strPath);

    delete pRegKey;
}

void MainDlg::OnInit(wxInitDialogEvent& event)
{
    // Set desktop path to mgt
    wxString strPath;
    getDesktopPath(strPath);
    m_categorizeMgr.Init(strPath);

    // Attach Observer object
    m_categorizeMgr.AttachObserver(this);

    ///////////////////////////////////////////////////////////////////
    // Init check list box
    updateRuleLbx(false);

    // Initial list ctrl
    for (int i=0; i<N_COL_NUM; i++)
    {
        m_pLcResult->InsertColumn(i, CSZ_COL_NAMES[i], wxLIST_FORMAT_LEFT, N_COL_WIDTH[i]);
    }
    //
    for (int i=0; i<N_FOLDER_SIZE_LC_COL_NUM; i++)
    {
        m_pLcFolderSize->InsertColumn(i, CSZ_FOLDER_SIZE_LC_COL_NAMES[i], wxLIST_FORMAT_LEFT, N_FOLDER_SIZE_LC_COL_WIDTH[i]);
    }

    ///////////////////////////////////////////////////////////////////

}

void MainDlg::OnBtnRunClick(wxCommandEvent& event)
{
    //
    m_pLcResult->DeleteAllItems();
    // m_pLcFolderSize->DeleteAllItems();

    //
    m_categorizeMgr.Categorize();

}

/**
 * Preview
 */
void MainDlg::OnBtnPreviewClick(wxCommandEvent& event)
{
    // Clear list
    m_pLcResult->DeleteAllItems();
    //m_pLcFolderSize->DeleteAllItems();

    // Colect rules setting
    int nType = m_pRbxBaseRules->GetSelection();
    Rule* pRule = m_categorizeMgr.GetRuleByIndex(0); // Basic rule
    bool bSel = false;
    if (nType == NBaseRuleTypeTime)
    {
        bSel = true;
    }
	pRule->m_bSelected = bSel;

    // Get rule select status
    int nCnt = m_pLbxCustRules->GetCount();
    int nIndex = -1;
    bool bChecked = false;
    for (int i = 0; i < nCnt; i++)
    {
    	bChecked = m_pLbxCustRules->IsChecked(i);
    	pRule = m_categorizeMgr.GetRuleByIndex(i + 1); // 1 start base index
    	if(pRule)
			pRule->m_bSelected = bChecked;
    }

	//
    // Preview and update UI
    //
    m_categorizeMgr.Preview();
    updateUICtrls();
}

void MainDlg::updateUICtrls()
{
    //
    int nCnt = m_pLcResult->GetItemCount();

    if (nCnt > 0)
    {
        m_btnRun->Enable();
    }
    else
    {
        m_btnRun->Enable(false);
    }
}

void MainDlg::OnBtnTestClick(wxCommandEvent& event)
{
    // BoxSizer1->Show(BoxSizer5);
}

void MainDlg::UpdateCategorizationCtrls()
{
    //
    ArrayCategorizationFileInfo* pArrFileInfo = m_categorizeMgr.GetCategorizationFileInfos();

    int nCnt = pArrFileInfo->GetCount();
    int nIndex = 0;
    CategorizationFileInfo* pFileInfo = 0;
    wxString strTemp;
    for (int i=0; i<nCnt; i++)
    {
        pFileInfo = pArrFileInfo->Item(i);

		if (pFileInfo->m_bPreProcessed == false && pFileInfo->m_bProcessed == false)
		{
			strTemp = _T("-");
		}
		else if (pFileInfo->m_bPreProcessed == true && pFileInfo->m_bProcessed == false )
        {
            strTemp = _("Previewed");
        }
        else
        {
            strTemp = _("Processed");
        }

		nIndex = m_pLcResult->InsertItem(m_pLcResult->GetItemCount(), strTemp);
        m_pLcResult->SetItem(nIndex, 1, pFileInfo->m_pFileName->GetFullPath());
        m_pLcResult->SetItem(nIndex, 2, pFileInfo->GetDestFullPath());
    }
}
void MainDlg::OnLbxRuleItemSelect(wxCommandEvent& event)
{
    updateButtons();
}

///////////////////////////////////////////////////////////////////////
// Rule ctrl group
///////////////////////////////////////////////////////////////////////

void MainDlg::OnBtnNewClick(wxCommandEvent& event)
{
    CustomRuleDlg dlg(this, CustomRuleDlg::RuleModeNew);

    if (dlg.ShowModal() == wxID_OK)
    {
        RuleInfo ruleInfo;
        dlg.GetRuleInfo(ruleInfo);

        m_categorizeMgr.AddRule(ruleInfo);

        //
        updateRuleLbx(true);
    }
}

void MainDlg::OnBtnEditClick(wxCommandEvent& event)
{
    // Get selection
    int nIndex = -1;
    nIndex = m_pLbxCustRules->GetSelection();

    if (-1 == nIndex)
        return;

    // Find pRule from CateMgr
    Rule* pRule = m_categorizeMgr.GetRuleByIndex(nIndex + 1);  // 1 base

    // Set pRule to dlg
    CustomRuleDlg dlg(this, CustomRuleDlg::RuleModeEdit);
    dlg.SetRule(pRule);

    if (dlg.ShowModal() == wxID_OK)
    {
        updateRuleLbx(true);
    }
}

void MainDlg::updateRuleLbx(bool bClear)
{
    if (bClear)
        m_pLbxCustRules->Clear();

    // Init check list box
    ArrayRule* pArrRule = m_categorizeMgr.GetRuleArray();

    // int nCnt = pArrRule->GetCount();
    int nCnt = CategorizeMgr::ms_nCurMaxIndex;
    Rule* pRule = 0;
    wxString strTemp;
    int nIndex = -1;
    for (int i=0; i<nCnt; i++)
    {
        pRule = m_categorizeMgr.GetRuleByIndex(i + 1);
        if (pRule)
        {
            pRule->GetDispStr(strTemp);
            nIndex = m_pLbxCustRules->Append(strTemp);
            pRule->m_nIndex = nIndex + 1;
            if (pRule->m_bSelected)
                m_pLbxCustRules->Check(nIndex);
        }
    }
}

void MainDlg::OnBtnDeleteClick(wxCommandEvent& event)
{
    // Get selection
    int nIndex = -1;
    nIndex = m_pLbxCustRules->GetSelection();

    if (-1 == nIndex)
        return;

    m_categorizeMgr.DeleteRule(nIndex + 1);

    updateRuleLbx(true);
    updateButtons();
}

void MainDlg::updateButtons()
{
    bool bEnable = false;
    if ( wxNOT_FOUND != m_pLbxCustRules->GetSelection())
    {
        bEnable = true;
    }

    m_btnEdit->Enable(bEnable);
    m_btnDelete->Enable(bEnable);
    m_btnUp->Enable(bEnable);
    m_btnDown->Enable(bEnable);
}

void MainDlg::OnBtnUpClick(wxCommandEvent& event)
{
    int nIndex = m_pLbxCustRules->GetSelection();
    if ( wxNOT_FOUND == nIndex)
        return;

    if (nIndex == 0)
        return;

	//
	Rule* pRuleCur = m_categorizeMgr.GetRuleByIndex(nIndex + 1);	// Base 1
	Rule* pRulePrev = m_categorizeMgr.GetRuleByIndex(nIndex);		// Base 1

	pRuleCur->m_nIndex = nIndex;
	pRulePrev->m_nIndex = nIndex + 1;

	updateRuleLbx(true);

	m_pLbxCustRules->SetSelection(nIndex - 1);
}

void MainDlg::OnBtnDownClick(wxCommandEvent& event)
{
	int nIndex = m_pLbxCustRules->GetSelection();
    if ( wxNOT_FOUND == nIndex)
        return;

	int nCnt = m_pLbxCustRules->GetCount();
    if (nIndex == nCnt - 1)
        return;

	//
	Rule* pRuleCur = m_categorizeMgr.GetRuleByIndex(nIndex + 1);			// Base 1
	Rule* pRuleForward = m_categorizeMgr.GetRuleByIndex(nIndex + 2);		// Base 1

	pRuleCur->m_nIndex = nIndex + 2;
	pRuleForward->m_nIndex = nIndex + 1;


	updateRuleLbx(true);

	m_pLbxCustRules->SetSelection(nIndex + 1);
}

void MainDlg::OnBtnUiLangClick(wxCommandEvent& event)
{
    ChangeUILanguage();
}
