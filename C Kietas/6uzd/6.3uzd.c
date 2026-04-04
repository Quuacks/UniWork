#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
int checkName(char name[], int ilgis){
    if(strcmp(name + ilgis - 4, ".txt") != 0)
        return 1;
    return 0;
}
int main(){
    FILE *fptr;

    char input_string[100];
    int ilgis = 0;
    char tempNum[40];
    int nums[3];
    int temp = 0;
    int numsCounter = 0;

    scanf("%s", input_string);
    ilgis = strlen(input_string);

    for(int i = 0; i < ilgis; ++i){
        if(input_string[i] != ';'){
            tempNum[temp] = input_string[i];
            ++temp;
        }
        else{
            temp = 0;
            nums[numsCounter] = atoi(tempNum);
            ++numsCounter;
            memset(tempNum, '\0', sizeof(tempNum));
        }

        if(i == ilgis - 1)
            nums[numsCounter] = atoi(tempNum);
    }

    int vidurys;
    if((nums[0] > nums[1] && nums[0] < nums[2]) || (nums[0] <= nums[1] && nums[0] >= nums[2]))
        vidurys = nums[0];
    else if((nums[1] > nums[0] && nums[1] < nums[2]) || (nums[1] <= nums[0] && nums[1] >= nums[2]))
        vidurys = nums[1];
    else
        vidurys = nums[2];
    char fileName[100];

    do{
        printf("Iveskite failo pavadinima turi baigtis.txt");
        scanf("%s", fileName);

    }while(checkName(fileName, strlen(fileName)));

    fptr = fopen(fileName, "w");
    fprintf(fptr, "%d", vidurys);
    
    fclose(fptr);
    return 0;
}