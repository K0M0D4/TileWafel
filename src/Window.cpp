//
// Created by komoda on 07.04.2022.
//

#include "Window.hpp"

#include <iostream>

namespace wfl {
    Window::Window() = default;

    Window::Window(int32_t sizeX, int32_t sizeY, const std::string& name) {
        create(sizeX, sizeY, name);
    }

    void Window::create(int32_t sizeX, int32_t sizeY, const std::string& name) {
        m_window = glfwCreateWindow(sizeX, sizeY, name.c_str(),
                                    nullptr, nullptr);
        checkWindow();
        glfwMakeContextCurrent(m_window);
        glfwSetFramebufferSizeCallback(m_window, framebuffer_size_callback);

    }

    bool Window::shouldClose() {
        return glfwWindowShouldClose(m_window);
    }

    void Window::clear(float r, float g, float b, float a) {
        glClearColor(r, g, b, a);
        glClear(GL_COLOR_BUFFER_BIT);
    }

    void Window::display() {
        glfwSwapBuffers(m_window);
        glfwPollEvents();
    }

    void Window::checkWindow() {
        if(m_window == nullptr) {
            std::cout << "\nERROR: Failed to create window\n";
            glfwTerminate();
            throw std::exception();
        }
    }
}

void framebuffer_size_callback(GLFWwindow* window, int width, int height) {
    glViewport(0, 0, width, height);
}