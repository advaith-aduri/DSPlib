#pragma once

typedef struct signal{
	long zero;
	double *data;
	long size;
} signal;


signal signal_init(long zero, double *data, long size);
void signal_print(signal sig);

void time_shifting(signal *sig, long shift);
void time_delay(signal *sig, long delay);
void time_advance(signal *sig, long delay);
void time_reversal(signal *sig);

void plot_y(signal sig);