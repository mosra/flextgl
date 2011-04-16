
LFLAGS= -lglfw -lGL

all: example

example: example.o ExtGL.o
	g++ $(LFLAGS) -o example example.o ExtGL.o

example.o: example.cpp ExtGL.cpp
	g++ -c example.cpp

ExtGL.o: ExtGL.cpp
	g++ -c ExtGL.cpp

ExtGL.cpp: profile.txt
	python2.7 ../extensionGen.py -D . profile.txt

clean:
	rm -f *.o
	rm -f ExtGL.h ExtGL.cpp
	rm -f example
