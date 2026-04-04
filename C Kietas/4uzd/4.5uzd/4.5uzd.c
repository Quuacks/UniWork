#include <stdio.h>
int main(){
    int n;
    double temp;
    double min,max = 0,suma = 0;
    printf("Iveskite skaiciu n: ");
    scanf("%d\n", &n);
    int i = 1;
    scanf("%lf", &temp);
    min = temp;
    do{
        suma += temp;
        min = temp < min? temp : min;
        max = temp > max? temp : max;
        scanf("%lf", &temp);
        i++;
    }while(i < n);
    suma += temp;
    min = temp < min? temp : min;
    max = temp > max? temp : max;
    printf("Skaiciu suma: %lf \nSkaiciu min: %lf \nSkaiciu max: %lf \nSkaiciu vidurkis: %lf", suma, min, max, suma / n);
}