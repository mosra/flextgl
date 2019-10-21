/*
    This file was generated using https://github.com/mosra/flextgl:

        path/to/flextGLgen.py -D generated -t somepath profile.txt

    Do not edit directly, modify the template or profile and regenerate.
*/

#include "flextGL.h"

#include <SDL.h>

#ifdef __cplusplus
extern "C" {
#endif

void flextLoadOpenGLFunctions(void) {
    /* GL_ARB_tessellation_shader */
    glpfPatchParameteri = (PFNGLPATCHPARAMETERI_PROC*)SDL_GL_GetProcAddress("glPatchParameteri");

    /* GL_VERSION_3_0 */
    glpfGetStringi = (PFNGLGETSTRINGI_PROC*)SDL_GL_GetProcAddress("glGetStringi");

}

int flextInit(void) {
    int major;
    int minor;
    SDL_GL_GetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, &major);
    SDL_GL_GetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, &minor);

    flextLoadOpenGLFunctions();

    /* Check for minimal version and profile */

    if(major * 10 + minor < 32) {
        return SDL_SetError("OpenGL context hasn't the expected version 3.2.");
    }

    /* --- Check for extensions --- */

    if(SDL_GL_ExtensionSupported("GL_ARB_tessellation_shader")) {
        FLEXT_ARB_tessellation_shader = GL_TRUE;
    }

    return 0;
}

/* Extension flag definitions */
int FLEXT_ARB_tessellation_shader = GL_FALSE;

/* Function pointer definitions */

/* GL_ARB_tessellation_shader */

PFNGLPATCHPARAMETERI_PROC* glpfPatchParameteri = NULL;

/* GL_VERSION_3_0 */

PFNGLGETSTRINGI_PROC* glpfGetStringi = NULL;

#ifdef __cplusplus
}
#endif
