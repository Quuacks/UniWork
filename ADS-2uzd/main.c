#include <stdlib.h>
#include <stdio.h>
#include <string.h>
typedef struct Daiktas
{
    int svoris;
    int kaina;
}Daiktas;

void readFromFile(char *fileName, Daiktas **daiktai, int *n, int *S);
void readFromFileNoN(char *fileName, Daiktas **daiktai, int *n, int *S);
int findBestForS(Daiktas *daiktai, int n, int S);

int main(){
    int n, S;
    Daiktas *daiktai = NULL;
    char fileName[100];

    printf("File name: ");
    scanf("%99s", fileName);

    readFromFile(fileName, &daiktai, &n, &S);

    int maxKaina = findBestForS(daiktai, n, S);

    printf("Max kaina: %d", maxKaina);

    free(daiktai);
}
void readFromFile(char *fileName, Daiktas **daiktai, int *n, int *S){
    FILE *fptr = fopen(fileName, "r");

    if(!fptr)
        return;

    fscanf(fptr, "%d %d", n, S);
    *daiktai = calloc(*n, sizeof(Daiktas));
    for(int i = 0; i < *n; ++i){
        fscanf(fptr, "%d %d", &(*daiktai)[i].svoris, &(*daiktai)[i].kaina);
    }

    fclose(fptr);
}
void readFromFileNoN(char *fileName, Daiktas **daiktai, int *n, int *S){
    FILE *fptr = fopen(fileName, "r");

    if(!fptr)
        return;

    fscanf(fptr, "%d", S);

    int size = 10;
    *daiktai = calloc(size, sizeof(Daiktas));
    int i = 0;
    while(fscanf(fptr, "%d %d", &(*daiktai)[i].svoris, &(*daiktai)[i].kaina) == 2){
        i++;
        if(i >= size){
            size += 10;
            (*daiktai) = realloc(*daiktai, size * sizeof(Daiktas));
            
        }
    }
    *n = i;
}
int findBestForS(Daiktas *daiktai, int n, int S){
    int *dp = calloc(S + 1, sizeof(int));

    for(int i = 0; i < n; i++){
        for(int w = S; w >= daiktai[i].svoris; w--){
            int newVal = dp[w - daiktai[i].svoris] + daiktai[i].kaina;
            if(newVal > dp[w]){
                dp[w] = newVal;
            }
        }
    }

    int result = dp[S];
    free(dp);
    return result;
}