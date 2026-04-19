#include <stdio.h>
#include <stdlib.h>
#include "list.h"

int main(){
    Element *firstElement = NULL;
    const char fileName[64];

    int choice, value, target;
    
    

    do {
        printf("\n--- MENIU ---\n");
        printf("0. Add element\n");
        printf("1. Load from file\n");
        printf("2. Print list\n");
        printf("3. Insert before target value\n");
        printf("4. Delete list\n");
        printf("5. EXIT\n");
        printf("Choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 0:
                printf("Enter value to add: ");
                scanf("%d", &value);
                addElement(&firstElement, value);
                break;
            
            case 1:
                printf("Enter file name: ");
                scanf("%s", fileName);
                loadFromFile(&firstElement, fileName);
                printf("Loaded from file\n");
                break;

            case 2:
                printList(firstElement);
                break;

            case 3:
                printf("Value to insert before: ");
                scanf("%d", &target);
                printf("New value to insert ");
                scanf("%d", &value);
                insertElement(&firstElement, target, value);
                break;

            case 4:
                deleteList(&firstElement);
                printf("List deleted");
                break;

            case 5:
                printf("Exited\n");
                break;

            default:
                printf("Choice not found\n");
        }

    } while (choice != 5);

    saveToFile(firstElement, fileName);
    deleteList(&firstElement);

    return 0;
}