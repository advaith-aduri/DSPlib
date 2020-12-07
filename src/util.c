/**********************************************
*  util.c : contains utility functions similar
*           to matlab
*
*  Author: Aduri Sri Sambasiva Advaith
*
***********************************************/
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include "../include/dsplib.h"

// This function takes the start value and keeps adding step to it until it reaches the end value and returns the resulting array
double * linspace(double start, double step, double end, long *size)
{
    // Here step refers to 1 / Fs
    if (((start > end) && (step >= 0)) || ((start < end) && (step <= 0)))
    {
        printf("Could not create array.\nExiting the program.\n");
        exit(-1);
    }
    double *arr = (double *)malloc(sizeof(double) * floor(fabs(end - start) / fabs(step)) + 1);
    arr[0] = start;
    for (int i = 1; i <= floor(fabs(end - start) / fabs(step)); i++)
    {
        arr[i] = arr[i - 1] + step;
    }
    *size = floor(fabs(end - start) / fabs(step)) + 1;
    return arr;
}

void resize_signal(signal_t *sig)
{
    int i = 0;
    while (sig->size > pow(2,i))
    {
        i++;
    }
    if (sig->size == pow(2,i))
        return;
    double *temp = (double *)malloc(sizeof(double)*pow(2,i));
    for  (int i = 0; i < sig->size; i++)
    {
        temp[i] = sig->data[i];
    }
    sig->size = pow(2,i);
    sig->data = temp;
    return;
}

/*
The following functions provide implementation of some of the basic signals.
*/

double * step(signal_t sig)
{
    double *arr = (double *)malloc(sizeof(double) * sig.size);
    for (int i = 0; i < sig.size; i++)
    {
        if (sig.zero >= i)
        {
            arr[i] = 1;
        }
        else
        {
            arr[i] = 0;
        }
    }
    return arr;
}

double * ramp(signal_t sig, long Fs)
{
    double *arr = (double *)malloc(sizeof(double) * sig.size);
    for (int i = 0; i < sig.size; i++)
    {
        if (sig.zero >= i)
        {
            arr[i] = ((double)i - sig.zero) / Fs;
        }
        else
        {
            arr[i] = 0;
        }
    }
    return arr;
}

double * sine(signal_t sig, double fc)
{
    double *arr = (double *)malloc(sizeof(double) * sig.size);
    for (int i = 0; i < sig.size; i++)
    {
        arr[i] = sin(2 * M_PI * fc * sig.data[i]);
    }
    return arr;
}

double * cosine(signal_t sig, double fc)
{
    double *arr = (double *)malloc(sizeof(double) * sig.size);
    for (int i = 0; i < sig.size; i++)
    {
        arr[i] = cos(2 * M_PI * fc * sig.data[i]);
    }
    return arr;
}

double * tangent(signal_t sig, double fc)
{
    double *arr = (double *)malloc(sizeof(double) * sig.size);
    for (int i = 0; i < sig.size; i++)
    {
        arr[i] = tan(2 * M_PI * fc * sig.data[i]);
    }
    return arr;
}

double * exponent(signal_t sig)
{
    double *arr = (double *)malloc(sizeof(double) * sig.size);
    for (int i = 0; i < sig.size; i++)
    {
        arr[i] = exp(sig.data[i]);
    }
    return arr;
}

double * log_e(signal_t sig)
{
    double *arr = (double *)malloc(sizeof(double) * sig.size);
    for (int i = 0; i < sig.size; i++)
    {
        arr[i] = log(sig.data[i]);
    }
    return arr;
}

double * log_10(signal_t sig)
{
    double *arr = (double *)malloc(sizeof(double) * sig.size);
    for (int i = 0; i < sig.size; i++)
    {
        arr[i] = log10(sig.data[i]);
    }
    return arr;
}


