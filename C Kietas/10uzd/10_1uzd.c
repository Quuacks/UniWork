#include <stdio.h>
#include <assert.h>
size_t my_strlen(char *str){
    size_t count = 0;
    while(str[count] != '\0')
        count++;
    return count;
}
void test_my_strlen() {
    assert(my_strlen("") == 0);
    assert(my_strlen("a") == 1);
    assert(my_strlen("labas") == 5);
    assert(my_strlen("kazkoks testas") == 14);
    assert(my_strlen(" ") == 1);
}
int main(){
    test_my_strlen();
    printf("Visi testai praejo\n");
    return 0;
}