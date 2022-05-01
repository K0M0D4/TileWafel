//
// Created by komoda on 01.05.2022.
//

#pragma once

#include "Shader.hpp"

namespace wfl {
    class ShaderProgram {
    public:
        ShaderProgram();

        void init(const std::string& vertexFilepath,
                      const std::string& fragmentFilepath);

        void use();

    private:
        uint32_t m_program{};

        void errorCheck() const;

        Shader m_vs{};
        Shader m_fs{};
    };
}


