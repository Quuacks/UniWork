#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int RandomInt(int a, int b){
    return rand() % (b - a + 1) + a;
}
int main(){
    int masyvas[1000];
    int a,b,c;
    printf("Iveskite rezius [a,b] ir kiek iteraciju c reikes daryt: ");
    scanf("%d%d%d", &a, &b, &c);
    srand(time(NULL));
    for(int i = 0; i < c; i++){
        masyvas[i] = RandomInt(a,b);
        
    }

    printf("Random skaiciai sugeneruoti intervale [%d, %d]: \n", a, b);
    for(int i = 0; i < c; i++)
        printf("%d\n", masyvas[i]);

    return 0;
}