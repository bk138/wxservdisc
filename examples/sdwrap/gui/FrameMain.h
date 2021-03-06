// -*- C++ -*- generated by wxGlade 0.6.3

#include <wx/wx.h>
#include <wx/image.h>

#ifndef FRAMEMAIN_H
#define FRAMEMAIN_H

// begin wxGlade: ::dependencies
// end wxGlade

// begin wxGlade: ::extracode
#include "bitmapFromMem.h"
#ifndef SDWRAP_XPM
#define SDWRAP_XPM
#include "res/sdwrap.xpm"
#endif

// end wxGlade


class FrameMain: public wxFrame {
public:
    // begin wxGlade: FrameMain::ids
    // end wxGlade

    FrameMain(wxWindow* parent, int id, const wxString& title, const wxPoint& pos=wxDefaultPosition, const wxSize& size=wxDefaultSize, long style=wxDEFAULT_FRAME_STYLE);

private:
    // begin wxGlade: FrameMain::methods
    void set_properties();
    void do_layout();
    // end wxGlade

protected:
    // begin wxGlade: FrameMain::attributes
    wxStaticBox* sizer_wBox_staticbox;
    wxMenuBar* frame_main_menubar;
    wxStatusBar* frame_main_statusbar;
    wxListBox* list_box_services;
    wxPanel* panel_wborder;
    wxPanel* panel_top;
    // end wxGlade

    DECLARE_EVENT_TABLE();

public:
    virtual void file_exit(wxCommandEvent &event); // wxGlade: <event_handler>
    virtual void edit_connect(wxCommandEvent &event); // wxGlade: <event_handler>
    virtual void edit_endconn(wxCommandEvent &event); // wxGlade: <event_handler>
    virtual void edit_preferences(wxCommandEvent &event); // wxGlade: <event_handler>
    virtual void help_contents(wxCommandEvent &event); // wxGlade: <event_handler>
    virtual void help_about(wxCommandEvent &event); // wxGlade: <event_handler>
    virtual void list_dclick(wxCommandEvent &event); // wxGlade: <event_handler>
    virtual void list_select(wxCommandEvent &event); // wxGlade: <event_handler>
}; // wxGlade: end class


#endif // FRAMEMAIN_H
