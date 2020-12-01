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

time_taken test(long size);


int main(int argc, char const *argv[])
{
	
	time_taken k;
	double multith = 0,singleth = 0;
	int N = 2;
	long size[] = {2,4,8,16,32,64,128,256,512,1024,2048,4096,8192,50000};
	printf("Size\tTime_Single\tTime_Multi\tPerformance\n");
	for (int j = 0; j < 14;j++)
	{
	for (int i = 0; i < N; i++)
	{
		k = test(size[j]);
		multith += k.multi;
		singleth += k.single;
	}
	multith /= N;
	singleth /= N;
	printf("%ld \t %f \t %f \t %f\n",size[j],singleth,multith,(singleth/multith));
	}
	return 0;
}

time_taken test(long size)
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
	FFT_th(s);
	clock_gettime( CLOCK_MONOTONIC, &stop);
	m.multi = ( stop.tv_sec - start.tv_sec ) + (double)( stop.tv_nsec - start.tv_nsec ) / (double)BILLION;
	return m;
}
