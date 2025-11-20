#include <stdio.h>
#include <stdlib.h>

// Function prototypes
void writeInputFile();
void processInputFile();
void displayFiles();

int main() {
    writeInputFile();
    processInputFile();
    displayFiles();
    return 0;
}

// 1. Function to prompt user to enter 10 integers and store in "input.txt"
void writeInputFile() {
    FILE *fptr;
    int num, i;

    fptr = fopen("input.txt", "w");
    if (fptr == NULL) {
        printf("Error opening file for writing.\n");
        exit(1);
    }

    printf("Enter 10 integers:\n");
    for (i = 0; i < 10; i++) {
        printf("Number %d: ", i + 1);
        scanf("%d", &num);
        fprintf(fptr, "%d ", num);
    }

    fclose(fptr);
    printf("\nData successfully written to input.txt\n\n");
}

// 2. Function to read from "input.txt", calculate sum and average, and write to "output.txt"
void processInputFile() {
    FILE *fptrIn, *fptrOut;
    int num, sum = 0, count = 0;
    float avg;

    fptrIn = fopen("input.txt", "r");
    if (fptrIn == NULL) {
        printf("Error opening input.txt for reading.\n");
        exit(1);
    }

    while (fscanf(fptrIn, "%d", &num) == 1) {
        sum += num;
        count++;
    }

    fclose(fptrIn);

    if (count == 0) {
        printf("No data found in input.txt\n");
        exit(1);
    }

    avg = (float)sum / count;

    fptrOut = fopen("output.txt", "w");
    if (fptrOut == NULL) {
        printf("Error opening output.txt for writing.\n");
        exit(1);
    }

    fprintf(fptrOut, "Sum = %d\nAverage = %.2f\n", sum, avg);
    fclose(fptrOut);
    printf("Results successfully written to output.txt\n\n");
}

// 3. Function to read and display both input.txt and output.txt contents
void displayFiles() {
    FILE *fptr;
    char ch;

    printf("---- Contents of input.txt ----\n");
    fptr = fopen("input.txt", "r");
    if (fptr == NULL) {
        printf("Error opening input.txt.\n");
        exit(1);
    }
    while ((ch = fgetc(fptr)) != EOF)
        putchar(ch);
    fclose(fptr);

    printf("\n\n---- Contents of output.txt ----\n");
    fptr = fopen("output.txt", "r");
    if (fptr == NULL) {
        printf("Error opening output.txt.\n");
        exit(1);
    }
    while ((ch = fgetc(fptr)) != EOF)
        putchar(ch);
    fclose(fptr);
    printf("\n");
}