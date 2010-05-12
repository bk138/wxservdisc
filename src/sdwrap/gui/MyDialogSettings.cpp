/* 
   MyDialogSettings.cpp: settings dialog implementation

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

#include "wx/config.h"

#include "MyDialogSettings.h"
#include "../dfltcfg.h"

using namespace std;


MyDialogSettings::MyDialogSettings(wxWindow* parent, int id, const wxString& title, const wxPoint& pos, const wxSize& size, long style):
  DialogSettings(parent, id, title, pos, size, style)
{
  // this creates standard buttons in platform specific order
  wxSizer* std_buttonsizer = CreateButtonSizer(wxOK | wxCANCEL);

  // Add it to the dialog's main sizer 
  GetSizer()->Add(std_buttonsizer, 0, wxEXPAND | wxALL, 3);
    
  // and resize to fit
  Fit();
}


MyDialogSettings::~MyDialogSettings()
{


}







wxString MyDialogSettings::getSrv() const
{
  return text_ctrl_service->GetValue();
}



wxString MyDialogSettings::getCmd() const
{
  return text_ctrl_command->GetValue();
}



void MyDialogSettings::setSrv(const wxString& value) 
{
  text_ctrl_service->SetValue(value);
}


void MyDialogSettings::setCmd(const wxString& value) 
{
  text_ctrl_command->SetValue(value);
}

