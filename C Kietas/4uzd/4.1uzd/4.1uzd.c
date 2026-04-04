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
    printf("Rasti kvadratines lygties ax^2+bx+c sprendinius");
    int a, b, c;
    printf("Iveskite tris skaicius: ");
    a = GetInput(a);
    b = GetInput(b);
    c = GetInput(c);
    double d = pow(b,2.0) - (4 * a * c);
    if(d < 0){
        printf("Kvadratine lygtis neturi sprendiniu");
        return 0;
    }

    double xOne = (-b + sqrt(d)) / (2 * a);

    if(d == 0){
        printf("Kvadratine lygtis turi viena sprendini: %f", xOne);
    }
    else{
        double xTwo = (-b - sqrt(d)) / (2 * a);
        printf("Lygtis turi du sprendinius: x1 = %.2f, x2 = %.2f", xOne, xTwo);
    }
    return 0;
}