/***************************************************************
 * Name:      Text_EditorApp.h
 * Purpose:   Defines Application Class
 * Author:    Ihor Shevchenko ()
 * Created:   2022-01-03
 * Copyright: Ihor Shevchenko ()
 * License:
 **************************************************************/

#ifndef TEXT_EDITORAPP_H
#define TEXT_EDITORAPP_H

#include <wx/app.h>

class Text_EditorApp : public wxApp
{
    public:
        virtual bool OnInit();
};

#endif // TEXT_EDITORAPP_H
