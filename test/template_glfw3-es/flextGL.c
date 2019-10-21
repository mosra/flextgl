/* WARNING: This file was automatically generated */
/* Do not edit. */

#include "flextGL.h"

#include <stdio.h>
#include <GLFW/glfw3.h>

#ifdef __cplusplus
extern "C" {
#endif

void flextLoadOpenGLFunctions(void) {
    /* GL_OES_vertex_array_object */
    glpfGenVertexArraysOES = (PFNGLGENVERTEXARRAYSOES_PROC*)glfwGetProcAddress("glGenVertexArraysOES");

}

int flextInit(GLFWwindow* window) {
    int major = glfwGetWindowAttrib(window, GLFW_CONTEXT_VERSION_MAJOR);
    int minor = glfwGetWindowAttrib(window, GLFW_CONTEXT_VERSION_MINOR);

    flextLoadOpenGLFunctions();

    /* Check for minimal version */

    if(major * 10 + minor < 20) {
        fprintf(stderr, "Error: OpenGL version 2.0 not supported.\n");
        fprintf(stderr, "       Your version is %d.%d.\n", major, minor);
        fprintf(stderr, "       Try updating your graphics driver.\n");
        return GL_FALSE;
    }

    /* Check for extensions */

    if(glfwExtensionSupported("GL_OES_vertex_array_object")) {
        FLEXT_OES_vertex_array_object = GL_TRUE;
    }

    return GL_TRUE;
}

/* Extension flag definitions */
int FLEXT_OES_vertex_array_object = GL_FALSE;

/* Function pointer definitions */

/* GL_OES_vertex_array_object */
PFNGLGENVERTEXARRAYSOES_PROC* glpfGenVertexArraysOES = NULL;

#ifdef __cplusplus
}
#endif
