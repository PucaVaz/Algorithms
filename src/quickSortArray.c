#include "../include/quickSortArray.h"

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int numbers[], int left, int right) {
    int middle = left + (right - left) / 2;
    int pivot = numbers[middle];  

    int i = left;
    int j = right;

    while (i <= j) {
        while (numbers[i] < pivot) {
            i++;
        }

        while (numbers[j] > pivot) {
            j--;
        }

        if (i <= j) {
            swap(&numbers[i], &numbers[j]);
            i++;
            j--;
        }
    }

    return i;  
}

void quickSort(int numbers[], int left, int right) {
    if (left < right) {
        int partitionIndex = partition(numbers, left, right);  

        quickSort(numbers, left, partitionIndex - 1);  
        quickSort(numbers, partitionIndex, right);  
    }
}

void quickSortArray(int numbers[], int size) {
    quickSort(numbers, 0, size - 1);
}
