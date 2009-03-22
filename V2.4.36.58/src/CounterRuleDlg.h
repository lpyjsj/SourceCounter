#ifndef COUNTERRULEDLG_H
#define COUNTERRULEDLG_H

#ifndef WX_PRECOMP
//(*HeadersPCH(CounterRuleDlg)
#include <wx/sizer.h>
#include <wx/stattext.h>
#include <wx/textctrl.h>
#include <wx/button.h>
#include <wx/dialog.h>
#include <wx/combobox.h>
//*)
#endif
//(*Headers(CounterRuleDlg)
#include <wx/statline.h>
//*)

#include "CountingManager.h"
#include "CounterRule.h"

class CounterRuleDlg: public wxDialog
{
public:

    enum RuleMode
    {
        RuleModeNew,
        RuleModeEdit,
    };

    CounterRuleDlg(wxWindow* parent,RuleMode nMode=RuleModeNew, wxWindowID id=wxID_ANY,const wxPoint& pos=wxDefaultPosition,const wxSize& size=wxDefaultSize);
    virtual ~CounterRuleDlg();

    //(*Declarations(CounterRuleDlg)
    wxStaticText* StaticText2;
    wxStaticText* StaticText6;
    wxTextCtrl* m_txtSlgLnComm;
    wxStaticText* m_txtSLComm;
    wxStaticText* StaticText1;
    wxTextCtrl* m_txtRuleDesc;
    wxTextCtrl* m_txtMltLnCommBegin;
    wxStaticText* StaticText3;
    wxTextCtrl* m_txtMltLnCommEnd;
    wxButton* m_btnOK;
    wxStaticText* StaticText5;
    wxStaticText* StaticText7;
    wxButton* m_btnCancel;
    wxStaticLine* StaticLine1;
    wxComboBox* m_cmbMethod;
    wxTextCtrl* m_txtExtDesc;
    wxTextCtrl* m_txtExtName;
    //*)

    void SetRuleData(MapStrToCounterRule* pMapCounterRule, FileExtension* pFileExt)
    {
        m_pMapCounterRule = pMapCounterRule;
        m_pFileExt = pFileExt;
    }

protected:

    //(*Identifiers(CounterRuleDlg)
    static const long ID_STATICTEXT1;
    static const long ID_TEXTCTRL1;
    static const long ID_STATICTEXT3;
    static const long ID_TEXTCTRL2;
    static const long ID_STATICTEXT2;
    static const long ID_COMBOBOX1;
    static const long ID_STATICTEXT7;
    static const long ID_TEXTCTRL6;
    static const long ID_STATICTEXT4;
    static const long ID_TEXTCTRL3;
    static const long ID_STATICTEXT5;
    static const long ID_TEXTCTRL4;
    static const long ID_STATICTEXT6;
    static const long ID_TEXTCTRL5;
    static const long ID_STATICLINE1;
    //*)

private:

    //(*Handlers(CounterRuleDlg)
    void OnInit(wxInitDialogEvent& event);
    void OnBtnOKClick(wxCommandEvent& event);
    void OnBtnCancelClick(wxCommandEvent& event);
    void OnCmbMethodSelect(wxCommandEvent& event);
    //*)

	RuleMode m_nMode;
    MapStrToCounterRule* m_pMapCounterRule;
    FileExtension* m_pFileExt;

	void updateRuleCtrls();

    DECLARE_EVENT_TABLE()
};

#endif
