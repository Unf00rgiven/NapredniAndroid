package com.rtrk.propertyexample;

import android.app.Activity;
import android.os.Bundle;
import android.os.SystemProperties;
import android.util.Log;

public class MainActivity extends Activity {
	private static final String KEY = "persist.sys.rtrk.android";
	private static final String PROPERTY_VALUE = "RTRK";


    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
	String value;

	Log.d("PROP_EXAMPLE", "Activity starting...");
	value = SystemProperties.get(KEY);
	if (value.length() > 0) {
		Log.d("PROP_EXAMPLE", "Comparing properties...");
		if (!value.equals(PROPERTY_VALUE)) {
            		SystemProperties.set(KEY, PROPERTY_VALUE);
			Log.d("PROP_EXAMPLE", "Properties not equal, set property " + KEY + " " + PROPERTY_VALUE);
        	}
	}
	else {

		SystemProperties.set(KEY, PROPERTY_VALUE);
		Log.d("PROP_EXAMPLE", "Property NULL set property " + KEY + " " + PROPERTY_VALUE);

	}
    }

}
