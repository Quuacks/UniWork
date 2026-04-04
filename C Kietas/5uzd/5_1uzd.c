#include <stdio.h>
void SpausdintMasyva(int masyvas[]){
    for(int i = 0; i < 10; i++)
        printf("%d ", masyvas[i]);
    printf("\n");
}
int main(){
    int masyvas[10] = {0};
    SpausdintMasyva(masyvas);

    masyvas[0] = 1;
    masyvas[3] = 2;
    masyvas[9] = 3;

    for(int i = 2; i < 9; i++){
        masyvas[i] = masyvas[i+1];
    }
    int temp;
    for(int i = 9; i > 6; i--){
        masyvas[i] = masyvas[i-1];
    }
    masyvas[6] = 4;
    SpausdintMasyva(masyvas);

    int x,y;
    printf("iveskite x(indeksa) ir y koki skaiciu irasyti i indeksa: ");
    scanf("%d%d", &x, &y);
    masyvas[x] = y;

    printf("Iveskite indeksa x ir elementas bus istryntas is masyvo: ");
    scanf("%d", &x);
    for(int i = x-1; i < 10; i++)
        masyvas[i] = masyvas[i+1];
    
    printf("Iveskite indeksa x ir reiksme y kuria reikia iterpti: ");
    scanf("%d %d", &x, &y);
    for(int i = 9; i > x; i--)
        masyvas[i] = masyvas[i-1];
    masyvas[x] = y;
    SpausdintMasyva(masyvas);

    return 0;
}