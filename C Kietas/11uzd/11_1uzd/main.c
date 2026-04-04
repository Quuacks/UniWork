#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "file.h"
int fillArray(int *ptr, int count){
    for(int i = 0; i < count; ++i){
        ptr[i] = rand() % 100;
    }
}
int printArray(int *ptr, int count){
    for(int i = 0; i < count; ++i){
        printf("%d ", ptr[i]);
    }
    printf("\n");
}
int compareArrays(const int *arr1, const int *arr2, int count) {
    for (int i = 0; i < count; i++) {
        if (arr1[i] != arr2[i]) {
            return 0;
        }
    }
    return 1;
}
int main(){
    srand(time(NULL));

    int count = 10;
    char fileName[64] = "text.bin";
    char fileName2[64] = "otherText.bin";

    int *m1 = (int *)malloc(count * sizeof(int));
    int *m2 = (int *)malloc(count * sizeof(int));
    int *m3 = (int *)malloc(count * sizeof(int));
    if(m1 == NULL || m2 == NULL || m3 == NULL){
        printf("Memory alocation failed ");
        return -1;
    }
    fillArray(m1, count);
    fillArray(m2, count);
    fillArray(m3, count);

    printf("Array m1:\n");
    printArray(m1, count);
    printf("Array m2:\n");
    printArray(m2, count);
    printf("Array m3:\n");
    printArray(m3, count);

    if(saveToFile(fileName, m1, count) == 0){
        printf("Array saved to file\n");
    }
    else{
        printf("Failed SaveToFile\n");
        return -1;
    }

    if(saveToFile(fileName, m3, count) == 0){
        printf("Array saved to file\n");
    }
    else{
        printf("Failed SaveToFile\n");
        return -1;
    }

    int loadedSize = 0;

    if(loadFromFile(fileName, &m1, &loadedSize) != 0){
        printf("Failed to load array from file\n");
        return -1;
    }

    if(saveToFile(fileName2, m2, count) == 0){
        printf("Array saved to file\n");
    }
    else{
        printf("Failed SaveToFile\n");
        return -1;
    }

    if(loadFromFile(fileName, &m3, &loadedSize) != 0){
        printf("Failed to load array from file\n");
        return -1;
    }

    if(loadFromFile(fileName2, &m2, &loadedSize) != 0){
        printf("Failed to load array from file\n");
        return -1;
    }

    extern int saveCount;
    extern int loadCount;
    if(saveCount == 3  && loadCount == 3){
        printf("All good\n");
    }
    else{
        printf("something's wrong\n");
    }

    free(m1);
    free(m2);
    return -1;
}
