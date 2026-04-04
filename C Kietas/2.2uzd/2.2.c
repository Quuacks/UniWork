#include <stdio.h>

int main() {
    printf("%s",(27 == 0b11011)?"taip\n": "ne\n");
    printf("%s",(148 == 0b10010100)?"taip\n": "ne\n");
    printf("%s",(13013 == 0b11001011010101)?"taip\n": "ne\n");
    printf("%s",(0b100101 == 37)?"taip\n": "ne\n");
    printf("%s",(0b11110001 == 241)?"taip\n": "ne\n");
    printf("%s",(0b100110110111 == 2487)?"taip\n": "ne\n");
    printf("%s",(1762 == 0x6e2)?"taip\n": "ne\n");
    printf("%s",(60723 == 0xed33)?"taip\n": "ne\n");
    printf("%s",(1193046 == 0x123456)?"taip\n": "ne\n");

    printf("%s",(3451 == 0b100111010001)?"taip\n": "ne\n");
    return 0;
}
