//
// Created by panyi on 2017/8/29.
//
#include "HelloTrigle.h"
#include "common.h"

int HelloTrigle::init() {
    ALOGE("HelloTrigle::init");

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
    }

    glClearColor(1.0f , 1.0f , 1.0f, 0.0f);
    return GL_TRUE;
}

void HelloTrigle::resize(int w,int h) {
    ALOGE("HelloTrigle::resize %d %d", w, h);
    this->m_width = w;
    this->m_height = h;
}

void HelloTrigle::update() {
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

void HelloTrigle::destory() {
    ALOGE("HelloTrigle::destory");
    if(m_program > 0){
        glDeleteProgram(this->m_program);
    }
}



