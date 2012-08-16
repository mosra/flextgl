#include "common.hpp"
#include "mesh.hpp"

#define BUFFER_SIZE 65536

// Some global variables

// Window dimensions
int window_width  = 800,
    window_height = 600;

vec3 light_pos(0, 8, 3);
vec4 light_color(1,1,1,1);
vec4 ambient_color(0.0125,0.025,0.025,1);

float specular_coeff = 1.0;
float shininess = 30.0; 

// Shader objects
GLuint vertex_shader;
GLuint fragment_shader;
GLuint shader_program;

// VAOs and VBOs
GLuint mesh_vao;
GLuint vertex_buffer;
GLuint color_buffer;
GLuint normal_buffer;
GLuint index_buffer;

// Function declarations
void init_shaders(const string& vertex_shader_file, const string& fragment_shader_file);
void free_shaders();
void init_buffers(const Mesh& mesh);
void free_buffers();
void display_loop();
void draw(const Mesh& mesh, const mat4& perspective, const mat4& view, const mat4& model);

int main()
{    
    // Initialize GLFW
    glfwInit();

    // Set flags before window creation
    glfwOpenWindowHint(GLFW_WINDOW_NO_RESIZE, GL_TRUE); // Make window size fixed

    if(glfwOpenWindow(window_width, window_height,   // Window size
                      0, 0, 0, 0,                    // Bit depth: automatic
                      24, 8,                         // Depth, stencil depth
                      GLFW_WINDOW) != GL_TRUE) {     // Windowed mode
        cerr << "Failed to create OpenGL window" << endl;
        
        glfwTerminate();
        return 1;
    }

    // Initialize flextGL
    if (flextInit() != GL_TRUE) {
        return 1;
    }

    // Start display loop
    display_loop();    

    glfwTerminate();
    return 0;
}

void init_transforms(mat4& perspective, mat4& view, mat4& model)
{
    float aspect = float(window_width)/float(window_height);
    perspective = glm::perspective(60.0f, aspect, 0.1f, 100.0f);

    view = glm::translate(mat4(1.0f), vec3(0,0,-4));

    model = mat4(1.0f);
}

void step_simulation(mat4& view, mat4& model, double time_diff)
{
    // Do a continuous rotation of the model
    model = glm::rotate(model, float(30.0 * time_diff), vec3(0,1,0));
    model = glm::rotate(model, float(20.0 * time_diff), vec3(1,0,0));
    model = glm::rotate(model, float(10.0 * time_diff), vec3(0,0,1));
}


void display_loop()
{
    Mesh mesh;
    create_donut(mesh, 1.0, 0.25, 128, 32);

    glEnable(GL_FRAMEBUFFER_SRGB);
    glEnable(GL_DEPTH_TEST);

    init_shaders("minimal.vert", "minimal.frag");
    init_buffers(mesh);

    bool running = true;
    mat4 perspective, view, model;

    init_transforms(perspective, view, model);

    double last_time = glfwGetTime();

    while(running) {
        double time_now = glfwGetTime();
        double time_diff = time_now-last_time;
        last_time = time_now;

        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        step_simulation(view, model, time_diff);

        draw(mesh, perspective, view, model);

        get_errors();
        glfwSwapBuffers();
        
        running = running && !glfwGetKey( GLFW_KEY_ESC );
        running = running && !glfwGetKey( 'Q' );
        running = running && glfwGetWindowParam( GLFW_OPENED );        
    }

    free_buffers();
    free_shaders();

    // Mesh destructor is called here..
}

GLuint compile_shader(const string& source, const string& name, GLenum type)
{
    GLint status;
    GLuint shader = glCreateShader(type);

    const char* source_c_string = source.c_str();

    glShaderSource(shader, 1, &source_c_string, NULL);
    glCompileShader(shader);

    glGetShaderiv(shader, GL_COMPILE_STATUS, &status);

    if (!glIsShader(shader) || !status) {
        cout << name << ": Shader compilation failed." << endl;
        
        char* buffer = new char[BUFFER_SIZE];
        GLsizei length;

        glGetShaderInfoLog(shader, BUFFER_SIZE, &length, buffer);

        if (length > 0) {
            cout << buffer << endl;
        }    
        
        delete[] buffer;

        exit(1);
    }

    return shader;
}

GLuint link_program(GLuint vertex, GLuint fragment)
{
    GLint status;
    GLuint program = glCreateProgram();

    glAttachShader(program, vertex);
    glAttachShader(program, fragment);

    glLinkProgram(program);

    glGetProgramiv(program, GL_LINK_STATUS, &status);

    if (!glIsProgram(program) || !status) {
        cout << "Shader linkage failed." << endl;
        
        char* buffer = new char[BUFFER_SIZE];
        GLsizei length;

        glGetProgramInfoLog(program, BUFFER_SIZE, &length, buffer);

        if (length > 0) {
            cout << buffer << endl;
        }

        delete[] buffer;

        exit(1);
    }

    return program;
}

void init_shaders(const string& vertex_shader_file,
                  const string& fragment_shader_file)
{
    if (!file_exists(vertex_shader_file) ||
        !file_exists(fragment_shader_file)) {
        cerr << "Shader file missing" << endl;
        exit(1);
    }
    

    string vertex_shader_source = read_file(vertex_shader_file);
    string fragment_shader_source = read_file(fragment_shader_file);

    vertex_shader = compile_shader(vertex_shader_source, vertex_shader_file, GL_VERTEX_SHADER);
    fragment_shader = compile_shader(fragment_shader_source, fragment_shader_file, GL_FRAGMENT_SHADER);
    
    shader_program = link_program(vertex_shader, fragment_shader);

    get_errors();
}

void free_shaders()
{
    glDeleteProgram(shader_program);
    glDeleteShader(vertex_shader);
    glDeleteShader(fragment_shader);
}

void init_buffers(const Mesh& mesh)
{
    // Create and bind VAO
    glGenVertexArrays(1, &mesh_vao);
    glBindVertexArray(mesh_vao);


    // Create VBOs
    glGenBuffers(1, &vertex_buffer);
    glGenBuffers(1, &color_buffer);
    glGenBuffers(1, &normal_buffer);
    glGenBuffers(1, &index_buffer);


    // Upload, enable & set VBOs

    
    glBindBuffer(GL_ARRAY_BUFFER, vertex_buffer);
    glBufferData(GL_ARRAY_BUFFER, mesh.vertex_count * sizeof(vec4), mesh.vertices, GL_STATIC_DRAW);
    GLint vertex_attrib = glGetAttribLocation(shader_program, "vertex");
    glEnableVertexAttribArray(vertex_attrib);
    glVertexAttribPointer(vertex_attrib, 4, GL_FLOAT, GL_FALSE, 0, NULL);

    glBindBuffer(GL_ARRAY_BUFFER, color_buffer);
    glBufferData(GL_ARRAY_BUFFER, mesh.vertex_count * sizeof(vec4), mesh.colors, GL_STATIC_DRAW);
    GLint color_attrib  = glGetAttribLocation(shader_program, "color");
    glEnableVertexAttribArray(color_attrib);
    glVertexAttribPointer(color_attrib, 4, GL_FLOAT, GL_FALSE, 0, NULL);

    glBindBuffer(GL_ARRAY_BUFFER, normal_buffer);
    glBufferData(GL_ARRAY_BUFFER, mesh.vertex_count * sizeof(vec3), mesh.normals, GL_STATIC_DRAW);
    GLint normal_attrib = glGetAttribLocation(shader_program, "normal");
    glEnableVertexAttribArray(normal_attrib);
    glVertexAttribPointer(normal_attrib, 3, GL_FLOAT, GL_FALSE, 0, NULL);

    
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, index_buffer);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, mesh.index_count * sizeof(GLuint), mesh.indices, GL_STATIC_DRAW);

    glBindVertexArray(0);
                 
}

void free_buffers()
{
    glDeleteVertexArrays(1, &mesh_vao);

    glDeleteBuffers(1, &vertex_buffer);
    glDeleteBuffers(1, &color_buffer);
    glDeleteBuffers(1, &normal_buffer);
    glDeleteBuffers(1, &index_buffer);
}

void draw(const Mesh& mesh, const mat4& perspective, const mat4& view, const mat4& model)
{
    // Bind shader
    glUseProgram(shader_program);

    // Set uniforms
    GLint perspective_uniform    = glGetUniformLocation(shader_program, "perspective");
    GLint view_uniform           = glGetUniformLocation(shader_program, "view");
    GLint model_uniform          = glGetUniformLocation(shader_program, "model");
    GLint light_pos_uniform      = glGetUniformLocation(shader_program, "light_pos");
    GLint light_color_uniform    = glGetUniformLocation(shader_program, "light_color");
    GLint ambient_color_uniform  = glGetUniformLocation(shader_program, "ambient_color");
    GLint specular_coeff_uniform = glGetUniformLocation(shader_program, "specular_coeff");
    GLint shininess_uniform      = glGetUniformLocation(shader_program, "shininess");

    glUniformMatrix4fv(perspective_uniform, 1, GL_FALSE, glm::value_ptr(perspective));
    glUniformMatrix4fv(view_uniform, 1, GL_FALSE, glm::value_ptr(view));
    glUniformMatrix4fv(model_uniform, 1, GL_FALSE, glm::value_ptr(model));
    
    glUniform3fv(light_pos_uniform, 1, glm::value_ptr(light_pos));
    glUniform4fv(light_color_uniform, 1, glm::value_ptr(light_color));
    glUniform4fv(ambient_color_uniform, 1, glm::value_ptr(ambient_color));
    glUniform1f(specular_coeff_uniform, specular_coeff);
    glUniform1f(shininess_uniform, shininess);


    // Bind VAO
    glBindVertexArray(mesh_vao);

    // Draw mesh
    glDrawElements(mesh.primitive_type, mesh.index_count, GL_UNSIGNED_INT, NULL);

    // Unbind VAO
    glBindVertexArray(0);

    // Unbind shaders
    glUseProgram(0);
}
