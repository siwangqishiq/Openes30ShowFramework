//
// Created by panyi on 2017/9/26.
//

#ifndef _FRAGSHADER_H_
#define _FRAGSHADER_H_

#include "IExe.h"
#include "common.h"


class FragConfig :public IExe {
public:
    int init();
    void resize(int w,int h);
    void update();
    void destory();

private:
    void initFragConfig();
};

#endif //OPENES30SHOWFRAMEWORK_FRAGSHADER_H
