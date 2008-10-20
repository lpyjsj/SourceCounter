/***************************************************************
 * Name:      SourceCounterApp.cpp
 * Purpose:   Code for Application Class
 * Author:    boomworks.net (boomworks@gmail.com)
 * Created:   2008-10-09
 * Copyright: boomworks.net (http://www.boomworks.net)
 * License:
 **************************************************************/

#include "wx_pch.h"
#include "SourceCounterApp.h"

//(*AppHeaders
#include "SourceCounterMain.h"
#include <wx/image.h>
//*)

IMPLEMENT_APP(SourceCounterApp);

bool SourceCounterApp::OnInit()
{
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
