#include <stdio.h>
int main(){
    int n;
    scanf("%d", &n); 
    printf("skaicius %d yra %s", n, (n % 2 == 0)? "lyginis" : "nelyginis");
    return 0;
}