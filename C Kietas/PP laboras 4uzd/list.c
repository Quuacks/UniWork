#include <stdio.h>
#include <stdlib.h>
#include "list.h"

Element* createElement(int value){
    Element *e = malloc(sizeof(Element));
    if(!e){
        printf("Memory alocation failed");
        exit(1);
    }

    e->data = value;
    e->nextElement = NULL;
    return e;
}
void addElement(Element **firstElement, int value){
    Element *e = createElement(value);

    if(*firstElement == NULL){
        *firstElement = e;
        return;
    }

    Element *current = *firstElement;
    while(current->nextElement){
        current = current->nextElement;
    }
    current->nextElement = e;
}
void insertElement(Element **firstElement, int target, int value){
    if(*firstElement == NULL){
        printf("Empty list");
        return;
    }

    if((*firstElement)->data == target){
        Element *e = createElement(value);
        e->nextElement = *firstElement;
        *firstElement = e;
        return;
    }

    Element *previous = *firstElement;
    Element *current = (*firstElement)->nextElement;

    while(current && current->data != target){
        previous = current;
        current = current->nextElement;
    }

    if(!current){
        //printf("Reiksme %d nerasta ", target);
        return;
    }

    Element *e = createElement(value);
    previous->nextElement = e;
    e->nextElement = current;

}
void printList(Element *element){
    if(element != NULL){
        printf("%d ", element->data);
        printList(element->nextElement);
    }
    else{
        printf("\n");
    }
    return;
}
void deleteList(Element **firstElement){
    Element *current = *firstElement;
    while(current){
        Element *temp = current;
        current = current->nextElement;
        free(temp); 
    }
    *firstElement = NULL;
}
void saveToFile(Element *firstElement, const char *fileName){
    FILE *f = fopen(fileName, "w");
    if(!f){
        printf("could not open file");
        return;
    }
    while(firstElement){
        fprintf(f, "%d\n", firstElement->data);
        firstElement = firstElement->nextElement;
    }
    fclose(f);
}
void loadFromFile(Element **firstElement, const char *fileName){
    FILE *f = fopen(fileName, "r");
    if(!f){
        printf("failed to open file");
        return;
    }
    
    int value;
    while(fscanf(f, "%d", &value) == 1){
        addElement(firstElement, value);
    }
    fclose(f);
}