#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int showMenu(char *menuTitle, char *menuOptions[], int menuSize, char *inputMsg) {
    char input[100];
    int choice;
    char extraBuff;

    while (1) {
        printf("\n%s\n", menuTitle);
        printf("----------------------\n");

        for (int i = 0; i < menuSize; i++) {
            printf("%d. %s\n", i + 1, menuOptions[i]);
        }

        printf("%s", inputMsg);

        if (fgets(input, sizeof(input), stdin) == NULL)
            continue;

        if (sscanf(input, " %d %c", &choice, &extraBuff) == 1) {
            if (choice >= 1 && choice <= menuSize) {
                return choice;
            }
        }

        printf("Neteisingas pasirinkimas. Bandykite dar karta.\n\n");
    }
}
int main() {
    char *options[] = {
        "Kebabas su kiauliena",
        "Kebabas su vistiena",
        "Chicken nagetsai"
    };

    int pasirinkimas = showMenu(
        "KEBABINES MENIU",
        options,
        3,
        "Iveskite savo pasirinkima (1-3): "
    );

    printf("Siandien valgysit : %d\n", pasirinkimas);
    return 0;
}
