package com.xinlan.openes30showframework;

import android.content.res.AssetManager;

/**
 * Created by panyi on 2017/8/28.
 */

public class NativeRenderJNI {

    static{
        System.loadLibrary("native-lib");
    }

    public static native void init(AssetManager assetMgr);

    public static native void update();

    public static native void resize(int width, int height);

    public static native void destory();
}
