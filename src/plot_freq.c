/**********************************************
*  plot_freq.c : Plots a frequency using python script
*
*  Author: Aduri Sri Sambasiva Advaith
*
***********************************************/
/*
Order to be followed when piping data to be plotted:
1 - size of data
2 - data
3 - xlabel
4 - ylabel
5 - title

Ps:- if multiple data exist, repeat 1,2 before going to 3
*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "../include/signal.h"

void plot_f(spectrum freq, char *xlabel, char *ylabel, char *title)
{
    FILE *fp = popen("python3 ../Python/plot_y.py","w");
    //sending size of data to plot.py
    fprintf(fp,"%ld\n",freq.size);
    //sending data to plot.py
    for (int i = 0; i < freq.size; i++)
    {
        fprintf(fp,"%f\n",mag(freq.data[i]));
    }
    //sending xlabel to plot.py
    fprintf(fp,"%s\n",xlabel);
    //sending ylabel to plot.py
    fprintf(fp,"%s\n",ylabel);
    //sending title to plot.py
    fprintf(fp,"%s\n",title);
    fclose(fp);
}