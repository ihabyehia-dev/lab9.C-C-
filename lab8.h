/***************************************************************** 

    File: lab8.h

    Author: [ihab yehia]
    Seneca email: [iyehia1@myseneca.ca]

	The function prototypes for every function you write go
	into the header file.  You do not need to modify this file
        
***************************************************************/

/*this struct is used by all functions in lab 8.  We typically declare structs in 
.h files so that it can be included in all files that need to use the struct*/

struct DateTime
{
	int day;
	int month;
	int year;
	int hour;
	int minute;
};

int readNumericDataFile(const char* name, struct DateTime records[], int maxCapacity);

int readStringDataFile(const char* name, struct DateTime records[], int maxCapacity);

void printToFile(const char* filename, struct DateTime data[], int size);
/* Add the function prototypes for the lab8 problems to this file.  
 below this comment  You can copy these from the lab specifications. */
