/***************************************************************
 * Name:      DeskAssistantApp.cpp
 * Purpose:   Code for Application Class
 * Author:    Boom (BoomWorks@hotmail.com)
 * Created:   2008-11-26
 * Copyright: Boom (http://www.boomworks.org)
 * License:
 **************************************************************/

#include "wx_pch.h"
#include "DeskAssistantApp.h"

//(*AppHeaders
#include "MainDlg.h"
#include <wx/image.h>
//*)

#include "wx/chooselang.h"

IMPLEMENT_APP(DeskAssistantApp);

bool DeskAssistantApp::OnInit()
{
    //
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
    m_locale.AddCatalog(wxT("DeskAssistant"));

    ///////////////////////////////////////////////////////////////////
    //
    wxIcon ico;
    ico.LoadFile(wxT("img\\DesktopAssistant.ico"), wxBITMAP_TYPE_ICO);

    bool wxsOK = true;
    wxInitAllImageHandlers();
    if ( wxsOK )
    {
        //DeskAssistantDialog Dlg(0);
        MainDlg Dlg(0);
        Dlg.SetIcon(ico);

        SetTopWindow(&Dlg);
        Dlg.ShowModal();
        wxsOK = false;
    }
    return wxsOK;
}
