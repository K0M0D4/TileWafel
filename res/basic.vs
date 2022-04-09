#version 330 core
layout (location) in vec3 vPos;

void main() {
    gl_Position = vec4(vPos.x, vPos.y, vPos.z, 1.0f);
}