#include <stdio.h>
#include <stdlib.h> 
long getFileSize(char *fileName){
    FILE *file = fopen(fileName, "rb");
    if (file == NULL)
        return -1;

    if (fseek(file, 0, SEEK_END) != 0) {
        fclose(file);
        return -1;
    }

    long size = ftell(file);
    fclose(file);

    return size;
}
int main(){
    char fileName[32];
    long fileSize;

    printf("Iveskite failo pavadinima: ");
    scanf("%s", &fileName);
    fileSize = getFileSize(fileName);
    printf("Failo dydis: %ld", fileSize);
}