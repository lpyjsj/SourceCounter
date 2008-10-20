/***************************************************************
 * Name:      SourceCounterMain.cpp
 * Purpose:   Code for Application Frame
 * Author:    boomworks.net (boomworks@gmail.com)
 * Created:   2008-10-09
 * Copyright: boomworks.net (http://www.boomworks.net)
 * License:
 **************************************************************/

//(*InternalHeaders(SourceCounterDialog)
#include <wx/settings.h>
#include <wx/intl.h>
#include <wx/string.h>
//*)

#include <wx/tokenzr.h>
#include <wx/msgdlg.h>

#include "wx_pch.h"
#include "SourceCounterMain.h"

#include "aboutdlg.h"
#include "CntSettingDlg.h"
#include "SrcTypeSelDlg.h"

//(*IdInit(SourceCounterDialog)
const long SourceCounterDialog::ID_STATICTEXT2 = wxNewId();
const long SourceCounterDialog::ID_CHECKLISTBOX1 = wxNewId();
const long SourceCounterDialog::ID_BUTTON3 = wxNewId();
const long SourceCounterDialog::ID_BUTTON9 = wxNewId();
const long SourceCounterDialog::ID_STATICTEXT1 = wxNewId();
const long SourceCounterDialog::ID_COMBOBOX1 = wxNewId();
const long SourceCounterDialog::ID_BUTTON8 = wxNewId();
const long SourceCounterDialog::ID_CHECKBOX1 = wxNewId();
const long SourceCounterDialog::ID_BUTTON4 = wxNewId();
const long SourceCounterDialog::ID_BUTTON5 = wxNewId();
const long SourceCounterDialog::ID_BUTTON6 = wxNewId();
const long SourceCounterDialog::ID_LISTCTRL1 = wxNewId();
const long SourceCounterDialog::ID_STATICTEXT3 = wxNewId();
const long SourceCounterDialog::ID_STATICTEXT11 = wxNewId();
const long SourceCounterDialog::ID_STATICTEXT12 = wxNewId();
const long SourceCounterDialog::ID_STATICTEXT4 = wxNewId();
const long SourceCounterDialog::ID_STATICTEXT5 = wxNewId();
const long SourceCounterDialog::ID_STATICTEXT14 = wxNewId();
const long SourceCounterDialog::ID_STATICTEXT13 = wxNewId();
const long SourceCounterDialog::ID_STATICTEXT6 = wxNewId();
const long SourceCounterDialog::ID_STATICTEXT7 = wxNewId();
const long SourceCounterDialog::ID_STATICTEXT15 = wxNewId();
const long SourceCounterDialog::ID_STATICTEXT16 = wxNewId();
const long SourceCounterDialog::ID_STATICTEXT8 = wxNewId();
const long SourceCounterDialog::ID_STATICTEXT9 = wxNewId();
const long SourceCounterDialog::ID_STATICTEXT10 = wxNewId();
const long SourceCounterDialog::ID_BUTTON7 = wxNewId();
const long SourceCounterDialog::ID_BUTTON1 = wxNewId();
const long SourceCounterDialog::ID_BUTTON2 = wxNewId();
//*)

BEGIN_EVENT_TABLE(SourceCounterDialog,wxDialog)
    //(*EventTable(SourceCounterDialog)
    //*)
END_EVENT_TABLE()

SourceCounterDialog::SourceCounterDialog(wxWindow* parent,wxWindowID id)
{
    //(*Initialize(SourceCounterDialog)
    wxBoxSizer* BoxSizer4;
    wxStaticBoxSizer* StaticBoxSizer2;
    wxBoxSizer* BoxSizer6;
    wxBoxSizer* BoxSizer15;
    wxBoxSizer* BoxSizer5;
    wxBoxSizer* BoxSizer10;
    wxBoxSizer* BoxSizer7;
    wxBoxSizer* BoxSizer8;
    wxBoxSizer* BoxSizer13;
    wxBoxSizer* BoxSizer2;
    wxBoxSizer* BoxSizer11;
    wxBoxSizer* BoxSizer12;
    wxBoxSizer* BoxSizer14;
    wxBoxSizer* BoxSizer9;
    wxStaticBoxSizer* StaticBoxSizer1;
    wxBoxSizer* BoxSizer3;
    
    Create(parent, wxID_ANY, _("SourceCounter"), wxDefaultPosition, wxDefaultSize, wxDEFAULT_DIALOG_STYLE|wxSYSTEM_MENU|wxRESIZE_BORDER|wxMAXIMIZE_BOX|wxMINIMIZE_BOX, _T("wxID_ANY"));
    BoxSizer1 = new wxBoxSizer(wxVERTICAL);
    StaticBoxSizer1 = new wxStaticBoxSizer(wxVERTICAL, this, _("Options"));
    BoxSizer4 = new wxBoxSizer(wxVERTICAL);
    StaticText2 = new wxStaticText(this, ID_STATICTEXT2, _("Source code &folder:"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT2"));
    BoxSizer4->Add(StaticText2, 0, wxTOP|wxLEFT|wxRIGHT|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer2 = new wxBoxSizer(wxHORIZONTAL);
    BoxSizer14 = new wxBoxSizer(wxHORIZONTAL);
    m_lbxSrcFolder = new wxCheckListBox(this, ID_CHECKLISTBOX1, wxDefaultPosition, wxSize(387,80), 0, 0, wxLB_SINGLE, wxDefaultValidator, _T("ID_CHECKLISTBOX1"));
    BoxSizer14->Add(m_lbxSrcFolder, 1, wxTOP|wxLEFT|wxRIGHT|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer2->Add(BoxSizer14, 5, wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer13 = new wxBoxSizer(wxVERTICAL);
    m_btnAdd = new wxButton(this, ID_BUTTON3, _("A&dd..."), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON3"));
    BoxSizer13->Add(m_btnAdd, 0, wxTOP|wxLEFT|wxRIGHT|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    m_btnDelete = new wxButton(this, ID_BUTTON9, _("Delete"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON9"));
    m_btnDelete->Disable();
    BoxSizer13->Add(m_btnDelete, 0, wxTOP|wxLEFT|wxRIGHT|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer2->Add(BoxSizer13, 0, wxALIGN_TOP|wxALIGN_CENTER_HORIZONTAL, 5);
    BoxSizer4->Add(BoxSizer2, 0, wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticBoxSizer1->Add(BoxSizer4, 0, wxLEFT|wxRIGHT|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer3 = new wxBoxSizer(wxHORIZONTAL);
    BoxSizer15 = new wxBoxSizer(wxHORIZONTAL);
    StaticText1 = new wxStaticText(this, ID_STATICTEXT1, _("Source &type:"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT1"));
    BoxSizer15->Add(StaticText1, 0, wxTOP|wxLEFT|wxRIGHT|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    m_cmbSrcTypes = new wxComboBox(this, ID_COMBOBOX1, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, 0, wxCB_READONLY, wxDefaultValidator, _T("ID_COMBOBOX1"));
    BoxSizer15->Add(m_cmbSrcTypes, 1, wxTOP|wxLEFT|wxRIGHT|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer3->Add(BoxSizer15, 1, wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    m_btnSelSrcType = new wxButton(this, ID_BUTTON8, _("S&elect..."), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON8"));
    BoxSizer3->Add(m_btnSelSrcType, 0, wxTOP|wxLEFT|wxRIGHT|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticBoxSizer1->Add(BoxSizer3, 1, wxLEFT|wxRIGHT|wxEXPAND|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer5 = new wxBoxSizer(wxHORIZONTAL);
    m_chbRecursiveCouting = new wxCheckBox(this, ID_CHECKBOX1, _("Recursive file counting"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_CHECKBOX1"));
    m_chbRecursiveCouting->SetValue(true);
    m_chbRecursiveCouting->SetToolTip(_("Check this box if you wish to count all files that located in the subfolders of source code folder."));
    BoxSizer5->Add(m_chbRecursiveCouting, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    m_btnMoreSetting = new wxButton(this, ID_BUTTON4, _("&More settings..."), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON4"));
    BoxSizer5->Add(m_btnMoreSetting, 0, wxTOP|wxLEFT|wxRIGHT|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticBoxSizer1->Add(BoxSizer5, 1, wxLEFT|wxRIGHT|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer1->Add(StaticBoxSizer1, 0, wxTOP|wxLEFT|wxRIGHT|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer11 = new wxBoxSizer(wxHORIZONTAL);
    BoxSizer11->Add(-1,-1,2, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    m_btnStart = new wxButton(this, ID_BUTTON5, _("Sta&rt"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON5"));
    BoxSizer11->Add(m_btnStart, 1, wxTOP|wxLEFT|wxRIGHT|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    m_btnStop = new wxButton(this, ID_BUTTON6, _("Sto&p"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON6"));
    m_btnStop->Disable();
    BoxSizer11->Add(m_btnStop, 1, wxTOP|wxLEFT|wxRIGHT|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer1->Add(BoxSizer11, 0, wxLEFT|wxRIGHT|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticBoxSizer2 = new wxStaticBoxSizer(wxVERTICAL, this, _("Counting result"));
    BoxSizer6 = new wxBoxSizer(wxVERTICAL);
    m_lstResult = new wxListCtrl(this, ID_LISTCTRL1, wxDefaultPosition, wxSize(500,160), wxLC_REPORT|wxLC_SINGLE_SEL, wxDefaultValidator, _T("ID_LISTCTRL1"));
    BoxSizer6->Add(m_lstResult, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticBoxSizer2->Add(BoxSizer6, 1, wxLEFT|wxRIGHT|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer7 = new wxBoxSizer(wxHORIZONTAL);
    StaticText3 = new wxStaticText(this, ID_STATICTEXT3, _("Total files"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT3"));
    BoxSizer7->Add(StaticText3, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    m_lblTotalFiles = new wxStaticText(this, ID_STATICTEXT11, _("0"), wxDefaultPosition, wxDefaultSize, wxSUNKEN_BORDER, _T("ID_STATICTEXT11"));
    BoxSizer7->Add(m_lblTotalFiles, 2, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticText12 = new wxStaticText(this, ID_STATICTEXT12, _("Code lines"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT12"));
    BoxSizer7->Add(StaticText12, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    m_lblCodeLines = new wxStaticText(this, ID_STATICTEXT4, _("0"), wxDefaultPosition, wxDefaultSize, wxSUNKEN_BORDER, _T("ID_STATICTEXT4"));
    BoxSizer7->Add(m_lblCodeLines, 2, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticBoxSizer2->Add(BoxSizer7, 0, wxLEFT|wxRIGHT|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer8 = new wxBoxSizer(wxHORIZONTAL);
    StaticText5 = new wxStaticText(this, ID_STATICTEXT5, _("Total size (KB)"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT5"));
    BoxSizer8->Add(StaticText5, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    m_lblTotalSize = new wxStaticText(this, ID_STATICTEXT14, _("0"), wxDefaultPosition, wxDefaultSize, wxSUNKEN_BORDER, _T("ID_STATICTEXT14"));
    BoxSizer8->Add(m_lblTotalSize, 2, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticText13 = new wxStaticText(this, ID_STATICTEXT13, _("Comment lines"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT13"));
    BoxSizer8->Add(StaticText13, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    m_lblCommentLines = new wxStaticText(this, ID_STATICTEXT6, _("0"), wxDefaultPosition, wxDefaultSize, wxSUNKEN_BORDER, _T("ID_STATICTEXT6"));
    BoxSizer8->Add(m_lblCommentLines, 2, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticBoxSizer2->Add(BoxSizer8, 0, wxLEFT|wxRIGHT|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer9 = new wxBoxSizer(wxHORIZONTAL);
    StaticText7 = new wxStaticText(this, ID_STATICTEXT7, _("Total lines"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT7"));
    BoxSizer9->Add(StaticText7, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    m_lblTotalLines = new wxStaticText(this, ID_STATICTEXT15, _("0"), wxDefaultPosition, wxDefaultSize, wxSUNKEN_BORDER, _T("ID_STATICTEXT15"));
    BoxSizer9->Add(m_lblTotalLines, 2, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticText16 = new wxStaticText(this, ID_STATICTEXT16, _("Blank lines"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT16"));
    BoxSizer9->Add(StaticText16, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    m_lblBlankLines = new wxStaticText(this, ID_STATICTEXT8, _("0"), wxDefaultPosition, wxDefaultSize, wxSUNKEN_BORDER, _T("ID_STATICTEXT8"));
    BoxSizer9->Add(m_lblBlankLines, 2, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticBoxSizer2->Add(BoxSizer9, 0, wxLEFT|wxRIGHT|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer10 = new wxBoxSizer(wxHORIZONTAL);
    StaticText9 = new wxStaticText(this, ID_STATICTEXT9, _("Counting status"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT9"));
    BoxSizer10->Add(StaticText9, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    m_lblStatus = new wxStaticText(this, ID_STATICTEXT10, _("Ready."), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT10"));
    m_lblStatus->SetForegroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_HIGHLIGHT));
    m_lblStatus->SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_INFOBK));
    BoxSizer10->Add(m_lblStatus, 4, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    m_btnSave = new wxButton(this, ID_BUTTON7, _("&Save..."), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON7"));
    m_btnSave->Disable();
    BoxSizer10->Add(m_btnSave, 1, wxLEFT|wxRIGHT|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticBoxSizer2->Add(BoxSizer10, 0, wxLEFT|wxRIGHT|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer1->Add(StaticBoxSizer2, 1, wxLEFT|wxRIGHT|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer12 = new wxBoxSizer(wxHORIZONTAL);
    BoxSizer12->Add(-1,-1,4, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    Button1 = new wxButton(this, ID_BUTTON1, _("&About..."), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON1"));
    BoxSizer12->Add(Button1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 4);
    Button2 = new wxButton(this, ID_BUTTON2, _("&Quit"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON2"));
    BoxSizer12->Add(Button2, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 4);
    BoxSizer1->Add(BoxSizer12, 0, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    SetSizer(BoxSizer1);
    m_dlgAddDir = new wxDirDialog(this, _("Select directory"), _("W:\\boomworks\\SrcCounter\\TestCase"), wxDD_DIR_MUST_EXIST, wxDefaultPosition, wxDefaultSize, _T("wxDirDialog"));
    BoxSizer1->Fit(this);
    BoxSizer1->SetSizeHints(this);
    Center();
    
    Connect(ID_CHECKLISTBOX1,wxEVT_COMMAND_CHECKLISTBOX_TOGGLED,(wxObjectEventFunction)&SourceCounterDialog::OnLbxSrcFolderCheck);
    Connect(ID_BUTTON3,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&SourceCounterDialog::OnBtnAddDirClick);
    Connect(ID_BUTTON9,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&SourceCounterDialog::OnBtnDeleteClick);
    Connect(ID_BUTTON8,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&SourceCounterDialog::OnBtnSelSrcTypeClick);
    Connect(ID_BUTTON4,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&SourceCounterDialog::OnBtnMoreSettingsClick);
    Connect(ID_BUTTON5,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&SourceCounterDialog::OnBtnStartClick);
    Connect(ID_BUTTON6,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&SourceCounterDialog::OnBtnStopClick);
    Connect(ID_BUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&SourceCounterDialog::OnAbout);
    Connect(ID_BUTTON2,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&SourceCounterDialog::OnQuit);
    Connect(wxID_ANY,wxEVT_INIT_DIALOG,(wxObjectEventFunction)&SourceCounterDialog::OnInit);
    //*)

    //
    Connect(ID_CHECKLISTBOX1, wxEVT_COMMAND_LISTBOX_SELECTED, (wxObjectEventFunction)&SourceCounterDialog::OnLbxSrcFolderItemSelect);

}

SourceCounterDialog::~SourceCounterDialog()
{
    //(*Destroy(SourceCounterDialog)
    //*)



}

void SourceCounterDialog::OnQuit(wxCommandEvent& event)
{
    Close();
}

void SourceCounterDialog::OnAbout(wxCommandEvent& event)
{
//    wxString msg = wxbuildinfo(long_f);
//    wxMessageBox(msg, _("Welcome to..."));
    AboutDlg dlg(this);
    dlg.ShowModal();
}

void SourceCounterDialog::OnBtnMoreSettingsClick(wxCommandEvent& event)
{
    CntSettingDlg dlg(this);
    dlg.ShowModal();
}

void SourceCounterDialog::OnBtnAddDirClick(wxCommandEvent& event)
{
    try
    {
        if ( wxID_OK == m_dlgAddDir->ShowModal())
        {
            //
            wxString strPath = m_dlgAddDir->GetPath();
            int nIndex = m_lbxSrcFolder->Append(strPath);
            m_lbxSrcFolder->Check(nIndex, true);
        }
    }
    catch (...)
    {
        wxMessageBox(_T("catch"));
    }
}

void SourceCounterDialog::OnBtnDeleteClick(wxCommandEvent& event)
{
    // Get selection
    int nIndex = -1;
    nIndex = m_lbxSrcFolder->GetSelection();

    // Delete item
    m_lbxSrcFolder->Delete(nIndex);

    updateOptionsCtrls();
}

void SourceCounterDialog::OnBtnSelSrcTypeClick(wxCommandEvent& event)
{
    //
    SrcTypeSelDlg dlg(this);

    if (wxID_OK == dlg.ShowModal())
    {
        wxString strSrcTypes;
        dlg.GetSrcTypes(strSrcTypes);
        //wxMessageBox(strSrcTypes);
        m_cmbSrcTypes->Append(strSrcTypes);
        m_cmbSrcTypes->SetValue(strSrcTypes);

    }
}

void SourceCounterDialog::OnLbxSrcFolderCheck(wxCommandEvent& event)
{
//    int nIndex = -1;
//    nIndex = m_lbxSrcFolder->GetSelection();
//
//    wxString strTemp;
//    strTemp.Printf(_T("%d"), nIndex);
//
//    wxMessageBox(strTemp);
}

void SourceCounterDialog::OnLbxSrcFolderItemSelect(wxCommandEvent& evt)
{
    //
    m_btnDelete->Enable();
}

void SourceCounterDialog::OnBtnStartClick(wxCommandEvent& event)
{
    //
    // Check counting parameter
    //

    // Check source folder exist
    int nCount = m_lbxSrcFolder->GetCount();
    if (0 == nCount)
    {
        wxMessageBox(_T("Please add source folder."));
        return;
    }

    // Check source folder have been checked
    bool bHasChecked = false;
    for (int i = 0; i < nCount; i++)
    {
        bHasChecked = m_lbxSrcFolder->IsChecked(i);
        if (bHasChecked)
        {
            break;
        }
    }

    if (!bHasChecked)
    {
        wxMessageBox(_T("Please check counting folder."));
        return;
    }

    // Check source types
    wxString strSrcTypes;
    strSrcTypes.Empty();
    strSrcTypes = m_cmbSrcTypes->GetValue();
    if (strSrcTypes.IsEmpty())
    {
        wxMessageBox(_T("Please select source types."));
        return;
    }

    //
    // Prepare counting
    //

    // Clear prev counting info
    m_countingInfo.Clear();
    m_countingMgr.Clear();

    // Update options ctrls and Initial counting ctrls
    m_countingMgr.SetStatus(NManagerStatusRunning);

    updateOptionsCtrls();
    initCountingCtrls();

    //
    // Collection of counting parameter information
    //

    CountingParam countingParam;

    // Collect source folder path for counting
    for (int i = 0; i < nCount; i++)
    {
        if (m_lbxSrcFolder->IsChecked(i))
        {
            countingParam.m_arrSrcFolderPath.Add(m_lbxSrcFolder->GetString(i));
        }
    }

    // Collect source types
    wxStringTokenizer tkz(strSrcTypes, _T(";"));
    while ( tkz.HasMoreTokens() )
    {
        wxString token = tkz.GetNextToken();
        countingParam.m_arrSrcType.Add(token);
    }

    // Collect recursive counting
    countingParam.m_bRecursiveCounting = m_chbRecursiveCouting->GetValue();
    // TODO: countingParam.m_settingParam.m_nCountingMethodType = ;

    // Set counting parameter to CountingManager
    m_countingMgr.SetCountingParam( &countingParam );

    //
    // Start counting by call CountingManager
    //

    // Attach observer and start counting
    m_countingMgr.AttachObserver(this);
    m_countingMgr.StartCounting();

    //
    // finally
    //

    switch ( m_countingMgr.GetStatus())
    {
    case NManagerStatusComplete:
        // SetDlgItemText( IDC_STC_STATISTIC_STATUS, CSZ_STATISTIC_STATUS[3] );
        m_lblStatus->SetLabel(_T("Completed."));
        break;

    case NManagerStatusStop:
        // SetDlgItemText( IDC_STC_STATISTIC_STATUS, CSZ_STATISTIC_STATUS[2] );
        m_lblStatus->SetLabel(_T("Canceled."));
        break;

    default:
        break;
    }

    updateOptionsCtrls();
}

void SourceCounterDialog::updateOptionsCtrls()
{
    //
    m_lbxSrcFolder->Enable(m_countingMgr.GetStatus() == NManagerStatusRunning ? false : true );
    m_btnAdd->Enable(m_countingMgr.GetStatus() == NManagerStatusRunning ? false : true );

    if (m_countingMgr.GetStatus() == NManagerStatusRunning || m_lstResult->GetItemCount() == 0)
    {
        m_btnDelete->Enable(false);
    }


    m_cmbSrcTypes->Enable(m_countingMgr.GetStatus() == NManagerStatusRunning ? false : true );
    m_btnSelSrcType->Enable(m_countingMgr.GetStatus() == NManagerStatusRunning ? false : true );

    m_chbRecursiveCouting->Enable(m_countingMgr.GetStatus() == NManagerStatusRunning ? false : true);
    m_btnMoreSetting->Enable(m_countingMgr.GetStatus() == NManagerStatusRunning ? false : true);

    m_btnStart->Enable(m_countingMgr.GetStatus() == NManagerStatusRunning ? false : true);
    m_btnStop->Enable(m_countingMgr.GetStatus() == NManagerStatusRunning ? true : false);

    // Save btn
    bool bEnableBtnSave = false;
    if (m_lstResult->GetItemCount() >0 && m_countingMgr.GetStatus() != NManagerStatusRunning)
    {
        bEnableBtnSave = true;
    }
    m_btnSave->Enable( bEnableBtnSave );
}

void SourceCounterDialog::initCountingCtrls()
{
    // Delete all listctrl items, if exist.
    m_lstResult->DeleteAllItems();
    // Initial labels

    m_lblStatus->SetLabel(_T("Ready."));


}

void SourceCounterDialog::UpdateCountingInfoCtrls()
{
    //
    // wxMessageBox(_T("Notified"));
    //
    m_countingMgr.GetCountingInfo( m_countingInfo );

    //
    // Insert item to resutl listctrl
    //
    long nIndex = m_lstResult->InsertItem(m_lstResult->GetItemCount(), m_countingInfo.m_countingFileInfo.m_strFileName);
    m_lstResult->SetItem(nIndex, 1, m_countingInfo.m_countingFileInfo.m_strFileExtName);
    m_lstResult->SetItem(nIndex, 2, m_countingInfo.m_countingFileInfo.m_strFolderPath);

    wxString strTemp;

    strTemp.Printf(_T("%d"), m_countingInfo.m_countingFileInfo.m_nTotalStatement);
    m_lstResult->SetItem(nIndex, 3, strTemp);

    strTemp.Printf(_T("%d"), m_countingInfo.m_countingFileInfo.m_nCodeStatement);
    m_lstResult->SetItem(nIndex, 4, strTemp);

    strTemp.Printf(_T("%d"), m_countingInfo.m_countingFileInfo.m_nCommentStatement);
    m_lstResult->SetItem(nIndex, 5, strTemp);

    strTemp.Printf(_T("%d"), m_countingInfo.m_countingFileInfo.m_nBlankStatement);
    m_lstResult->SetItem(nIndex, 6, strTemp);

    // Update labels
    strTemp.Printf(_T("%d"), m_countingInfo.m_nTotalFile);
    m_lblTotalFiles->SetLabel(strTemp);

    strTemp.Printf(_T("%d"), m_countingInfo.m_nTotalFile);
    m_lblTotalSize->SetLabel(strTemp);

    strTemp.Printf(_T("%d"), m_countingInfo.m_nTotalStatement);
    m_lblTotalLines->SetLabel(strTemp);

    strTemp.Printf(_T("%d"), m_countingInfo.m_nTotalCodeStatement);
    m_lblCodeLines->SetLabel(strTemp);

    strTemp.Printf(_T("%d"), m_countingInfo.m_nTotalCommentStatement);
    m_lblCommentLines->SetLabel(strTemp);

    strTemp.Printf(_T("%d"), m_countingInfo.m_nTotalBlankStatement);
    m_lblBlankLines->SetLabel(strTemp);

//    wxMessageBox(m_countingInfo.m_countingFileInfo.m_strFileFullPath);
//    wxMessageBox(m_countingInfo.m_countingFileInfo.m_strFileName);
    m_lblStatus->SetLabel(m_countingInfo.m_countingFileInfo.m_strFileFullPath);

}

void SourceCounterDialog::OnInit(wxInitDialogEvent& event)
{
    m_lstResult->InsertColumn(0, _T("File"));
    m_lstResult->InsertColumn(1, _T("Type"));
    m_lstResult->InsertColumn(2, _T("Folder"));
    m_lstResult->InsertColumn(3, _T("Total lines"));
    m_lstResult->InsertColumn(4, _T("Code lines"));
    m_lstResult->InsertColumn(5, _T("Comment lines"));
    m_lstResult->InsertColumn(6, _T("Blank lines"));
}

void SourceCounterDialog::OnBtnStopClick(wxCommandEvent& event)
{
    m_countingMgr.StopCounting();
}
