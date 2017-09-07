//
// Created by panyi on 2017/8/29.
//

#ifndef GLDRAW_IEXE_H
#define GLDRAW_IEXE_H

#include "common.h"

class IExe{
public:
    virtual int init() = 0;
    virtual void resize(int w,int h) = 0;
    virtual void update() = 0;
    virtual void destory() = 0;

    static GLuint loadShader(GLenum type , const char *shaderSrc);
protected:
    int m_width;
    int m_height;
};

#endif //GLDRAW_IEXE_H
