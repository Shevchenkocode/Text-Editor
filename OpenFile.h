#ifndef OPENFILE_H_INCLUDED
#define OPENFILE_H_INCLUDED
#include <wx/wx.h>

class Openfile : public wxFrame
{
    public:
        Openfile(const wxString& title);
        void OnOpen(wxCommandEvent& event);
        wxTextCtrl *tc;
};

#endif // OPENFILE_H_INCLUDED
