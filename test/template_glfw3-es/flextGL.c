
#include "flextGL.h"
#include "GLFW/glfw3.h"

#include <stdio.h>


#ifdef __cplusplus
extern "C" {
#endif


void flextLoadOpenGLFunctions(void);

int flextInit(GLFWwindow* window)
{
    int major = glfwGetWindowAttrib(window, GLFW_CONTEXT_VERSION_MAJOR);
    int minor = glfwGetWindowAttrib(window, GLFW_CONTEXT_VERSION_MINOR);

    flextLoadOpenGLFunctions();

    /* --- Check for minimal version and profile --- */

    if (major * 10 + minor < 20) {
        fprintf(stderr, "Error: OpenGL version 2.0 not supported.\n");
        fprintf(stderr, "       Your version is %d.%d.\n", major, minor);
        fprintf(stderr, "       Try updating your graphics driver.\n");
        return GL_FALSE;
    }

    /* --- Check for extensions --- */

    if (glfwExtensionSupported("GL_OES_vertex_array_object")) {
        FLEXT_OES_vertex_array_object = GL_TRUE;
    }


    return GL_TRUE;
}



void flextLoadOpenGLFunctions(void)
{
    /* --- Function pointer loading --- */


    /* GL_OES_vertex_array_object */

    glpfGenVertexArraysOES = (PFNGLGENVERTEXARRAYSOES_PROC*)glfwGetProcAddress("glGenVertexArraysOES");


}

/* ----------------------- Extension flag definitions ---------------------- */
int FLEXT_OES_vertex_array_object = GL_FALSE;

/* ---------------------- Function pointer definitions --------------------- */

/* GL_OES_vertex_array_object */

PFNGLGENVERTEXARRAYSOES_PROC* glpfGenVertexArraysOES = NULL;



#ifdef __cplusplus
}
#endif
