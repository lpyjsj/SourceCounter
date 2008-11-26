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

//(*InternalHeaders(DeskAssistantDialog)
#include <wx/intl.h>
#include <wx/string.h>
//*)

#include "wx_pch.h"
#include "DeskAssistantMain.h"

///////////////////////////////////////////////////////////////////////

const int N_COL_NUM = 3;

const wxString CSZ_COL_NAMES[] =
{
    _("File"),
    _("Dest dir"),
    _("Progress"),
};

///////////////////////////////////////////////////////////////////////

//helper functions
enum wxbuildinfoformat
{
    short_f, long_f
};

wxString wxbuildinfo(wxbuildinfoformat format)
{
    wxString wxbuild(wxVERSION_STRING);

    if (format == long_f )
    {
#if defined(__WXMSW__)
        wxbuild << _T("-Windows");
#elif defined(__UNIX__)
        wxbuild << _T("-Linux");
#endif

#if wxUSE_UNICODE
        wxbuild << _T("-Unicode build");
#else
        wxbuild << _T("-ANSI build");
#endif // wxUSE_UNICODE
    }

    return wxbuild;
}

//(*IdInit(DeskAssistantDialog)
const long DeskAssistantDialog::ID_LISTCTRL1 = wxNewId();
const long DeskAssistantDialog::ID_BUTTON3 = wxNewId();
//*)

BEGIN_EVENT_TABLE(DeskAssistantDialog,wxDialog)
    //(*EventTable(DeskAssistantDialog)
    //*)
END_EVENT_TABLE()

DeskAssistantDialog::DeskAssistantDialog(wxWindow* parent,wxWindowID id)
{
    //(*Initialize(DeskAssistantDialog)
    Create(parent, wxID_ANY, _("wxWidgets app"), wxDefaultPosition, wxDefaultSize, wxDEFAULT_DIALOG_STYLE|wxSYSTEM_MENU|wxRESIZE_BORDER|wxMAXIMIZE_BOX|wxMINIMIZE_BOX, _T("wxID_ANY"));
    BoxSizer1 = new wxBoxSizer(wxVERTICAL);
    m_pLcFiles = new wxListCtrl(this, ID_LISTCTRL1, wxDefaultPosition, wxSize(320,200), wxLC_REPORT, wxDefaultValidator, _T("ID_LISTCTRL1"));
    BoxSizer1->Add(m_pLcFiles, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer2 = new wxBoxSizer(wxHORIZONTAL);
    m_btnRun = new wxButton(this, ID_BUTTON3, _("&Run"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON3"));
    BoxSizer2->Add(m_btnRun, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer2->Add(-1,-1,1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    Button1 = new wxButton(this, wxID_ABOUT, _("About"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("wxID_ABOUT"));
    BoxSizer2->Add(Button1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 4);
    Button2 = new wxButton(this, wxID_CLOSE, _("Quit"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("wxID_CLOSE"));
    BoxSizer2->Add(Button2, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 4);
    BoxSizer1->Add(BoxSizer2, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 4);
    SetSizer(BoxSizer1);
    BoxSizer1->Fit(this);
    BoxSizer1->SetSizeHints(this);

    Connect(ID_BUTTON3,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&DeskAssistantDialog::OnBtnRunClick);
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
    wxString msg = wxbuildinfo(long_f);
    wxMessageBox(msg, _("Welcome to..."));
}

void DeskAssistantDialog::OnBtnRunClick(wxCommandEvent& event)
{
    //
    //wxString strDeskFullPath = _T("C:\\Documents and Settings\\pengli\\Desktop\\*");
    wxString strDeskFullPath = _T("C:\\Documents and Settings\\boomworks\\桌面\\*");
    wxString strDeskFullPath1 = _T("C:\\Documents and Settings\\boomworks\\桌面\\");

    //wxSetWorkingDirectory(strDeskFullPath);

    wxString strFileExtName;

    wxString fname = ::wxFindFirstFile(strDeskFullPath, wxFILE);
    if (fname.IsEmpty())
    {
        return;
    }

    while (!fname.IsEmpty())
    {
        ///////////////////////////////////////////////////////////////
        MSG	msg;
        if ( ::PeekMessage( &msg, NULL, 0, 0, PM_REMOVE ))
        {
            ::DispatchMessage( &msg );
        }

        ///////////////////////////////////////////////////////////////

        // Collect counting info
        //getFileExtName(fname, strFileExtName);
        wxFileName ff(fname);
        strFileExtName = ff.GetExt();
        strFileExtName = _T("____") + strFileExtName;

		wxString strTemp(strDeskFullPath1 + strFileExtName);
        if (!wxDirExists(strTemp))
        {
            wxMkdir(strTemp);
        }

		wxRenameFile(ff.GetFullPath(), strTemp + _T("\\") + ff.GetFullName() );


//		wxFile fileTemp(fname);
//		if(fileTemp.IsOpened())
//			strFileExtName += _T(" Opened");
        // wxMessageBox( ff.GetFullPath(),strFileExtName );

        long nIndex = m_pLcFiles->InsertItem(m_pLcFiles->GetItemCount(), ff.GetFullPath());
        m_pLcFiles->SetItem(nIndex, 1, strFileExtName);
        m_pLcFiles->SetItem(nIndex, 2, _T("aaa"));

        // File function
        // wxCopyFile

        ///////////////////////////////////////////////////////////////

        // Next file
        fname =::wxFindNextFile();
    }//END WHILE

}

void DeskAssistantDialog::OnInit(wxInitDialogEvent& event)
{
    //
    for (int i=0; i<N_COL_NUM; i++)
    {
        m_pLcFiles->InsertColumn(i, CSZ_COL_NAMES[i]);
    }
}
