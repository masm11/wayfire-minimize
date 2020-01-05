all: minimize.so

minimize.so: minimize.o
	ld -shared -o $@ minimize.o `pkg-config --libs wayfire`

minimize.o: minimize.cpp
	cc -c -fPIC -o $@ `pkg-config --cflags wayfire` -I/usr/include/pixman-1 -DWLR_USE_UNSTABLE -DWAYFIRE_PLUGIN minimize.cpp

clean:
	-rm -f *.o *.so *~
