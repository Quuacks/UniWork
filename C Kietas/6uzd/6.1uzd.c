#include <stdio.h>
int GetInput(int input){
    while((scanf("%d", &input) != 1) || (getchar() != '\n')){
        printf("Neteisinga ivestis, iveskite sveika skaiciu ");
        while(getchar() != '\n');
    }
    return input;
}
int main(){
    int n;
    int factorial = 1;
    FILE *fptr;
    fptr = fopen("out.txt", "w");


    while(1){
        n = GetInput(n);
        if(n > 0)
            break;
        printf("Iveskite teigiama skaiciu");
    }

    for(int i = n; i > 0; --i){
        factorial *= i;
    }
    printf("Factorial: %d", factorial);
    fprintf(fptr, "%d", factorial);
    fclose(fptr);

    return 0;
}