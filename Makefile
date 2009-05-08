
## 
WXCONFIG=wx-config

CFLAGS=-O2 -g
CXXFLAGS = $(shell $(WXCONFIG) --cxxflags) -Wall -O -g
LIBS = $(shell $(WXCONFIG) --libs net,adv) 
OUTFILE=sdwrap
#
#
#


OBJS=SdwrapApp.o wxServDisc/wxServDisc.o wxServDisc/1035.o wxServDisc/mdnsd.o gui/FrameMain.o gui/MyFrameMain.o gui/DialogSettings.o gui/MyDialogSettings.o 

#
#

.PHONY : clean depend

all: $(OUTFILE) 

$(OUTFILE):	$(OBJS) 	 
	$(CXX) $(OBJS) -o $(OUTFILE) $(LIBS)


# clean me up, scotty
clean:
	$(RM) $(OUTFILE) $(OBJS)  *~ gui/*~ wxServDisc/*~


# you can depend on me
depend:
	makedepend -Y -- *.cpp gui/*.cpp wxServDisc/*.cpp wxServDisc/*.c 



# DO NOT DELETE

SdwrapApp.o: SdwrapApp.h gui/MyFrameMain.h gui/FrameMain.h
SdwrapApp.o: gui/bitmapFromMem.h gui/res/icon.xpm wxServDisc/wxServDisc.h
SdwrapApp.o: wxServDisc/1035.h
gui/DialogSettings.o: gui/DialogSettings.h
gui/FrameMain.o: gui/FrameMain.h gui/bitmapFromMem.h gui/res/icon.xpm
gui/MyDialogSettings.o: gui/MyDialogSettings.h gui/DialogSettings.h config.h
gui/MyFrameMain.o: gui/res/about.png.h gui/MyFrameMain.h gui/FrameMain.h
gui/MyFrameMain.o: gui/bitmapFromMem.h gui/res/icon.xpm
gui/MyFrameMain.o: wxServDisc/wxServDisc.h wxServDisc/1035.h
gui/MyFrameMain.o: gui/MyDialogSettings.h gui/DialogSettings.h config.h
gui/MyFrameMain.o: SdwrapApp.h
wxServDisc/wxServDisc.o: wxServDisc/wxServDisc.h wxServDisc/1035.h
wxServDisc/wxServDisc.o: wxServDisc/mdnsd.h
wxServDisc/1035.o: wxServDisc/1035.h
wxServDisc/mdnsd.o: wxServDisc/mdnsd.h wxServDisc/1035.h
