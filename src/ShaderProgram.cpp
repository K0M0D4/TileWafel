//
// Created by komoda on 01.05.2022.
//

#include "ShaderProgram.hpp"

#include <iostream>

namespace wfl {
    ShaderProgram::ShaderProgram() = default;

    void ShaderProgram::init(const std::string &vertexFilepath,
                             const std::string &fragmentFilepath) {
        m_vs.compile(GL_VERTEX_SHADER, vertexFilepath);
        m_fs.compile(GL_FRAGMENT_SHADER, fragmentFilepath);

        m_program = glCreateProgram();
        glAttachShader(m_program, m_vs.getID());
        glAttachShader(m_program, m_fs.getID());
        glLinkProgram(m_program);

        errorCheck();

        m_vs.remove();
        m_fs.remove();
    }

    void ShaderProgram::use() {
        glUseProgram(m_program);
    }

    void ShaderProgram::errorCheck() const {
        int  success;
        char infoLog[512];
        glGetProgramiv(m_program, GL_LINK_STATUS, &success);

        if(!success) {
            glGetProgramInfoLog(m_program, 512, nullptr, infoLog);
            std::cout << "ERROR: Shader compilation failed: " << infoLog << "\n";
        }
    }
}