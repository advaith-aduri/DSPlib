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
#include "../include/signal.h"


double * create_arr(double start, double step, double end, long *size)
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


double * sine(double start, double step, double end, long *size)
{
    double *arr = create_arr(start, step, end, size);
    for (int i = 0; i < *size; i++)
    {
        arr[i] = sin(arr[i]);
    }
    return arr;
}

double * cosine(double start, double step, double end, long *size)
{
    double *arr = create_arr(start, step, end, size);
    for (int i = 0; i < *size; i++)
    {
        arr[i] = cos(arr[i]);
    }
    return arr;
}

double * tangent(double start, double step, double end, long *size)
{
    double *arr = create_arr(start, step, end, size);
    for (int i = 0; i < *size; i++)
    {
        arr[i] = tan(arr[i]);
    }
    return arr;
}

double * exponent(double start, double step, double end, long *size)
{
    double *arr = create_arr(start, step, end, size);
    for (int i = 0; i < *size; i++)
    {
        arr[i] = exp(arr[i]);
    }
    return arr;
}

double * log_e(double start, double step, double end, long *size)
{
    double *arr = create_arr(start, step, end, size);
    for (int i = 0; i < *size; i++)
    {
        arr[i] = log(arr[i]);
    }
    return arr;
}

double * log_10(double start, double step, double end, long *size)
{
    double *arr = create_arr(start, step, end, size);
    for (int i = 0; i < *size; i++)
    {
        arr[i] = log10(arr[i]);
    }
    return arr;
}