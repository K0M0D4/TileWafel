//
// Created by komoda on 07.04.2022.
//

#include "Triangle.hpp"

#include "glad/glad.h"
#include <GLFW/glfw3.h>

namespace wfl {
    Triangle::Triangle() {
        m_verts = {
                -0.5f, -0.5f,
                 0.5f, -0.5f,
                 0.0f,  0.5f,
        };
    };

    Triangle::Triangle(float ax, float ay, float bx, float by, float cx, float cy) {
        m_verts = {
                ax, ay,
                bx, by,
                cx, cy
        };
    }

    void Triangle::initGLStuff() {
        glGenBuffers(1, &m_VBO);
        glBindBuffer(GL_ARRAY_BUFFER, m_VBO);
        glBufferData(GL_ARRAY_BUFFER, m_verts.size() * sizeof(float), &m_verts, GL_STATIC_DRAW);
    }
}