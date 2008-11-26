/***************************************************************
 * Name:      DeskAssistantApp.cpp
 * Purpose:   Code for Application Class
 * Author:    Boom (BoomWorks@hotmail.com)
 * Created:   2008-11-26
 * Copyright: Boom (http://www.boomworks.net)
 * License:
 **************************************************************/

#include "wx_pch.h"
#include "DeskAssistantApp.h"

//(*AppHeaders
#include "DeskAssistantMain.h"
#include <wx/image.h>
//*)

IMPLEMENT_APP(DeskAssistantApp);

bool DeskAssistantApp::OnInit()
{
    //
    this->SetVendorName(_T("BoomWorks"));

    //
    wxIcon ico;
    ico.LoadFile(wxT("img\\DesktopAssistant.ico"), wxBITMAP_TYPE_ICO);

    //(*AppInitialize
    bool wxsOK = true;
    wxInitAllImageHandlers();
    if ( wxsOK )
    {
        DeskAssistantDialog Dlg(0);
        Dlg.SetIcon(ico);

        SetTopWindow(&Dlg);
        Dlg.ShowModal();
        wxsOK = false;
    }
    //*)
    return wxsOK;

}
