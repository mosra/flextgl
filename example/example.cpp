
// Important: Include ExtGL before GLFW!
#include "ExtGL.h"

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

    // You can use the EXTGL_*_VERSION macros to define the OpenGL version
    glfwOpenWindowHint(GLFW_OPENGL_VERSION_MAJOR, EXTGL_MAJOR_VERSION);
    glfwOpenWindowHint(GLFW_OPENGL_VERSION_MINOR, EXTGL_MINOR_VERSION);
    glfwOpenWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    // Create window and OpenGL context
    GLint success = glfwOpenWindow(800, 600, 0,0,0,0,0,0, GLFW_WINDOW);

    if (!success) {
        cerr << "Failed to create OpenGL window." << endl;
        glfwTerminate();
        return 1;
    }

    // Call ExtGL's init_opengl() function.

    if (!init_opengl()) {
        // init_opengl failed. It will print it's own error message.
        glfwTerminate();
        return 1;
    }

    // Let's test if our optional extensions are supported:

    if (EXTGL_EXT_texture_filter_anisotropic) {
        cout << "EXT_texture_filter_anisotropic is supported." << endl;
    } else  {
        cout << "EXT_texture_filter_anisotropic is NOT supported." << endl;
    }

    // Put your render loop here...


    // Close GLFW and exit
    glfwTerminate();
    return 0;
}
