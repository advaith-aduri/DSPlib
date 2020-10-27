/**********************************************
*  plot.c : Plots a signal using pyhon script
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
#include "../include/signal.h"

char plot_cmd[] = "python3 ../Python/plot.py";

void plot_y(signal sig, char *xlabel, char *ylabel, char *title)
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
    //sending xlabel to plot.py
    fprintf(fp,"%s\n",xlabel);
    //sending ylabel to plot.py
    fprintf(fp,"%s\n",ylabel);
    //sending title to plot.py
    fprintf(fp,"%s\n",title);
    fclose(fp);
}


void plot_xy(signal x, signal y, char *xlabel, char *ylabel, char *title)
{
    if (x.size != y.size)
    {
        printf("Incorrect signal dimensions.\n");
        return;
    }
    FILE *fp = popen(plot_cmd,"w");
    //sending number of variables to plot
    fprintf(fp,"%d\n",2);
    //sending size of x data to plot.py
    fprintf(fp,"%ld\n",x.size);
    //sending data to plot.py
    for (int i = 0; i < x.size; i++)
    {
        fprintf(fp,"%f\n",x.data[i]);
    }
    //sending size of y data to plot.py
    fprintf(fp,"%ld\n",y.size);
    //sending data to plot.py
    for (int i = 0; i < y.size; i++)
    {
        fprintf(fp,"%f\n",y.data[i]);
    }

    //sending xlabel to plot.py
    fprintf(fp,"%s\n",xlabel);
    //sending ylabel to plot.py
    fprintf(fp,"%s\n",ylabel);
    //sending title to plot.py
    fprintf(fp,"%s\n",title);
    fclose(fp);
}

void plot_ny(signal y[], int size, char *xlabel, char *ylabel, char *title)
{
    FILE *fp = popen(plot_cmd,"w");
    //sending code to plot.py
    fprintf(fp,"%d\n",3);
    //sending number of variables to plot
    fprintf(fp,"%d\n",size);
    for (int i = 0; i < size; i++)
    {
        //sending size of data to plot.py
        fprintf(fp,"%ld\n",y[i].size);
        //sending data to plot.py
        for (int j = 0; j < y[i].size; j++)
        {
            fprintf(fp,"%f\n",y[i].data[j]);
        }
    }
    //sending xlabel to plot.py
    fprintf(fp,"%s\n",xlabel);
    //sending ylabel to plot.py
    fprintf(fp,"%s\n",ylabel);
    //sending title to plot.py
    fprintf(fp,"%s\n",title);
    fclose(fp);
}