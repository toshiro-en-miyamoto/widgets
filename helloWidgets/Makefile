CFLAGS=-mthreads -g -O0 -std=c++1z -static -mtune=generic -march=i686 \
  -Wall -Wundef -Wunused-parameter -Wno-ctor-dtor-privacy -Woverloaded-virtual
INCLUDES=-I/c/wx/wx304/include -I/c/wx/wx304/build32-debug/lib/wx/include/msw-unicode-static-3.0
DEFINES=-D__WXMSW__ -D_FILE_OFFSET_BITS=64 -DWX_PRECOMP
LDFLAGS=-mwindows -mthreads
LIBS=-lstdc++fs -L/c/wx/wx304/build32-debug/lib \
  -lwx_mswu_core-3.0 -lwx_baseu-3.0 -lwxtiff-3.0 -lwxjpeg-3.0 -lwxpng-3.0 -lwxregexu-3.0 \
	-lz -lrpcrt4 -loleaut32 -lole32 -luuid -llzma -lwinspool -lwinmm -lshell32 -lcomctl32 \
	-lcomdlg32 -ladvapi32 -lwsock32 -lgdi32

helloWidgets.exe: helloWidgets.o
	$(CXX) $? $(LDFLAGS) -o $@ $(LIBS)

clean:
	rm *.o helloWidgets.exe

.cpp.o:
	$(CXX) $(CFLAGS) $(DEFINES) $(INCLUDES) -c $<

