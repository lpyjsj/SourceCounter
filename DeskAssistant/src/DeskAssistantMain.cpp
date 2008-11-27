/***************************************************************
 * Name:      DeskAssistantMain.cpp
 * Purpose:   Code for Application Frame
 * Author:    Boom (BoomWorks@hotmail.com)
 * Created:   2008-11-26
 * Copyright: Boom (http://www.boomworks.net)
 * License:
 **************************************************************/

#include <wx/msgdlg.h>
#include <wx/filename.h>
#include <wx/file.h>
#include <wx/config.h>

//(*InternalHeaders(DeskAssistantDialog)
#include <wx/intl.h>
#include <wx/string.h>
//*)

#include "wx_pch.h"
#include "DeskAssistantMain.h"
#include "AboutDlg.h"

///////////////////////////////////////////////////////////////////////

const int N_COL_NUM = 3;

const wxString CSZ_COL_NAMES[] =
{
    _("File"),
    _("Destination directory"),
    _("Progress"),
};

const wxChar* CSZ_DESKTOP_KEY_NAME = _T("Desktop");

const wxString CSZ_DESKTOP_KEY_PATH =
    _T("HKEY_CURRENT_USER\\Software\\Microsoft\\Windows\\CurrentVersion\\Explorer\\Shell Folders");

const wxString CSZ_EXCLUDING_FILE_EXT = _T("lnk"); // excluding file type
///////////////////////////////////////////////////////////////////////

//(*IdInit(DeskAssistantDialog)
const long DeskAssistantDialog::ID_LISTCTRL1 = wxNewId();
const long DeskAssistantDialog::ID_BUTTON1 = wxNewId();
const long DeskAssistantDialog::ID_BUTTON3 = wxNewId();
const long DeskAssistantDialog::ID_BUTTON2 = wxNewId();
//*)

BEGIN_EVENT_TABLE(DeskAssistantDialog,wxDialog)
    //(*EventTable(DeskAssistantDialog)
    //*)
END_EVENT_TABLE()

DeskAssistantDialog::DeskAssistantDialog(wxWindow* parent,wxWindowID id)
{
    //(*Initialize(DeskAssistantDialog)
    Create(parent, wxID_ANY, _("Desktop Assistant"), wxDefaultPosition, wxDefaultSize, wxDEFAULT_DIALOG_STYLE|wxSYSTEM_MENU|wxRESIZE_BORDER|wxMAXIMIZE_BOX|wxMINIMIZE_BOX, _T("wxID_ANY"));
    BoxSizer1 = new wxBoxSizer(wxVERTICAL);
    m_pLcFiles = new wxListCtrl(this, ID_LISTCTRL1, wxDefaultPosition, wxSize(320,200), wxLC_REPORT, wxDefaultValidator, _T("ID_LISTCTRL1"));
    BoxSizer1->Add(m_pLcFiles, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer2 = new wxBoxSizer(wxHORIZONTAL);
    m_btnPreview = new wxButton(this, ID_BUTTON1, _("&Preview"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON1"));
    BoxSizer2->Add(m_btnPreview, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    m_btnRun = new wxButton(this, ID_BUTTON3, _("&Run"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON3"));
    BoxSizer2->Add(m_btnRun, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer2->Add(-1,-1,1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    m_btnCheckUpdate = new wxButton(this, ID_BUTTON2, _("Check for update..."), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON2"));
    BoxSizer2->Add(m_btnCheckUpdate, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    Button1 = new wxButton(this, wxID_ABOUT, _("&About..."), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("wxID_ABOUT"));
    BoxSizer2->Add(Button1, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 4);
    Button2 = new wxButton(this, wxID_CLOSE, _("&Quit"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("wxID_CLOSE"));
    BoxSizer2->Add(Button2, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 4);
    BoxSizer1->Add(BoxSizer2, 0, wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 4);
    SetSizer(BoxSizer1);
    BoxSizer1->Fit(this);
    BoxSizer1->SetSizeHints(this);

    Connect(ID_BUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&DeskAssistantDialog::OnBtnPreviewClick);
    Connect(ID_BUTTON3,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&DeskAssistantDialog::OnBtnRunClick);
    Connect(ID_BUTTON2,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&DeskAssistantDialog::OnBtnCheckUpdateClick);
    Connect(wxID_ABOUT,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&DeskAssistantDialog::OnAbout);
    Connect(wxID_CLOSE,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&DeskAssistantDialog::OnQuit);
    Connect(wxID_ANY,wxEVT_INIT_DIALOG,(wxObjectEventFunction)&DeskAssistantDialog::OnInit);
    //*)
}

DeskAssistantDialog::~DeskAssistantDialog()
{
    //(*Destroy(DeskAssistantDialog)
    //*)
}

void DeskAssistantDialog::OnQuit(wxCommandEvent& event)
{
    Close();
}

void DeskAssistantDialog::OnAbout(wxCommandEvent& event)
{
    // wxString msg = wxbuildinfo(long_f);
    // wxMessageBox(msg, _("Welcome to..."));
    AboutDlg dlg(this);
    dlg.ShowModal();
}

void DeskAssistantDialog::OnBtnRunClick(wxCommandEvent& event)
{
    // Clear listcltr items
    m_pLcFiles->DeleteAllItems();
    MoveFilesToFolder(true);
}

void DeskAssistantDialog::OnInit(wxInitDialogEvent& event)
{
    //
    for (int i=0; i<N_COL_NUM; i++)
    {
        m_pLcFiles->InsertColumn(i, CSZ_COL_NAMES[i]);
    }
}

void DeskAssistantDialog::OnBtnPreviewClick(wxCommandEvent& event)
{
    // Clear listcltr items
    m_pLcFiles->DeleteAllItems();

    //
    MoveFilesToFolder(false);
}

void DeskAssistantDialog::MoveFilesToFolder(bool bPreview)
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
            nIndex = m_pLcFiles->InsertItem(m_pLcFiles->GetItemCount(), fnCur.GetFullPath());
            m_pLcFiles->SetItem(nIndex, 1, strFileExtName);

            if (bPreview)
            {
                wxString strTemp(strDesktopFullPath + _T("\\") + strFileExtName);
                if (!wxDirExists(strTemp))
                {
                    wxMkdir(strTemp);
                }
                // Move file to dest dir
                wxRenameFile(fnCur.GetFullPath(), strTemp + _T("\\") + fnCur.GetFullName() );
                m_pLcFiles->SetItem(nIndex, 2, _T("Compeleted"));
            }

        }// END IF

        // Next file
        strFilePath =::wxFindNextFile();
    }//END WHILE

}

void DeskAssistantDialog::OnBtnCheckUpdateClick(wxCommandEvent& event)
{
	wxLaunchDefaultBrowser(_T("http://down.boomworks.net/"));
}
