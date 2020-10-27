#include <stdio.h>
#include <math.h>
#include "signal.h"

int main(int argc, char const *argv[])
{
	double arr[6] = {6, 5, 4, 8, 7, 34};
	double time[7] = {1, 2, 3, 4, 5, 6, 7};
	signal sig = signal_init(2, arr, sizeof(arr)/sizeof(double));
	signal sig2 = signal_init(2, time, sizeof(time)/sizeof(double));
	plot_xy(sig2,sig,"time","amp","test");
	return 0;
}