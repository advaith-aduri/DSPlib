#pragma once

#include <complex.h>

typedef struct signal{
	long zero;
	double *data;
	long size;
} signal;


// Basic signal funtions
signal signal_init(long zero, double *data, long size);
void signal_print(signal sig);
signal get_time(signal sig, double Fs);
double * convolution(double * sig1, long size1, double * sig2, long size2);

// Time related Operations
void time_shifting(signal *sig, long shift);
void time_delay(signal *sig, long delay);
void time_advance(signal *sig, long delay);
void time_reversal(signal *sig);

// Basic plots using pipes
void plot_y(signal sig, char *xlabel, char *ylabel, char *title);
void plot_xy(signal x, signal y, char *xlabel, char *ylabel, char *title);
void plot_ny(signal y[], int size, char *xlabel, char *ylabel, char *title);

// Functions in util.c
void resize_signal(signal *sig);
double * create_arr(double start, double step, double end, long *size);
double * sine(signal sig, double fc);
double * cosine(signal sig, double fc);
double * tangent(signal sig, double fc);
double * exponent(signal sig);
double * log_e(signal sig);
double * log_10(signal sig);


// Frequency domain

typedef struct spectrum{
	double complex *data;
	long size;
} spectrum;

// helper functions
void print_freq(spectrum freq);
double mag(double complex val);
double complex W_n(double k, double N);
double * get_odd(double *arr, int size);
double * get_even(double *arr, int size);

// Singlethreaded implementations
spectrum DFT(double *signal, long N);
spectrum FFT(signal sig);

// Multithreaded implementations
spectrum FFT_th(signal sig);

// frequency plot
void plot_f(spectrum freq, double Fs);