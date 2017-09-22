package com.xinlan.openes30showframework;

import android.content.Context;
import android.content.res.AssetManager;
import android.graphics.Bitmap;
import android.graphics.Bitmap.Config;
import android.graphics.BitmapFactory;
import android.graphics.ColorSpace;
import android.opengl.GLSurfaceView;
import android.view.SurfaceHolder;

import java.io.IOException;
import java.io.InputStream;

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

        readImages();
    }

    private void readImages(){
        try {
            InputStream ips = mAssetMgr.open("SOE-562.jpg");
            BitmapFactory.Options options= new BitmapFactory.Options();
            // Make sure it is 24 bit color as our image processing algorithm
            // expects this format
            options.inPreferredConfig = Config.ARGB_8888;
            Bitmap bit = BitmapFactory.decodeStream(ips , null , options);
            System.out.println("size = "+bit.getWidth() +" x " +bit.getHeight()+" bit.getConfig() = "+bit.getConfig());

            NativeRenderJNI.loadImage(bit);//send to native code zone
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    @Override
    public void onSurfaceCreated(GL10 gl, EGLConfig config) {
        //System.out.println("onSurfaceCreated "+Thread.currentThread());
        NativeRenderJNI.init(mAssetMgr);
    }

    @Override
    public void onSurfaceChanged(GL10 gl, int width, int height) {
        //System.out.println("onSurfaceChanged "+Thread.currentThread());
        NativeRenderJNI.resize(width , height);
    }

    @Override
    public void onDrawFrame(GL10 gl) {
        //System.out.println("onDrawFrame "+Thread.currentThread());
        NativeRenderJNI.update();
    }

    @Override
    public void surfaceDestroyed(SurfaceHolder holder) {
        //System.out.println("surfaceDestroyed "+Thread.currentThread());
        super.surfaceDestroyed(holder);
        NativeRenderJNI.destory();
    }
}//end class
