#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void modifyText(const char *text, char **rezult) {
    int len = strlen(text);
    int maxLen = len * 2;
    *rezult = (char *)malloc(maxLen * sizeof(char));
    
    if (*rezult == NULL) {
        printf("Memory alocation failed\n");
        return;
    }
    
    int i = 0;
    int index = 0;
    
    while (i < len) {
        char curr = text[i];
        int count = 1;
        
        if (curr != ' ') {
            while (i + count < len && text[i + count] == curr) {
                count++;
            }
        }
        
        if (count > 1 && curr != ' ') {
            index += sprintf(&(*rezult)[index], "%c$%d", curr, count);
        } 
        else {
            (*rezult)[index++] = curr;
        }
        
        i += count;
    }
    
    (*rezult)[index] = '\0';
}

char* readFile(const char *fileName) {
    FILE *file = fopen(fileName, "r");
    
    if (file == NULL) {
        printf("Failed to open file");
        return NULL;
    }
    
    char buffer[256];
    int totalSize = 0;
    int capacity = sizeof(buffer);
    char *text = (char *)malloc(sizeof(char));
    
    if (text == NULL) {
        printf("Memory alocation failed");
        fclose(file);
        return NULL;
    }
    
    text[0] = '\0';
    
    while (fgets(buffer, sizeof(buffer), file) != NULL) {

        int overMaxLength = 0;
        if (strchr(buffer, '\n') == NULL) {
            int ch;

            overMaxLength = 1;
            while ((ch = fgetc(file)) != '\n' && ch != EOF) {
                
            }
        }

        int bufLen = strlen(buffer);
        capacity += bufLen + 2;
        char *temp = (char *)realloc(text, capacity * sizeof(char));
        if (temp == NULL) {
                free(text);
                fclose(file);
                printf("Memory realocation failed");
                return NULL;
            }
        text = temp;

        strcat(text, buffer);
        totalSize += bufLen;

        if(overMaxLength){
            text[totalSize++] = '\n';
            text[totalSize] = '\0';
        }
    }
    
    fclose(file);
    return text;
}

int writeFile(const char *fileName, const char *text) {
    FILE *file = fopen(fileName, "w");
    
    if (file == NULL) {
        printf("Failed to open file");
        return 0;
    }
    
    fprintf(file, "%s", text);
    fclose(file);
    printf("Done writing in file\n");
    return 1;
}

int main() {
    // const char inputFile[64];
    // const char outputFile[64];

    const char inputFile[64] = "test.txt";
    const char outputFile[64] = "isvestis.txt";
    
    // printf("Input file name: ");
    // scanf("%s", &inputFile);
    // printf("Output file name: ");
    // scanf("%s", &outputFile);

    char *text = readFile(inputFile);
    if (text != NULL) {
        char *rezult;
        modifyText(text, &rezult);
        writeFile(outputFile, rezult);
        free(text);
        free(rezult);
    }
    
    return 0;
}