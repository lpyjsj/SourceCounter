#ifndef RULEDLG_H
#define RULEDLG_H

#ifndef WX_PRECOMP
//(*HeadersPCH(RuleDlg)
#include <wx/listctrl.h>
#include <wx/sizer.h>
#include <wx/radiobox.h>
#include <wx/checklst.h>
#include <wx/button.h>
#include <wx/dialog.h>
//*)
#endif
//(*Headers(RuleDlg)
//*)

#include <wx/listctrl.h>


class RuleDlg: public wxDialog
{
public:

    RuleDlg(wxWindow* parent,wxWindowID id=wxID_ANY,const wxPoint& pos=wxDefaultPosition,const wxSize& size=wxDefaultSize);
    virtual ~RuleDlg();

    //(*Declarations(RuleDlg)
    wxButton* Button1;
    wxButton* m_btnQuit;
    wxButton* m_btnPreview;
    wxCheckListBox* m_pLbxCustRules;
    wxButton* Button2;
    wxButton* Button6;
    wxRadioBox* m_pRbxBaseRules;
    wxButton* m_btnCheckUpdate;
    wxButton* Button9;
    wxListCtrl* m_pLcResult;
    wxButton* m_btnRun;
    wxButton* Button8;
    wxButton* m_btnAbout;
    //*)

protected:

    //(*Identifiers(RuleDlg)
    static const long ID_BUTTON1;
    static const long ID_BUTTON2;
    static const long ID_BUTTON6;
    static const long ID_BUTTON8;
    static const long ID_BUTTON9;
    static const long ID_CHECKLISTBOX1;
    static const long ID_RADIOBOX1;
    static const long ID_BUTTON7;
    static const long ID_BUTTON4;
    static const long ID_LISTCTRL1;
    static const long ID_BUTTON3;
    //*)

private:

    //(*Handlers(RuleDlg)
    void OnBtnQuitClick(wxCommandEvent& event);
    void OnBtnAboutClick(wxCommandEvent& event);
    void OnBtnPreviewClick(wxCommandEvent& event);
    void OnBtnCheckUpdateClick(wxCommandEvent& event);
    void OnBtnRunClick(wxCommandEvent& event);
    void OnInit(wxInitDialogEvent& event);
    //*)

    ///////////////////////////////////////////////////////////////
    void MoveFilesToFolder(bool bPreview);


    DECLARE_EVENT_TABLE()
};

#endif
