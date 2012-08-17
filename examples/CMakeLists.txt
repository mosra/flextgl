
cmake_minimum_required(VERSION 2.8)
project(example)

find_package(PythonInterp REQUIRED)
find_package(OpenGL REQUIRED)

find_library(GLFW_LIBRARIES glfw)

include_directories("${PROJECT_BINARY_DIR}/generated")

add_custom_command(OUTPUT "${PROJECT_BINARY_DIR}/generated/flextGL.h" "${PROJECT_BINARY_DIR}/generated/flextGL.c"
                   COMMAND ${PYTHON_EXECUTABLE} "${PROJECT_SOURCE_DIR}/../flextGLgen.py" -Dgenerated -Tglfw ${PROJECT_SOURCE_DIR}/profile.txt
                   DEPENDS ${PROJECT_SOURCE_DIR}/profile.txt 
                           ${PROJECT_SOURCE_DIR}/../flextGLgen.py
                           ${PROJECT_SOURCE_DIR}/../flext.py
                           ${PROJECT_SOURCE_DIR}/../templates/glfw/flextGL.h.template
                           ${PROJECT_SOURCE_DIR}/../templates/glfw/flextGL.c.template)                           
                   

add_executable(example example.cpp mesh.cpp utility.cpp generated/flextGL.c)
target_link_libraries(example ${OPENGL_LIBRARIES} ${GLFW_LIBRARIES} ${GLEW_LIBRARIES})

add_custom_command(TARGET example COMMAND ${CMAKE_COMMAND} -E copy_if_different 
                   "${PROJECT_SOURCE_DIR}/example.frag" $<TARGET_FILE_DIR:example>)
add_custom_command(TARGET example COMMAND ${CMAKE_COMMAND} -E copy_if_different 
                   "${PROJECT_SOURCE_DIR}/example.vert" $<TARGET_FILE_DIR:example>)
