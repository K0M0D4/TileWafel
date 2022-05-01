//
// Created by komoda on 07.04.2022.
//

#pragma once

#include "ShaderProgram.hpp"
#include "Triangle.hpp"
#include "Window.hpp"

namespace wfl {
    class App {
    public:
        App();
        void start();

        ~App();
    private:
        Window m_window{};
        ShaderProgram m_basicShader{};
        Triangle m_triangle{};

        static void initGLFW();
        void initGLAD();
        void setupGLFW();
    };
}




