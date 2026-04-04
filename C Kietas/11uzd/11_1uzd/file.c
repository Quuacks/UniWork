#include "file.h"
#include <stdio.h>
#include <stdlib.h>
int saveCount = 0;
int loadCount = 0;

int loadFromFile(const char *fileName, int **ptr, int *count){
    FILE *file = fopen(fileName, "rb");
    if (file == NULL) {
        printf("Failed to open file");
        return -1;
    }
    
    if(fread(count, sizeof(int), 1, file) != 1){
        fclose(file);
        return -1;
    }

    if(*count <= 0){
        fclose(file);
        printf("LoadFromFile array size <= 0");
        return -1;
    }
    
    *ptr = (int *)malloc(*count * sizeof(int));
    if(*ptr == NULL){
        fclose(file);
        printf("Memory alocation failed");
        return -1;
    }

    if(fread(*ptr, sizeof(int), *count, file) != (size_t)*count){
        free(*ptr);
        *ptr = NULL;
        fclose(file);
        printf("Failed to read array");
        return -1;
    }
    ++loadCount;
    fclose(file);
    return 0;
}
int saveToFile(const char *fileName, const int *ptr, int count){

    FILE *file = fopen(fileName, "wb");
    if (file == NULL) {
        printf("Failed to open file");
        return -1;
    }

    if(fwrite(&count, sizeof(int), 1, file) != 1){
        fclose(file);
        printf("Error writing array size");
        return -1;
    }

    if(fwrite(ptr, sizeof(int), count, file) != (size_t)count){
        fclose(file);
        printf("Failled writing array");
        return -1;
    }
    ++saveCount;
    fclose(file);
    return 0;
}