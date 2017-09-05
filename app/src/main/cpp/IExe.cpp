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
