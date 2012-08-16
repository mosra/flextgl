#include "mesh.hpp"

GLint grid_index_count(int w, int h)
{
    return w*h + w*(h-2) + 2*(h-2);
}

#define GRIDPOS(x,y) ((y)*w+(x)+offset)

void create_grid_indices(GLuint* dst, int w, int h, GLuint offset=0)
{
    int i = 0;

    for (int y = 0; y < h-1; ++y) {
        if (y > 0) {
            dst[i] = GRIDPOS(w-1,y-1); ++i;
            dst[i] = GRIDPOS(0,y+1);   ++i;
        }

        for (int x = 0; x < w; ++x) {
            dst[i] = GRIDPOS(x,y+1); ++i;
            dst[i] = GRIDPOS(x,y);   ++i;
        }
    }

    assert(i == grid_index_count(w,h));
}


void create_donut(Mesh& mesh, float r1, float r2, int s1, int s2)
{
    mesh.primitive_type = GL_TRIANGLE_STRIP;
    mesh.vertex_count = (s1+1)*(s2+1);
    mesh.index_count =  grid_index_count(s2+1, s1+1);

    mesh.vertices = new vec4[mesh.vertex_count];
    mesh.colors   = new vec4[mesh.vertex_count];
    mesh.normals  = new vec3[mesh.vertex_count];

    mesh.indices  = new GLuint[mesh.index_count];

    for (int i = 0; i <= s1; ++i) {
        double outer = (double)i/s1 * 2*M_PI;

        vec3 dir1 = vec3(sin(outer),cos(outer),0);
        vec3 dir2 = vec3(0,0,1);

        // vec3 tangent = cross(dir1,dir2);

        vec3 pos = r1 * dir1;

        for (int j = 0; j <= s2; ++j) {
            double inner = ((double)j/s2)*2*M_PI;

            vec3 normal = (float)cos(inner)*dir1 + (float)sin(inner)*dir2;

            mesh.vertices[i*(s2+1)+j] = vec4(r2 * normal + pos,1);
            mesh.normals[i*(s2+1)+j] = normal;
            // mesh.tangents[i*(s2+1)+j] = tangent;


            mesh.colors[i*(s2+1)+j] = vec4(glm::rgbColor(vec3(outer/(2*M_PI)*360, 1, 1)),1);
        }
    }

    create_grid_indices(mesh.indices, s2+1, s1+1);
}

void create_cube(Mesh& mesh)
{
    static const int indices[24] = {4, 5, 7, 6,
                                    6, 7, 3, 2,
                                    5, 1, 3, 7,
                                    0, 2, 3, 1,
                                    4, 0, 1, 5,
                                    0, 4, 6, 2};

    static const vec3 normals[6] = {vec3( 0, 0, 1),
                                    vec3( 0, 1, 0),
                                    vec3( 1, 0, 0),
                                    vec3( 0, 0,-1),
                                    vec3( 0,-1, 0),
                                    vec3(-1, 0, 0)};

    static const vec4 colors[6] = {vec4( 0, 0, 1, 1),
                                   vec4( 0, 1, 0, 1),
                                   vec4( 1, 0, 0, 1),
                                   vec4( 1, 1, 0, 1),
                                   vec4( 1, 0, 1, 1),
                                   vec4( 0, 1, 1, 1)};
    vec4 vertices[8];

    for (int i = 0, z = -1; z < 2; z+=2) 
        for (int y = -1; y < 2; y+=2) 
            for (int x = -1; x < 2; x+=2) {
                vertices[i] = vec4(x, y, z, 1);
                i++;
            }

    mesh.vertices = new vec4[24];
    mesh.normals  = new vec3[24];
    mesh.colors   = new vec4[24];
    mesh.indices  = new GLuint[24];

    for (int i = 0, f = 0; f < 6; ++f) {
        for (int c = 0; c < 4; ++c, ++i) {
            mesh.vertices[i] = vertices[indices[i]];
            mesh.normals[i]  = normals[f];
            mesh.colors[i]   = colors[f];

            mesh.indices[i]  = GLuint(i);
        }
    }

    mesh.vertex_count = 24;
    mesh.index_count = 24;
    mesh.primitive_type = GL_QUADS;
}
