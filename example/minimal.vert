#version 330

uniform mat4 perspective;
uniform mat4 view;
uniform mat4 model;

in vec4 vertex;
in vec3 normal;
in vec4 color;

out vec4 frag_color;
out vec3 world_normal;
out vec4 world_pos;
out vec3 world_view;

void main()
{
    world_pos = model * vertex;
    vec4 view_pos = view * world_pos;
    gl_Position = perspective * view_pos;

    world_normal = mat3(model) * normal;
        
    world_view = inverse(mat3(view))*-normalize(view_pos.xyz);

    frag_color = color;
}
