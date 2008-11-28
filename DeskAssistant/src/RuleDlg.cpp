/**
 * Rule dialog
 */

#ifndef WX_PRECOMP
//(*InternalHeadersPCH(RuleDlg)
#include <wx/intl.h>
#include <wx/string.h>
//*)
#endif
//(*InternalHeaders(RuleDlg)
#include <wx/bitmap.h>
#include <wx/image.h>
//*)

#include <wx/config.h>
#include <wx/msgdlg.h>
#include <wx/filename.h>
#include <wx/file.h>
#include <wx/config.h>

#include "wx_pch.h"
#include "RuleDlg.h"
#include "AboutDlg.h"

//(*IdInit(RuleDlg)
const long RuleDlg::ID_STATICBITMAP1 = wxNewId();
const long RuleDlg::ID_STATICTEXT1 = wxNewId();
const long RuleDlg::ID_BUTTON1 = wxNewId();
const long RuleDlg::ID_BUTTON2 = wxNewId();
const long RuleDlg::ID_BUTTON6 = wxNewId();
const long RuleDlg::ID_BUTTON8 = wxNewId();
const long RuleDlg::ID_BUTTON9 = wxNewId();
const long RuleDlg::ID_CHECKLISTBOX1 = wxNewId();
const long RuleDlg::ID_RADIOBOX1 = wxNewId();
const long RuleDlg::ID_BUTTON7 = wxNewId();
const long RuleDlg::ID_BUTTON4 = wxNewId();
const long RuleDlg::ID_LISTCTRL1 = wxNewId();
const long RuleDlg::ID_BUTTON3 = wxNewId();
//*)

///////////////////////////////////////////////////////////////////////
const int N_COL_NUM = 3;	///< Result listctrl column number

/** Result listctrl column names */
const wxString CSZ_COL_NAMES[] =
{
    _("File"),
    _("Destination directory"),
    _("Progress"),
};

const wxChar* CSZ_DESKTOP_KEY_NAME = _T("Desktop");   ///<

/** Desktop register path */
const wxString CSZ_DESKTOP_KEY_PATH =
    _T("HKEY_CURRENT_USER\\Software\\Microsoft\\Windows\\CurrentVersion\\Explorer\\Shell Folders");

const wxString CSZ_EXCLUDING_FILE_EXT = _T("lnk"); ///< excluding file type
///////////////////////////////////////////////////////////////////////

BEGIN_EVENT_TABLE(RuleDlg,wxDialog)
    //(*EventTable(RuleDlg)
    //*)
END_EVENT_TABLE()

RuleDlg::RuleDlg(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size)
{
    //(*Initialize(RuleDlg)
    wxBoxSizer* BoxSizer4;
    wxBoxSizer* BoxSizer6;
    wxBoxSizer* BoxSizer5;
    wxBoxSizer* BoxSizer2;
    wxBoxSizer* BoxSizer1;
    wxStaticBoxSizer* StaticBoxSizer1;
    wxBoxSizer* BoxSizer3;

    Create(parent, id, _("Desktop Assistant"), wxDefaultPosition, wxDefaultSize, wxDEFAULT_DIALOG_STYLE|wxRESIZE_BORDER|wxMINIMIZE_BOX, _T("id"));
    SetClientSize(wxDefaultSize);
    Move(wxDefaultPosition);
    BoxSizer1 = new wxBoxSizer(wxVERTICAL);
    BoxSizer5 = new wxBoxSizer(wxHORIZONTAL);
    StaticBitmap1 = new wxStaticBitmap(this, ID_STATICBITMAP1, wxBitmap(wxImage(_T("img\\DesktopAssistant.ico"))), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICBITMAP1"));
    BoxSizer5->Add(StaticBitmap1, 0, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    StaticText1 = new wxStaticText(this, ID_STATICTEXT1, _("Desktop Assistant is a tool for Desktop file categorization.\nThis tool can categorize files to folders by using the rule defined beforehand. \nThe folders that stores the files is automatically created. "), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT1"));
    BoxSizer5->Add(StaticText1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer1->Add(BoxSizer5, 0, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticBoxSizer1 = new wxStaticBoxSizer(wxVERTICAL, this, _("Select customize categorization rules"));
    BoxSizer3 = new wxBoxSizer(wxHORIZONTAL);
    m_btnNew = new wxButton(this, ID_BUTTON1, _("&New..."), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON1"));
    BoxSizer3->Add(m_btnNew, 0, wxTOP|wxLEFT|wxRIGHT|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    Button2 = new wxButton(this, ID_BUTTON2, _("&Edit..."), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON2"));
    Button2->Disable();
    BoxSizer3->Add(Button2, 0, wxTOP|wxLEFT|wxRIGHT|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    Button6 = new wxButton(this, ID_BUTTON6, _("&Delete"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON6"));
    Button6->Disable();
    BoxSizer3->Add(Button6, 0, wxTOP|wxLEFT|wxRIGHT|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    Button8 = new wxButton(this, ID_BUTTON8, _("&Up"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON8"));
    Button8->Disable();
    BoxSizer3->Add(Button8, 1, wxTOP|wxLEFT|wxRIGHT|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    Button9 = new wxButton(this, ID_BUTTON9, _("Dow&n"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON9"));
    Button9->Disable();
    BoxSizer3->Add(Button9, 1, wxTOP|wxLEFT|wxRIGHT|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer3->Add(0,0,1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer3->Add(0,0,1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticBoxSizer1->Add(BoxSizer3, 0, wxBOTTOM|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 2);
    m_pLbxCustRules = new wxCheckListBox(this, ID_CHECKLISTBOX1, wxDefaultPosition, wxDefaultSize, 0, 0, wxLB_SINGLE|wxLB_NEEDED_SB, wxDefaultValidator, _T("ID_CHECKLISTBOX1"));
    m_pLbxCustRules->Append(_("7z, zip -> @ZIP@"));
    m_pLbxCustRules->Disable();
    StaticBoxSizer1->Add(m_pLbxCustRules, 0, wxBOTTOM|wxLEFT|wxRIGHT|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer1->Add(StaticBoxSizer1, 0, wxTOP|wxLEFT|wxRIGHT|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    wxString __wxRadioBoxChoices_1[3] =
    {
    _("By file extend name"),
    _("By file modify time"),
    _("None")
    };
    m_pRbxBaseRules = new wxRadioBox(this, ID_RADIOBOX1, _("Select base categorization rules"), wxDefaultPosition, wxDefaultSize, 3, __wxRadioBoxChoices_1, 1, wxRA_VERTICAL, wxDefaultValidator, _T("ID_RADIOBOX1"));
    BoxSizer1->Add(m_pRbxBaseRules, 0, wxTOP|wxLEFT|wxRIGHT|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer2 = new wxBoxSizer(wxHORIZONTAL);
    m_btnPreview = new wxButton(this, ID_BUTTON7, _("&Preview"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON7"));
    BoxSizer2->Add(m_btnPreview, 0, wxTOP|wxLEFT|wxRIGHT|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    m_btnRun = new wxButton(this, ID_BUTTON4, _("&Run"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON4"));
    m_btnRun->Disable();
    BoxSizer2->Add(m_btnRun, 0, wxTOP|wxLEFT|wxRIGHT|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer1->Add(BoxSizer2, 0, wxTOP|wxRIGHT|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer6 = new wxBoxSizer(wxVERTICAL);
    m_pLcResult = new wxListCtrl(this, ID_LISTCTRL1, wxDefaultPosition, wxSize(360,120), wxLC_REPORT, wxDefaultValidator, _T("ID_LISTCTRL1"));
    BoxSizer6->Add(m_pLcResult, 1, wxTOP|wxBOTTOM|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer1->Add(BoxSizer6, 1, wxLEFT|wxRIGHT|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer4 = new wxBoxSizer(wxHORIZONTAL);
    m_btnCheckUpdate = new wxButton(this, ID_BUTTON3, _("C&heck for update..."), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON3"));
    BoxSizer4->Add(m_btnCheckUpdate, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    m_btnAbout = new wxButton(this, wxID_ABOUT, _("&About..."), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("wxID_ABOUT"));
    BoxSizer4->Add(m_btnAbout, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    m_btnQuit = new wxButton(this, wxID_EXIT, _("&Quit"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("wxID_EXIT"));
    BoxSizer4->Add(m_btnQuit, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer1->Add(BoxSizer4, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    SetSizer(BoxSizer1);
    BoxSizer1->Fit(this);
    BoxSizer1->SetSizeHints(this);
    Center();

    Connect(ID_BUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&RuleDlg::OnBtnNewClick);
    Connect(ID_BUTTON7,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&RuleDlg::OnBtnPreviewClick);
    Connect(ID_BUTTON4,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&RuleDlg::OnBtnRunClick);
    Connect(ID_BUTTON3,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&RuleDlg::OnBtnCheckUpdateClick);
    Connect(wxID_ABOUT,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&RuleDlg::OnBtnAboutClick);
    Connect(wxID_EXIT,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&RuleDlg::OnBtnQuitClick);
    Connect(wxID_ANY,wxEVT_INIT_DIALOG,(wxObjectEventFunction)&RuleDlg::OnInit);
    //*)
}

RuleDlg::~RuleDlg()
{
    //(*Destroy(RuleDlg)
    //*)
}


void RuleDlg::OnBtnQuitClick(wxCommandEvent& event)
{
    Close();
}

void RuleDlg::OnBtnAboutClick(wxCommandEvent& event)
{
    AboutDlg dlg(this);
    dlg.ShowModal();
}

void RuleDlg::OnBtnCheckUpdateClick(wxCommandEvent& event)
{
    wxLaunchDefaultBrowser(_T("http://down.boomworks.net/"));
}

/**
 * Preview
 */
void RuleDlg::OnBtnPreviewClick(wxCommandEvent& event)
{
    // Clear list
    m_pLcResult->DeleteAllItems();

    MoveFilesToFolder(false);
}
void RuleDlg::OnBtnRunClick(wxCommandEvent& event)
{
    //
    m_pLcResult->DeleteAllItems();

    MoveFilesToFolder(true);
}


void RuleDlg::MoveFilesToFolder(bool bPreview)
{
    wxRegKey *pRegKey = new wxRegKey(CSZ_DESKTOP_KEY_PATH);

    //will create the Key if it does not exist
    if ( !pRegKey->Exists() )
    {
        return;
    }

    wxString strDesktopFullPath;
    pRegKey->QueryValue(CSZ_DESKTOP_KEY_NAME, strDesktopFullPath);
    delete pRegKey;

    ///////////////////////////////////////////////////////////////////

    wxString strFilePath = ::wxFindFirstFile(strDesktopFullPath + _T("\\*"), wxFILE);
    if (strFilePath.IsEmpty())
    {
        return;
    }

    wxString strFileExtName;
    long nIndex = -1;
    wxString strTemp;
    while (!strFilePath.IsEmpty())
    {
        ///////////////////////////////////////////////////////////////
        MSG	msg;
        if ( ::PeekMessage( &msg, NULL, 0, 0, PM_REMOVE ))
        {
            ::DispatchMessage( &msg );
        }

        ///////////////////////////////////////////////////////////////

        wxFileName fnCur(strFilePath);
        strFileExtName = fnCur.GetExt();
        if (0 != strFileExtName.CmpNoCase(CSZ_EXCLUDING_FILE_EXT))
        {
            strFileExtName = _T("____") + strFileExtName;

            // Insert item
            nIndex = m_pLcResult->InsertItem(m_pLcResult->GetItemCount(), fnCur.GetFullPath());
            m_pLcResult->SetItem(nIndex, 1, strFileExtName);

            if (bPreview)
            {
                wxString strTemp(strDesktopFullPath + _T("\\") + strFileExtName);
                if (!wxDirExists(strTemp))
                {
                    wxMkdir(strTemp);
                }
                // Move file to dest dir
                wxRenameFile(fnCur.GetFullPath(), strTemp + _T("\\") + fnCur.GetFullName() );
                m_pLcResult->SetItem(nIndex, 2, _T("Compeleted"));
            }

        }// END IF

        // Next file
        strFilePath =::wxFindNextFile();
    }//END WHILE

}

void RuleDlg::OnInit(wxInitDialogEvent& event)
{
    //
    for (int i=0; i<N_COL_NUM; i++)
    {
        m_pLcResult->InsertColumn(i, CSZ_COL_NAMES[i]);
    }
}

void RuleDlg::OnBtnNewClick(wxCommandEvent& event)
{
	wxMessageBox(_T("The feature of Customization is still being developed.\nPlease wait for a while. "));
}
