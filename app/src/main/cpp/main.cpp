#include <jni.h>
#include <android/asset_manager.h>
#include <string>
#include <android/asset_manager_jni.h>
#include "common.h"
#include "HelloTrigle.h"
#include "VertexDemo.h"
#include "VertexShow.h"
#include "VboShow.h"
#include "VaoInstance.h"
#include "ElemDraw.h"
#include "Texture.h"

static IExe *exe;

extern "C"
JNIEXPORT void JNICALL
Java_com_xinlan_openes30showframework_NativeRenderJNI_init(JNIEnv *env, jclass type,
                                                           jobject assetMgr) {
    printGlString("Version", GL_VERSION);
    printGlString("Vendor", GL_VENDOR);
    printGlString("Renderer", GL_RENDERER);
    printGlString("Extensions", GL_EXTENSIONS);
    ALOGE("init");

    AAssetManager* mgr = AAssetManager_fromJava(env, assetMgr);
    AAssetDir* assetDir = AAssetManager_openDir(mgr, "");
    const char* filename;
    while ((filename = AAssetDir_getNextFileName(assetDir)) != NULL) {
        ALOGE("asset file  = %s",filename);
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

    if(exe!= nullptr){
        delete exe;
        exe = nullptr;
    }

    //exe = new HelloTrigle();
    //exe = new VertexDemo();
    //exe = new VertexShow();
    //exe = new VboShow();
    //exe = new VaoInstance();
    //exe = new ElemDraw();
    exe = new TextureInstance();
    exe->init();
}

extern "C"
JNIEXPORT void JNICALL
Java_com_xinlan_openes30showframework_NativeRenderJNI_update(JNIEnv *env, jclass type) {
    //ALOGE("draw frame");
    exe->update();
}


extern "C"
JNIEXPORT void JNICALL
Java_com_xinlan_openes30showframework_NativeRenderJNI_resize(JNIEnv *env, jclass type, jint width, jint height) {
    ALOGE("resize");
    exe->resize(width ,height);
}

extern "C"
JNIEXPORT void JNICALL
Java_com_xinlan_openes30showframework_NativeRenderJNI_destory(JNIEnv *env, jclass type) {
    ALOGE("desorty");
    exe->destory();
}


