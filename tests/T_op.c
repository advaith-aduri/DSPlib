#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include "dsplib.h"

void time_operations(signal_t sig, long Fs)
{
    signal_t td,ta,tr;
    td = sig;
    ta = sig;
    tr = sig;
    time_delay(&td, 6, Fs);
    time_advance(&ta, 6, Fs);
    time_reversal(&tr);
    plot_xy(get_time(sig, Fs),sig,"time","amplitude","Original signal");
    plot_xy(get_time(td, Fs),td,"time","amplitude","Time delayed signal");
    plot_xy(get_time(ta, Fs),ta,"time","amplitude","Time advanced signal");
    plot_xy(get_time(tr, Fs),tr,"time","amplitude","Time reversed signal");
}


int main()
{
    long Fs = 1000;
    long size;
    double *t = linspace(0,0.001,1,&size);
    signal_t time = signal_init(0, t, size);
    signal_t sig = signal_init(0, sine(time, 2), size);
    time_operations(sig,Fs);
    return 0;
}