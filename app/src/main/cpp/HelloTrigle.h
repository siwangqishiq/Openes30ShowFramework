//
// Created by panyi on 2017/8/29.
//

#ifndef GLDRAW_HELLOTRIGLE_H
#define GLDRAW_HELLOTRIGLE_H
#include "IExe.h"
#include "common.h"


class HelloTrigle :public IExe {
public:
    int init();
    void resize(int w,int h);
    void update();
    void destory();
};

#endif //GLDRAW_HELLOTRIGLE_H
