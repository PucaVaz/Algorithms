// main.c
// Third-party libraries
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

// In-house libraries
#include "include/selectionSortArray.h"
#include "include/insertionSortArray.h"
#include "include/mergeSortArray.h"
#include "include/utils.h"

#define NUM_FILES 12
#define NUM_SCENARIOS 3  

struct node {
    int value;
    struct node* next;
};

int main(void) {
    // Define each file name
    const char* filenames[NUM_FILES] = {
        "instancias-numericas/num.1000.4.in",   "instancias-numericas/num.1000.3.in",   "instancias-numericas/num.1000.2.in",   "instancias-numericas/num.1000.1.in",
        "instancias-numericas/num.10000.4.in",  "instancias-numericas/num.10000.3.in",  "instancias-numericas/num.10000.2.in",  "instancias-numericas/num.10000.1.in",
        "instancias-numericas/num.100000.4.in", "instancias-numericas/num.100000.3.in", "instancias-numericas/num.100000.2.in", "instancias-numericas/num.100000.1.in"
    };

    double timeTaken[NUM_SCENARIOS];

    // Iterate through each file
    for (int i = 0; i < NUM_FILES; i++) {
        const char* filename = filenames[i];
        printf("\n\n");

        // Iterate through each scenario
        for (int scenario = 0; scenario < NUM_SCENARIOS; scenario++) {
            switch (scenario) {
                case 0: {
                    // Scenario 1: Selection Sort
                    printf("Selection Sort with Array: %s\n", filename);
                    int size;
                    FILE* file = fopen(filename, "r");
                    if (file == NULL) {
                        printf("Error on file read \n");
                        return 1;
                    }
                    size = getFileSize(file);
                    fseek(file, 0, SEEK_SET);
                    int numbers[size];
                    readFileToArray(file, numbers, size);
                    fclose(file);

                    clock_t tic = clock();
                    selectionSortArray(numbers, size);
                    clock_t toc = clock();
                    double elapsed = (double)(toc - tic) / CLOCKS_PER_SEC;
                    printf("Time taken for %s: %f seconds\n", filename, elapsed);
                    timeTaken[scenario] = elapsed;
                    break;
                }
                case 1: {
                    // Scenario 2: Insertion Sort
                    printf("Insertion Sort with Array: %s\n", filename);
                    int size;
                    FILE* file = fopen(filename, "r");
                    if (file == NULL) {
                        printf("Error on file read \n");
                        return 1;
                    }
                    size = getFileSize(file);
                    fseek(file, 0, SEEK_SET);
                    int numbers[size];
                    readFileToArray(file, numbers, size);
                    fclose(file);
                    clock_t tic = clock();
                    insertionSortArray(numbers, size); 
                    clock_t toc = clock();
                    double elapsed = (double)(toc - tic) / CLOCKS_PER_SEC;
                    printf("Time taken for %s: %f seconds\n", filename, elapsed);
                    timeTaken[scenario] = elapsed;
                    break;
                }
                case 2: {
                    // Scenario 3: Merge Sort
                    printf("Merge Sort with Array: %s\n", filename);
                    int size;
                    FILE* file = fopen(filename, "r");
                    if (file == NULL) {
                        printf("Error on file read \n");
                        return 1;
                    }
                    size = getFileSize(file);
                    fseek(file, 0, SEEK_SET);
                    int numbers[size];
                    readFileToArray(file, numbers, size);
                    fclose(file);

                    clock_t tic = clock();
                    mergeSortArray(numbers, size); 
                    clock_t toc = clock();
                    double elapsed = (double)(toc - tic) / CLOCKS_PER_SEC;
                    printf("Time taken for %s: %f seconds\n", filename, elapsed);
                    timeTaken[scenario] = elapsed;
                    break;
                }
            }
            print("\n");
        }
    }

    printf("\nTime taken for each scenario: \n");
    for (int i = 0; i < NUM_SCENARIOS; i++) {
        printf("Scenario %d: %f\n", i, timeTaken[i]);
    }

    return 0;
}
