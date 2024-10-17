#include "../include/mergeSortArray.h"

void merge(int numbers[], int left, int right) {
    int middle = (left + right) / 2;
    int n1 = middle - left + 1;
    int n2 = right - middle;

    int leftArray[n1];
    int rightArray[n2];

    for (int i = 0; i < n1; i++) {
        leftArray[i] = numbers[left + i];
    }

    for (int i = 0; i < n2; i++) {
        rightArray[i] = numbers[middle + 1 + i];
    }

    int i = 0, j = 0, k = left;

    while (i < n1 && j < n2) {
        if (leftArray[i] <= rightArray[j]) {
            numbers[k] = leftArray[i];
            i++;
        } else {
            numbers[k] = rightArray[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        numbers[k] = leftArray[i];
        i++;
        k++;
    }

    while (j < n2) {
        numbers[k] = rightArray[j];
        j++;
        k++;
    }
}

void mergeSort(int numbers[], int left, int right) {
    if (left < right) {
        int middle = (left + right) / 2;
        mergeSort(numbers, left, middle);
        mergeSort(numbers, middle + 1, right);
        merge(numbers, left, right);
    }
}

void mergeSortArray(int numbers[], int size) {
    mergeSort(numbers,  0, size - 1);
}