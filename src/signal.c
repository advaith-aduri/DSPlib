/**********************************************
*  signal.c : general signal functions
*
*  Author: Aduri Sri Sambasiva Advaith
*
***********************************************/
#include <stdio.h>
#include <stdlib.h>
#include "../include/dsplib.h"



// General signal functions

// Initialize a signal
signal_t signal_init(long zero, double *data, long size)
{
	signal_t temp;
	temp.zero = zero;
	temp.data = data;
	temp.size = size;
	return temp;
}

//Print a signal to the console
void signal_print(signal_t sig)
{
	printf("Zero : %ld\n", sig.zero);
	printf("Size : %ld\n", sig.size);
	printf("Data : ");
	for (int i = 0; i < sig.size; i++)
		printf("%f ",sig.data[i]);

	printf("\n");
}

/* 
This function takes in a signal as the input and returns it's corresponding time series.
Since the signal_t contains only the zero location, this function can be used to get the corresponding time values.
*/
signal_t get_time(signal_t sig, double Fs)
{
    signal_t time;
    time.size = sig.size;
    time.zero = sig.zero;
    time.data = (double *)malloc((sizeof(double))*time.size);

    for (long i = 0; i < time.size; i++)
    {
        time.data[i] = (i - time.zero)/Fs;
    }
    return time;
}


double * convolution(double * sig1, long size1, double * sig2, long size2, long *out_size)
{
    double *output = (double *)malloc(sizeof(double)*(size1 + size2 - 1));
    for (long i = 0; i < (size1 + size2 - 1); i++)
    {
        output[i] = 0;
        for (long j = 0; j < size1; j++)
        {
            for (long k = 0; k < size2; k++)
            {
                if (j + k - 1 == i)
                {
                    output[i] += sig1[j] * sig2[k];
                }
            }
        }
    }
    *out_size = size1 + size2 - 1;
    return output;
}


