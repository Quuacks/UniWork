#include <stdio.h>
#include <math.h>
int main(){
    //x+4y+z^3
    //(x + sqr(𝑦))(z^4-abs(z)+46.3)
    double x,y,z;
    printf("iveskite 3 skaicius: ");
    scanf("%lf %lf %lf" ,&x ,&y ,&z);
    double pirmas = x+4*y+pow(z,3);
    double antras = (x + sqrt(y) * (pow(z,4) - abs(z) + 46.3));
    printf("x+4y+z^3 = %.2f \n(x + sqrt(y))(z^4-|z|+46.3) = %.3f", pirmas, antras);
    return 0;
}