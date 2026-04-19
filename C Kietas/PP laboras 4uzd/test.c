#include <assert.h>
#include <stdio.h>
#include "list.h"

int listEquals(Element *firstElement, int *arr, int n) {
    for (int i = 0; i < n; i++) {
        if (!firstElement){
            return 0;
        } 

        if (firstElement->data != arr[i]){
            return 0;
        }

        firstElement = firstElement->nextElement;
    }
    return firstElement == NULL;
}

void testInsertBeforeFirstElement() {
    Element *firstElement = NULL;

    addElement(&firstElement, 10);
    addElement(&firstElement, 20);

    insertElement(&firstElement, 10, 5);

    int expected[] = {5, 10, 20};
    assert(listEquals(firstElement, expected, 3));

    deleteList(&firstElement);
}

void testInsertBeforeMiddle() {
    Element *firstElement = NULL;

    addElement(&firstElement, 10);
    addElement(&firstElement, 20);
    addElement(&firstElement, 30);

    insertElement(&firstElement, 20, 15);

    int expected[] = {10, 15, 20, 30};
    assert(listEquals(firstElement, expected, 4));

    deleteList(&firstElement);
}

void testInsertBeforeNonexistent() {
    Element *firstElement = NULL;

    addElement(&firstElement, 10);
    addElement(&firstElement, 20);

    insertElement(&firstElement, 99, 5);

    int expected[] = {10, 20};
    assert(listEquals(firstElement, expected, 2));

    deleteList(&firstElement);
}

int main() {
    printf("Undergoing testing \n");

    testInsertBeforeFirstElement();
    testInsertBeforeMiddle();
    testInsertBeforeNonexistent();

    printf("All tests passed\n");
    return 0;
}
