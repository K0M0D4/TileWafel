//
// Created by komoda on 07.04.2022.
//

#pragma once

#include <array>
#include <cstdint>

namespace wfl {
    class Triangle {
    public:
        Triangle();
        Triangle(float ax, float ay, float bx, float by, float cx, float cy);
    private:
        std::array<float, 6> m_verts {};

        uint32_t m_VBO{};
        uint32_t m_VAO{};

        void initGLStuff();
    };
}
