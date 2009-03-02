/***************************************************************
 * Name:      DeskAssistantApp.h
 * Purpose:   Defines Application Class
 * Author:    Boom (BoomWorks@hotmail.com)
 * Created:   2008-11-26
 * Copyright: Boom (http://www.boomworks.org)
 * License:
 **************************************************************/

#ifndef DESKASSISTANTAPP_H
#define DESKASSISTANTAPP_H

#include <wx/app.h>

class DeskAssistantApp : public wxApp
{
public:
    virtual bool OnInit();

private:
    wxLocale m_locale;  ///< Locale
};

#endif // DESKASSISTANTAPP_H
