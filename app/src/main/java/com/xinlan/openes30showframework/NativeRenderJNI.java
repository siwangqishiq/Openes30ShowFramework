package com.xinlan.openes30showframework;

/**
 * Created by panyi on 2017/8/28.
 */

public class NativeRenderJNI {

    static{
        System.loadLibrary("native-lib");
    }

    public static native void init();

    public static native void update();

    public static native void resize(int width, int height);

    public static native void destory();
}
