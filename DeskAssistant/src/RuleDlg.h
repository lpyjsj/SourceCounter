#ifndef RULEDLG_H
#define RULEDLG_H

#ifndef WX_PRECOMP
	//(*HeadersPCH(RuleDlg)
	#include <wx/sizer.h>
	#include <wx/stattext.h>
	#include <wx/textctrl.h>
	#include <wx/checklst.h>
	#include <wx/button.h>
	#include <wx/dialog.h>
	//*)
#endif
//(*Headers(RuleDlg)
//*)

	#include <wx/listctrl.h>


class RuleDlg: public wxDialog
{
	public:

		RuleDlg(wxWindow* parent,wxWindowID id=wxID_ANY,const wxPoint& pos=wxDefaultPosition,const wxSize& size=wxDefaultSize);
		virtual ~RuleDlg();

		//(*Declarations(RuleDlg)
		wxStaticText* StaticText2;
		wxButton* Button1;
		wxButton* m_btnQuit;
		wxCheckListBox* CheckListBox1;
		wxButton* m_btnPreview;
		wxStaticText* StaticText1;
		wxButton* Button2;
		wxButton* Button6;
		wxButton* Button3;
		wxButton* Button9;
		wxTextCtrl* TextCtrl1;
		wxButton* Button8;
		wxButton* m_btnAbout;
		//*)

	protected:

		//(*Identifiers(RuleDlg)
		static const long ID_STATICTEXT2;
		static const long ID_CHECKLISTBOX1;
		static const long ID_BUTTON1;
		static const long ID_BUTTON2;
		static const long ID_BUTTON6;
		static const long ID_BUTTON7;
		static const long ID_BUTTON8;
		static const long ID_BUTTON9;
		static const long ID_STATICTEXT1;
		static const long ID_TEXTCTRL1;
		static const long ID_BUTTON3;
		//*)

	private:

		//(*Handlers(RuleDlg)
		void OnBtnQuitClick(wxCommandEvent& event);
		void OnBtnAboutClick(wxCommandEvent& event);
		void OnBtnPreviewClick(wxCommandEvent& event);
		//*)

		DECLARE_EVENT_TABLE()
};

#endif
