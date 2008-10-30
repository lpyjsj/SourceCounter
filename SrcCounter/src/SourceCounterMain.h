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
#include <wx/checklst.h>
#include <wx/checkbox.h>
#include <wx/filedlg.h>
#include <wx/button.h>
#include <wx/dirdlg.h>
#include <wx/dialog.h>
#include <wx/combobox.h>
//*)

///////////////////////////////////////////////////////////////////////

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
    void OnLstItemActivated(wxListEvent& event);
    void OnBtnUiLangClick(wxCommandEvent& event);
    void OnBtnCheckUpdateClick(wxCommandEvent& event);
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
    static const long ID_BUTTON5;
    static const long ID_BUTTON6;
    static const long ID_LISTCTRL1;
    static const long ID_STATICTEXT3;
    static const long ID_STATICTEXT11;
    static const long ID_STATICTEXT12;
    static const long ID_STATICTEXT4;
    static const long ID_STATICTEXT5;
    static const long ID_STATICTEXT14;
    static const long ID_STATICTEXT13;
    static const long ID_STATICTEXT6;
    static const long ID_STATICTEXT7;
    static const long ID_STATICTEXT15;
    static const long ID_STATICTEXT16;
    static const long ID_STATICTEXT8;
    static const long ID_STATICTEXT9;
    static const long ID_STATICTEXT10;
    static const long ID_BUTTON7;
    static const long ID_BUTTON11;
    static const long ID_BUTTON10;
    static const long ID_BUTTON1;
    static const long ID_BUTTON2;
    //*)

    //(*Declarations(SourceCounterDialog)
    wxStaticText* StaticText9;
    wxStaticText* StaticText13;
    wxListCtrl* m_lstResult;
    wxStaticText* StaticText2;
    wxStaticText* m_lblTotalLines;
    wxDirDialog* m_dlgAddDir;
    wxButton* Button1;
    wxButton* m_btnDelete;
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
    wxButton* m_btnStop;
    wxFileDialog* m_dlgFile;
    wxBoxSizer* BoxSizer1;
    wxStaticText* StaticText12;
    wxButton* m_btnSelSrcType;
    wxCheckListBox* m_lbxSrcFolder;
    wxComboBox* m_cmbSrcTypes;
    wxStaticText* m_lblBlankLines;
    wxStaticText* StaticText16;
    wxStaticText* m_lblTotalFiles;
    wxStaticText* m_lblCodeLines;
    wxStaticText* m_lblCommentLines;
    //*)

    ///////////////////////////////////////////////////////////////

    CountingInfo m_countingInfo;        ///< Counting information collector
    CountingManager* m_countingMgr;      ///< Counting manager

    ///////////////////////////////////////////////////////////////

    void updateOptionsCtrls();
    void initCountingCtrls();

    void saveCouningResultToCSV(wxString fileName);

    /**
     * update statistic infomation.
     */
    virtual void UpdateCountingInfoCtrls( void );
    ///////////////////////////////////////////////////////////////

    DECLARE_EVENT_TABLE()
};

#endif // SOURCECOUNTERMAIN_H
