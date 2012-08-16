
CFLAGS= -Igenerated -std=c89
CXXFLAGS= -Igenerated -std=c++98
LFLAGS= -lGL -ldl

all: glfw_example glut_example

glfw_example: glfw_example.o flextGL.o
	g++ $(LFLAGS) -lglfw -o glfw_example glfw_example.o flextGL.o

glfw_example.o: glfw_example.cpp generated/flextGL.c
	g++ $(CXXFLAGS) -c glfw_example.cpp


glut_example: glut_example.o flextGL.o
	gcc $(LFLAGS) -lglut -o glut_example glut_example.o flextGL.o

glut_example.o: glut_example.c generated/flextGL.c
	gcc $(CFLAGS) -c glut_example.c

flextGL.o: generated/flextGL.c
	gcc $(CFLAGS) -c generated/flextGL.c

generated/flextGL.c: profile.txt
	python ../../flextGLgen.py -T compatible -D generated profile.txt

clean:
	rm -f *.o
	rm -rf generated
	rm -f glfw_example glut_example
