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
#include <wx/statline.h>
//*)

#include "CountingManager.h"

class SrcTypeSelDlg: public wxDialog
{
public:

    SrcTypeSelDlg(wxWindow* parent,wxWindowID id=wxID_ANY,const wxPoint& pos=wxDefaultPosition,const wxSize& size=wxDefaultSize);
    virtual ~SrcTypeSelDlg();

    //(*Declarations(SrcTypeSelDlg)
    wxButton* m_btnEdit;
    wxStaticText* StaticText1;
    wxButton* m_btnAdd;
    wxCheckBox* m_ckbSelAll;
    wxCheckListBox* m_lbxSrcTypes;
    wxButton* m_btnCancel;
    wxStaticLine* StaticLine1;
    wxButton* m_btnDel;
    wxButton* m_btnOk;
    //*)


    //
    void GetSrcTypes(wxString& strSrcTypes)
    {
        strSrcTypes = m_strSrcTypes;
    }
    // void SetSrcTypes(wxString strSrcTypes);


    void SetMapData(MapStrToCounterRule* pMapRule, MapStrToFileExtension* pMapFileExt)
    {
        m_pMapRule = pMapRule;
        m_pMapFileExtension = pMapFileExt;
    }

protected:

    //(*Identifiers(SrcTypeSelDlg)
    static const long ID_STATICTEXT1;
    static const long ID_CHECKLISTBOX1;
    static const long ID_CHECKBOX1;
    static const long ID_BUTTON1;
    static const long ID_BUTTON2;
    static const long ID_BUTTON3;
    static const long ID_STATICLINE1;
    //*)

private:

    //(*Handlers(SrcTypeSelDlg)
    void OnBtnCancelClick(wxCommandEvent& event);
    void OnInit(wxInitDialogEvent& event);
    void OnBtnOkClick(wxCommandEvent& event);
    void Onm_ckbSelAllClick(wxCommandEvent& event);
    void OnBtnAddClick(wxCommandEvent& event);
    void OnLbxSrcTypesSelect(wxCommandEvent& event);
    void OnBtnEditClick(wxCommandEvent& event);
    void OnBtnDelClick(wxCommandEvent& event);
    //*)


    wxString m_strSrcTypes;
    MapStrToCounterRule* m_pMapRule;
    MapStrToFileExtension* m_pMapFileExtension;

    ///////////////////////////////////////////////////////////////////

	FileExtension* getSelItemData();
    void updateSrcTypeLbx();
    void updateButtons();

    DECLARE_EVENT_TABLE()
};

#endif //
