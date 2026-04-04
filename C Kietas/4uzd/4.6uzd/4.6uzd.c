#include <stdio.h>
#include <math.h>
#include <string.h>
int DigitCount(char a[]){
    int length = strlen(a);
    for(int i = 0; i < length; i++){
        if(a[i] == ',' || a[i] == '.')
            return length - 1;
    }
    return length;
}
int main(){
    
    char a[33], longestNum[33];
    int maxDigits;
    printf("Ivesdinekite skaicius: ");
    scanf("%32s",&a);
    if(a[0] == '-')
        return 0;
    maxDigits = DigitCount(a);
    strcpy(longestNum, a);
    while(1){
        scanf("%32s",&a);
        if(a[0] == '-')
            break;

        if(DigitCount(a) > maxDigits){
            maxDigits = strlen(a);
            strcpy(longestNum, a);
        }
    }
    printf("skaitmenis turi: %s", longestNum);
}