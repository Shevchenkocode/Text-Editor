/***************************************************************
 * Name:      Text_EditorMain.h
 * Purpose:   Defines Application Frame
 * Author:    Ihor Shevchenko ()
 * Created:   2022-01-03
 * Copyright: Ihor Shevchenko ()
 * License:
 **************************************************************/

#ifndef TEXT_EDITORMAIN_H
#define TEXT_EDITORMAIN_H



#include "Text_EditorApp.h"
#include "GUIFrame.h"

class Text_EditorFrame: public GUIFrame
{
    public:
        Text_EditorFrame(wxFrame *frame);
        ~Text_EditorFrame();
    private:
        virtual void OnClose(wxCloseEvent& event);
        virtual void FileCreate(wxCommandEvent& event);
        virtual void FileOpen(wxCommandEvent& event);
        virtual void FileSave(wxCommandEvent& event);
        virtual void FileClose(wxCommandEvent& event);
        virtual void OnQuit(wxCommandEvent& event);
        virtual void OnAbout(wxCommandEvent& event);
};

#endif // TEXT_EDITORMAIN_H
