CFLAGS=-g -std=c++1z -static -mtune=generic -march=i686
INCLUDES=
LDFLAGS=
LIBS=-lstdc++fs

helloFilesystem.exe: helloFilesystem.o
	$(CXX) $(INCLUDES) $? $(LDFLAGS) -o $@ $(LIBS)

clean:
	rm *.o helloFilesystem.exe

.cpp.o:
	$(CXX) $(CFLAGS) $(INCLUDES) -c $<

