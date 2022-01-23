///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Feb 17 2007)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#ifndef __GUIFrame__
#define __GUIFrame__

// Define WX_GCH in order to support precompiled headers with GCC compiler.
// You have to create the header "wx_pch.h" and include all files needed
// for compile your gui inside it.
// Then, compile it and place the file "wx_pch.h.gch" into the same
// directory that "wx_pch.h".
#ifdef WX_GCH
#include <wx_pch.h>
#else
#include <wx/wx.h>
#endif

#include <wx/menu.h>

///////////////////////////////////////////////////////////////////////////
#define idMenuClose 996
#define idMenuSave 997
#define idMenuOpen 998
#define idMenuCreate 999
#define idMenuQuit 1000
#define idMenuAbout 1001
#define idTEXTAREA 1002

///////////////////////////////////////////////////////////////////////////////
/// Class GUIFrame
///////////////////////////////////////////////////////////////////////////////
class GUIFrame : public wxFrame
{
    DECLARE_EVENT_TABLE()
    private:

        // Private event handlers
        void _wxFB_FileCreate( wxCommandEvent& event ){ FileCreate( event ); }
        void _wxFB_FileOpen( wxCommandEvent& event ){ FileOpen( event ); }
        void _wxFB_FileSave( wxCommandEvent& event ){ FileSave( event ); }
        void _wxFB_FileClose( wxCommandEvent& event ){ FileClose( event ); }

        void _wxFB_OnClose( wxCloseEvent& event ){ OnClose( event ); }
        void _wxFB_OnQuit( wxCommandEvent& event ){ OnQuit( event ); }
        void _wxFB_OnAbout( wxCommandEvent& event ){ OnAbout( event ); }


    protected:
        wxMenuBar* mbar;
        wxStatusBar* statusBar;

        // Virtual event handlers, overide them in your derived class
        virtual void FileCreate( wxCommandEvent& event ){ event.Skip(); }
        virtual void FileOpen( wxCommandEvent& event ){ event.Skip(); }
        virtual void FileSave( wxCommandEvent& event ){ event.Skip(); }
        virtual void FileClose( wxCommandEvent& event ){ event.Skip(); }

        virtual void OnClose( wxCloseEvent& event ){ event.Skip(); }
        virtual void OnQuit( wxCommandEvent& event ){ event.Skip(); }
        virtual void OnAbout( wxCommandEvent& event ){ event.Skip(); }


    public:
        GUIFrame( wxWindow* parent, int id = wxID_ANY, wxString title = wxT("Текстовий редактор"), wxPoint pos = wxDefaultPosition, wxSize size = wxSize( 481,466 ), int style = wxDEFAULT_FRAME_STYLE|wxTAB_TRAVERSAL );
        wxTextCtrl* textArea;
};

#endif //__GUIFrame__
