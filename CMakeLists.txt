cmake_minimum_required(VERSION 3.22)
project(TileWafel)

set(CMAKE_CXX_STANDARD 20)

add_subdirectory(dep/GLFW)

add_library(GLAD dep/glad/src/glad.c)

set(SOURCE_FILES src/main.cpp src/App.cpp src/App.hpp src/Window.cpp src/Window.hpp src/Triangle.cpp src/Triangle.hpp src/Shader.cpp src/Shader.hpp src/ShaderProgram.cpp src/ShaderProgram.hpp)

add_executable(${PROJECT_NAME} ${SOURCE_FILES})

target_include_directories(${PROJECT_NAME} PUBLIC dep/glad/include dep/glfw/include dep/stb_image)
target_link_directories(${PROJECT_NAME} PRIVATE dep/glfw/src)

target_link_libraries(${PROJECT_NAME} glfw GLAD)

file(COPY res/ DESTINATION res/)