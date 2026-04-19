//LSP: 2513660 staneviciusarmantas@gmail.com 1 uzd. 11 variantas.⁠
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int GetInput(){
    int input;
    while((scanf("%d", &input) != 1) || (getchar() != '\n')){
        printf("Neteisinga ivestis, iveskite sveika skaiciu ");
        while(getchar() != '\n');
    }
    return input;
}
void GenerateArray(int* a, int n){
    int input;
    for(int i = 0; i < n; i++){
        input = GetInput();
        a[i] = input;
    }
    return;
}
float Average(int a[], int n){
    float average = 0;
    for(int i = 0; i < n; i++){
        average += (float)a[i];
    }
    return average / n;
}
void PrintResult(int a[], int n, float average){
    int lowerIndex = 0, higherIndex = 0;
    for(int i = 0; i < n; ++i){
        if(a[i+1] >= average){
            lowerIndex = i;
            break;
        }
    }
    for(int i = n; i > lowerIndex; --i){
        if(a[i-1] <= average){
            higherIndex = i;
            break;
        }
    }
    if(higherIndex - lowerIndex == n){
        printf("Masyvo visi elementai lygus");
    }
    else
        printf("Rez: %d %d : %d, %d ",lowerIndex, higherIndex, a[lowerIndex], a[higherIndex]);
}
void Sort(int *a, int n){
    int temp;
    for(int i = 0; i < (n - 1); i++){
        for(int j = i+1; j < n; j++){
            if(a[i] > a[j]){
                temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }
    return;
}
int main(){
    int n;
    printf("Iveskite kiek bus masyvo elementu ");
    n = GetInput();
    while(n <= 0){
        printf("Neteisinga ivestis iveskite teigiama skaiciu ");
        n = GetInput();
    }
    int *a = (int *)malloc(n);
    GenerateArray(a, n);
    Sort(a,n);
    PrintResult(a, n, Average(a,n));

    /*for(int i = 0; i < n; i++)
        printf("%d ", a[i]);
    printf("mid: %f ", Average(a,n));*/

}