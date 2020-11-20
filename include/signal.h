#pragma once

#include <complex.h>

typedef struct signal{
	long zero;
	double *data;
	long size;
} signal;



signal signal_init(long zero, double *data, long size);
void signal_print(signal sig);

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
double * sine(double start, double step, double end, long *size);
double * cosine(double start, double step, double end, long *size);
double * tangent(double start, double step, double end, long *size);
double * exponent(double start, double step, double end, long *size);
double * log_e(double start, double step, double end, long *size);
double * log_10(double start, double step, double end, long *size);


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
spectrum FFT_th(signal sig, int cores);

// frequency plot
void plot_f(spectrum freq, double Fs);