
CFLAGS= -Igenerated
LFLAGS= -lglfw -lGL

all: example

example: example.o flextGL.o
	g++ $(LFLAGS) -o example example.o flextGL.o

example.o: example.cpp generated/flextGL.cpp
	g++ $(CFLAGS) -c example.cpp

flextGL.o: generated/flextGL.cpp
	g++ $(CFLAGS) -c generated/flextGL.cpp

generated/flextGL.cpp: profile.txt
	python2.7 ../flextGLgen.py -D generated profile.txt

clean:
	rm -f *.o
	rm -rf generated
	rm -f example
