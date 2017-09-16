package com.xinlan.openes30showframework;

import android.content.Context;
import android.content.res.AssetManager;
import android.opengl.GLSurfaceView;
import android.view.SurfaceHolder;

import javax.microedition.khronos.egl.EGLConfig;
import javax.microedition.khronos.opengles.GL10;

/**
 * Created by panyi on 2017/8/28.
 */

public class RenderSurface extends GLSurfaceView implements GLSurfaceView.Renderer {
    private AssetManager mAssetMgr;
    public RenderSurface(Context context, AssetManager assetMgr) {
        super(context);
        this.mAssetMgr = assetMgr;
        init();
    }

    private void init() {
        setEGLConfigChooser(8, 8, 8, 0, 16, 0);
        setEGLContextClientVersion(3);
        setRenderer(this);
    }

    @Override
    public void onSurfaceCreated(GL10 gl, EGLConfig config) {
        NativeRenderJNI.init(mAssetMgr);
    }

    @Override
    public void onSurfaceChanged(GL10 gl, int width, int height) {
        NativeRenderJNI.resize(width , height);
    }

    @Override
    public void onDrawFrame(GL10 gl) {
        NativeRenderJNI.update();
    }

    @Override
    public void surfaceDestroyed(SurfaceHolder holder) {
        super.surfaceDestroyed(holder);
        NativeRenderJNI.destory();
    }
}//end class
