package com.course.android.nativeservice;

import android.app.Activity;
import android.os.Bundle;
import android.os.IBinder;
import android.os.RemoteException;
import android.os.ServiceManager;
import android.util.Log;
import android.view.View;
import android.widget.Button;
import android.widget.TextView;
import android.os.Environment;

public class MainActivity extends Activity {

    public static final String TAG = "MainActivity";
    //Counter kojim definisemo koliko puta zelimo da se algoritam izvrsi, tj bencmarkovanje
    private static final int CNT = 10;
    TextView writeSpeedView;
    double writeSpeed = 0;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
	writeSpeedView = (TextView)findViewById(R.id.TextView);
        BenchmarkAlgorithm();
    }

    private void BenchmarkAlgorithm() {
        IBinder binder = (IBinder) ServiceManager.getService("benchmark");
        IExample example = IExample.Stub.asInterface(binder);

        try {
                long testFileSizeMB = 100;
                int copyCnt = 0;
                long previousCopyTime = 0;
		double difference = 0;

                while (copyCnt < CNT) {
                    long startTime = System.nanoTime();
                    String benchmarkCommand = "dd if=/dev/zero of=" + Environment.getExternalStorageDirectory() + "/testfile bs=1 count=1 seek=104857600";
                    // Call Exec command from module
                    int result = example.exec(benchmarkCommand);
                    // Calculate copy time
                    long currentCopyTime = System.nanoTime() - startTime;
                    if (result == 0) {
                        Log.d(TAG, "Benchmarking algorithm starting");
                        // Calculate speed
			difference = currentCopyTime - previousCopyTime;
			Log.d(TAG,"Current - previous = "+ difference + " FileSize = " + testFileSizeMB);
                        writeSpeed = calculateSpeed(difference, testFileSizeMB);
                        // Add 10MB to test file
                        testFileSizeMB += 10;
                        // Update previousCopyTime
                        previousCopyTime = currentCopyTime;
			// Update copyCnt
                        copyCnt++;

                    } else {
                        Log.d(TAG, "Benchmarking failed, result of writting is not 0");
                    }
                }
		writeSpeedView.setText(String.valueOf(writeSpeed));
                Log.d(TAG, "Benchmarking ended successfully");
        } catch(Exception e) {
            e.printStackTrace();
                Log.d(TAG, "Error ", e);
        }
    }

	private double calculateSpeed(double copyTimeDifference, long testFileSizeMB) {
		// Floating point calculation
		double copyTimeSeconds = copyTimeDifference / 1000000000.0;
	    
	    	// Error handling
	    	if (copyTimeSeconds == 0) {
	       		return 0;
	    	}
	    
	    	// Results is MB/s
	    	return testFileSizeMB / copyTimeSeconds;	
    	}

}
