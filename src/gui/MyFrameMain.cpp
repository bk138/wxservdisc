/* 
   MyFrameMain.cpp: main frame implementation

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

#include "wx/aboutdlg.h"
#include "wx/socket.h"

#include "res/about.png.h"

#include "MyFrameMain.h"
#include "MyDialogSettings.h"
#include "../dfltcfg.h"
#include "../SdwrapApp.h"









// map recv of wxServDiscNOTIFY to list update method
BEGIN_EVENT_TABLE(MyFrameMain, FrameMain)
  EVT_COMMAND  (wxID_ANY, wxServDiscNOTIFY, MyFrameMain::onSDNotify)
END_EVENT_TABLE()




using namespace std;
 




/*
  This is a helper class to specify the handler for process termination
  taken from wxwidgets exec sample
*/
#include "wx/process.h"

class MyProcess : public wxProcess
{
protected:
  MyFrameMain *m_parent; 
  wxString m_cmd;
  void (MyFrameMain::*m_callback)(wxString&, int);

public:
  bool do_callback;

  MyProcess(MyFrameMain *parent, const wxString& cmd,
	    void (MyFrameMain::*callback)(wxString&, int))
    : wxProcess(parent), m_cmd(cmd)
  {
    m_parent = parent; // save our caller for later on
    m_callback = callback;
    do_callback = true;
  }


  void OnTerminate(int pid, int status)
  {
    // clean up after us
    if(do_callback)
      {
	wxLogDebug(wxT("SDWrap: calling callback"));
	(m_parent->*m_callback)(m_cmd, status);
      }
    
    // we're not needed any more
    delete this;
  }
};





MyFrameMain::MyFrameMain(wxWindow* parent, int id, const wxString& title, 
			 const wxPoint& pos,
			 const wxSize& size,
			 long style):
  FrameMain(parent, id, title, pos, size, style)	
{
  /*
    disable some menu items for a new frame
    unfortunately there seems to be a bug in wxMenu::FindItem(str): 
    it skips '&' characters,  but GTK uses '_' for accelerators and 
    these are not trimmed...
  */
  // "end connection"
  frame_main_menubar->GetMenu(frame_main_menubar->FindMenu(wxT("Edit")))->FindItemByPosition(1)->Enable(false);


  // dont forget this! otherwise we'll be killin some innocent app
  client_pid = 0;
  client_proc = 0;
  

  // read in cmd template and service spec
  read_config();

  // mdns service scanner
  servscan = new wxServDisc(this, servicestring, QTYPE_PTR);

}




MyFrameMain::~MyFrameMain()
{
  kill_client();
}



/*
  private functions

*/

// config stuff
void MyFrameMain::read_config()
{
  // get default config object, created on demand if not exist
  wxConfigBase *pConfig = wxConfigBase::Get();

  servicestring = pConfig->Read(K_SERVICE, V_DFLTSERVICE);
  if(servicestring == wxEmptyString) // could be that key found, but empty
    servicestring = V_DFLTSERVICE;

  client_cmd_template = pConfig->Read(K_COMMAND, V_DFLTCOMMAND);
 
}









// client stuff
bool MyFrameMain::spawn_client()
{
  if(client_cmd_template == wxEmptyString)
    {
      wxLogError(_("No command specified!"));
      return false;
    }

  SetStatusText(_("Connecting to ") + addr + _T(":") + port + _T("..."));
  wxBusyCursor busy;

  // handle %a and %p
  wxString cmd = client_cmd_template;
  cmd.Replace(_T("%a"), addr);
  cmd.Replace(_T("%p"), port);
  
  // terminate old one
  kill_client();

  client_proc = new MyProcess(this, cmd, &MyFrameMain::on_client_term);
  client_pid = wxExecute(cmd, wxEXEC_ASYNC|wxEXEC_MAKE_GROUP_LEADER, client_proc);
  
  wxLogDebug(wxT("SDWrap: spawn_client() spawned '%i'"), client_pid);
 
  if ( !client_pid )
    {
      SetStatusText(_("Client execution failed."));
      wxLogError( _("Execution of '%s' failed."), cmd.c_str());

      client_proc = 0; // obj pointed to by client_proc deletes itself

      return false;
    }

  SetStatusText(_("Connected to ") + addr + _T(":") + port);

  // this is "share window"
  frame_main_menubar->GetMenu(frame_main_menubar->FindMenu(wxT("Edit")))->FindItemByPosition(0)->Enable(true);
  // "end connection"
  frame_main_menubar->GetMenu(frame_main_menubar->FindMenu(wxT("Edit")))->FindItemByPosition(3)->Enable(true);
  
  return true;
}


void MyFrameMain::kill_client()
{
  // avoid callback call
  if(wxProcess::Exists(client_pid))
    if(client_proc)
      {
	client_proc->do_callback = false;
	client_proc = 0; // obj pointed to by client_proc deletes itself
      }
     

  wxLogDebug(wxT("SDWrap: kill_client() tries to kill '%i'"), client_pid);

  if(client_pid)
    if(wxKill(client_pid, wxSIGTERM, NULL, wxKILL_CHILDREN) == 0)
      {
	wxLogDebug(wxT("SDWrap: kill_client() zeros '%i'"), client_pid);
	client_pid = 0;
	  
	// this is "share window"
	frame_main_menubar->GetMenu(frame_main_menubar->FindMenu(wxT("Edit")))->FindItemByPosition(0)->Enable(false);
	// this is "stop share window"
	frame_main_menubar->GetMenu(frame_main_menubar->FindMenu(wxT("Edit")))->FindItemByPosition(1)->Enable(false);
	// "end connection"
	frame_main_menubar->GetMenu(frame_main_menubar->FindMenu(wxT("Edit")))->FindItemByPosition(3)->Enable(false);
      }
}


void MyFrameMain::on_client_term(wxString& cmd, int status)
{
  wxLogDebug(wxT("SDWrap: on_client_term() zeros '%i'"), client_pid);

   if(status == 0) 
    SetStatusText(_("Client terminated gracefully."));
   else
     if(status == -1 || status == 1)
       {
	 SetStatusText( _("Connection failed."));
	 wxLogError( _("Connection failed."));
       }
    else
      {
	SetStatusText(_("Error running client."));
	wxLogError(_("Error running '%s'."), cmd.c_str());
      }
   
   client_pid = 0;
   client_proc = 0;
   
   // this is "share window"
   frame_main_menubar->GetMenu(frame_main_menubar->FindMenu(wxT("Edit")))->FindItemByPosition(0)->Enable(false);
   // this is "stop share window"
   frame_main_menubar->GetMenu(frame_main_menubar->FindMenu(wxT("Edit")))->FindItemByPosition(1)->Enable(false);
   // "end connection"
   frame_main_menubar->GetMenu(frame_main_menubar->FindMenu(wxT("Edit")))->FindItemByPosition(3)->Enable(false);
   
}






/*
  handler functions
*/



void MyFrameMain::file_exit(wxCommandEvent &event)
{
  Close(true);
}


void MyFrameMain::edit_connect(wxCommandEvent &event)
{
  wxString s = wxGetTextFromUser(_("Enter host to connect to:"),
				 _("Connect to specific host"));
  if(s != wxEmptyString)
    {
      wxIPV4address host_addr;
	    
      // get host part and port part
      wxString host_name, host_port;
      host_name = s.BeforeFirst(_T(':'));
      host_port = s.AfterFirst(_T(':'));
      
      // look up name
      if(! host_addr.Hostname(host_name))
	{
	  wxLogError(_("Invalid hostname or IP address."));
	  return;
	}
      else
#ifdef __WIN32__
	addr = host_addr.Hostname(); // wxwidgets bug, ah well ...
#else
        addr = host_addr.IPAddress();
#endif

      
      // and handle port
      if(host_addr.Service(host_port))
	port = wxString() << host_addr.Service();
      else
	port = wxEmptyString;


      spawn_client();
    }
}



void MyFrameMain::edit_endconn(wxCommandEvent &event)
{
  kill_client();  
  SetStatusText( _("Connection terminated."));
}








void MyFrameMain::edit_preferences(wxCommandEvent &event)
{
  MyDialogSettings dialog_settings(this, wxID_ANY, _("Preferences"));

  read_config();
  dialog_settings.setSrv(servicestring);
  dialog_settings.setCmd(client_cmd_template);

  if(dialog_settings.ShowModal() == wxID_OK)
    {
      wxConfigBase *pConfig = wxConfigBase::Get();      

      pConfig->Write(K_SERVICE, dialog_settings.getSrv());
      pConfig->Write(K_COMMAND, dialog_settings.getCmd());

      read_config();

      delete servscan;
      servscan = new wxServDisc(this, servicestring, QTYPE_PTR);
    }
}


void MyFrameMain::help_about(wxCommandEvent &event)
{	
  wxAboutDialogInfo info;
  wxIcon icon;
  icon.CopyFromBitmap(bitmapFromMem(about_png));

  info.SetIcon(icon);
  info.SetName(wxT("SDWrap"));
  info.SetVersion(wxT(VERSION));
  info.SetDescription(_("This is SDWrap, a service discovery wrapper to start other applications with Zeroconf-supplied addresses and ports."));
  info.SetCopyright(wxT(COPYRIGHT));
  
  wxAboutBox(info); 

}




void MyFrameMain::help_contents(wxCommandEvent &e)
{
  wxLogMessage(_("Select a host in the list to get more information, double click to connect.\nYou can change the service to look for and the command to be run in preferences."));
}









void MyFrameMain::onSDNotify(wxCommandEvent& event)
{
    if(event.GetEventObject() == servscan)
      {
	wxArrayString items; 
	
	// length of qeury plus leading dot
	size_t qlen =  servscan->getQuery().Len() + 1;
	
	vector<wxSDEntry> entries = servscan->getResults();
	vector<wxSDEntry>::const_iterator it; 
	for(it=entries.begin(); it != entries.end(); it++)
	  items.Add(it->name.Mid(0, it->name.Len() - qlen));
	
	list_box_services->Set(items, 0);
      }
}



void MyFrameMain::list_select(wxCommandEvent &event)
{
  int timeout;
  wxBusyCursor busy;
  int sel = event.GetInt();
 
  if(sel < 0) // seems this happens when we update the list
    return;

  SetStatusText(_("Looking up host address..."));


  // lookup hostname and port
  {
    wxServDisc namescan(0, servscan->getResults().at(sel).name, QTYPE_SRV);
  
    timeout = 3000;
    while(!namescan.getResultCount() && timeout > 0)
      {
	wxMilliSleep(25);
	timeout-=25;
      }
    if(timeout <= 0)
      {
	wxLogError(_("Timeout looking up hostname."));
	SetStatusText(_("Timeout looking up hostname."));
	hostname = addr = port = wxEmptyString;
	return;
      }
    hostname = namescan.getResults().at(0).name;
    port = wxString() << namescan.getResults().at(0).port;
  }

  
  // lookup ip address
  {
    wxServDisc addrscan(0, hostname, QTYPE_A);
  
    timeout = 3000;
    while(!addrscan.getResultCount() && timeout > 0)
      {
	wxMilliSleep(25);
	timeout-=25;
      }
    if(timeout <= 0)
      {
	wxLogError(_("Timeout looking up IP address."));
	SetStatusText(_("Timeout looking up IP address."));
	hostname = addr = port = wxEmptyString;
	return;
      }
    addr = addrscan.getResults().at(0).ip;
  }

  SetStatusText(hostname + wxT(" (") + addr + wxT(":") + port + wxT(")"));
}


void MyFrameMain::list_dclick(wxCommandEvent &event)
{
  list_select(event); // get the actual values
  spawn_client();
} 
 
