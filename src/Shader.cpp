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
        m_shader = glCreateShader(type);
        const char* data = code.c_str();
        glShaderSource(m_shader, 1, &data, nullptr);
        glCompileShader(m_shader);
        errorCheck();
    }

    const uint32_t& Shader::getID() const {
        return m_shader;
    }

    void Shader::remove() const {
        glDeleteShader(m_shader);
    }

    void Shader::errorCheck() const {
        int  success;
        char infoLog[512];
        glGetShaderiv(m_shader, GL_COMPILE_STATUS, &success);

        if(!success) {
            glGetShaderInfoLog(m_shader, 512, nullptr, infoLog);
            std::cout << "ERROR: Shader compilation failed: " << infoLog << "\n";
        }
    }

    std::string Shader::load(const std::string& filepath) {
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