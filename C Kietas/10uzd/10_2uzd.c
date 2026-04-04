#include <stdio.h>
#include <assert.h>
#include <string.h>
char *my_strcpy(char *dest, const char *src) {
    int i = 0;
    while (src[i] != '\0') {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
    return dest;
}
void test_my_strcpy() {
    char dest[50];

    my_strcpy(dest, "labas");
    assert(strcmp(dest, "labas") == 0);

    my_strcpy(dest, "Kazkoks tekstas");
    assert(strcmp(dest, "Kazkoks tekstas") == 0);

    my_strcpy(dest, "");
    assert(strcmp(dest, "\0") == 0);

    printf("Visi testai praejo\n");
}

int main() {
    test_my_strcpy();
    return 0;
}