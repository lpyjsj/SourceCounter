#ifndef CNTSETTINGDLG_H
#define CNTSETTINGDLG_H

#ifndef WX_PRECOMP
	//(*HeadersPCH(CntSettingDlg)
	#include <wx/sizer.h>
	#include <wx/stattext.h>
	#include <wx/radiobut.h>
	#include <wx/button.h>
	#include <wx/dialog.h>
	//*)
#endif
//(*Headers(CntSettingDlg)
#include <wx/statline.h>
//*)

#include "CountingParam.h"

class CntSettingDlg: public wxDialog
{
	public:

		CntSettingDlg(wxWindow* parent,wxWindowID id=wxID_ANY,const wxPoint& pos=wxDefaultPosition,const wxSize& size=wxDefaultSize);
		virtual ~CntSettingDlg();

		//(*Declarations(CntSettingDlg)
		wxRadioButton* RadioButton1;
		wxStaticText* StaticText2;
		wxRadioButton* RadioButton2;
		wxButton* Button1;
		wxButton* Button2;
		wxRadioButton* RadioButton3;
		wxStaticLine* StaticLine1;
		//*)

        ///////////////////////////////////////////////////////////////
        void GetSettingParam(SettingParam& param);

	protected:

		//(*Identifiers(CntSettingDlg)
		static const long ID_STATICTEXT2;
		static const long ID_RADIOBUTTON1;
		static const long ID_RADIOBUTTON2;
		static const long ID_RADIOBUTTON3;
		static const long ID_STATICLINE1;
		static const long ID_BUTTON1;
		static const long ID_BUTTON2;
		//*)

	private:

		//(*Handlers(CntSettingDlg)
		void OnBtnOkClick(wxCommandEvent& event);
		void OnBtnCancelClick(wxCommandEvent& event);
		//*)

        ///////////////////////////////////////////////////////////////
        SettingParam    m_settingParam;

        ///////////////////////////////////////////////////////////////

		DECLARE_EVENT_TABLE()
};

#endif
