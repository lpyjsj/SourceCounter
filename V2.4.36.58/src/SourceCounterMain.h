/***************************************************************
 * Name:      SourceCounterMain.h
 * Purpose:   Defines Application Frame
 * Author:    boomworks.net (boomworks@gmail.com)
 * Created:   2008-10-09
 * Copyright: boomworks.net (http://www.boomworks.net)
 * License:
 **************************************************************/

#ifndef SOURCECOUNTERMAIN_H
#define SOURCECOUNTERMAIN_H

//(*Headers(SourceCounterDialog)
#include <wx/listctrl.h>
#include <wx/sizer.h>
#include <wx/stattext.h>
#include <wx/menu.h>
#include <wx/checklst.h>
#include <wx/checkbox.h>
#include <wx/filedlg.h>
#include <wx/button.h>
#include <wx/dirdlg.h>
#include <wx/dialog.h>
#include <wx/combobox.h>
//*)

#include "CountingManager.h"

///////////////////////////////////////////////////////////////////////

class SourceCounterDialog: public wxDialog, CCounterObserver
{
public:

    SourceCounterDialog(wxWindow* parent,wxWindowID id = -1);
    virtual ~SourceCounterDialog();

private:

    //(*Handlers(SourceCounterDialog)
    void OnQuit(wxCommandEvent& event);
    void OnAbout(wxCommandEvent& event);
    void OnBtnMoreSettingsClick(wxCommandEvent& event);
    void OnBtnAddDirClick(wxCommandEvent& event);
    void OnBtnDeleteClick(wxCommandEvent& event);
    void OnBtnSelSrcTypeClick(wxCommandEvent& event);
    void OnLbxSrcFolderCheck(wxCommandEvent& event);
    void OnBtnStartClick(wxCommandEvent& event);
    void OnInit(wxInitDialogEvent& event);
    void OnBtnStopClick(wxCommandEvent& event);
    void OnBtnSaveClick(wxCommandEvent& event);
    void OnBtnUiLangClick(wxCommandEvent& event);
    void OnBtnCheckUpdateClick(wxCommandEvent& event);
    void OnLstResultItemRClick(wxListEvent& event);
    void OnMenuItemOpenSelected(wxCommandEvent& event);
    void OnMenuItemOpenDirSelected(wxCommandEvent& event);
    //*)

    void OnLbxSrcFolderItemSelect(wxCommandEvent& evt);

    //(*Identifiers(SourceCounterDialog)
    static const long ID_STATICTEXT2;
    static const long ID_CHECKLISTBOX1;
    static const long ID_BUTTON3;
    static const long ID_BUTTON9;
    static const long ID_STATICTEXT1;
    static const long ID_COMBOBOX1;
    static const long ID_BUTTON8;
    static const long ID_CHECKBOX1;
    static const long ID_BUTTON4;
    static const long ID_STATICTEXT9;
    static const long ID_STATICTEXT10;
    static const long ID_BUTTON5;
    static const long ID_BUTTON6;
    static const long ID_LISTCTRL1;
    static const long ID_STATICTEXT12;
    static const long ID_STATICTEXT4;
    static const long ID_STATICTEXT22;
    static const long ID_STATICTEXT21;
    static const long ID_STATICTEXT3;
    static const long ID_STATICTEXT11;
    static const long ID_STATICTEXT13;
    static const long ID_STATICTEXT6;
    static const long ID_STATICTEXT23;
    static const long ID_STATICTEXT26;
    static const long ID_STATICTEXT5;
    static const long ID_STATICTEXT14;
    static const long ID_STATICTEXT16;
    static const long ID_STATICTEXT8;
    static const long ID_STATICTEXT27;
    static const long ID_STATICTEXT24;
    static const long ID_STATICTEXT18;
    static const long ID_STATICTEXT20;
    static const long ID_STATICTEXT29;
    static const long ID_STATICTEXT30;
    static const long ID_STATICTEXT25;
    static const long ID_STATICTEXT28;
    static const long ID_STATICTEXT19;
    static const long ID_STATICTEXT17;
    static const long ID_STATICTEXT7;
    static const long ID_STATICTEXT15;
    static const long ID_BUTTON7;
    static const long ID_BUTTON11;
    static const long ID_BUTTON10;
    static const long ID_MENU_ITEM_OPEN;
    static const long ID_MENU_ITEM_OPENDIR;
    //*)

    //(*Declarations(SourceCounterDialog)
    wxStaticText* StaticText10;
    wxStaticText* StaticText9;
    wxStaticText* StaticText13;
    wxListCtrl* m_lstResult;
    wxStaticText* StaticText2;
    wxStaticText* m_lblTotalLines;
    wxStaticText* StaticText14;
    wxDirDialog* m_dlgAddDir;
    wxButton* Button1;
    wxButton* m_btnDelete;
    wxStaticText* StaticText6;
    wxStaticText* StaticText8;
    wxStaticText* StaticText11;
    wxStaticText* StaticText18;
    wxButton* m_btnStart;
    wxButton* m_btnSave;
    wxStaticText* m_lblStatus;
    wxCheckBox* m_chbRecursiveCouting;
    wxStaticText* StaticText1;
    wxStaticText* StaticText3;
    wxButton* m_btnUiLang;
    wxButton* Button2;
    wxButton* m_btnAdd;
    wxStaticText* m_lblTotalSize;
    wxButton* m_btnMoreSetting;
    wxButton* m_btnCheckUpdate;
    wxStaticText* StaticText5;
    wxStaticText* StaticText7;
    wxStaticText* m_lblTotalCost;
    wxButton* m_btnStop;
    wxStaticText* m_lblUtDefects;
    wxFileDialog* m_dlgFile;
    wxStaticText* m_lblTotalMM;
    wxBoxSizer* BoxSizer1;
    wxStaticText* StaticText15;
    wxStaticText* StaticText12;
    wxStaticText* m_lblItCases;
    wxMenu m_pMenu;
    wxButton* m_btnSelSrcType;
    wxCheckListBox* m_lbxSrcFolder;
    wxStaticText* StaticText4;
    wxComboBox* m_cmbSrcTypes;
    wxStaticText* m_lblBlankLines;
    wxStaticText* StaticText16;
    wxStaticText* m_lblTotalFiles;
    wxStaticText* m_lblItDefects;
    wxStaticText* m_lblCodeLines;
    wxStaticText* m_lblCommentLines;
    wxStaticText* m_lblUtCases;
    //*)

private:

    CountingManager* m_pCountingMgr;      ///< Counting manager

    ///////////////////////////////////////////////////////////////

    void updateOptionsCtrls();
    void initCountingCtrls();

    void getSelectedItem(wxListItem& listItem);

    /**
     * update statistic infomation.
     */
    virtual void UpdateCountingInfoCtrls( void );

    ///////////////////////////////////////////////////////////////

    DECLARE_EVENT_TABLE()
};

#endif // SOURCECOUNTERMAIN_H
