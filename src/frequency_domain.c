/**********************************************
*  frequency_domain.c : Basic frequency related operations
*
*  Author: Aduri Sri Sambasiva Advaith
*
***********************************************/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <complex.h>
#include "../include/signal.h"

void print_freq(spectrum freq)
{
	printf("Size : %ld\n", freq.size);
	printf("Data : \n");
	for (int i = 0; i < freq.size; i++)
		printf("val :%f + %fi \t mag: %f \n",creal(freq.data[i]),cimag(freq.data[i]),mag(freq.data[i]));

	printf("\n");
}

// The following function expects the size of array to be even
double * get_even(double *arr, int size)
{
    double *out = (double *)malloc(sizeof(double)*(size/2));
    for (int i = 0; i < size/2; i++)
    {
        out[i] = arr[2 * i];
    }
    return out;
}

// The following function expects the size of array to be even
double * get_odd(double *arr, int size)
{
    double *out = (double *)malloc(sizeof(double)*(size/2));
    for (int i = 0; i < size/2; i++)
    {
        out[i] = arr[2 * i + 1];
    }
    return out;
}

double mag(double complex val)
{
    return sqrt(creal(val) * creal(val) + cimag(val) * cimag(val));
}

double complex W_n(double k, double N)
{
    return cexp(- I * 2 * M_PI * k / N);
}

spectrum DFT(double *signal, long N)
{
    double complex *data = (double complex *)malloc(sizeof(double complex)*N);
    spectrum freq;
    freq.data = data;
    freq.size = N;
    double complex temp;
    for (int i = 0; i < N; i++)
    {
        temp = 0 + 0 * I;
        for (int j = 0; j < N; j++)
        {
            temp += signal[j]*W_n(i*j,N);
        }
        freq.data[i] = temp; 
    }
    return freq;
}

spectrum FFT(double *signal, long N)
{
    double *ev = get_even(signal, N);
    double *od = get_odd(signal, N);
    double complex *freq = (double complex *)malloc(sizeof(double complex)*N);
    spectrum fev = DFT(ev,N/2);
    spectrum fod = DFT(od,N/2);
    for (int i = 0; i < N/2; i++)
    {
        freq[i] = fev.data[i] + W_n(i,N) * fod.data[i];
        freq[i + N/2] = fod.data[i] + W_n(i + N/2, N) * fev.data[i];
    }
    spectrum out;
    out.size = N;
    out.data = freq;
    return out;
}