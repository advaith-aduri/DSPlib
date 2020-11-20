#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "signal.h"
#include <time.h>

#define BILLION  1000000000L;
typedef struct{
	double multi;
	double single;
} time_taken;

time_taken test(long size, int core);


int main(int argc, char const *argv[])
{
	
	time_taken k;
	double multith = 0,singleth = 0;
	int N = 25;
	long size = 5000;
	int cores = 8;
	for (int i = 0; i < N; i++)
	{
		k = test(size,cores);
		multith += k.multi;
		singleth += k.single;
	}
	multith /= N;
	singleth /= N;
	printf("The performance improvement is %f.\n",(singleth/multith));
	
	return 0;
}

time_taken test(long size, int core)
{
	double x[size];
	time_taken m;
	srand(time(0));
	for (long i = 0; i < size; i++)
		x[i] = rand();
	signal s = signal_init(0,x,size);
	struct timespec start, stop;
	clock_gettime( CLOCK_MONOTONIC, &start);
	FFT(s);
	clock_gettime( CLOCK_MONOTONIC, &stop);
	m.single = ( stop.tv_sec - start.tv_sec ) + (double)( stop.tv_nsec - start.tv_nsec ) / (double)BILLION;
	
	clock_gettime( CLOCK_MONOTONIC, &start);
	FFT_th(s,core);
	clock_gettime( CLOCK_MONOTONIC, &stop);
	m.multi = ( stop.tv_sec - start.tv_sec ) + (double)( stop.tv_nsec - start.tv_nsec ) / (double)BILLION;
	return m;
}
