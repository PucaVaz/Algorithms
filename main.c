#include <stdio.h>
#include "include/selectionSort.h"
#include "include/insertionSort.h"

void printArray(int numbers[], int size){
    // Print each number
    for(int i = 0; i < size; i++){
        printf("%d \n", numbers[i]);
    }
}

int main(int argc, char * argv[]) {
    if (argc < 2) {
        printf("Usage: %s <filename>\n.", argv[0]);
        return 1;
    }
    // Check if we can open the file
    //FILE *file = fopen("test.txt", "r");
    FILE *file = fopen(argv[1], "r");
    if (file == NULL) {
        printf("Erro ao ler arquivo. \n");
        return 1;
    }

    // Check the number of numbers in the file.
    int c;
    int numbersSize = 1;

    if (file) {
        while ((c = getc(file)) != EOF){
            if (c == ' ' || c == '\n' || c == '\t'){
                
                numbersSize++;
            }
        }
    }
    // Return to the beginning of the file.
    fseek(file, 0, SEEK_SET);

    // Define a varible based on the number of numbers.
    int numbers[numbersSize];

    // Read each number in the file and save it at the vetor.
    int index = 0;
    while (index < numbersSize && fscanf(file, "%d", &numbers[index]) == 1) {
        index++;
    }

    // Now, with each element saved on the array, we can close the file.  
    fclose(file);

    // Ask the user which sort algorithm they want to use.
    printf("\nWhich sort algorithm do you want to use?\n1. Selection sort\n2. Insertion sort\n");
    int choice;
    scanf("%d", &choice);
    switch (choice)
    {
    case 1:
        selectionSort(numbers, numbersSize);
    case 2:
        insertionSort(numbers, numbersSize);
    default:
        printf("\nYou must choice a option.\n");
        break;
    }
    printf("Print something?\n 1. Yep, unsorted and unsorted array\n 2. Just the unsorted array\n 3. I'm good");
    scanf("%d", &choice);
    printArray(numbers, numbersSize);
    return 0;
}