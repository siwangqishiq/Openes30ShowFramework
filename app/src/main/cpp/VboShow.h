//
// Created by panyi on 2017/9/8.
//

#ifndef _VBOSHOW_H_
#define _VBOSHOW_H_

#include "IExe.h"
#include <math.h>

class VboShow : public IExe{
#define X_IDX 3
#define Y_IDX 4

public:
    int init();
    void resize(int w,int h);
    void update();
    void destory();
private:
    float angle;

protected:
    GLuint m_vbo;
    GLuint m_vbo_shape;
};

#endif //OPENES30SHOWFRAMEWORK_VERTEXSHOW_H
