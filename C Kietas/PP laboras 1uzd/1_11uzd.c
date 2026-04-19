//LSP: 2513660 staneviciusarmantas@gmail.com 1 uzd. 11 variantas.⁠
#include <stdio.h>
#include <math.h>
int GetInput(int input){
    while((scanf("%d", &input) != 1) || (getchar() != '\n')){
        printf("Neteisinga ivestis, iveskite sveika skaiciu ");
        while(getchar() != '\n');
    }
    return input;
}
int main(){
    int a,userInput;
    int minNum = 0,maxNum = 0;
    int differenceMod = 0;
    
    printf("Iveskite sveika teigiama skaiciu: ");
    a = GetInput(a);
    while(a <= 0){
        printf("Neteisinga ivestis. Iveskite sveika teigiama skaiciu: ");
        a = GetInput(a);
    }

    printf("Ivesdinekite skaicius\n");
    userInput = GetInput(userInput);
    maxNum = userInput;
    minNum = userInput;
    differenceMod = abs(differenceMod - userInput);
    while(differenceMod >= a){
        userInput = GetInput(userInput);
        if(userInput > maxNum)
            maxNum = userInput;
        else if(userInput < minNum)
            minNum = userInput;
        differenceMod = abs(differenceMod - userInput);
    }
    printf("Min: %d   Max: %d", minNum, maxNum);

    int i;
    for(printf("Iki") ; i < 4; printf("Oho")){
        printf("%d", i);
        i++;
    }

    return 0;
}