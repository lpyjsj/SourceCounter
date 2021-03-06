#ifndef RULEDLG_H
#define RULEDLG_H

#ifndef WX_PRECOMP
//(*HeadersPCH(MainDlg)
#include <wx/listctrl.h>
#include <wx/sizer.h>
#include <wx/stattext.h>
#include <wx/radiobox.h>
#include <wx/checklst.h>
#include <wx/statbmp.h>
#include <wx/button.h>
#include <wx/dialog.h>
//*)
#endif
//(*Headers(MainDlg)
#include <wx/notebook.h>
//*)

#include <wx/listctrl.h>

#include "CategorizeMgr.h"
#include "CategorizationObserver.h"

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////

class MainDlg: public wxDialog, CategorizationObserver
{
public:

    MainDlg(wxWindow* parent,wxWindowID id=wxID_ANY,const wxPoint& pos=wxDefaultPosition,const wxSize& size=wxDefaultSize);
    virtual ~MainDlg();

    //(*Declarations(MainDlg)
    wxNotebook* Notebook1;
    wxButton* m_btnDown;
    wxButton* m_btnEdit;
    wxButton* m_btnDelete;
    wxStaticBitmap* StaticBitmap1;
    wxListCtrl* m_pLcFolderSize;
    wxButton* m_btnQuit;
    wxButton* m_btnPreview;
    wxStaticText* StaticText1;
    wxCheckListBox* m_pLbxCustRules;
    wxButton* m_btnUiLang;
    wxButton* m_btnUp;
    wxRadioBox* m_pRbxBaseRules;
    wxButton* m_btnCheckUpdate;
    wxButton* m_btnNew;
    wxListCtrl* m_pLcResult;
    wxButton* m_btnRun;
    wxButton* m_btnAbout;
    wxButton* m_btnTest;
    //*)

	///////////////////////////////////////////////////////////////////////

	virtual void UpdateCategorizationCtrls(void);

protected:

    //(*Identifiers(MainDlg)
    static const long ID_STATICBITMAP1;
    static const long ID_STATICTEXT1;
    static const long ID_BUTTON1;
    static const long ID_BUTTON2;
    static const long ID_BUTTON6;
    static const long ID_BUTTON8;
    static const long ID_BUTTON9;
    static const long ID_CHECKLISTBOX1;
    static const long ID_RADIOBOX1;
    static const long ID_BUTTON7;
    static const long ID_BUTTON4;
    static const long ID_BUTTON5;
    static const long ID_LISTCTRL1;
    static const long ID_LISTCTRL2;
    static const long ID_NOTEBOOK1;
    static const long ID_BUTTON3;
    static const long ID_BUTTON10;
    //*)

private:

    //(*Handlers(MainDlg)
    void OnBtnQuitClick(wxCommandEvent& event);
    void OnBtnAboutClick(wxCommandEvent& event);
    void OnBtnPreviewClick(wxCommandEvent& event);
    void OnBtnCheckUpdateClick(wxCommandEvent& event);
    void OnBtnRunClick(wxCommandEvent& event);
    void OnInit(wxInitDialogEvent& event);
    void OnBtnNewClick(wxCommandEvent& event);
    void OnListbook1PageChanged(wxNotebookEvent& event);
    void OnBtnTestClick(wxCommandEvent& event);
    void OnBtnEditClick(wxCommandEvent& event);
    void OnBtnDeleteClick(wxCommandEvent& event);
    void OnBtnUpClick(wxCommandEvent& event);
    void OnBtnDownClick(wxCommandEvent& event);
    void OnBtnUiLangClick(wxCommandEvent& event);
    //*)

	void OnLbxRuleItemSelect(wxCommandEvent& event);

    ///////////////////////////////////////////////////////////////////

	CategorizeMgr 		m_categorizeMgr;


    ///////////////////////////////////////////////////////////////////

    void getDesktopPath(wxString& strPath);
//	void categorizeByTime(bool bPreview);
	void updateUICtrls();

	void updateButtons();
	void updateRuleLbx(bool bClear);
	///////////////////////////////////////////////////////////////////

    DECLARE_EVENT_TABLE()
};

#endif
