#include <stdio.h>
int isInRange(int number, int low, int high){
    if(low > high)
        return 0;

    if(number > low && number <= high)
        return 1;
    return 0;
}
int main(){
    int number, low, high;
    printf("Iveskite skaiciu ir rezius (low, high]\n");
    scanf("%d%d%d",&number, &low, &high);
    if(isInRange(number,low,high))
        printf("True");
    else
        printf("False");
}