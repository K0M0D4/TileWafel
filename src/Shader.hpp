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

        const uint32_t& getID() const;
        void remove() const;

    private:
        uint32_t m_shader{};

        void errorCheck() const;

        static std::string load(const std::string& filepath);
    };
}

