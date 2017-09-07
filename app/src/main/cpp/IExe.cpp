//
// Created by panyi on 2017/9/5.
//
#include "IExe.h"

GLuint IExe::loadShader(GLenum type , const char *shaderSrc){
    GLuint shader;
    GLint complied;

    shader = glCreateShader(type);
    if(shader == 0)
        return 0;

    glShaderSource(shader, 1 ,&shaderSrc, NULL);
    glCompileShader(shader);

    glGetShaderiv(shader,GL_COMPILE_STATUS ,&complied);
    if(!complied){
        GLint infoLen = 0;
        glGetShaderiv(shader , GL_INFO_LOG_LENGTH , &infoLen);
        if(infoLen > 1){
            char *infoLog = (char *)malloc(sizeof(char) * infoLen);
            glGetShaderInfoLog(shader,infoLen,NULL,infoLog);
            ALOGE("%s",infoLog);

            free(infoLog);
        }
        glDeleteShader(shader);
        return 0;
    }

    return shader;
}

GLuint IExe::loadProgram(const char *vertexShaderSrc,const char *fragShaderSrc){
    GLuint vertexShader;
    GLuint fragmentShader;
    GLuint progreamObj;
    GLint linked;

    vertexShader = loadShader(GL_VERTEX_SHADER,vertexShaderSrc);
    if(!vertexShader){
        ALOGE("%s","vertexShader error");
        return GL_FALSE;
    }

    fragmentShader = loadShader(GL_FRAGMENT_SHADER,fragShaderSrc);
    if(!fragmentShader){
        ALOGE("%s","fragmentShader error");
        return GL_FALSE;
    }

    progreamObj = glCreateProgram();
    if(progreamObj == 0)
        return GL_FALSE;

    glAttachShader(progreamObj , vertexShader);
    glAttachShader(progreamObj , fragmentShader);
    glLinkProgram(progreamObj);

    glGetProgramiv(progreamObj ,GL_LINK_STATUS ,&linked);
    if(!linked){
        GLint infoLen = 0;
        glGetProgramiv(progreamObj , GL_INFO_LOG_LENGTH , &infoLen);
        if(infoLen > 1){
            char *infoLog = (char *)malloc(sizeof(char) * infoLen);
            glGetProgramInfoLog(progreamObj,infoLen,NULL,infoLog);
            ALOGE("%s",infoLog);
            free(infoLog);
        }
        glDeleteProgram(progreamObj);
        return GL_FALSE;
    }

    return progreamObj;
}
