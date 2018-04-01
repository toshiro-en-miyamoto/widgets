CFLAGS=-g -std=c++1z -mtune=generic -march=i686
INCLUDES=
LDFLAGS=
LIBS=-L. -lexample_dll
DLLFLAGS=
DLLLIBS=

all: example_dll.dll example_exe.exe

example_dll.dll: example_dll.o
	$(CXX) $(INCLUDES) $? $(DLLFLAGS) -shared -o $@ $(DLLLIBS)

example_dll.o: example_dll.cpp example_dll.h
	$(CXX) $(CFLAGS) $(INCLUDES) -DBUILDING_EXAMPLE_DLL -c $<

example_exe.exe: example_exe.o
	$(CXX) $(INCLUDES) $? $(LDFLAGS) -o $@ $(LIBS)

clean:
	rm *.o example_dll.dll example_exe.exe

.cpp.o:
	$(CXX) $(CFLAGS) $(INCLUDES) -c $<

