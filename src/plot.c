/**********************************************
*  plot.c : Plots a signal using pyhon script
*
*  Author: Aduri Sri Sambasiva Advaith
*
***********************************************/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "../include/signal.h"

char plot_cmd[] = "python3 ../Python/plot.py";

void plot_y(signal sig)
{
    FILE *fp = popen(plot_cmd,"w");
    //sending number of variables to plot
    fprintf(fp,"%d\n",1);
    //sending size of data to plot.py
    fprintf(fp,"%ld\n",sig.size);
    //sending data to plot.py
    for (int i = 0; i < sig.size; i++)
    {
        fprintf(fp,"%f\n",sig.data[i]);
    }
    fclose(fp);
}