/***************************************************************
 * Name:      SourceCounterApp.h
 * Purpose:   Defines Application Class
 * Author:    boomworks.net (boomworks@gmail.com)
 * Created:   2008-10-09
 * Copyright: boomworks.net (http://www.boomworks.net)
 * License:
 **************************************************************/

#ifndef SOURCECOUNTERAPP_H
#define SOURCECOUNTERAPP_H

#include <wx/app.h>

class SourceCounterApp : public wxApp
{

public:

    // Setting default locale
    SourceCounterApp() : m_locale(wxLANGUAGE_DEFAULT) {}

    // Initial
    virtual bool OnInit();

private:
    wxLocale m_locale;  ///< Locale

};

#endif // SOURCECOUNTERAPP_H
