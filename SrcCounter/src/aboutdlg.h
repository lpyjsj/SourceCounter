#ifndef ABOUTDLG_H
#define ABOUTDLG_H

#include <wx/wxprec.h>

#ifdef __BORLANDC__
    #pragma hdrstop
#endif

//(*Headers(AboutDlg)
#include <wx/sizer.h>
#include <wx/stattext.h>
#include <wx/statbmp.h>
#include <wx/button.h>
#include <wx/dialog.h>
//*)

class AboutDlg: public wxDialog
{
	public:

		AboutDlg(wxWindow* parent,wxWindowID id = -1);
		virtual ~AboutDlg();

		//(*Identifiers(AboutDlg)
		static const long ID_STATICBITMAP1;
		static const long ID_STATICBITMAP2;
		static const long ID_STATICTEXT1;
		static const long ID_STATICTEXT2;
		static const long ID_STATICTEXT3;
		static const long ID_STATICTEXT5;
		static const long ID_STATICTEXT4;
		static const long ID_BUTTON1;
		//*)

	protected:

		//(*Handlers(AboutDlg)
		void OnButton1Click(wxCommandEvent& event);
		void OnButton2Click(wxCommandEvent& event);
		//*)

		//(*Declarations(AboutDlg)
		wxStaticBitmap* StaticBitmap2;
		wxStaticText* StaticText2;
		wxButton* Button1;
		wxStaticBitmap* StaticBitmap1;
		wxStaticText* StaticText1;
		wxBoxSizer* BoxSizer2;
		wxStaticText* StaticText3;
		wxStaticText* StaticText5;
		wxBoxSizer* BoxSizer1;
		wxBoxSizer* BoxSizer3;
		wxStaticText* StaticText4;
		//*)

	private:

		DECLARE_EVENT_TABLE()
};

#endif
