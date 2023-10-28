/*
This is an attempt at making a tool to read in a CSV
then count data under each header. I will write a python version to compare 

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1000

typedef struct {
    char* header;
    int* data;
    int dataCount;
} ColumnData;

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <csv_file>\n", argv[0]);
        return 1;
    }

    const char* filename = argv[1];
    FILE* file = fopen(filename, "r");

    if (file == NULL) {
        fprintf(stderr, "Error opening file: %s\n", filename);
        return 1;
    }

    char line[MAX_LINE_LENGTH];
    if (fgets(line, sizeof(line), file) != NULL) {
        //Tokenize the line to get the headers
        const char delimiters[] = ",";
        char* token = strtok(line, delimiters);
        
        int columnCount = 0;
        ColumnData* columns = (ColumnData*)malloc(10 * sizeof(ColumnData)); // Allocate space for up to 10 columns initially
        while (token != NULL) {
            //Allocate memory for the header and initialize data for each column
            columns[columnCount].header = strdup(token);
            columns[columnCount].data = (int*)malloc(100 * sizeof(int)); // Assuming maximum 100 data points initially
            columns[columnCount].dataCount = 0;
            columnCount++;
            token = strtok(NULL, delimiters);
        }

        //Read the file line by line and store data for each column
        int rowIndex = 0;
        while (fgets(line, sizeof(line), file) != NULL) {
            token = strtok(line, delimiters);
            int columnIndex = 0;
            while (token != NULL) {
                columns[columnIndex].data[rowIndex] = atoi(token); //Assuming the data is integer values
                columns[columnIndex].dataCount++;
                columnIndex++;
                token = strtok(NULL, delimiters);
            }
            rowIndex++;
        }

        //Print the data count for each header
        printf("Headers:\tData Count:\n");
        for (int i = 0; i < columnCount; i++) {
            printf("\t%s\t%d\n", columns[i].header, columns[i].dataCount);
        }

        //Free memory for column data
        for (int i = 0; i < columnCount; i++) {
            free(columns[i].header);
            free(columns[i].data);
        }
        free(columns);
    }

    fclose(file);
    return 0;
}
