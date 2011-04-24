
CFLAGS= -Igenerated
LFLAGS= -lglfw -lGL

all: example

example: example.o flextGL.o
	g++ $(LFLAGS) -o example example.o flextGL.o

example.o: example.cpp generated/flextGL.c
	g++ $(CFLAGS) -c example.cpp

flextGL.o: generated/flextGL.c
	gcc $(CFLAGS) -c generated/flextGL.c

generated/flextGL.c: profile.txt
	python2.7 ../flextGLgen.py -T compatible -D generated profile.txt

clean:
	rm -f *.o
	rm -rf generated
	rm -f example
