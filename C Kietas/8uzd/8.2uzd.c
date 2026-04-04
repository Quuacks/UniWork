#include <stdio.h>
#include <stdlib.h>
char* largestFile(int size, char** fileNames){
    if(size < 2)
        return NULL;
    
    char* largestFile = NULL;
    long largestSize = -1;

    for(int i = 0; i < size; i++) {
        FILE* f = fopen(fileNames[i], "rb");
        if(f == NULL){
            printf("Failo nepavyko atidaryti %s ", fileNames[i]);
            continue;
        }

        fseek(f, 0, SEEK_END);
        long size = ftell(f);
        fclose(f);

        if(size> largestSize){
            largestFile = fileNames[i];
            largestSize = size;
        }
    }

    return largestFile;
}
int main(int argc, char** argv){
    int fileCount = argc - 1;
    const char* largest = largestFile(fileCount, argv);

    if (largest == NULL) {
        printf("Nerasta nei vieno tinkamo failo.\n");
    } else {
        printf("Didziausias failas: %s\n", largest);
    }

    return 0;
}