/*
Example 15-7 (pg 244) 
search -- searches a set of numbers

Usage:
    search
        you will be asked numbers to look up
Files:
    numbers.dat -- Numbers 1 per line to search


*/

#include <stdio.h>
#include <stdlib.h>

#define MAX_NUMBERS 1000 /*Max numbers in file*/
const char DATA_FILE[] = "numbers.dat"; /*The file with numbers*/

int data[MAX_NUMBERS]; /*Arr of nums to search*/
int max_count; /*Num of valid elements in data*/

int main()
{
    FILE *in_file;
    int middle;
    int low, high;
    int search;
    char line[80];
    in_file = fopen(DATA_FILE, "r");
    if ( in_file == NULL) {
        fprintf(stderr, "Error: Unable to open %s\n", DATA_FILE);
        exit(8);
    }
    /*
    READ IN DATA
    */
    max_count = 0;
    while (1) {
            if (fgets(line, sizeof(line), in_file) == NULL) break;
            /*convert number*/
            sscanf(line, "%d", &data[max_count]);
            ++max_count;
    }

    while(1){
        printf("Enter number to search f or -1 to quit: ");
        fgets(line, sizeof(line), stdin);
         sscanf(line, "%d", &search);

         if(search == -1) 
         break;

         low = 0;
         high = max_count;
         while(1){
            middle= (low + high) / 2;
            if(data[middle] == search){
                printf("Found at index %d\n", middle);
                break;
            }
            if(low == high){
                printf("Not found\n");
                break;
            }
            if(data[middle] < search)
                low = middle +1;
            else
                high = middle -1;
         }
    }
    return 0;
}
