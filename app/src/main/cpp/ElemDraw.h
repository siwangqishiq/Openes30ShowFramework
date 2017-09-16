//
// Created by panyi on 2017/9/11.
//

#ifndef _ELEMDRAW_H_
#define _ELEMDRAW_H_
#include "IExe.h"

class ElemDraw :public IExe{
public:
    int init();
    void resize(int w,int h);
    void update();
    void destory();
};

#endif //OPENES30SHOWFRAMEWORK_ELEMDRAW_H
