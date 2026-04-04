#include <stdio.h>
int main(){
    int _0 = 0, _1 = 0, _2 = 0, _3 = 0, _4 = 0, _5 = 0, _6 = 0, _7 = 0, _8 = 0, _9 = 0;
    int a;
    printf("Iveskite skaiciu: ");
    scanf("%d", &a);
    int skaitmuo = 0;
    while(a > 0){
        skaitmuo = a%10;
        if(skaitmuo == 0) _0++;
        else if (skaitmuo == 1) _1++;
        else if (skaitmuo == 2) _2++;
        else if (skaitmuo == 3) _3++;
        else if (skaitmuo == 4) _4++;
        else if (skaitmuo == 5) _5++;
        else if (skaitmuo == 6) _6++;
        else if (skaitmuo == 7) _7++;
        else if (skaitmuo == 8) _8++;
        else if (skaitmuo == 9) _9++;
        a /= 10;
    }

    while (_9 ) {printf("9"); _9--;}
    while (_8 ) {printf("8"); _8--;}
    while (_7 ) {printf("7"); _7--;}
    while (_6) {printf("6"); _6--;}
    while (_5) {printf("5"); _5--;}
    while (_4) {printf("4"); _4--;}
    while (_3) {printf("3"); _3--;}
    while (_2) {printf("2"); _2--;}
    while (_1) {printf("1"); _1--;}
    while (_0) {printf("0"); _0--;}
}