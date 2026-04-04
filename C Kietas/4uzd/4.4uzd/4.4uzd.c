#include <stdio.h>
int GetInput(int input){
    while((scanf("%d", &input) != 1) || (getchar() != '\n') || input <= 0){
        printf("Neteisinga ivestis, iveskite naturalu skaiciu ");
        while(getchar() != '\n');
    }
    return input;
}
int DBD(int a, int b, int c){
    int min = a < b ? (a < c ? a : c) : (b < c ? b : c);
    for(int i = min; i > 0; i--){
        if(a % i == 0 && b % i == 0 && c % i == 0)
            return i;
    }
}
int MBK(int a, int b, int c){
    int max = a > b ? (a > c ? a : c) : (b > c ? b : c);
    for(int i = max; 1; i += max){
        if(a % i == 0 && b % i == 0 && c % i == 0)
            return i;
    }
    return -1;
}
int main(){
    int a, b, c;
    printf("Iveskite tris naturalius skaicius (nulis neieina): ");
    a = GetInput(a);
    b = GetInput(b);
    c = GetInput(c);
    printf("Didziausias bendras daliklis: %d\n", DBD(a,b,c));
    printf("Maziausias bendras kartotinis: %d", MBK(a,b,c));
    
}