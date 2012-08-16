#version 330

uniform vec3 light_pos;
uniform vec4 light_color;
uniform float specular_coeff;
uniform float shininess;
uniform vec4 ambient_color;

in vec4 frag_color;

in vec3 world_normal;
in vec4 world_pos;
in vec3 world_view;

vec4 diffuse(vec4 mat_color, vec4 light_color, vec3 N, vec3 L)
{
    return mat_color * light_color * max(0, dot(N,L));
}

vec4 specular(vec4 light_color, float coeff, float shininess, 
              vec3 N, vec3 L, vec3 V)
{
    vec3 H = normalize(L+V);

    return light_color * coeff * pow(max(0,dot(N,H)), shininess);
}

void main()
{
    vec3 normal = normalize(world_normal);
    vec3 pos = world_pos.xyz / world_pos.w;
    vec3 view = normalize(world_view);

    vec3 light_dir = normalize(light_pos-pos);

    vec4 ambient_part = ambient_color * frag_color;
    vec4 diffuse_part = diffuse(frag_color, light_color, normal, light_dir);
    vec4 specular_part = specular(light_color, specular_coeff, shininess,
                                  normal, light_dir, view);

    gl_FragColor = ambient_part + diffuse_part + specular_part;
}
