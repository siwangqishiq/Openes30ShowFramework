//
// Created by panyi on 2017/9/8.
//
#include "VertexShow.h"

int VertexShow::init() {
    char vShaderStr[] =
            "#version 300 es    \n"
                    "layout(location = 0) in vec4 vColor; \n"
                    "layout(location = 1) in vec4 vPosition; \n"
                    "out vec4 vOutColor; \n"
                    "void main()    \n"
                    "{              \n"
                    "   gl_Position = vPosition; \n"
                    "   vOutColor = vColor; \n"
                    "}              \n";

    char fShaderStr[] =
            "#version 300 es    \n"
                    "precision mediump float; \n"
                    "in vec4 vOutColor; \n"
                    "out vec4 fragColor; \n"
                    "void main() { \n"
                    "   fragColor = vOutColor; \n"
                    "}  \n";

    this->m_program = loadProgram(vShaderStr, fShaderStr);
    if (m_program == GL_FALSE) {
        ALOGE("%s", "load progream Error!");
    }

    char fShaderStr2[] =
            "#version 300 es    \n"
                    "precision mediump float; \n"
                    "out vec4 fragColor; \n"
                    "void main() { \n"
                    "   fragColor = vec4(1.0f , 1.0f , 0.0f , 1.0f); \n"
                    "}  \n";

    m_second_program = loadProgram(vShaderStr, fShaderStr2);

    if (m_second_program == GL_FALSE) {
        ALOGE("%s", "load progream Error!");
    }

    glClearColor(1.0f, 1.0f, 1.0f, 0.0f);

    return GL_TRUE;
}

void VertexShow::resize(int w, int h) {
    this->m_width = w;
    this->m_height = h;
}

void VertexShow::update() {
    GLfloat color[4] = {0.0f, 0.0f, 0.0f, 1.0f};
    GLfloat vertexPos[3 * 3] =
            {
                    0.0f, 0.5f, 0.0f,
                    -0.5f, -0.5f, 0.0f,
                    0.5f, -0.5f, 0.0f,
            };

    glViewport(0, 0, this->m_width, this->m_height);
    glClear(GL_COLOR_BUFFER_BIT);

    frame++;
    if (frame % 2 == 0) {
        glUseProgram(m_program);
    } else {
        glUseProgram(m_second_program);
    }

    glVertexAttrib4fv(0, color);
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 0, vertexPos);
    glEnableVertexAttribArray(1);
    glDrawArrays(GL_TRIANGLES, 0, 3);
    glDisableVertexAttribArray(1);

    ALOGE("VertexShow::draw");
}

void VertexShow::destory() {
    if (m_program != GL_FALSE) {
        glDeleteProgram(m_program);
    }
}
