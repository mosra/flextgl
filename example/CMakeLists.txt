
cmake_minimum_required(VERSION 2.8)
project(example)

find_package(PythonInterp REQUIRED)
find_package(OpenGL REQUIRED)
find_library(GLFW_LIBRARIES glfw)

if (WIN32)
	set(PYTHON_EXECUTABLE "C:/python32/python.exe")
	include_directories("${PROJECT_SOURCE_DIR}/glfw/include")
	
	find_library(GLFW_LIBRARIES glfw3.lib PATHS glfw/lib/win32)
endif()

include_directories("${PROJECT_BINARY_DIR}/generated")

add_custom_command(OUTPUT "${PROJECT_BINARY_DIR}/generated/flextGL.h" "${PROJECT_BINARY_DIR}/generated/flextGL.c"
                   COMMAND ${PYTHON_EXECUTABLE} "${PROJECT_SOURCE_DIR}/../flextGLgen.py" -Dgenerated -Tglfw3 ${PROJECT_SOURCE_DIR}/profile.txt
                   DEPENDS ${PROJECT_SOURCE_DIR}/profile.txt 
                           ${PROJECT_SOURCE_DIR}/../flextGLgen.py
                           ${PROJECT_SOURCE_DIR}/../flext.py
                           ${PROJECT_SOURCE_DIR}/../templates/glfw3/flextGL.h.template
                           ${PROJECT_SOURCE_DIR}/../templates/glfw3/flextGL.c.template)                           
                   
set(SOURCE_FILES example.cpp mesh.cpp utility.cpp)
set(HEADER_FILES common.hpp mesh.hpp utility.hpp)
set(SHADERS example.frag example.vert)
				   
add_executable(example ${SOURCE_FILES} ${HEADER_FILES} ${SHADERS} profile.txt generated/flextGL.c)
target_link_libraries(example ${OPENGL_LIBRARIES} ${GLFW_LIBRARIES} ${GLEW_LIBRARIES})

add_custom_command(TARGET example COMMAND ${CMAKE_COMMAND} -E copy_if_different 
                   "${PROJECT_SOURCE_DIR}/example.frag" "${PROJECT_BINARY_DIR}")
add_custom_command(TARGET example COMMAND ${CMAKE_COMMAND} -E copy_if_different 
                   "${PROJECT_SOURCE_DIR}/example.vert" "${PROJECT_BINARY_DIR}")
