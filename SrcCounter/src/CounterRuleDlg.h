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

class CounterRuleDlg: public wxDialog
{
	public:

		CounterRuleDlg(wxWindow* parent,wxWindowID id=wxID_ANY,const wxPoint& pos=wxDefaultPosition,const wxSize& size=wxDefaultSize);
		virtual ~CounterRuleDlg();

		//(*Declarations(CounterRuleDlg)
		wxStaticText* StaticText2;
		wxStaticText* StaticText1;
		wxStaticText* StaticText3;
		wxButton* Button2;
		wxButton* Button3;
		wxTextCtrl* TextCtrl2;
		wxComboBox* ComboBox1;
		wxTextCtrl* TextCtrl1;
		//*)

	protected:

		//(*Identifiers(CounterRuleDlg)
		static const long ID_STATICTEXT1;
		static const long ID_TEXTCTRL1;
		static const long ID_STATICTEXT3;
		static const long ID_TEXTCTRL2;
		static const long ID_STATICTEXT2;
		static const long ID_COMBOBOX1;
		//*)

	private:

		//(*Handlers(CounterRuleDlg)
		//*)

		DECLARE_EVENT_TABLE()
};

#endif
