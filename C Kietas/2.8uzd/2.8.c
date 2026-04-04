#include <stdio.h>
int BinToDec(int a){
    int lastNum,base = 1,b = 0;
    while(a > 0){
        lastNum = a%10;
        b += base * lastNum;
        base *= 2;
        a /= 10;
    }
    return b;
}
void BinToHex(int a){
    printf("0x%x",BinToDec(a));
}
void DecToHex(int a){
    printf("0x%x", a);
}
void DecToBin(int a){
    int binary[16] = {0};
    if(a == 0)
        printf("0");
    int i = 0;
    while(a > 0){
         binary[i] = a%2;
         a = a / 2;
         i++;
    }

    for(int j = i - 1; j >= 0; j--){
        printf("%d", binary[j]);
    }
}
void HexToBin(int a){
    
}
void HexToDec(int a){

}
int main(){
    int a;
    printf("iveskite skaicu: ");
    scanf("%d", &a);
    DecToBin(a);
}