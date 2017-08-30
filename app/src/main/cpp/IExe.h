//
// Created by panyi on 2017/8/29.
//

#ifndef GLDRAW_IEXE_H
#define GLDRAW_IEXE_H

class IExe{
public:
    virtual int init() = 0;
    virtual void resize(int w,int h) = 0;
    virtual void update() = 0;
    virtual void destory() = 0;
};

#endif //GLDRAW_IEXE_H
