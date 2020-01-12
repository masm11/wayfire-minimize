all: libminimize.so

libminimize.so: minimize.o
	cc -shared -o $@ minimize.o `pkg-config --libs wayfire`

minimize.o: minimize.cpp
	cc -std=c++17 -Wall -c -fPIC -o $@ `pkg-config --cflags wayfire` -I/usr/include/pixman-1 -DWLR_USE_UNSTABLE -DWAYFIRE_PLUGIN minimize.cpp

clean:
	-rm -f *.o *.so *~
