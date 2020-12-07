/**********************************************
*  plot_freq.c : Plots a frequency using python script
*
*  Author: Aduri Sri Sambasiva Advaith
*
***********************************************/
/*
Order to be followed when piping data to be plotted:
1 - Fs
2 - size of data
3 - data
*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "../include/dsplib.h"

void plot_f(spectrum freq, long Fs)
{
    FILE *fp = popen("python3 ../Python/plot_f.py","w");
    //sending Fs of data to plot.py
    fprintf(fp,"%ld\n",Fs);
    //sending size of data to plot.py
    fprintf(fp,"%ld\n",freq.size);
    //sending data to plot.py
    for (int i = 0; i < freq.size; i++)
    {
        fprintf(fp,"%f\n",cabs(freq.data[i]));
    }
    for (int i = 0; i < freq.size; i++)
    {
        fprintf(fp,"%f\n",carg(freq.data[i]));
    }
    fclose(fp);
}