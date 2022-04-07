//
// Created by komoda on 07.04.2022.
//

#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <string>

namespace wfl {
    class Window {
    public:
        Window();
        Window(int32_t sizeX, int32_t sizeY, std::string name);

        void create(int32_t sizeX, int32_t sizeY, std::string name);

        bool shouldClose();
        void display();

        void clear(float r, float g, float b, float a);
    private:
        GLFWwindow* m_window{};

        // chceck if good after creating
        void checkWindow();
    };
}

void framebuffer_size_callback(GLFWwindow* window, int width, int height);
