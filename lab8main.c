/***************************************************************** 

    File: lab8main.c

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
#define max 100
#define size 100
int main(void){
char* filename = "lab8format1.txt";
char* filename2 = "lab8format2.txt";
struct DateTime records[max];
struct DateTime data[size];
int n = readNumericDataFile(filename, records, max);


for (int i = 0 ; i < n ; i++){
    printf("day: %d, month: %d,year: %d, hour: %d, minute: %d\n",records[i].day,records[i].month,records[i].year,records[i].hour,records[i].minute);
}

printf("------------------------------------------------\n");

readStringDataFile(filename2, records,max);

printf("------------------------------------------------\n");

printToFile(filename, data, size);
    return 0;
}