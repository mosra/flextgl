
// Important: Include ExtGL before GLFW!
#include "flextGL.h"

// Since GLU does not work with core OpenGL, we inhibit it's inclusion.
#define GLFW_NO_GLU
#include <GL/glfw.h>

#include <iostream>

using std::cout;
using std::cerr;
using std::endl;

int main ()
{
    // Initialize GLFW
    glfwInit();

    // The FLEXTGL_*_VERSION macro define the minor and major version selected 
    // in the profile file.

    cout << "We want OpenGL " 
         << FLEXTGL_MAJOR_VERSION << "." << FLEXTGL_MINOR_VERSION << " "
         << (FLEXTGL_CORE_PROFILE?"core":"compatibility")
         << endl;
    
    // FLEXTGL_CORE_PROFILE tells us if this is core or compatibility.

    GLuint profile;
    if (FLEXTGL_CORE_PROFILE) {
      profile = GLFW_OPENGL_CORE_PROFILE;
    } else {
      profile = GLFW_OPENGL_COMPAT_PROFILE;
    }

    // We can use this to setup the desired OpenGL version in GLFW
    glfwOpenWindowHint(GLFW_OPENGL_VERSION_MAJOR, FLEXTGL_MAJOR_VERSION);
    glfwOpenWindowHint(GLFW_OPENGL_VERSION_MINOR, FLEXTGL_MINOR_VERSION);
    glfwOpenWindowHint(GLFW_OPENGL_PROFILE, profile);

    // Create window and OpenGL context
    GLint success = glfwOpenWindow(800, 600, 0,0,0,0,0,0, GLFW_WINDOW);

    if (!success) {
        cerr << "Failed to create OpenGL window." << endl;
        glfwTerminate();
        return 1;
    }

    cout << "OpenGL context created successfully" << endl;
    
    // Call ExtGL's init_opengl() function.

    if (!init_opengl()) {
        // init_opengl failed. It will print it's own error message.
        glfwTerminate();
        return 1;
    }
    
    cout << "OpenGL functions and extensions loaded successfully" << endl;

    // Let's test if our optional extensions are supported:

    if (FLEXTGL_EXT_texture_filter_anisotropic) {
        cout << "EXT_texture_filter_anisotropic is supported." << endl;
    } else  {
        cout << "EXT_texture_filter_anisotropic is NOT supported." << endl;
    }

    // Put your render loop here...


    // Close GLFW and exit
    glfwTerminate();
    return 0;
}
