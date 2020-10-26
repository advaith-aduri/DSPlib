#include <stdio.h>
#include <math.h>
#include "signal.h"

int main(int argc, char const *argv[])
{
	double arr[6] = {1, 2.5, 3.5, 2, 9, 5.6};
	signal sig = signal_init(2, arr, sizeof(arr)/sizeof(double));
	signal_print(sig);
	time_reversal(&sig);
	signal_print(sig);
	return 0;
}