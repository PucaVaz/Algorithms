#include <stdio.h>
#include "../include/utils.h"

void printArray(int numbers[], int size) {
    // Print each number in an array
    for (int i = 0; i < size; i++) {
        printf("%d \n", numbers[i]);
    }
}

int getFileSize(FILE* file) {
    int c;
    int numbersSize = 1;

    if (file) {
        while ((c = getc(file)) != EOF) {
            if (c == ' ' || c == '\n' || c == '\t') {
                numbersSize++;
            }
        }
    }

    return numbersSize;
}

void readFileToArray(FILE* file, int numbers[], int size) {
    int index = 0;
    while (index < size && fscanf(file, "%d", &numbers[index]) == 1) {
        index++;
    }
}