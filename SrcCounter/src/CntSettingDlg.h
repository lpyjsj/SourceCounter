#ifndef CNTSETTINGDLG_H
#define CNTSETTINGDLG_H

#ifndef WX_PRECOMP
	//(*HeadersPCH(CntSettingDlg)
	#include <wx/sizer.h>
	#include <wx/radiobox.h>
	#include <wx/button.h>
	#include <wx/dialog.h>
	//*)
#endif
//(*Headers(CntSettingDlg)
//*)

#include "CountingParam.h"

class CntSettingDlg: public wxDialog
{
	public:

		CntSettingDlg(wxWindow* parent,wxWindowID id=wxID_ANY,const wxPoint& pos=wxDefaultPosition,const wxSize& size=wxDefaultSize);
		virtual ~CntSettingDlg();

		//(*Declarations(CntSettingDlg)
		wxButton* Button1;
		wxButton* Button2;
		wxRadioBox* m_rdbCountingMethod;
		//*)

        ///////////////////////////////////////////////////////////////
        void SetSettingParam(SettingParam* pParam);
        void GetSettingParam(SettingParam& param);

	protected:

		//(*Identifiers(CntSettingDlg)
		static const long ID_RADIOBOX1;
		//*)

	private:

		//(*Handlers(CntSettingDlg)
		void OnBtnOkClick(wxCommandEvent& event);
		void OnBtnCancelClick(wxCommandEvent& event);
		void OnRdbCountingMethodSelect(wxCommandEvent& event);
		void OnInit(wxInitDialogEvent& event);
		//*)

        ///////////////////////////////////////////////////////////////
        SettingParam    m_settingParam;

        ///////////////////////////////////////////////////////////////

		DECLARE_EVENT_TABLE()
};

#endif
