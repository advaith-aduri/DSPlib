#pragma once

#include <complex.h>

typedef struct signal_t{
	long zero;
	double *data;
	long size;
} signal_t;


// Basic signal funtions
signal_t signal_init(long zero, double *data, long size);
void signal_print(signal_t sig);
signal_t get_time(signal_t sig, double Fs);
double * convolution(double * sig1, long size1, double * sig2, long size2, long *out_size);

// Time related Operations
void time_shifting(signal_t *sig, long shift);
void time_delay(signal_t *sig, long delay, long Fs);
void time_advance(signal_t *sig, long advance, long Fs);
void time_reversal(signal_t *sig);

// Basic plots using pipes
void plot_y(signal_t sig, char *xlabel, char *ylabel, char *title);
void plot_xy(signal_t x, signal_t y, char *xlabel, char *ylabel, char *title);
void plot_ny(signal_t y[], int size, char *xlabel, char *ylabel, char *title);

// Functions in util.c
void resize_signal(signal_t *sig);
double * linspace(double start, double step, double end, long *size);
double * step(signal_t sig);
double * ramp(signal_t sig, long Fs);
double * sine(signal_t sig, double fc);
double * cosine(signal_t sig, double fc);
double * tangent(signal_t sig, double fc);
double * exponent(signal_t sig);
double * log_e(signal_t sig);
double * log_10(signal_t sig);


// Frequency domain

typedef struct spectrum{
	double complex *data;
	long size;
} spectrum;

// helper functions
void print_freq(spectrum freq);
double mag(double complex val);
double complex W_n(double k, double N);
double * get_odd(double *arr, long size);
double * get_even(double *arr, long size);

// Singlethreaded implementations
spectrum DFT(double *signal, long N);
spectrum FFT(signal_t sig);

// Multithreaded implementations
spectrum FFT_th(signal_t sig);

// frequency plot
void plot_f(spectrum freq, long Fs);