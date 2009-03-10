#ifndef CNTSETTINGDLG_H
#define CNTSETTINGDLG_H

#ifndef WX_PRECOMP
	//(*HeadersPCH(CntSettingDlg)
	#include <wx/sizer.h>
	#include <wx/stattext.h>
	#include <wx/radiobox.h>
	#include <wx/textctrl.h>
	#include <wx/button.h>
	#include <wx/dialog.h>
	#include <wx/combobox.h>
	//*)
#endif
//(*Headers(CntSettingDlg)
#include <wx/spinctrl.h>
//*)

#include "CountingParam.h"

class CntSettingDlg: public wxDialog
{
	public:

		CntSettingDlg(wxWindow* parent,wxWindowID id=wxID_ANY,const wxPoint& pos=wxDefaultPosition,const wxSize& size=wxDefaultSize);
		virtual ~CntSettingDlg();

		//(*Declarations(CntSettingDlg)
		wxStaticText* StaticText10;
		wxStaticText* StaticText9;
		wxStaticText* StaticText13;
		wxStaticText* StaticText2;
		wxStaticText* StaticText14;
		wxButton* Button1;
		wxStaticText* StaticText6;
		wxSpinCtrl* m_spinUtDefectDensity;
		wxSpinCtrl* m_spinItCaseDensity;
		wxStaticText* StaticText8;
		wxStaticText* StaticText11;
		wxStaticText* StaticText1;
		wxStaticText* StaticText3;
		wxComboBox* m_cmbLinesPerMM;
		wxButton* Button2;
		wxTextCtrl* m_txtCost;
		wxSpinCtrl* m_spinItDefectDensity;
		wxStaticText* StaticText5;
		wxStaticText* StaticText7;
		wxSpinCtrl* m_spinUtCaseDensity;
		wxStaticText* StaticText12;
		wxStaticText* StaticText4;
		wxRadioBox* m_rdbCountingMethod;
		wxSpinCtrl* m_spinDays;
		//*)

        ///////////////////////////////////////////////////////////////
        void SetSettingParam(SettingParam* pParam);
        void GetSettingParam(SettingParam& param);

	protected:

		//(*Identifiers(CntSettingDlg)
		static const long ID_RADIOBOX1;
		static const long ID_STATICTEXT5;
		static const long ID_SPINCTRL2;
		static const long ID_STATICTEXT6;
		static const long ID_STATICTEXT8;
		static const long ID_SPINCTRL3;
		static const long ID_STATICTEXT7;
		static const long ID_STATICTEXT11;
		static const long ID_SPINCTRL4;
		static const long ID_STATICTEXT13;
		static const long ID_STATICTEXT12;
		static const long ID_SPINCTRL5;
		static const long ID_STATICTEXT14;
		static const long ID_STATICTEXT2;
		static const long ID_COMBOBOX1;
		static const long ID_STATICTEXT1;
		static const long ID_STATICTEXT3;
		static const long ID_SPINCTRL1;
		static const long ID_STATICTEXT10;
		static const long ID_STATICTEXT4;
		static const long ID_TEXTCTRL1;
		static const long ID_STATICTEXT9;
		//*)

	private:

		//(*Handlers(CntSettingDlg)
		void OnBtnOkClick(wxCommandEvent& event);
		void OnBtnCancelClick(wxCommandEvent& event);
		void OnRdbCountingMethodSelect(wxCommandEvent& event);
		void OnInit(wxInitDialogEvent& event);
		//*)

        ///////////////////////////////////////////////////////////////
        static SettingParam m_settingParam;

        ///////////////////////////////////////////////////////////////

		DECLARE_EVENT_TABLE()
};

#endif
