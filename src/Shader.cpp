//
// Created by komoda on 09.04.2022.
//

#include "Shader.hpp"

#include <fstream>
#include <iostream>
#include <sstream>

namespace wfl {
    Shader::Shader() = default;

    Shader::Shader(GLenum type, const std::string& filepath) {
        compile(type, filepath);
    }

    void Shader::compile(GLenum type, const std::string& filepath) {
        std::string code = load(filepath);
        m_shader = glCreateShader(GL_VERTEX_SHADER);
        glShaderSource(m_shader, 1, &code.c_str(), NULL);
        glCompileShader(m_shader);
    }

    std::string load(const std::string& filepath) {
        std::ifstream file(filepath);
        if(!file.good()) {
            std::cout << "\nERROR: Opening shader file failed: " << filepath << "\n";
        }

        std::ostringstream input{};
        input << file.rdbuf();

        file.close();

        return input.str();
    }
}