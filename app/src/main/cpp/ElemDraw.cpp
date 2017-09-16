//
// Created by panyi on 2017/9/11.
//

#include "ElemDraw.h"

int ElemDraw::init() {
    char vShaderStr[]=
            "#version 300 es    \n"
                    "layout(location = 0) in vec4 vPosition; \n"
                    "void main()    \n"
                    "{              \n"
                    "   gl_Position = vPosition; \n"
                    "}              \n";

    char fShaderStr[]=
            "#version 300 es    \n"
                    "precision mediump float; \n"
                    "out vec4 fragColor; \n"
                    "void main() { \n"
                    "   fragColor = vec4(1.0f,0.0f,0.0f,1.0f); \n"
                    "}  \n";

    this->m_program = loadProgram(vShaderStr , fShaderStr);
    if(m_program == GL_FALSE){
        ALOGE("%s","load progream Error!");
        return GL_FALSE;
    }

    glClearColor(1.0f,1.0f,1.0f,1.0f);
    return GL_TRUE;
}

void ElemDraw::resize(int w,int h) {
    this->m_width = w;
    this->m_height = h;
}

void ElemDraw::update() {
    //ALOGE("HelloTrigle::update");
    GLfloat vVertex[]={ 0.0f ,0.5f ,0.0f
                       ,-0.5f ,-0.5f ,0.0f,
                       0.5f ,-0.5f ,0.0f};

    glViewport( 0, 0,this->m_width,this->m_height);
    glClear(GL_COLOR_BUFFER_BIT);

    glUseProgram(this->m_program);
    glVertexAttribPointer(0,3,GL_FLOAT,GL_FALSE,0,vVertex);
    glEnableVertexAttribArray(0);
    glDrawArrays(GL_TRIANGLES,0,3);
    glDisableVertexAttribArray(0);
}

void ElemDraw::destory() {
    ALOGE("HelloTrigle::destory");
    if(m_program > 0){
        glDeleteProgram(this->m_program);
    }
}