#include <stdio.h>
int GetInput(int input){
    while((scanf("%d", &input) != 1) || (getchar() != '\n')){
        printf("Neteisinga ivestis, iveskite sveika skaiciu ");
        while(getchar() != '\n');
    }
    return input;
}
int main(){
    int a, b, c, temp;
    printf("Iveskite tris sveikus skaicius: ");
    a = GetInput(a);
    b = GetInput(b);
    c = GetInput(c);
    for(int i = 1; i < c; i++){
        temp = b;
        b = b + a;
        a = temp;
    }
    printf("fc = %d ", b);
}