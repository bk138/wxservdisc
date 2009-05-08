/* 
   SdwrapApp.h: main app header

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

#ifndef SDWRAPAPP_H
#define SDWRAPAPP_H


#include <wx/wxprec.h>
#ifndef WX_PRECOMP 
#include "wx/wx.h"       
#endif  
#include "wx/config.h"



#define VERSION "0.2"
#define COPYRIGHT "Copyright (C) 2009 Christian Beier <dontmind@freeshell.org>"


class SdwrapApp: public wxApp 
{
  wxLocale *locale;
public:
  
  bool OnInit();
  int  OnExit();
  bool setLocale(int language);
};


DECLARE_APP(SdwrapApp);





#endif // SDWRAPAPP_H
