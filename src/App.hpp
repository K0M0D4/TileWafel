//
// Created by komoda on 07.04.2022.
//

#pragma once

#include "Window.hpp"

namespace wfl {
    class App {
    public:
        App();
        void start();

        ~App();
    private:
        Window m_window{};

        static void initGLFW();
        void initGLAD();
        void setupGLFW();
    };
}




