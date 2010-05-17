// -*- C++ -*- generated by wxGlade 0.6.3

#include "FrameMain.h"

// begin wxGlade: ::extracode

// end wxGlade


FrameMain::FrameMain(wxWindow* parent, int id, const wxString& title, const wxPoint& pos, const wxSize& size, long style):
    wxFrame(parent, id, title, pos, size, wxDEFAULT_FRAME_STYLE)
{
    // begin wxGlade: FrameMain::FrameMain
    panel_top = new wxPanel(this, wxID_ANY);
    panel_wborder = new wxPanel(panel_top, wxID_ANY);
    sizer_wBox_staticbox = new wxStaticBox(panel_wborder, -1, _("Available Service Instances"));
    frame_main_menubar = new wxMenuBar();
    wxMenu* wxglade_tmp_menu_1 = new wxMenu();
    wxglade_tmp_menu_1->Append(wxID_EXIT, wxEmptyString, _("Exit."), wxITEM_NORMAL);
    frame_main_menubar->Append(wxglade_tmp_menu_1, _("&File"));
    wxMenu* wxglade_tmp_menu_2 = new wxMenu();
    wxglade_tmp_menu_2->Append(wxID_PROPERTIES, _("&Connect to host"), _("Connect to a specific host."), wxITEM_NORMAL);
    wxglade_tmp_menu_2->Append(wxID_STOP, _("&End Connection"), _("Terminate connection."), wxITEM_NORMAL);
    wxglade_tmp_menu_2->AppendSeparator();
    wxglade_tmp_menu_2->Append(wxID_PREFERENCES, wxEmptyString, _("Change preferences."), wxITEM_NORMAL);
    frame_main_menubar->Append(wxglade_tmp_menu_2, _("&Edit"));
    wxMenu* wxglade_tmp_menu_3 = new wxMenu();
    wxglade_tmp_menu_3->Append(wxID_HELP, _("&Contents"), _("Show Help."), wxITEM_NORMAL);
    wxglade_tmp_menu_3->Append(wxID_ABOUT, wxEmptyString, _("Show some background information."), wxITEM_NORMAL);
    frame_main_menubar->Append(wxglade_tmp_menu_3, _("&Help"));
    SetMenuBar(frame_main_menubar);
    frame_main_statusbar = CreateStatusBar(1, 0);
    const wxString *list_box_services_choices = NULL;
    list_box_services = new wxListBox(panel_wborder, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0, list_box_services_choices, wxLB_SINGLE|wxLB_HSCROLL|wxLB_NEEDED_SB);

    set_properties();
    do_layout();
    // end wxGlade
}


BEGIN_EVENT_TABLE(FrameMain, wxFrame)
    // begin wxGlade: FrameMain::event_table
    EVT_MENU(wxID_EXIT, FrameMain::file_exit)
    EVT_MENU(wxID_PROPERTIES, FrameMain::edit_connect)
    EVT_MENU(wxID_STOP, FrameMain::edit_endconn)
    EVT_MENU(wxID_PREFERENCES, FrameMain::edit_preferences)
    EVT_MENU(wxID_HELP, FrameMain::help_contents)
    EVT_MENU(wxID_ABOUT, FrameMain::help_about)
    EVT_LISTBOX_DCLICK(wxID_ANY, FrameMain::list_dclick)
    EVT_LISTBOX(wxID_ANY, FrameMain::list_select)
    // end wxGlade
END_EVENT_TABLE();


void FrameMain::file_exit(wxCommandEvent &event)
{
    event.Skip();
    wxLogDebug(wxT("Event handler (FrameMain::file_exit) not implemented yet")); //notify the user that he hasn't implemented the event handler yet
}


void FrameMain::edit_connect(wxCommandEvent &event)
{
    event.Skip();
    wxLogDebug(wxT("Event handler (FrameMain::edit_connect) not implemented yet")); //notify the user that he hasn't implemented the event handler yet
}


void FrameMain::edit_endconn(wxCommandEvent &event)
{
    event.Skip();
    wxLogDebug(wxT("Event handler (FrameMain::edit_endconn) not implemented yet")); //notify the user that he hasn't implemented the event handler yet
}


void FrameMain::edit_preferences(wxCommandEvent &event)
{
    event.Skip();
    wxLogDebug(wxT("Event handler (FrameMain::edit_preferences) not implemented yet")); //notify the user that he hasn't implemented the event handler yet
}


void FrameMain::help_contents(wxCommandEvent &event)
{
    event.Skip();
    wxLogDebug(wxT("Event handler (FrameMain::help_contents) not implemented yet")); //notify the user that he hasn't implemented the event handler yet
}


void FrameMain::help_about(wxCommandEvent &event)
{
    event.Skip();
    wxLogDebug(wxT("Event handler (FrameMain::help_about) not implemented yet")); //notify the user that he hasn't implemented the event handler yet
}


void FrameMain::list_dclick(wxCommandEvent &event)
{
    event.Skip();
    wxLogDebug(wxT("Event handler (FrameMain::list_dclick) not implemented yet")); //notify the user that he hasn't implemented the event handler yet
}


void FrameMain::list_select(wxCommandEvent &event)
{
    event.Skip();
    wxLogDebug(wxT("Event handler (FrameMain::list_select) not implemented yet")); //notify the user that he hasn't implemented the event handler yet
}


// wxGlade: add FrameMain event handlers


void FrameMain::set_properties()
{
    // begin wxGlade: FrameMain::set_properties
    SetTitle(_("Service Discovery"));
    wxIcon _icon;
    _icon.CopyFromBitmap(wxICON(icon));
    SetIcon(_icon);
    int frame_main_statusbar_widths[] = { -1 };
    frame_main_statusbar->SetStatusWidths(1, frame_main_statusbar_widths);
    const wxString frame_main_statusbar_fields[] = {
        _("Status")
    };
    for(int i = 0; i < frame_main_statusbar->GetFieldsCount(); ++i) {
        frame_main_statusbar->SetStatusText(frame_main_statusbar_fields[i], i);
    }
    panel_top->SetMinSize(wxSize(400,300));
    // end wxGlade
}


void FrameMain::do_layout()
{
    // begin wxGlade: FrameMain::do_layout
    wxBoxSizer* sizer_top = new wxBoxSizer(wxHORIZONTAL);
    wxBoxSizer* sizer_2 = new wxBoxSizer(wxHORIZONTAL);
    wxStaticBoxSizer* sizer_wBox = new wxStaticBoxSizer(sizer_wBox_staticbox, wxHORIZONTAL);
    sizer_wBox->Add(list_box_services, 1, wxEXPAND, 0);
    panel_wborder->SetSizer(sizer_wBox);
    sizer_2->Add(panel_wborder, 1, wxALL|wxEXPAND, 3);
    panel_top->SetSizer(sizer_2);
    sizer_top->Add(panel_top, 1, wxEXPAND, 0);
    SetSizer(sizer_top);
    sizer_top->Fit(this);
    Layout();
    // end wxGlade
}

