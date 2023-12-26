package rtrk.pnrs.jniexample;


public class FibonacciNative {
    static {
	System.loadLibrary("fibonacci");
    }

    public native int get(int n);
}
