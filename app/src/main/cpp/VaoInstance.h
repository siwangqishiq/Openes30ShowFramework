//
// Created by 潘易 on 2017/9/9.
//

#ifndef _VAOINSTANCE_H_
#define _VAOINSTANCE_H_

#include "IExe.h"

class VaoInstance : public IExe{
public :
    int init();
    void resize(int w,int h);
    void update();
    void destory();

private:
    GLuint m_vao[2];
    GLuint m_vbo[2];
};

#endif //OPENES30SHOWFRAMEWORK_VAOINSTANCE_H
