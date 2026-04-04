#include <stdio.h>
int getFactorial(int number){
    if(number < 0)
        return 0;
    else if(number == 0 || number == 1)
        return 1;
    else
        return number *= getFactorial(number - 1);
}
int main(){
    int number;
    printf("Iveskite kurio skaiciaus factoriala reikia rasti: ");
    scanf("%d",&number);
    printf("Faktorialas: %d", getFactorial(number));
}