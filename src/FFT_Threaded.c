/**********************************************
*  FFT_Threaded.c : Implementation of multithreaded FFT
*
*  Author: Aduri Sri Sambasiva Advaith
*
***********************************************/


#include "../include/signal.h"
#include <pthread.h>
#include <semaphore.h>
#include <stdlib.h>
#include <stdio.h>
#include <complex.h>


typedef struct{
    double *signal;
    long size;
    spectrum *output;
    int core;
} th_data;

void *runner(void *param)
{
    th_data *var = param;

    spectrum *temp = (spectrum *)malloc(sizeof(spectrum));
    if (var->core == 1)
    { 
        *temp = DFT(var->signal,var->size);
    }
    else
    {
        signal *temp_sig = (signal *)malloc(sizeof(signal));
        temp_sig->data = var->signal;
        temp_sig->size = var->size;
        temp_sig->zero = 0;
        *temp = FFT_th(*temp_sig,var->core);
    }
    (var->output) = temp;
}

spectrum FFT_th(signal sig, int cores)
{
    resize_signal(&sig);
    long N = sig.size;
    double complex *freq = (double complex *)malloc(sizeof(double complex)*N);
    double *d[2];
    d[0] = get_even(sig.data, N);
    d[1] = get_odd(sig.data, N);

    pthread_t tid[2];
    pthread_attr_t attr[2];
    th_data t_data[2];
    int core = cores/2;
    for (int i = 0; i < 2; i++)
    {
        t_data[i].signal = d[i];
        t_data[i].size = N/2;
        t_data[i].core = core;
        pthread_attr_init(&attr[i]);
        if (pthread_create(&tid[i],&attr[i],runner,&t_data[i]) != 0)
            printf("Falied to create thread.\n");
    }
    for (int i = 0; i < 2; i++)
    {
        pthread_join(tid[i],0);
    }
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