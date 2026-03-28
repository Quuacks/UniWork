#include <stdlib.h>
#include <stdio.h>
#include <string.h>
typedef struct Daiktas
{
    float svoris;
    float kaina;
}Daiktas;

void readFromFile(char *fileName, Daiktas **daiktai, int *n);

int main(){
    int n;
    Daiktas *daiktai = NULL;
    char *fileName = "test.txt";

    readFromFile(fileName, &daiktai, &n);

    printf("n = %d\n", n);

    for(int i = 0; i < n; i++){
        printf("%d. Svoris: %.2f, Kaina: %.2f\n", i, daiktai[i].svoris, daiktai[i].kaina);
    }
}
void readFromFile(char *fileName, Daiktas **daiktai, int *n){
    FILE *fptr = fopen(fileName, "r");

    if(!fptr)
        return;

    fscanf(fptr, "%d", n);
    *daiktai = calloc(*n, sizeof(Daiktas));
    for(int i = 0; i < *n; ++i){
        fscanf(fptr, "%f %f", &(*daiktai)[i].svoris, &(*daiktai)[i].kaina);
    }

    fclose(fptr);
}
