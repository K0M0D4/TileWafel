//
// Created by komoda on 09.04.2022.
//

#pragma  once

#include "glad/glad.h"
#include <GLFW/glfw3.h>

#include <string>

namespace wfl {
    class Shader {
    public:
        Shader();
        Shader(GLenum type, const std::string& filepath);

        void compile(GLenum type, const std::string& filepath);

    private:
        uint32_t m_shader{};

        std::string load(const std::string& filepath);
    };
}

