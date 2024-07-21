#include "../include/insertionSort.h"

void insertionSort(int numbers[], int size){
    for(int i = 0; i < size; i++){
        int j = i;
        while (j > 0 && numbers[j-1] > numbers[j])
        {
            int buffer = numbers[j-1];
            numbers[j-1] = numbers[j];
            numbers[j] = buffer;
            j--;
        }
    }
}
