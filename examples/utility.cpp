#include "utility.hpp"

#include <fstream>

bool file_exists(const string &filename)
{
    std::ifstream ifile(filename.c_str());
    return ifile;
}

string read_file(const string &filename)
{
    std::ifstream ifile(filename.c_str());

    return string(std::istreambuf_iterator<char>(ifile),
                  std::istreambuf_iterator<char>());
}

void get_errors(void)
{
    GLenum error = glGetError();

    if (error != GL_NO_ERROR) {
        switch (error) {
        case GL_INVALID_ENUM:
            cerr << "GL: enum argument out of range." << endl;
            break;
        case GL_INVALID_VALUE:
            cerr << "GL: Numeric argument out of range." << endl;
            break;
        case GL_INVALID_OPERATION:
            cerr << "GL: Operation illegal in current state." << endl;
            break;
        case GL_INVALID_FRAMEBUFFER_OPERATION:
            cerr << "GL: Framebuffer object is not complete." << endl;
            break;
        case GL_OUT_OF_MEMORY:
            cerr << "GL: Not enough memory left to execute command." << endl;
            break;
        default:
            cerr << "GL: Unknown error." << endl;
        }
    }
}
