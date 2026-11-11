/***************************************************************** 

    File: lab8.c

    Author: [ihab yehia]
    Seneca email: [iyehia1@myseneca.ca]

    To compile program in codespaces, in terminal pane type:
        gcc -Wall lab8.c lab8main.c
    To run program in codespaces, in terminal pane type:
        ./a.out
        
***************************************************************/
//Uncomment the next line if you are using Visual Studio
//#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include "lab8.h"

int readNumericDataFile(const char* name, struct DateTime records[], int maxCapacity){
    FILE *fp = fopen(name,"r");
       int i = 0;
    if(fp != NULL){
        while(i < maxCapacity && fscanf(fp, "%d,%d,%d,%d,%d\n" ,&records[i].day,&records[i].month,&records[i].year,&records[i].hour,&records[i].minute) == 5){
         i++;
        }
    }
    else{
        printf("Error opening the file!");
    }
    fclose(fp);
    return i;
}

int readStringDataFile(const char* name, struct DateTime records[], int maxCapacity){
    FILE *f = fopen(name,"r");
    char temp[10];
    int i = 0;
    if(f != NULL){
        while(i < maxCapacity && fscanf(f, "%d/%d/%d;%d:%d %s",&records[i].day,&records[i].month,&records[i].year,&records[i].hour,&records[i].minute, temp) == 6){
            printf("%d/%d/%d,%02d:%02d %s\n",records[i].day,records[i].month,records[i].year,records[i].hour,records[i].minute, temp);       
            i++;
        }
    }
    else{
        printf("Error in opening the file!");
    }
    fclose(f);
    return i;
}

void printToFile(const char* filename, struct DateTime data[], int size){

    FILE *p = fopen(filename,"r");
    char* month;
    int i = 0;
    if(p != NULL){
        while(i < size && fscanf(p, "%d/%d/%d;%d:%d %s",&data[i].day,&data[i].month,&data[i].year,&data[i].hour,&data[i].minute, month) == 6){
           if(data[i].month == 1){
            month ="January";
        }
   else if(data[i].month == 2){
      month ="February";
   } 
   else if(data[i].month == 3){
      month ="March";
   } 
   else if(data[i].month == 4){
      month ="April";
   } 
   else if(data[i].month == 5){
      month ="May";
   } 
   else if(data[i].month == 6){
      month ="June";
   } 
   else if(data[i].month == 7){
      month ="July";
   } 
   else if(data[i].month == 8){
      month ="August";
   } 
   else if(data[i].month == 9){
      month ="September";
   } 
     else if(data[i].month == 10){
      month ="October";
   } else if(data[i].month == 11){
      month ="November";
   } else if(data[i].month == 12){
      month ="December";
   } 
            printf("%s %d, %d\n",month,data[i].day,data[i].year);       
            i++;
        }
    }
    else{ //test
        printf("Error in opening the file!");
    }
    fclose(p);

}