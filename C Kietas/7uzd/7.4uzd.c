#include<stdio.h>
#include <stdlib.h>
#include <time.h>
void generateArray(int data[], int size, int low, int high){
    for(int i = 0; i < size; ++i)
        data[i] = rand() % (high - low + 1) + low;
}
int main(){
    int data[100], size, low, high;
    srand(time(NULL));

    printf("Iveskite masyvo dydi, rezius [low, high]: ");
    scanf("%d%d%d", &size, &low, &high);
    
    generateArray(data, size, low, high);
    for(int i = 0; i < size; ++i)
        printf("%d ", data[i]);
}