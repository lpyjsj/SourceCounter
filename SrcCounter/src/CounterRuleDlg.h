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
//*)

#include "CounterRule.h"

class CounterRuleDlg: public wxDialog
{
	public:

		CounterRuleDlg(wxWindow* parent,wxWindowID id=wxID_ANY,const wxPoint& pos=wxDefaultPosition,const wxSize& size=wxDefaultSize);
		virtual ~CounterRuleDlg();

		//(*Declarations(CounterRuleDlg)
		wxTextCtrl* TextCtrl4;
		wxStaticText* StaticText2;
		wxStaticText* StaticText6;
		wxStaticText* StaticText1;
		wxStaticText* StaticText3;
		wxButton* m_btnOK;
		wxStaticText* StaticText5;
		wxStaticText* StaticText7;
		wxButton* m_btnCancel;
		wxTextCtrl* TextCtrl2;
		wxTextCtrl* TextCtrl1;
		wxComboBox* m_cmbMethod;
		wxTextCtrl* m_txtExtDesc;
		wxStaticText* StaticText4;
		wxTextCtrl* TextCtrl3;
		wxTextCtrl* m_txtExtName;
		//*)

		void SetRuleData(FileExtension* pFileExt) { m_pFileExt = pFileExt; }

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
		//*)

	private:

		//(*Handlers(CounterRuleDlg)
		void OnInit(wxInitDialogEvent& event);
		void OnBtnOKClick(wxCommandEvent& event);
		void OnBtnCancelClick(wxCommandEvent& event);
		//*)

		FileExtension* m_pFileExt;

		DECLARE_EVENT_TABLE()
};

#endif
