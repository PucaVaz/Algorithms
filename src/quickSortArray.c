#include "../include/quickSortArray.h"

int partition(int numbers[], int left, int right) {
    int pivot = numbers[right];  
    int i = left - 1;  

    for (int j = left; j < right; j++) {
        if (numbers[j] <= pivot) {
            i++;
            int temp = numbers[i];
            numbers[i] = numbers[j];
            numbers[j] = temp;
        }
    }

    int temp = numbers[i + 1];
    numbers[i + 1] = numbers[right];
    numbers[right] = temp;

    return i + 1;
}

void quickSort(int numbers[], int left, int right) {
    if (left < right) {
        int partitionIndex = partition(numbers, left, right);  

        quickSort(numbers, left, partitionIndex - 1);  
        quickSort(numbers, partitionIndex + 1, right);
    }
}

void quickSortArray(int numbers[], int size) {
    quickSort(numbers, 0, size - 1);
}
