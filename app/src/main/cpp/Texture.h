//
// Created by panyi on 2017/9/15.
//

#ifndef _TEXTURE_H_
#define _TEXTURE_H_

#include "IExe.h"

class TextureInstance : public IExe{
public:
    virtual int init();
    virtual void resize(int w,int h);
    virtual void update();
    virtual void destory();

    GLuint createSimpleTexture2D();
private:
    GLuint m_texture_id;
    GLint m_sampler_loc;
};

#endif //OPENES30SHOWFRAMEWORK_TEXTURE_H
