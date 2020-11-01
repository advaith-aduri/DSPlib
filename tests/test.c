#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "signal.h"
#include <time.h>
int main(int argc, char const *argv[])
{
	double data[8] = {1,2,3,4,5,6,7,8};
	spectrum dft,fft;
	dft = DFT(data,8);
	fft = FFT(data,8);
	print_freq(dft);
	print_freq(fft);
	return 0;
}
