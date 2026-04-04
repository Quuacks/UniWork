#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int SWAP_COUNT = 0;
int ITERATION_COUNT = 0;

int generateArray(int **arr, int length){
    *arr = malloc(length * sizeof(int));
    if(arr == NULL){
        printf("memory alloc fail");
        return -1;
    }

    for(int i = 0; i < length; ++i){
        int randomNum = rand() % (100 - (-100) + 1) + -100;
        (*arr)[i] = randomNum;
    }
    return 0;
}

int CheckIfSortedCorrectly(int *arr, int length){
    for(int i = 0; i < length - 1; i++){
        if(arr[i] > arr[i+1]){
            printf("Not sorted correctly");
            return i;
        }
    }
    printf("Sorted correctly");
    return -1;
}

void printArray(int *arr, int length){
    for(int i = 0; i < length; ++i){
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void swapElements(int *arr, int indexOne, int indexTwo){
    int temp = arr[indexOne];
    arr[indexOne] = arr[indexTwo];
    arr[indexTwo] = temp;
    ++SWAP_COUNT;
}

void bubbleSort(int *arr, int length){
    SWAP_COUNT = 0;
    ITERATION_COUNT = 0;
    int swapCount = 0;
    for(int i = 0; i < length - 1; ++i){
        swapCount = 0;
        for(int j = 0; j < length - 1; ++j){
            if(arr[j] > arr[j+1]){
                swapElements(arr, j, j+1);
                ++swapCount;
            }
            ++ITERATION_COUNT;
        }
        ++ITERATION_COUNT;
        if(swapCount == 0)
            break;
    }
    printf("Bubble Sort:    Swaps: %d   Iterations: %d\n", SWAP_COUNT, ITERATION_COUNT);

}
int partition(int *arr, int low, int high) {
    
    int pivot = arr[high];
    
    int i = low - 1;

    for (int j = low; j <= high - 1; j++) {
        ++ITERATION_COUNT;
        if (arr[j] < pivot) {
            i++;
            swapElements(arr, i, j);
        }
    }
    
    swapElements(arr, i + 1, high);  
    return i + 1;
}

void quickSort(int *arr, int low, int high) {
    if (low < high) {
        
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
    
}

void insertionSort(int *arr, int length){
    ITERATION_COUNT = 0;
    SWAP_COUNT = 0;
    for(int i = 1; i < length; ++i){
        ++ITERATION_COUNT;
        int key = arr[i];
        int j = i - 1;

        while(j >= 0 && arr[j] > key){
            SWAP_COUNT++;
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
    printf("Insertion sort:     Swaps: %d   Iterations: %d\n", SWAP_COUNT, ITERATION_COUNT);
}

void selectionSort(int *arr, int length){
    ITERATION_COUNT = 0;
    SWAP_COUNT = 0;
    for(int i = 0; i < length-1; ++i){
        ++ITERATION_COUNT;
        int jMin = i;
        for(int j = i + 1; j < length; ++j){
            ++ITERATION_COUNT;
            if(arr[j] < arr[jMin]){
                jMin = j;
            }
        }
        if(jMin != i){
            swapElements(arr, i, jMin);
        }

    }
    printf("selection Sort:     Swaps: %d   Iterations: %d\n", SWAP_COUNT, ITERATION_COUNT);
}
int main(){
    srand(time(NULL));
    int *arr;
    int length = 500;
    generateArray(&arr, length);
    //printArray(arr, length);  
    //bubbleSort(arr, length);
    //quickSort(arr, 0, length - 1);
    //insertionSort(arr, length);
    selectionSort(arr, length);
    printArray(arr,length);
    printf("failed at %d\n", CheckIfSortedCorrectly(arr, length));
    //printf("Quick sort:     Swaps: %d   Iterations: %d\n", SWAP_COUNT, ITERATION_COUNT);
}