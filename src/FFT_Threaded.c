/**********************************************
*  FFT_Threaded.c : Implementation of multithreaded FFT
*
*  Author: Aduri Sri Sambasiva Advaith
*
***********************************************/


#include "../include/dsplib.h"
#include <pthread.h>
#include <semaphore.h>
#include <stdlib.h>
#include <stdio.h>
#include <complex.h>

// data that is passed to the runner function
typedef struct{
    double *signal; 
    long size;
    spectrum *output;
} th_data;

/*
The following runner function returns the frequency of a input signal by performing DFT operation
*/
void *runner(void *param)
{
    th_data *var = param;

    spectrum *temp = (spectrum *)malloc(sizeof(spectrum));
    
    *temp = DFT(var->signal,var->size);
   
    (var->output) = temp;
}

/*
In this function we are first dividing both the even and odd indexed signal values and perform the DFT operations on two different threads
Then we combine the output from both the threads to calculate the frequency
*/
spectrum FFT_th(signal_t sig)
{
    resize_signal(&sig);  //Performed to convert the signal size as a power of 2
    long N = sig.size;
    double complex *freq = (double complex *)malloc(sizeof(double complex)*N);
    double *d[2];
    d[0] = get_even(sig.data, N); // get even indexed values
    d[1] = get_odd(sig.data, N); // get odd indexed values

    pthread_t tid[2];
    pthread_attr_t attr[2];
    th_data t_data[2];
    for (int i = 0; i < 2; i++)
    {
        t_data[i].signal = d[i];
        t_data[i].size = N/2;
        pthread_attr_init(&attr[i]);
        if (pthread_create(&tid[i],&attr[i],runner,&t_data[i]) != 0) // create 2 threads to perform DFT operation
            printf("Falied to create thread.\n");
    }
    // Wait for both the threads to complete execution
    for (int i = 0; i < 2; i++)
    {
        pthread_join(tid[i],0);
    }
    // Now compute the final values of the frequency spectrum
    for (int i = 0; i < N/2; i++)
    {
        freq[i] = (t_data[0].output)->data[i] + W_n(i,N) * (t_data[1].output)->data[i];
        freq[i + N/2] = (t_data[1].output)->data[i] + W_n(i + N/2, N) * (t_data[0].output)->data[i];
    }
    
    spectrum fft;
    fft.size = N;
    fft.data = freq;
    return fft;
}