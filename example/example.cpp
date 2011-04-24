
// Important: Include flextGL before GLFW!
#include "flextGL.h"

// Since GLU does not work with core OpenGL, we inhibit it's inclusion.
#define GLFW_NO_GLU
#include <GL/glfw.h>

#include <iostream>

using std::cout;
using std::cerr;
using std::endl;


/* 
 * Helper function that properly initializes the GLFW window before opening.
 */
int openWindow( int width, int height, 
                int redbits, int greenbits, int bluebits, int alphabits,
                int depthbits, int stencilbits, int mode )
{
    GLuint profile;
    if (FLEXT_CORE_PROFILE) {
      profile = GLFW_OPENGL_CORE_PROFILE;
    } else {
      profile = GLFW_OPENGL_COMPAT_PROFILE;
    }

    // We can use this to setup the desired OpenGL version in GLFW
    glfwOpenWindowHint(GLFW_OPENGL_VERSION_MAJOR, FLEXT_MAJOR_VERSION);
    glfwOpenWindowHint(GLFW_OPENGL_VERSION_MINOR, FLEXT_MINOR_VERSION);
    glfwOpenWindowHint(GLFW_OPENGL_PROFILE, profile);

    // Create window and OpenGL context
    GLint success = glfwOpenWindow(width, height,
                                   redbits, greenbits, bluebits, alphabits,
                                   depthbits, stencilbits, mode);

    if (!success) {
        cerr << "Failed to create OpenGL window." << endl;
        return GL_FALSE;
    }
    
    // Call flext's init_opengl() function.
    success = flextInit();

    return success;
}

int main ()
{
    // Initialize GLFW
    glfwInit();

    // The FLEXT_*_VERSION macro define the minor and major version selected 
    // in the profile file.

    cout << "We want OpenGL " 
         << FLEXT_MAJOR_VERSION << "." << FLEXT_MINOR_VERSION << " "
         << (FLEXT_CORE_PROFILE?"core":"compatibility")
         << endl;
    
    if (!openWindow(800, 600, 0,0,0,0,0,0, GLFW_WINDOW)) {
        glfwTerminate();        
        return 1;
    }

    cout << "OpenGL window created successfully" << endl;    
    cout << "OpenGL functions and extensions loaded successfully" << endl;

    // Let's test if our optional extensions are supported:

    if (FLEXT_EXT_texture_filter_anisotropic) {
        cout << "EXT_texture_filter_anisotropic is supported." << endl;
    } else  {
        cout << "EXT_texture_filter_anisotropic is NOT supported." << endl;
    }

    // Put your render loop here...


    // Close GLFW and exit
    glfwTerminate();
    return 0;
}
