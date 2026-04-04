#include <stdlib.h>
#include <stdio.h>
void Swap(int* a, int*b){
    int temp = *a;
    *a = *b;
    *b = temp;
}
int main(){
    int a, b;
    scanf("%d%d", &a, &b);
    Swap(&a, &b);
    printf("%d %d", a, b);
}