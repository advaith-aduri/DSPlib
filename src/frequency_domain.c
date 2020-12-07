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
#include "../include/dsplib.h"

// This function prints the frequency spectrum to the console
void print_freq(spectrum freq)
{
	printf("Size : %ld\n", freq.size);
	printf("Data : \n");
	for (int i = 0; i < freq.size; i++)
		printf("val :%f + %fi \t mag: %f \n",creal(freq.data[i]),cimag(freq.data[i]),mag(freq.data[i]));

	printf("\n");
}

/*
This function returns the even indexed values of an array
This function expects the size of array to be even
*/
double * get_even(double *arr, long size)
{
    double *out = (double *)malloc(sizeof(double)*(size/2));
    for (long i = 0; i < size/2; i++)
    {
        out[i] = arr[2 * i];
    }
    return out;
}

/*
This function returns the odd indexed values of an array
This function expects the size of array to be even
*/
double * get_odd(double *arr, long size)
{
    double *out = (double *)malloc(sizeof(double)*(size/2));
    for (long i = 0; i < size/2; i++)
    {
        out[i] = arr[2 * i + 1];
    }
    return out;
}

// This function returns the magnitude of a complex number
double mag(double complex val)
{
    return sqrt(creal(val) * creal(val) + cimag(val) * cimag(val));
}

// This function returns the twiddle factor 
double complex W_n(double k, double N)
{
    return cexp(- I * 2 * M_PI * k / N);
}

/*
This function takes an array as an input and performs Discrete Fourier Transform to find its frequency spectrum
*/
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

/*
This function performs a basic Cooley Tukey FFT algorithm to find the spectrum of a signal
*/
spectrum FFT(signal_t sig)
{
    resize_signal(&sig);
    long N = sig.size;
    double *ev = get_even(sig.data, N); // get even indexed values
    double *od = get_odd(sig.data, N); // get odd indexed values

    double complex *freq = (double complex *)malloc(sizeof(double complex)*N);
    //Compute DFT on the even and odd parts
    spectrum fev = DFT(ev,N/2); 
    spectrum fod = DFT(od,N/2);

    // Now compute the final values of the frequency spectrum
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
