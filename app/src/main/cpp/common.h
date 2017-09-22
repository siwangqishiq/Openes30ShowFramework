//
// Created by panyi on 2017/8/29.
//

#ifndef GLDRAW_COMMON_H
#define GLDRAW_COMMON_H

#include <android/bitmap.h>
#include <android/log.h>
#include <math.h>
#include <GLES3/gl3.h>
#include <stdlib.h>
#include "IExe.h"


#define DEBUG 1
#define LOG_TAG "APP_PANYI"
#define ALOGE(...) __android_log_print(ANDROID_LOG_ERROR, LOG_TAG, __VA_ARGS__)
#if DEBUG
#define ALOGV(...) __android_log_print(ANDROID_LOG_VERBOSE, LOG_TAG, __VA_ARGS__)
#else
#define ALOGV(...)
#endif

typedef struct//彩色图片数据
{
    uint8_t alpha;
    uint8_t red;
    uint8_t green;
    uint8_t blue;
} ARGB;

typedef struct _Bit{
    uint32_t width;
    uint32_t height;
    uint32_t perPixel;
    uint8_t *data;
};

typedef struct _Bit Bit;


static void printGlString(const char* name, GLenum s) {
    const char* v = (const char*)glGetString(s);
    ALOGV("GL %s: %s\n", name, v);
}

#endif //GLDRAW_COMMON_H
