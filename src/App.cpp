//
// Created by komoda on 07.04.2022.
//

#include "App.hpp"

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <iostream>

namespace wfl {
    App::App() {
        initGLFW();
        setupGLFW();
        m_window.create(1280, 720, "TileWafel");
        initGLAD();

        m_triangle.init();

        m_basicShader.init("res/basic.vs", "res/basic.fs");
        m_basicShader.use();
    }

    void App::start() {
        while(!m_window.shouldClose()) {
            m_window.clear(0.3f, 0.3f, 0.35f, 1.0f);

            m_triangle.draw();

            m_window.display();
        }
    }

    App::~App() {
        glfwTerminate();
    }

    void App::initGLFW() {
        if(!glfwInit()) {
            std::cout << "\nERROR: Failed to initialize GLFW\n";
            throw std::exception();
        }
    }

    void App::initGLAD() {
        if(!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
            std::cout << "\nERROR: Failed to initialize GLAD\n";
            throw std::exception();
        }
    }

    void App::setupGLFW() {
        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    }
}