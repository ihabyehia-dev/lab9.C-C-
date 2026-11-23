# C Lab - File Input and Date Records

This exercise reads date/time records from files into arrays of C structs.

## Features
- Read numeric data into `DateTime` records
- Read a text-formatted file of date/time records
- Display parsed dates and times
- Practice writing records to a file

## Files
- `lab8.c`, `lab8.h` - record and file functions
- `lab8main.c` - console tester
- `lab8format1.txt`, `lab8format2.txt` - sample inputs

## Build
```bash
gcc -Wall -Wextra lab8.c lab8main.c -o lab8
./lab8
```

Run the program from the same directory as the two text files. The output-writing logic was corrected: the program reads the second input into a populated array, then creates `lab8output.txt` without overwriting the source files. File errors and string widths are handled more safely.
