///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Feb 17 2007)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "wx/wxprec.h"

#ifdef __BORLANDC__
#pragma hdrstop
#endif //__BORLANDC__

#ifndef WX_PRECOMP
#include <wx/wx.h>
#endif //WX_PRECOMP

#include "GUIFrame.h"
#include <wx/textctrl.h>

///////////////////////////////////////////////////////////////////////////
BEGIN_EVENT_TABLE( GUIFrame, wxFrame )
    EVT_CLOSE( GUIFrame::_wxFB_OnClose )
    EVT_MENU( idMenuCreate, GUIFrame::_wxFB_FileCreate)
    EVT_MENU( idMenuOpen, GUIFrame:: _wxFB_FileOpen)
    EVT_MENU( idMenuSave, GUIFrame::_wxFB_FileSave)
    EVT_MENU( idMenuClose, GUIFrame::_wxFB_FileClose)
    EVT_MENU( idMenuQuit, GUIFrame::_wxFB_OnQuit )
    EVT_MENU( idMenuAbout, GUIFrame::_wxFB_OnAbout )
END_EVENT_TABLE()

GUIFrame::GUIFrame( wxWindow* parent, int id, wxString title, wxPoint pos, wxSize size, int style ) : wxFrame( parent, id, title, pos, size, style )
{
    m_parent = parent;
    this->SetSizeHints( wxDefaultSize, wxDefaultSize );

    mbar = new wxMenuBar( 0 );
    wxMenu* fileMenu;
    fileMenu = new wxMenu();
    wxMenuItem* menuFileCreate = new wxMenuItem( fileMenu, idMenuCreate, wxString( wxT("&Створити") ) + wxT('\t') + wxT("Ctrl+N"), wxT("Створити новий файл."), wxITEM_NORMAL );
    fileMenu->Append(menuFileCreate);
    wxMenuItem* menuFileOpen = new wxMenuItem( fileMenu, idMenuOpen, wxString( wxT("&Відкрити") ) + wxT('\t') + wxT("Ctrl+O"), wxT("Відкрити файл."), wxITEM_NORMAL );
    fileMenu->Append(menuFileOpen);
    wxMenuItem* menuFileSave = new wxMenuItem( fileMenu, idMenuSave, wxString( wxT("&Зберегти") ) + wxT('\t') + wxT("Ctrl+S"), wxT("Зберегти файл."), wxITEM_NORMAL );
    fileMenu->Append(menuFileSave);
    wxMenuItem* menuFileClose = new wxMenuItem( fileMenu, idMenuClose, wxString( wxT("&Закрити файл") ) + wxT('\t') + wxT("Ctrl+W"), wxT("Закрити файл."), wxITEM_NORMAL );
    fileMenu->Append(menuFileClose);
    wxMenuItem* menuFileQuit = new wxMenuItem( fileMenu, idMenuQuit, wxString( wxT("&Вихід") ) + wxT('\t') + wxT("Alt+F4"), wxT("Вихід з додатку."), wxITEM_NORMAL );
    fileMenu->Append( menuFileQuit );
    mbar->Append( fileMenu, wxT("&Файл") );
    wxMenu* helpMenu;
    helpMenu = new wxMenu();
    wxMenuItem* menuHelpAbout = new wxMenuItem( helpMenu, idMenuAbout, wxString( wxT("&Справка") ) + wxT('\t') + wxT("F1"), wxT("Інформація про программу."), wxITEM_NORMAL );
    helpMenu->Append( menuHelpAbout );
    mbar->Append( helpMenu, wxT("&Допомога") );
    this->SetMenuBar( mbar );

    textArea = new wxTextCtrl(this, idTEXTAREA, "", wxDefaultPosition, wxSize(100, 100), wxTE_MULTILINE);

    statusBar = this->CreateStatusBar( 2, wxST_SIZEGRIP, wxID_ANY );
    Center();
}
