#include "../include/selectionSortArray.h"

void selectionSortArray(int numbers[], int size) {
    for (int i = 0; i < size; i++) {
        int smallest = numbers[i];
        int smallestIndex = i;

        for (int j = i; j < size; j++) {
            // Find the smallest number in the subarray
            if (smallest > numbers[j]) {
                smallest = numbers[j];
                smallestIndex = j;
            }
        }
        // Save the leftmost number
        int buffer = numbers[i];
        // Put the smallest to the beginning of the subarray
        numbers[i] = smallest;
        numbers[smallestIndex] = buffer;
    }  
}