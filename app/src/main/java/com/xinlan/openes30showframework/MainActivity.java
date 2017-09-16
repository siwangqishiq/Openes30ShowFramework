package com.xinlan.openes30showframework;

import android.opengl.GLSurfaceView;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import java.util.zip.ZipOutputStream;

public class MainActivity extends AppCompatActivity {
    private GLSurfaceView mRenderView;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        mRenderView = new RenderSurface(this,getAssets());
        setContentView(mRenderView);
    }

    @Override
    protected void onPause() {
        super.onPause();
        mRenderView.onPause();
    }

    @Override
    protected void onResume() {
        super.onResume();
        mRenderView.onResume();
    }
}//end class
