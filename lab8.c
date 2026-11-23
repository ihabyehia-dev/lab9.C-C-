#include <stdio.h>
#include "lab8.h"

int readNumericDataFile(const char* name, struct DateTime records[], int maxCapacity) {
    FILE* fp = fopen(name, "r");
    if (fp == NULL) {
        printf("Could not open %s\n", name);
        return 0;
    }
    int count = 0;
    while (count < maxCapacity && fscanf(fp, "%d,%d,%d,%d,%d", &records[count].day,
           &records[count].month, &records[count].year, &records[count].hour,
           &records[count].minute) == 5) {
        count++;
    }
    fclose(fp);
    return count;
}

int readStringDataFile(const char* name, struct DateTime records[], int maxCapacity) {
    FILE* fp = fopen(name, "r");
    if (fp == NULL) {
        printf("Could not open %s\n", name);
        return 0;
    }
    char ampm[10];
    int count = 0;
    while (count < maxCapacity && fscanf(fp, "%d/%d/%d;%d:%d %9s",
           &records[count].day, &records[count].month, &records[count].year,
           &records[count].hour, &records[count].minute, ampm) == 6) {
        printf("%02d/%02d/%d %02d:%02d %s\n", records[count].day,
               records[count].month, records[count].year, records[count].hour,
               records[count].minute, ampm);
        count++;
    }
    fclose(fp);
    return count;
}

void printToFile(const char* filename, struct DateTime data[], int size) {
    const char* months[] = { "January", "February", "March", "April", "May", "June",
                            "July", "August", "September", "October", "November", "December" };
    FILE* fp = fopen(filename, "w");
    if (fp == NULL) {
        printf("Could not create %s\n", filename);
        return;
    }
    for (int i = 0; i < size; i++) {
        if (data[i].month >= 1 && data[i].month <= 12) {
            fprintf(fp, "%s %d, %d at %02d:%02d\n", months[data[i].month - 1],
                    data[i].day, data[i].year, data[i].hour, data[i].minute);
        }
    }
    fclose(fp);
    printf("Saved %d records to %s\n", size, filename);
}
