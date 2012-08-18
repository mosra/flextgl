
CFLAGS= -std=c89
CXXFLAGS= -Igenerated -std=c++98
LFLAGS= -lGL -lglfw -ldl

HEADERS= common.hpp mesh.hpp utility.hpp generated/flextGL.h
FLEXT_TEMPLATES=../templates/compatible/*
FLEXT_SCRIPT=../*.py

all: example

example: example.o mesh.o utility.o flextGL.o
	g++ $(LFLAGS) -o example example.o mesh.o utility.o flextGL.o

example.o: example.cpp $(HEADERS)
	g++ $(CXXFLAGS) -c example.cpp

mesh.o: mesh.cpp $(HEADERS)
	g++ $(CXXFLAGS) -c mesh.cpp

utility.o: utility.cpp $(HEADERS)
	g++ $(CXXFLAGS) -c utility.cpp

flextGL.o: generated/flextGL.c
	gcc $(CFLAGS) -c generated/flextGL.c

generated/flextGL.c generated/flextGL.h: profile.txt $(FLEXT_TEMPLATES) $(FLEXT_SCRIPTS)
	python3.2 ../flextGLgen.py -T compatible -D generated profile.txt

clean:
	rm -f *.o
	rm -rf generated
	rm -f example
