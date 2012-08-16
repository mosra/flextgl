#include <stdio.h>
#include <stdlib.h>
#include <flextGL.h>
#include <GL/glut.h>

/*
 * This example is a modified version of gl3w's usage example. It
 * demonstrates using flextGL with GLUT.
 * We don't create a core context, because many GLUT versions don't
 * support it. This doesn't matter that much, because flextGL won't
 * export deprecated functions anyway.
 */

static int width = 600, height = 600;

static float randf()
{
	return (float) rand() / ((float) RAND_MAX + 1);
}

static void display(void)
{
	glClearColor(randf(), randf(), randf(), 1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glutSwapBuffers();
	glutPostRedisplay();
}

static void reshape(int w, int h)
{
	width = w > 1 ? w : 1;
	height = h > 1 ? h : 1;
	glViewport(0, 0, width, height);
	glClearDepth(1.0);
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	glEnable(GL_DEPTH_TEST);
}

int main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGBA | GLUT_DEPTH | GLUT_DOUBLE);
	glutInitWindowSize(width, height);
	glutCreateWindow("cookie");

	glutReshapeFunc(reshape);
	glutDisplayFunc(display);

	if (!flextInit()) {
		fprintf(stderr, "failed to initialize OpenGL\n");
		return -1;
	}

	printf("OpenGL %s, GLSL %s\n", glGetString(GL_VERSION),
	       glGetString(GL_SHADING_LANGUAGE_VERSION));

        
        /* Let's test if our optional extensions are supported: */

        if (FLEXT_EXT_texture_filter_anisotropic) {
            printf("EXT_texture_filter_anisotropic is supported.\n");
        } else  {
            printf("EXT_texture_filter_anisotropic is NOT supported.\n");
        }


	glutMainLoop();
	return 0;
}
