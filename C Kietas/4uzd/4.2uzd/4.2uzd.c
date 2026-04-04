#include <stdio.h>
int GetInput(int input){
    while((scanf("%d", &input) != 1) || (getchar() != '\n')){
        printf("Neteisinga ivestis, iveskite sveika skaiciu ");
        while(getchar() != '\n');
    }
    return input;
}
int main(){
    int a, b, c;
    printf("Iveskite tris sveikus skaicius: ");
    a = GetInput(a);
    b = GetInput(b);
    c = GetInput(c);
    if(b <= 0){
        printf("Sprendiniu nera");
        return 0;
    }
    printf("Sveiki skaiciai tarp (a,b] kurie dalyjasi is c su liekana 1: ");
    for(a <= 0 ? a = 1 : a++; a <= b; a++){
        if(a % c == 1){
            printf("%d ", a);
        }
    }

}