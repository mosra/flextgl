/* WARNING: This file was automatically generated */
/* Do not edit. */

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

    if (major * 10 + minor < 32) {
        fprintf(stderr, "Error: OpenGL version 3.2 not supported.\n");
        fprintf(stderr, "       Your version is %d.%d.\n", major, minor);
        fprintf(stderr, "       Try updating your graphics driver.\n");
        return GL_FALSE;
    }


    /* --- Check for extensions --- */

    if (glfwExtensionSupported("GL_ARB_tessellation_shader")) {
        FLEXT_ARB_tessellation_shader = GL_TRUE;
    }


    return GL_TRUE;
}



void flextLoadOpenGLFunctions(void)
{
    /* --- Function pointer loading --- */


    /* GL_ARB_tessellation_shader */

    glpfPatchParameteri = (PFNGLPATCHPARAMETERI_PROC*)glfwGetProcAddress("glPatchParameteri");


    /* GL_VERSION_1_2 */



    /* GL_VERSION_1_3 */



    /* GL_VERSION_1_4 */



    /* GL_VERSION_1_5 */



    /* GL_VERSION_2_0 */



    /* GL_VERSION_2_1 */



    /* GL_VERSION_3_0 */

    glpfGetStringi = (PFNGLGETSTRINGI_PROC*)glfwGetProcAddress("glGetStringi");


    /* GL_VERSION_3_1 */



    /* GL_VERSION_3_2 */



}

/* ----------------------- Extension flag definitions ---------------------- */
int FLEXT_ARB_tessellation_shader = GL_FALSE;

/* ---------------------- Function pointer definitions --------------------- */

/* GL_ARB_tessellation_shader */

PFNGLPATCHPARAMETERI_PROC* glpfPatchParameteri = NULL;

/* GL_VERSION_3_0 */

PFNGLGETSTRINGI_PROC* glpfGetStringi = NULL;



#ifdef __cplusplus
}
#endif
