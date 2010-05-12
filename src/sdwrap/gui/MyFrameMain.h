/* 
   MyFrameMain.h: main frame header

   This file is part of SDWrap, a crossplatform wxWidgets
   Zeroconf service discovery wrapper.
 
   Copyright (C) 2008 Christian Beier <dontmind@freeshell.org>
 
   SDWrap is free software; you can redistribute it and/or modify 
   it under the terms of the GNU General Public License as published by 
   the Free Software Foundation; either version 2 of the License, or 
   (at your option) any later version. 
 
   SDWrap is distributed in the hope that it will be useful, 
   but WITHOUT ANY WARRANTY; without even the implied warranty of 
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the 
   GNU General Public License for more details. 
 
   You should have received a copy of the GNU General Public License 
   along with this program; if not, write to the Free Software 
   Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA. 
*/
// -*- C++ -*- 

#ifndef MYFRAMEMAIN_H
#define MYFRAMEMAIN_H


#include "FrameMain.h"
#include "../wxServDisc/wxServDisc.h"



class MyProcess;

class MyFrameMain: public FrameMain
{
  friend class MyProcess; // to allow callback

  // main service scanner
  wxServDisc* servscan;
  wxString servicestring;

  // to temporarily store these
  wxString hostname;
  wxString addr;
  wxString port;


  void read_config();

  
  // the client command to be executed and its process id
  wxString client_cmd_template;
  long client_pid;
  MyProcess *client_proc;
  bool spawn_client();
  void kill_client();
  void on_client_term(wxString& cmd, int status); // callback if client exits on its own

  
protected:
  DECLARE_EVENT_TABLE();
 
public:
  MyFrameMain(wxWindow* parent, int id, const wxString& title, 
	      const wxPoint& pos=wxDefaultPosition, 
	      const wxSize& size=wxDefaultSize, 
	      long style=wxDEFAULT_FRAME_STYLE);
  ~MyFrameMain();

  
  // handlers
  void onSDNotify(wxCommandEvent& event);
  void list_dclick(wxCommandEvent &event); 
  void list_select(wxCommandEvent &event); 

  void file_exit(wxCommandEvent &event);

  void edit_preferences(wxCommandEvent &event);
  void edit_connect(wxCommandEvent &event);
  void edit_endconn(wxCommandEvent &event);

  void help_about(wxCommandEvent &event);
  void help_contents(wxCommandEvent &event);
};



#endif
