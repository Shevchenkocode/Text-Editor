/***************************************************************
 * Name:      Text_EditorMain.cpp
 * Purpose:   Code for Application Frame
 * Author:    Ihor Shevchenko ()
 * Created:   2022-01-03
 * Copyright: Ihor Shevchenko ()
 * License:
 **************************************************************/

#ifdef WX_PRECOMP
#include "wx_pch.h"
#endif

#ifdef __BORLANDC__
#pragma hdrstop
#endif //__BORLANDC__

#include "Text_EditorMain.h"
#include "GUIFrame.h"
#include "wx/msgdlg.h"
#include "wx/wx.h"
#include <wx/filename.h>


//helper functions
enum wxbuildinfoformat {
    short_f, long_f };

wxString wxbuildinfo(wxbuildinfoformat format)
{
    wxString wxbuild(wxVERSION_STRING);

    if (format == long_f )
    {
#if defined(__WXMSW__)
        wxbuild << _T("-Windows");
#elif defined(__WXMAC__)
        wxbuild << _T("-Mac");
#elif defined(__UNIX__)
        wxbuild << _T("-Linux");
#endif

#if wxUSE_UNICODE
        wxbuild << _T("-Unicode build");
#else
        wxbuild << _T("-ANSI build");
#endif // wxUSE_UNICODE
    }

    return wxbuild;
}


Text_EditorFrame::Text_EditorFrame(wxFrame *frame)
    : GUIFrame(frame)
{
#if wxUSE_STATUSBAR
    statusBar->SetStatusText(_(""), 0);
    statusBar->SetStatusText((""), 0);
#endif
}

Text_EditorFrame::~Text_EditorFrame()
{
}

void Text_EditorFrame::OnClose(wxCloseEvent &event)
{
    wxMessageDialog *saveFile = new wxMessageDialog(NULL,
        wxT("Ви хочете зберегти файл? "), wxT("Зберегти файл"),
        wxYES | wxNO );
    saveFile->SetYesNoLabels(wxT("Зберегти файл"), wxT("Не зберігати файл"));
    int dsave = saveFile->ShowModal();
    saveFile->Destroy();

    if(dsave == wxID_YES){

    }
    else {
        Destroy();
    }
    Destroy();
}

//Create file
void Text_EditorFrame::FileCreate(wxCommandEvent & event)
{
    wxMessageDialog *createFile = new wxMessageDialog(NULL,
        wxT("Ви хочете створити новий файл? "), wxT("Створити файл"),
        wxYES | wxNO );
    createFile->SetYesNoLabels(wxT("Новий файл"), wxT("Відмінити"));
    int dcreate = createFile->ShowModal();
    createFile->Destroy();
    if(dcreate == wxID_YES){
        Text_EditorFrame* frame = new Text_EditorFrame(0L);
        frame->Show();
    }
    else {
        wxMessageDialog *dial = new wxMessageDialog(NULL, wxT("З деяких причин неможливо створити новий файл"), wxT("Помилка"), wxOK | wxICON_ERROR);
        dial->ShowModal();
    }
}

//Open file
void Text_EditorFrame::FileOpen(wxCommandEvent & WXUNUSED(event) )
{
    wxChar *FILETYPES = _T(
            "All files|*.*"
    );
    wxFileDialog *openFileDialog = new wxFileDialog(this, _("Відкрити файл"), "", "", FILETYPES, wxFD_FILE_MUST_EXIST, wxDefaultPosition);
    if( openFileDialog->ShowModal() == wxID_OK ){
        wxString path;
        path.append( openFileDialog->GetDirectory() );
        path.append( wxFileName::GetPathSeparator() );
        path.append( openFileDialog->GetFilename() );
        textArea->LoadFile(path);
        SetStatusText(path, 0);
        SetStatusText(openFileDialog->GetDirectory(), 1);
    }
}

//Save file
void Text_EditorFrame::FileSave(wxCommandEvent & WXUNUSED(event) )
{
    wxMessageDialog *saveFile = new wxMessageDialog(NULL,
        wxT("Ви хочете зберегти файл? "), wxT("Зберегти файл"),
        wxYES | wxNO );
    saveFile->SetYesNoLabels(wxT("Зберегти файл"), wxT("Не зберігати файл"));
    int dsave = saveFile->ShowModal();
    saveFile->Destroy();

    wxChar *FILETYPES = _T(
            "All files|*.*"
    );

    if(dsave == wxID_YES){
        wxFileDialog *saveFileDialog = new wxFileDialog(this, _("Зберегти файл"), "", "", FILETYPES, wxFD_SAVE, wxDefaultPosition );
        if( saveFileDialog->ShowModal() == wxID_OK ){
            wxString path;
            path.append( saveFileDialog->GetDirectory() );
            path.append( wxFileName::GetPathSeparator() );
            path.append( saveFileDialog->GetFilename() );
            textArea->SaveFile(path);
            SetStatusText(path, 0);
            SetStatusText(saveFileDialog->GetDirectory(), 1);
        }
    }
    else {
        wxMessageDialog *dial = new wxMessageDialog(NULL, wxT("З деяких причин неможливо зберегти файл"), wxT("Помилка"), wxOK | wxICON_ERROR);
        dial->ShowModal();
    }
}

//Close file
void Text_EditorFrame::FileClose(wxCommandEvent &event)
{
    wxMessageDialog *closeFile = new wxMessageDialog(NULL,
        wxT("Ви хочете закрити файл? "), wxT("Закрити файл"),
        wxYES | wxNO );
    closeFile->SetYesNoLabels(wxT("Закрити"), wxT("Не закривати"));
    int dclose = closeFile->ShowModal();
    closeFile->Destroy();

    if(dclose == wxID_YES){
        Destroy();
    }
    else {
        wxMessageDialog *dial = new wxMessageDialog(NULL, wxT("Помилка закриття программи"), wxT("Помилка"), wxOK | wxICON_ERROR);
        dial->ShowModal();
    }
}

void Text_EditorFrame::OnQuit(wxCommandEvent &event)
{
    wxMessageDialog *saveFile = new wxMessageDialog(NULL,
        wxT("Ви хочете зберегти файл? "), wxT("Зберегти файл"),
        wxYES | wxNO );
    saveFile->SetYesNoLabels(wxT("Зберегти файл"), wxT("Не зберігати файл"));
    int dsave = saveFile->ShowModal();
    saveFile->Destroy();

    if(dsave == wxID_YES){

    }
    else {
        Destroy();
    }
    Destroy();
}

void Text_EditorFrame::OnAbout(wxCommandEvent &event)
{
    wxString msg = wxbuildinfo(long_f);
    wxMessageBox( "Author: Ihor Shevchenko Version: 1.0.0 2022 All right recerved." , _("Текстовий редактор..."));
}
