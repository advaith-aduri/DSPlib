#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include "dsplib.h"

int main()
{
    long Fs = 1000;
    long size;
    double *t = linspace(0,0.001,1,&size);
    signal_t time = signal_init(0, t, size);
    signal_t sig1 = signal_init(0, sine(time, 2), size);
    signal_t sig2 = signal_init(0, sine(time, 4), size);
    double * data = (double *)malloc(sizeof(double)*sig1.size);
    for (long i = 0; i < sig1.size; i++)
    {
        data[i] = sig1.data[i] + sig2.data[i];
    }
    
    signal_t sig_out = signal_init(0,data,sig1.size);
    plot_xy(time, sig_out,"time","amplitude","Input signal");
    spectrum freq = FFT_th(sig_out);
    plot_f(freq, Fs);
    return 0;
}