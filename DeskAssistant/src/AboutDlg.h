#ifndef ABOUTDLG_H
#define ABOUTDLG_H

#ifndef WX_PRECOMP
	//(*HeadersPCH(AboutDlg)
	#include <wx/sizer.h>
	#include <wx/stattext.h>
	#include <wx/statbmp.h>
	#include <wx/button.h>
	#include <wx/dialog.h>
	//*)
#endif
//(*Headers(AboutDlg)
//*)

#include "wx/hyperlink.h"

class AboutDlg: public wxDialog
{
	public:

		AboutDlg(wxWindow* parent,wxWindowID id=wxID_ANY);
		virtual ~AboutDlg();

		//(*Declarations(AboutDlg)
		wxStaticText* StaticText2;
		wxButton* Button1;
		wxStaticBitmap* StaticBitmap1;
		wxStaticText* StaticText1;
		wxStaticText* StaticText3;
		wxStaticText* m_pLblWxBuildInfo;
		wxStaticText* m_pLblVersion;
		wxStaticText* StaticText5;
		wxStaticText* StaticText4;
		//*)

		wxHyperLink* m_pLinkBmwHp;
		wxHyperLink* m_pLinkBmwMail;

	protected:

		//(*Identifiers(AboutDlg)
		static const long ID_STATICBITMAP1;
		static const long ID_STATICTEXT1;
		static const long ID_STATICTEXT2;
		static const long ID_STATICTEXT3;
		static const long ID_STATICTEXT5;
		static const long ID_STATICTEXT4;
		static const long ID_STATICTEXT7;
		static const long ID_STATICTEXT6;
		//*)

		static const long ID_LINK_BMW_HP;
		static const long ID_LINK_BMW_MAIL;

	private:

		//(*Handlers(AboutDlg)
		//*)

		DECLARE_EVENT_TABLE()
};

#endif
