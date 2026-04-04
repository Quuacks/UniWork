#include <stdlib.h>
#include <stdio.h>
void SpliData(int *originalArray, int arraySize, int firstPartSize, int** resultFirst, int** resultSecond){
    *resultFirst = malloc(firstPartSize);
    *resultSecond = malloc(arraySize - firstPartSize);

    for(int i = 0; i < firstPartSize; i++){
        (*resultFirst)[i] = originalArray[i];
    }

    int temp = 0;
    for(int i = firstPartSize; i < arraySize; i++, temp++){
        (*resultSecond)[temp] = originalArray[i];
    }
}
int main(){
    int a[] = {1,5,31,3,643,15,243,533,151,14};
    int size = 10;
    int firstPartSize = 6;
    int* resultFirst;
    int* resultSecond;

    SpliData(a, size, firstPartSize, &resultFirst, &resultSecond);
    for(int i = 0; i < firstPartSize; i++){
        printf("%d ", resultFirst[i]);
    }
    printf("\n");

    for(int i = 0; i < size - firstPartSize; i++){
        printf("%d ", resultSecond[i]);
    }
}