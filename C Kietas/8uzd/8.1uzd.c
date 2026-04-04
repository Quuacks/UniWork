#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int* generateArray(int size, int low, int high)
{
    if (size <= 0) 
        return NULL;
    int* array = malloc(sizeof(int) * size);

    for (int i = 0; i < size; i++){
        int range = high - low + 1;
        *(array + i) = (rand() % range) + low;
    }

    return array;
}

int main()
{
    int arraySize, low, high;
    scanf("%d%d%d", &arraySize, &low, &high);
    srand(time(NULL));
    int* array = generateArray(arraySize, low, high);
    for (int i = 0; i < arraySize; i++)
    {
        printf("Masyvo %d elementas = %d\n", i, array[i]);
    }
}