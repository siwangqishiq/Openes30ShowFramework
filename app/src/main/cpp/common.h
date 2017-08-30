//
// Created by panyi on 2017/8/29.
//

#ifndef GLDRAW_COMMON_H
#define GLDRAW_COMMON_H

#include <android/log.h>
#include <math.h>
#include <GLES3/gl3.h>
#include <stdlib.h>

#define DEBUG 1
#define LOG_TAG "APP_PANYI"
#define ALOGE(...) __android_log_print(ANDROID_LOG_ERROR, LOG_TAG, __VA_ARGS__)
#if DEBUG
#define ALOGV(...) __android_log_print(ANDROID_LOG_VERBOSE, LOG_TAG, __VA_ARGS__)
#else
#define ALOGV(...)
#endif

static void printGlString(const char* name, GLenum s) {
    const char* v = (const char*)glGetString(s);
    ALOGV("GL %s: %s\n", name, v);
}

#endif //GLDRAW_COMMON_H
