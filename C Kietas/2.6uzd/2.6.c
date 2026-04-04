#include <stdio.h>
int Min(int a, int b, int c){
    int min = (a < b) ? ((a < c) ? a : c) : ((b < c) ? b : c);
    return min;
}
int Max(int a, int b, int c){
    int max = (a > b) ? ((a > c) ? a : c) : ((b > c) ? b : c);
    return max;
}
void Test(int a, int b, int c, int tiketinasMax, int tiketinasMin){
    int max = Max(a,b,c), min = Min(a,b,c);
    printf("Min: %d   Max: %d\n", min,max);
    printf("%s",(min == tiketinasMin)? ((max == tiketinasMax) ? "Viskas teisingai\n" : "Max neteisingas\n") : "nei Min nei Max yra teisingi\n");
}
int main(){
    int a,b,c, tiketinasMax, tiketinasMin;
    int counter;
    printf("Kiek testu reikes vykdyti?: ");
    scanf("%d", &counter);
    while(counter > 0){
        printf("Iveskite 3 skaicius: ");
        scanf("%d %d %d", &a ,&b ,&c);
        printf("Iveskite siu skaiciu Max: ");
        scanf("%d", &tiketinasMax);
        printf("Iveskite siu skaiciu Min: ");
        scanf("%d", &tiketinasMin);
        Test(a,b,c,tiketinasMax,tiketinasMin);
        counter--;
    }
}
