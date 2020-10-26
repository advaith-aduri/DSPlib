/**********************************************
*  time_domain.c : Basic time related operations
*
*  Author: Aduri Sri Sambasiva Advaith
*
***********************************************/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "../include/signal.h"

// Operations in time domain

// Shift a signal by a given amount
void time_shifting(signal *sig, long shift)
{
	(*sig).zero = (*sig).zero + shift;

	// If zero location is negative, need to add zeros at the beginning of data
	if ((*sig).zero < 0)
	{
		double *temp = (*sig).data;
		(*sig).size = (*sig).size - (*sig).zero;
		double *new_data = (double *)malloc(sizeof(double) * (*sig).size); 

		(*sig).data = new_data;

		for (int i = 0; i < -(*sig).zero; i++)
			(*sig).data[i] = 0;

		for (int i = -(*sig).zero; i < (*sig).size; i++)
			(*sig).data[i] = temp[i + (*sig).zero];

		(*sig).zero = 0;
	}
	// If zero location is greater than data size, need to add zeros at end of data
	else if ((*sig).zero > (*sig).size - 1)
	{
		double *temp = (*sig).data;
		double *new_data = (double *)malloc(sizeof(double) * (*sig).zero + 1);

		(*sig).data = new_data;

		for (int i = 0; i < (*sig).size; i++)
			(*sig).data[i] = temp[i];

		for (int i = (*sig).size; i < (*sig).zero + 1; i++)
			(*sig).data[i] = 0;

		(*sig).size = (*sig).zero + 1;
	}
}


void time_delay(signal *sig, long delay)
{
	time_shifting(sig, -delay);
}


void time_advance(signal *sig, long delay)
{
	time_shifting(sig, delay);
}


void time_reversal(signal *sig)
{
	double temp;
	for (int i = 0; i < (*sig).size / 2; i++)
	{
		temp = (*sig).data[i];
		(*sig).data[i] = (*sig).data[(*sig).size - i - 1];
		(*sig).data[(*sig).size - i - 1] = temp;
	}

	(*sig).zero = (*sig).size - (*sig).zero - 1;
}

