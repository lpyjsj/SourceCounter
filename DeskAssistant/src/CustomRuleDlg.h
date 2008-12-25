#ifndef CUSTOMRULEDLG_H
#define CUSTOMRULEDLG_H

#ifndef WX_PRECOMP
//(*HeadersPCH(CustomRuleDlg)
#include <wx/sizer.h>
#include <wx/stattext.h>
#include <wx/radiobox.h>
#include <wx/textctrl.h>
#include <wx/button.h>
#include <wx/dialog.h>
//*)
#endif
//(*Headers(CustomRuleDlg)
//*)

#include "rule.h"


class CustomRuleDlg: public wxDialog
{
public:

    CustomRuleDlg(wxWindow* parent,wxWindowID id=wxID_ANY);
    virtual ~CustomRuleDlg();

    //(*Declarations(CustomRuleDlg)
    wxStaticText* StaticText2;
    wxRadioBox* RadioBox2;
    wxStaticText* StaticText1;
    wxButton* Button2;
    wxButton* m_btnOK;
    wxButton* Button3;
    wxTextCtrl* TextCtrl2;
    wxTextCtrl* TextCtrl1;
    //*)

    ///////////////////////////////////////////////////////////////////
	void SetRule(Rule* pRule)		{ m_pRule = pRule; }


protected:

    //(*Identifiers(CustomRuleDlg)
    static const long ID_RADIOBOX2;
    static const long ID_STATICTEXT1;
    static const long ID_TEXTCTRL1;
    static const long ID_STATICTEXT2;
    static const long ID_TEXTCTRL2;
    static const long ID_BUTTON3;
    //*)

private:

    //(*Handlers(CustomRuleDlg)
    void OnBtnOKClick(wxCommandEvent& event);
    void OnInit(wxInitDialogEvent& event);
    //*)

    ///////////////////////////////////////////////////////////////////

	Rule* m_pRule;

    ///////////////////////////////////////////////////////////////////


    DECLARE_EVENT_TABLE()
};

#endif
