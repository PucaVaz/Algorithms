#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "include/selectionSortArray.h"
#include "include/insertionSortArray.h"
#include "include/mergeSortArray.h"
#include "include/quickSortArray.h"
#include "include/utils.h"

#define NUM_FILES 12 
#define NUM_SCENARIOS 4

int main(void) {
    const char* filenames[NUM_FILES] = {
        "instancias-num/num.1000.1.in",   "instancias-num/num.1000.2.in",   "instancias-num/num.1000.3.in",   "instancias-num/num.1000.4.in",
        "instancias-num/num.10000.1.in",  "instancias-num/num.10000.2.in",  "instancias-num/num.10000.3.in",  "instancias-num/num.10000.4.in",
        "instancias-num/num.100000.1.in", "instancias-num/num.100000.2.in", "instancias-num/num.100000.3.in", "instancias-num/num.100000.4.in"
    };

    double totalTimeTaken[NUM_SCENARIOS] = {0};  

    for (int i = 0; i < NUM_FILES; i++) {
        const char* filename = filenames[i];
        printf("\nProcessing file: %s\n", filename);

        for (int scenario = 2; scenario < NUM_SCENARIOS; scenario++) {
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
                    printf("Time taken: %f seconds\n", elapsed);
                    totalTimeTaken[scenario] += elapsed;  
                    printf("\n");
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
                    printf("Time taken: %f seconds\n", elapsed);
                    totalTimeTaken[scenario] += elapsed; 
                    printf("\n");
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
                    printf("Time taken: %f seconds\n", elapsed);
                    totalTimeTaken[scenario] += elapsed;
                    printf("\n");
                    break;
                }
                case 3: {
                    // Scenario 4: Quick Sort
                    printf("Quick Sort with Array: %s\n", filename);
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
                    quickSortArray(numbers, size);
                    clock_t toc = clock();
                    double elapsed = (double)(toc - tic) / CLOCKS_PER_SEC;
                    printf("Time taken: %f seconds\n", elapsed);
                    totalTimeTaken[scenario] += elapsed; 
                    printf("\n");
                    break;
                }
            }
        }
    }
    printf("\nTotal time taken for each scenario:\n");
    for (int i = 0; i < NUM_SCENARIOS; i++) {
        printf("Scenario %d total time: %f seconds\n", i, totalTimeTaken[i]);
    }

    return 0;
}
