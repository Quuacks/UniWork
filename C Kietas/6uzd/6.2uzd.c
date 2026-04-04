#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int Validation(char myString[]){
    char *kablelis = strchr(myString, ',');
    int position = kablelis - myString;
    int length = strlen(myString);
    //printf("length: %d, kablelis: %d\n", length, position);
    if(--length - position > 3)
        return 0;
    return 1;
}
int main(){
    char fileName[32] = "in.txt";
    FILE *fptr;
    char *buff;
    double num;

    
    char myString[10];
    

    while(1){
        fptr = fopen(fileName,"r");
        fgets(myString, 10, fptr);
        num = strtod(myString, &buff);
        //printf("num: %f", num);
        if(!(fgetc(fptr) != EOF))
            if(!(*buff == '\0'))
                if(!(num < 10 || num > 1000))
                    if(Validation(myString))
                        break;
        
        printf("Bloga ivestis. Iveskite teisingo failo pavadinima: ");
            scanf("%s", fileName);
            continue;
    }
    
    printf("Ilgis: %d", strlen(myString) - 1);
    return 0;
}