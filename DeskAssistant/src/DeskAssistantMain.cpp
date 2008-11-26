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
#include <wx/settings.h>
#include <wx/font.h>
#include <wx/intl.h>
#include <wx/string.h>
//*)

#include "wx_pch.h"
#include "DeskAssistantMain.h"

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
const long DeskAssistantDialog::ID_STATICTEXT1 = wxNewId();
const long DeskAssistantDialog::ID_LISTCTRL1 = wxNewId();
const long DeskAssistantDialog::ID_BUTTON3 = wxNewId();
const long DeskAssistantDialog::ID_BUTTON1 = wxNewId();
const long DeskAssistantDialog::ID_BUTTON2 = wxNewId();
//*)

BEGIN_EVENT_TABLE(DeskAssistantDialog,wxDialog)
    //(*EventTable(DeskAssistantDialog)
    //*)
END_EVENT_TABLE()

DeskAssistantDialog::DeskAssistantDialog(wxWindow* parent,wxWindowID id)
{
    //(*Initialize(DeskAssistantDialog)
    wxBoxSizer* BoxSizer3;

    Create(parent, wxID_ANY, _("wxWidgets app"), wxDefaultPosition, wxDefaultSize, wxDEFAULT_DIALOG_STYLE, _T("wxID_ANY"));
    BoxSizer1 = new wxBoxSizer(wxVERTICAL);
    StaticText1 = new wxStaticText(this, ID_STATICTEXT1, _("Welcome to\nwxWidgets"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT1"));
    wxFont StaticText1Font = wxSystemSettings::GetFont(wxSYS_DEFAULT_GUI_FONT);
    if ( !StaticText1Font.Ok() ) StaticText1Font = wxSystemSettings::GetFont(wxSYS_DEFAULT_GUI_FONT);
    StaticText1Font.SetPointSize(20);
    StaticText1->SetFont(StaticText1Font);
    BoxSizer1->Add(StaticText1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 10);
    BoxSizer3 = new wxBoxSizer(wxVERTICAL);
    m_lstFiles = new wxListCtrl(this, ID_LISTCTRL1, wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_LISTCTRL1"));
    BoxSizer3->Add(m_lstFiles, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer1->Add(BoxSizer3, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    m_btnRun = new wxButton(this, ID_BUTTON3, _("&Run"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON3"));
    BoxSizer1->Add(m_btnRun, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer2 = new wxBoxSizer(wxVERTICAL);
    Button1 = new wxButton(this, ID_BUTTON1, _("About"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON1"));
    BoxSizer2->Add(Button1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 4);
    Button2 = new wxButton(this, ID_BUTTON2, _("Quit"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON2"));
    BoxSizer2->Add(Button2, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 4);
    BoxSizer1->Add(BoxSizer2, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 4);
    SetSizer(BoxSizer1);
    BoxSizer1->Fit(this);
    BoxSizer1->SetSizeHints(this);

    Connect(ID_BUTTON3,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&DeskAssistantDialog::OnBtnRunClick);
    Connect(ID_BUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&DeskAssistantDialog::OnAbout);
    Connect(ID_BUTTON2,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&DeskAssistantDialog::OnQuit);
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
    wxString strValidPath = _T("C:\\Documents and Settings\\pengli\\Desktop\\*");

	wxString strFileExtName;

    wxString fname = ::wxFindFirstFile(strValidPath, wxFILE);
    if (fname.IsEmpty())
    {
        return;
    }

    while (!fname.IsEmpty())
    {
        //CWaitCursor wait;

        ///////////////////////////////////////////////////////////



        ///////////////////////////////////////////////////////////
        MSG	msg;
        if ( ::PeekMessage( &msg, NULL, 0, 0, PM_REMOVE ))
        {
            ::DispatchMessage( &msg );
        }

        ///////////////////////////////////////////////////////////
        // Collect counting info
        //getFileExtName(fname, strFileExtName);
        wxFileName ff(fname);
        strFileExtName = ff.GetExt();
        strFileExtName = _T("____") + strFileExtName;

        if(!wxDirExists(strFileExtName))
        {
        	wxMkdir(strFileExtName);
		}


		wxFile fileTemp(fname);
		if(fileTemp.IsOpened())
			strFileExtName += _T(" Opened");

		wxMessageBox( ff.GetFullPath(),strFileExtName );





		// File function
		// wxCopyFile

		///////////////////////////////////////////////////////////////
        // Next file
        fname =::wxFindNextFile();
    }// While





}
