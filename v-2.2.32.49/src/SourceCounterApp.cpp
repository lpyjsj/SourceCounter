/***************************************************************
 * Name:      SourceCounterApp.cpp
 * Purpose:   Code for Application Class
 * Author:    boomworks.net (boomworks@gmail.com)
 * Created:   2008-10-09
 * Copyright: boomworks.net (http://www.boomworks.net)
 * License:
 **************************************************************/

//(*AppHeaders
#include <wx/image.h>
//*)

#include "wx_pch.h"

#include "SourceCounterApp.h"
#include "chooselang.h"
#include "SourceCounterMain.h"

IMPLEMENT_APP(SourceCounterApp);

bool SourceCounterApp::OnInit()
{
	this->SetVendorName(_T("BoomWorks"));

    //
    // Add catalog lookup path prefix
    //
#ifdef __WXMSW__   // Windows Only
    // wxMSW 2.4.0 does not search the directory of the executable by default.
    // Catalog path setting
    m_locale.AddCatalogLookupPathPrefix(wxT("locales\\"));
#endif

    // Initial locale
    m_locale.Init(GetUILanguage());

    // Add catalog
    m_locale.AddCatalog(wxT("SrcCounter"));

    //(*AppInitialize
    bool wxsOK = true;
    wxInitAllImageHandlers();
    if ( wxsOK )
    {
        SourceCounterDialog Dlg(0);

        wxIcon ico;
        ico.LoadFile(wxT("img\\SourceCounter.ico"), wxBITMAP_TYPE_ICO);
        Dlg.SetIcon(ico);

        SetTopWindow(&Dlg);
        Dlg.ShowModal();
        wxsOK = false;
    }
    //*)

    return wxsOK;
}
