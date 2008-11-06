#ifndef SRCTYPESELDLG_H
#define SRCTYPESELDLG_H

#ifndef WX_PRECOMP
//(*HeadersPCH(SrcTypeSelDlg)
#include <wx/sizer.h>
#include <wx/stattext.h>
#include <wx/checklst.h>
#include <wx/checkbox.h>
#include <wx/button.h>
#include <wx/dialog.h>
//*)
#endif

//(*Headers(SrcTypeSelDlg)
//*)

class SrcTypeSelDlg: public wxDialog
{
public:

    SrcTypeSelDlg(wxWindow* parent,wxWindowID id=wxID_ANY,const wxPoint& pos=wxDefaultPosition,const wxSize& size=wxDefaultSize);
    virtual ~SrcTypeSelDlg();

    //(*Declarations(SrcTypeSelDlg)
    wxStaticText* StaticText1;
    wxCheckBox* m_ckbSelAll;
    wxCheckListBox* m_lbxSrcTypes;
    wxButton* m_btnCancel;
    wxButton* m_btnOk;
    //*)


    //
    void GetSrcTypes(wxString& strSrcTypes) { strSrcTypes = m_strSrcTypes; }
    void SetSrcTypes(wxString strSrcTypes);

protected:

    //(*Identifiers(SrcTypeSelDlg)
    static const long ID_STATICTEXT1;
    static const long ID_CHECKLISTBOX1;
    static const long ID_CHECKBOX1;
    //*)

private:

    //(*Handlers(SrcTypeSelDlg)
    void OnBtnCancelClick(wxCommandEvent& event);
    void OnInit(wxInitDialogEvent& event);
    void OnBtnOkClick(wxCommandEvent& event);
    void Onm_ckbSelAllClick(wxCommandEvent& event);
    //*)


    wxString m_strSrcTypes;

    DECLARE_EVENT_TABLE()
};

#endif //
