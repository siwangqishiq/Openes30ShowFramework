


#include <jni.h>
#include <android/asset_manager.h>
#include <string>
#include <android/asset_manager_jni.h>
#include <android/bitmap.h>
#include "common.h"
#include "HelloTrigle.h"
#include "VertexDemo.h"
#include "VertexShow.h"
#include "VboShow.h"
#include "VaoInstance.h"
#include "ElemDraw.h"
#include "Texture.h"
#include "FragShader.h"

#ifdef __cplusplus
extern "C" {
#endif

static IExe *exe;
Bit *bitImage;

jint Java_com_xinlan_openes30showframework_NativeRenderJNI_loadImage(JNIEnv *env, jclass type, jobject bitmap) {
    if (bitImage != nullptr) {
        delete bitImage->data;
        delete bitImage;
        bitImage = nullptr;
    }

    bitImage = (Bit *)malloc(sizeof(Bit));
    if (bitImage == nullptr) {
        return -1;
    }

    AndroidBitmapInfo bitmapInfo;
    void *pixels;
    int ret;

    if ((ret = AndroidBitmap_getInfo(env, bitmap, &bitmapInfo)) < 0) {
        return -1;
    }
    bitImage->width = bitmapInfo.width;
    bitImage->height = bitmapInfo.height;
    bitImage->perPixel = bitmapInfo.stride / bitmapInfo.width;
    ALOGV("bitmapInfo width = %d", bitImage->width);
    ALOGV("bitmapInfo height = %d",bitImage->height);
    ALOGV("bitmapInfo stride = %d",bitImage->perPixel);
    bitImage->data = (uint8_t *) malloc(bitImage->width * bitImage->height * bitImage->perPixel * sizeof(uint8_t));
    if (bitImage->data == nullptr) {
        ALOGE("malloc bit data error!");
        free(bitImage);
        return -1;
    }

    if ((ret = AndroidBitmap_lockPixels(env, bitmap, &pixels)) < 0) {
        return -1;
    }

    memcpy(bitImage->data, (uint8_t *) pixels,
           bitImage->width * bitImage->height * bitImage->perPixel);//copy image data;
    ALOGV("copy image data complete");

    AndroidBitmap_unlockPixels(env, bitmap);
    ALOGV("bitImage = %lu" , bitImage);

    return 0;
}

void Java_com_xinlan_openes30showframework_NativeRenderJNI_init(JNIEnv *env, jclass type,
                                                           jobject assetMgr) {
    printGlString("Version", GL_VERSION);
    printGlString("Vendor", GL_VENDOR);
    printGlString("Renderer", GL_RENDERER);
    printGlString("Extensions", GL_EXTENSIONS);
    ALOGE("init");

    AAssetManager *mgr = AAssetManager_fromJava(env, assetMgr);
    AAssetDir *assetDir = AAssetManager_openDir(mgr, "");
    const char *filename;
    while ((filename = AAssetDir_getNextFileName(assetDir)) != NULL) {
        //ALOGE("asset file  = %s",filename);
//        AAsset* asset = AAssetManager_open(mgr, filename, AASSET_MODE_STREAMING);
//        char buf[BUFSIZ];
//        int nb_read = 0;
//        FILE* out = fopen(filename, "w");
//        while ((nb_read = AAsset_read(asset, buf, BUFSIZ)) > 0)
//            fwrite(buf, nb_read, 1, out);
//        fclose(out);
//        AAsset_close(asset);
    }//end while
    AAssetDir_close(assetDir);

    if (exe != nullptr) {
        delete exe;
        exe = nullptr;
    }

    //exe = new HelloTrigle();
    //exe = new VertexDemo();
    //exe = new VertexShow();
    //exe = new VboShow();
    //exe = new VaoInstance();
    //exe = new ElemDraw();
    //exe = new TextureInstance();
    //exe = new SimpleTexture();
    exe = new FragConfig();
    exe->init();
}

void Java_com_xinlan_openes30showframework_NativeRenderJNI_update(JNIEnv *env, jclass type) {
    //ALOGE("draw frame");
    exe->update();
}


void Java_com_xinlan_openes30showframework_NativeRenderJNI_resize(JNIEnv *env, jclass type, jint width,
                                                             jint height) {
    ALOGE("resize");
    exe->resize(width, height);
}

void Java_com_xinlan_openes30showframework_NativeRenderJNI_destory(JNIEnv *env, jclass type) {
    ALOGE("desorty");
    exe->destory();
}

#ifdef __cplusplus
}
#endif