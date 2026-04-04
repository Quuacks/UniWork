#include <stdio.h>
int getPositiveNumber(char *msg){
    char input[100];
    int number;
    char buff;

    printf("%s", msg);
    while(1){
        if(fgets(input, sizeof(input), stdin) == NULL)
            continue;

        if(sscanf(input, "%d %c", &number, &buff) == 1)
            if(number > 0)
                return number;

        printf("Neteisinga ivestis, iveskite viena sveika skaiciu: ");
    }
    
}
int main(){
    int number;
    number = getPositiveNumber("Get input: ");
    printf("%d", number);
}