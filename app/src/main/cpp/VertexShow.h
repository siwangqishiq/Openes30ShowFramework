//
// Created by panyi on 2017/9/8.
//

#ifndef _VERTEXSHOW_H_
#define _VERTEXSHOW_H_

#include "IExe.h"

class VertexShow : public IExe{
public:
    int init();
    void resize(int w,int h);
    void update();
    void destory();

private:
    int VERTEX_POS_SIZE  = 3;
    int VERTEX_NORMAL_SIZE = 3;
    int VERTEX_TEXCOOR0_SIZE = 2;
    int VERTEX_TEXCOOR1_SIZE = 2;

    int VERTEX_POS_INDEX = 0;
    int VERTEX_NORMAL_INDEX = 1;
    int VERTEX_TEXCOOR0_INDEX = 2;
    int VERTEX_TEXCOOR1_INDEX = 3;

    int VERTEX_POS_OFFSET = 0;
    int VERTEX_NORMAL_OFFSET = 3;
    int VERTEX_TEXCOOR0_OFFSET = 6;
    int VERTEX_TEXCOOR1_OFFSET = 8;

    int VERTEX_ATTRIB_SIZE = VERTEX_POS_SIZE +
            VERTEX_NORMAL_SIZE +
            VERTEX_TEXCOOR0_SIZE +
            VERTEX_TEXCOOR1_SIZE;
};

#endif //OPENES30SHOWFRAMEWORK_VERTEXSHOW_H
