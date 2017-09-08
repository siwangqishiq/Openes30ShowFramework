
#include "VboShow.h"

int VboShow::init() {
    char vShaderStr[] =
            "#version 300 es    \n"
                    "layout(location = 0) in vec4 vPosition; \n"
                    "void main()    \n"
                    "{              \n"
                    "   gl_Position = vPosition; \n"
                    "}              \n";

    char fShaderStr[] =
            "#version 300 es    \n"
                    "precision mediump float; \n"
                    "out vec4 fragColor; \n"
                    "void main() { \n"
                    "   fragColor = vec4(1.0f,1.0f,1.0f,1.0f); \n"
                    "}  \n";

    this->m_program = loadProgram(vShaderStr, fShaderStr);
    if (m_program == GL_FALSE) {
        ALOGE("%s", "load progream Error!");
    }

    glGenBuffers(1, &m_vbo);

    GLfloat vertexs[2 * 3] =
            {
                    0.0f, 0.0f, 0.0f,
                    0.5f, 0.5f, 0.0f,
            };
    glBindBuffer(GL_ARRAY_BUFFER , m_vbo);
    glBufferData(GL_ARRAY_BUFFER,sizeof(vertexs) ,vertexs,GL_STATIC_DRAW);


    glGenBuffers(1, &m_vbo_shape);
    GLfloat  shape_vertex[] =
            {
                    -0.3f , 0.5f ,0.0f,
                    0.3f , 0.7f ,0.0f,
                    0.0f , 0.0f ,0.0f
            };
    glBindBuffer(GL_ARRAY_BUFFER , m_vbo_shape);
    glBufferData(GL_ARRAY_BUFFER , sizeof(shape_vertex) ,shape_vertex , GL_STATIC_DRAW);

    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);

    return GL_TRUE;
}

void VboShow::resize(int w, int h) {
    this->m_width = w;
    this->m_height = h;
}


void VboShow::update() {
    ALOGE("m_vbo1 %d", this->m_vbo);
    ALOGE("m_vbo2 %d", this->m_vbo_shape);

    glViewport(0, 0, this->m_width, this->m_height);
    glClear(GL_COLOR_BUFFER_BIT);

    glUseProgram(m_program);

    //
    glEnableVertexAttribArray(0);
    glBindBuffer(GL_ARRAY_BUFFER, m_vbo);
    glVertexAttribPointer(0,3,GL_FLOAT,GL_FALSE,0,0);
    glDrawArrays(GL_LINES, 0, 2);

    glBindBuffer(GL_ARRAY_BUFFER , m_vbo_shape);
    glVertexAttribPointer(0,3,GL_FLOAT,GL_FALSE,0,0);
    glDrawArrays(GL_TRIANGLES, 0, 3);

    glDisableVertexAttribArray(0);
}

void VboShow::destory() {
    if (m_program != GL_FALSE) {
        glDeleteProgram(m_program);
    }

    if (m_vbo != 0) {
        glDeleteBuffers(1, &m_vbo);
    }
}
