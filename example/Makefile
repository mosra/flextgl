
LFLAGS= -lglfw -lGL

all: example

example: example.o flextGL.o
	g++ $(LFLAGS) -o example example.o flextGL.o

example.o: example.cpp flextGL.cpp
	g++ -c example.cpp

flextGL.o: flextGL.cpp
	g++ -c flextGL.cpp

flextGL.cpp: profile.txt
	python2.7 ../flextGLgen.py -D . profile.txt

clean:
	rm -f *.o
	rm -f flextGL.h flextGL.cpp
	rm -f example
