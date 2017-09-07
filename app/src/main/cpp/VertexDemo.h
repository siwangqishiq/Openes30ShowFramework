//
// Created by panyi on 2017/9/5.
//

#ifndef _VERTEXDEMO_H_
#define _VERTEXDEMO_H_

#include "IExe.h"
#include "common.h"

class VertexDemo: public IExe {
public:
    int init();
    void resize(int w,int h);
    void update();
    void destory();
private:
    GLuint m_program;
};

#endif //
