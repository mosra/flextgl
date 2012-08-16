#ifndef MESH_HH
#define MESH_HH

#include "common.hpp"

struct Mesh
{
    GLenum primitive_type;
    GLuint index_count;
    GLuint vertex_count;

    vec4* vertices;
    vec3* normals;
    vec4* colors;

    GLuint* indices;

    Mesh() :
        vertices(NULL),
        normals(NULL),
        colors(NULL),
        indices(NULL) {};

    ~Mesh() 
    {
        if (vertices!=NULL) delete[] vertices;
        if (normals!=NULL)  delete[] normals;
        if (colors!=NULL)   delete[] colors;
        if (indices!=NULL)  delete[] indices;
    }
};

void create_donut(Mesh& mesh, 
                  float radius1, float radius2, 
                  int resolution1, int resolution2);

void create_cube(Mesh& mesh);

#endif
