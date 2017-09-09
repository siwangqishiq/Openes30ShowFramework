//
// Created by 潘易 on 2017/9/9.
//

#include "VaoInstance.h"

int VaoInstance::init(){
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
                    "   fragColor = vec4(1.0f,0.0f,0.0f,1.0f); \n"
                    "}  \n";

    this->m_program = loadProgram(vShaderStr, fShaderStr);
    if (m_program == GL_FALSE) {
        ALOGE("%s", "load progream Error!");
        return GL_FALSE;
    }

    glGenVertexArrays(2 , this->m_vao);
    glGenBuffers(2 , this->m_vbo);

    glBindVertexArray(this->m_vao[0]);
    glBindBuffer(GL_ARRAY_BUFFER , m_vbo[0]);
    GLfloat  shape_vertex[] =
            {
                    -0.3f , 0.5f ,0.0f,
                    0.3f , 0.7f ,0.0f,
                    0.0f , 0.0f ,0.0f
            };
    glBufferData(GL_ARRAY_BUFFER ,sizeof(shape_vertex),shape_vertex , GL_STATIC_DRAW );
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0,3,GL_FLOAT ,GL_FALSE , 0 ,0);

    glBindVertexArray(m_vao[1]);
    glBindBuffer(GL_ARRAY_BUFFER , m_vbo[1]);
    GLfloat  down_vertex[] =
            {
                    0.0f , 0.0f ,0.0f,
                    -0.3f , -0.5f ,0.0f,
                    0.3f , -0.7f ,0.0f,
            };
    glBufferData(GL_ARRAY_BUFFER , sizeof(down_vertex) , down_vertex ,GL_STATIC_DRAW);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0,3,GL_FLOAT ,GL_FALSE , 0, 0);

    glBindVertexArray(0);


    glClearColor(1.0f, 1.0f, 1.0f, 0.0f);
    return GL_TRUE;
}

void VaoInstance::resize(int w,int h){
    this->m_width = w;
    this->m_height = h;
}

void VaoInstance::update(){
    //ALOGE("%s", "vao draw  sss");
    glViewport( 0 , 0, m_width , m_height);
    glClear(GL_COLOR_BUFFER_BIT);

    glUseProgram(m_program);

    glBindVertexArray(m_vao[0]);
    glDrawArrays(GL_TRIANGLES , 0 ,3);

    glBindVertexArray(m_vao[1]);
    glDrawArrays(GL_TRIANGLES , 0 ,3);

    glBindVertexArray(0);
}

void VaoInstance::destory(){
    if(m_program!=0){
        glDeleteProgram(m_program);
    }

    glDeleteVertexArrays(2,m_vao);
    glDeleteBuffers(2,m_vbo);
}

