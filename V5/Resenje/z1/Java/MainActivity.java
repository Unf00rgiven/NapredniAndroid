package com.course.android.nativeservice;

import android.app.Activity;
import android.os.Bundle;
import android.os.IBinder;
import android.os.RemoteException;
import android.os.ServiceManager;
import android.util.Log;

public class MainActivity extends Activity {

    public static final String TAG = "MainActivity";

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        testNativeService();
    }

    private void testNativeService() {
    IBinder binder = (IBinder) ServiceManager.getService("Example");
    IExample example = IExample.Stub.asInterface(binder);
    try{
	int value = example.getExample();
	Log.d(TAG, "value = " + value);
	value++;
	Log.d(TAG, "New value = " + value);
	example.setExample(value);
    }catch (RemoteException e){
		Log.d(TAG, "getExample FAILDED");
		e.printStackTrace();
	}

    }
}
