/**********************************************
*  signal.c : general signal functions
*
*  Author: Aduri Sri Sambasiva Advaith
*
***********************************************/
#include <stdio.h>
#include "../include/signal.h"



// General signal functions

// Initialize a signal
signal signal_init(long zero, double *data, long size)
{
	signal temp;
	temp.zero = zero;
	temp.data = data;
	temp.size = size;
	return temp;
}

//Print a signal
void signal_print(signal sig)
{
	printf("Zero : %ld\n", sig.zero);
	printf("Size : %ld\n", sig.size);
	printf("Data : ");
	for (int i = 0; i < sig.size; i++)
		printf("%f ",sig.data[i]);

	printf("\n");
}
 
