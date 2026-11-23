#include <stdio.h>
#include "lab8.h"
#define MAX 100

int main(void) {
    struct DateTime numeric[MAX];
    struct DateTime formatted[MAX];
    int count = readNumericDataFile("lab8format1.txt", numeric, MAX);
    printf("Numeric file contains %d records:\n", count);
    for (int i = 0; i < count; i++) {
        printf("%02d/%02d/%d %02d:%02d\n", numeric[i].day, numeric[i].month,
                numeric[i].year, numeric[i].hour, numeric[i].minute);
    }
    printf("\nText date/time records:\n");
    int formattedCount = readStringDataFile("lab8format2.txt", formatted, MAX);
    printToFile("lab8output.txt", formatted, formattedCount);
    return 0;
}
