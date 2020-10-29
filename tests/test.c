#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "signal.h"
#include <time.h>
int main(int argc, char const *argv[])
{
	long size;
	double *arr = create_arr(0,0.001,3.14*2,&size);
	double *arr1 = sine(0,0.001,3.14*2,&size);
	signal t = signal_init(0, arr, size);
	signal y = signal_init(0, arr1, size);
	time_reversal(&y);
	plot_xy(t,y,"time","amplitude","test");
	return 0;
}
