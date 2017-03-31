#include "stdafx.h"
#include <stdio.h>
#include <stdarg.h>
#include "stdlib.h"
#include "string.h"
#include "conio.h"

struct status
{
    int ID;
    float temp;
    int pulse;
    int respiration;
    int systolic;
    int diastolic;
};

int main(int argc, char *argv[])
{
    int i;
    struct status datum = {0,0.0,0,0,0,0};
    char date_time[50];
    char filename[100] = "i:\\log.txt";
    
    FILE *fptr;
    
    if (argc == 1)
    {
        printf ("No input - exiting \n");
        return 0;
    }
    
    fptr = fopen (filename, "a");
    
    if (argv[1] != NULL) datum.ID = atoi(argv[1]);
    if (argv[2] != NULL) datum.temp = atof(argv[2]);
    if (argv[3] != NULL) datum.pulse = atoi(argv[3]);
    if (argv[4] != NULL) datum.respiration = atoi(argv[4]);
    if (argv[5] != NULL) datum.systolic = atoi(argv[5]);
    if (argv[6] != NULL) datum.diastolic = atoi(argv[6]);
    
    strcpy(date_time, __DATE__);
    strcat(date_time, " ");
    strcat(date_time, __TIME__);
    
    fprintf (fptr, "%s\t%d\t%.2f\t%d\t%d\t%d\t%d \n", date_time,datum.ID,datum.temp,datum.pulse, datum.respiration,datum.systolic,datum.diastolic);
    
    fclose(fptr);
    
    return 0; 
    
} 

