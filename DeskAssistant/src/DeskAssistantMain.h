/***************************************************************
 * Name:      DeskAssistantMain.h
 * Purpose:   Defines Application Frame
 * Author:    Boom (BoomWorks@hotmail.com)
 * Created:   2008-11-26
 * Copyright: Boom (http://www.boomworks.net)
 * License:
 **************************************************************/

#ifndef DESKASSISTANTMAIN_H
#define DESKASSISTANTMAIN_H

//(*Headers(DeskAssistantDialog)
#include <wx/listctrl.h>
#include <wx/sizer.h>
#include <wx/button.h>
#include <wx/dialog.h>
//*)

class DeskAssistantDialog: public wxDialog
{
    public:

        DeskAssistantDialog(wxWindow* parent,wxWindowID id = -1);
        virtual ~DeskAssistantDialog();

    private:

        //(*Handlers(DeskAssistantDialog)
        void OnQuit(wxCommandEvent& event);
        void OnAbout(wxCommandEvent& event);
        void OnBtnRunClick(wxCommandEvent& event);
        void OnInit(wxInitDialogEvent& event);
        //*)

        //(*Identifiers(DeskAssistantDialog)
        static const long ID_LISTCTRL1;
        static const long ID_BUTTON3;
        //*)

        //(*Declarations(DeskAssistantDialog)
        wxListCtrl* m_pLcFiles;
        wxButton* Button1;
        wxBoxSizer* BoxSizer2;
        wxButton* Button2;
        wxBoxSizer* BoxSizer1;
        wxButton* m_btnRun;
        //*)

        DECLARE_EVENT_TABLE()
};

#endif // DESKASSISTANTMAIN_H
