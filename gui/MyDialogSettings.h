/* 
   MyDialogSettings.h: settings dialog header

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

#ifndef MYDIALOGSETTINGS_H
#define MYDIALOGSETTINGS_H

#include "DialogSettings.h"


class MyDialogSettings: public DialogSettings
{
 
public:
  wxString getSrv() const;
  wxString getCmd() const;
  void setSrv(const wxString& value);
  void setCmd(const wxString& value);
 
  
  MyDialogSettings(wxWindow* parent, int id, const wxString& title, const wxPoint& pos=wxDefaultPosition, const wxSize& size=wxDefaultSize, long style=wxDEFAULT_DIALOG_STYLE);


  ~MyDialogSettings();
};



#endif
