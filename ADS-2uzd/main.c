#include <stdlib.h>
#include <stdio.h>
#include <string.h>
typedef struct Daiktas
{
    float svoris;
    float kaina;
}Daiktas;

void readFromFile(char *fileName, Daiktas **daiktai, int *n);
void readFromFileNoN(char *fileName, Daiktas **daiktai, int *n);
void sortByPrice(Daiktas *daiktai, int n);

int main(){
    int n;
    Daiktas *daiktai = NULL;
    char *fileName = "test.txt";

    readFromFile(fileName, &daiktai, &n);
    sortByPrice(daiktai, n);

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
void readFromFileNoN(char *fileName, Daiktas **daiktai, int *n){
    FILE *fptr = fopen(fileName, "r");

    if(!fptr)
        return;

    int size = 10;
    *daiktai = calloc(size, sizeof(Daiktas));
    int i = 0;
    while(fscanf(fptr, "%f %f", &(*daiktai)[i].svoris, &(*daiktai)[i].kaina) == 2){
        i++;
        if(i >= size){
            size += 10;
            calloc(size, sizeof(Daiktas));
            if(daiktai == NULL)
                return;
        }
    }
    *n = i;
}
void sortByPrice(Daiktas *daiktai, int n){
    for(int i = 0; i < n; ++i){
        for(int j = i; j < n; ++j){
            if(daiktai[i].kaina < daiktai[j].kaina){
                Daiktas tmp = daiktai[i];
                daiktai[i] = daiktai[j];
                daiktai[j] = tmp;
            }
        }
    }
}