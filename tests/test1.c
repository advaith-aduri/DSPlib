#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "signal.h"


int main(int argc, char const *argv[])
{
    signal sig;
    double arr[] = {1,2,3,4,5,6};
    sig.zero = 3;
    sig.size = 6;
    sig.data = arr;
    signal time = get_time(sig,1);
    signal_print(sig);
    signal_print(time);
}