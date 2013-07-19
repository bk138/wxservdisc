
wxServDisc - a wxwidgets zeroconf service discovery module
==========================================================

API:
---

	// type can be one of QTYPE_A, QTYPE_NS, QTYPE_CNAME, QTYPE_PTR or QTYPE_SRV  
	wxServDisc(void* parent, const wxString& what, int type);
	~wxServDisc();

	// yeah well...
	std::vector<wxSDEntry> getResults() const;
	size_t getResultCount() const;

	// get query name
	const wxString& getQuery() const { const wxString& ref = query; return ref; };
	// get error string
	const wxString& getErr() const { const wxString& ref = err; return ref; };


Typically you would do a three-stage query when looking up the address of a 
service instance (look into sdwrap sample to see how it's done...):

	wxServDisc *servscan = new wxServDisc(this, wxT("_rfb._tcp.local."), QTYPE_PTR);
	wxServDisc namescan(0, servscan->getResults().at(0).name, QTYPE_SRV);
	wxServDisc addrscan(0, namescan.getResults().at(0).name;, QTYPE_A);
	wxString addr = addrscan.getResults().at(0).ip;

  
Ah yes and a wxServDisc instance sends a custom event when sth. is discovered.
so you have to add it to your event table, if you want to use it:

	// map recv of wxServDiscNOTIFY to some method
	BEGIN_EVENT_TABLE(MyFrameMain, FrameMain)
	   EVT_COMMAND  (wxID_ANY, wxServDiscNOTIFY, MyFrameMain::onSDNotify)
	END_EVENT_TABLE()

In that event listener function, you can then call getResults().


wxServDisc uses mdnsd (C) Jer <jer@jabber.org> internally. 




BUILDING:
--------


Prerequisites:  wxWidgets >= 2.8

	./configure && make 
   

   OR (when building for Win32 with mingw-w64):

        ./configure --build=<your build target name> --host=i686-w64-mingw32 \
               --with-wx-config=<your win32 wx-config>  && make


   OR (when building under OS X):
       
       ./configure && make && make appbundle




That's it, have fun!

   christian beier <dontmind@freeshell.org>
 
