//
// Created by panyi on 2017/9/15.
//

#ifndef _TEXTURE_H_
#define _TEXTURE_H_

#ifdef __cplusplus
extern "C" {
#endif

#include "IExe.h"

extern Bit *bitImage;

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


class TextureImage : public IExe{
public:
    virtual int init();
    virtual void resize(int w,int h);
    virtual void update();
    virtual void destory();
protected:
    GLboolean loadTexture();
};

class SimpleTexture : public IExe{
public:
    virtual int init();
    virtual void resize(int w,int h);
    virtual void update();
    virtual void destory();
protected:
    GLuint loadImageTexture();
private:
    GLuint m_texture_id;
    GLint m_sampler_loc;
};


#ifdef __cplusplus
}
#endif

#endif //OPENES30SHOWFRAMEWORK_TEXTURE_H
