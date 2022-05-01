//
// Created by komoda on 07.04.2022.
//

#include "Triangle.hpp"

#include "glad/glad.h"
#include <GLFW/glfw3.h>

#include <iostream>

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

    void Triangle::draw() {
        glBindVertexArray(m_VAO);
        glDrawArrays(GL_TRIANGLES, 0, 3);
    }

    void Triangle::init() {
        glGenBuffers(1, &m_VBO);
        glGenVertexArrays(1, &m_VAO);

        glBindVertexArray(m_VAO);
        glBindBuffer(GL_ARRAY_BUFFER, m_VBO);
        glBufferData(GL_ARRAY_BUFFER, m_verts.size() * sizeof(float), &m_verts,
                     GL_STATIC_DRAW);
        glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), (void*)0);
        glEnableVertexAttribArray(0);
    }
}