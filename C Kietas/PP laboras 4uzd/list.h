#ifndef LIST_H
#define LIST_H

typedef struct Element{
    int data;
    struct Element *nextElement;
}Element;

Element* createElement(int value);
void addElement(Element **firstElement, int value);
void insertElement(Element **firstElement, int target, int value);
void printList(Element *firstElement);
void deleteList(Element **firstElement);

void loadFromFile(Element **firstElement, const char *fileName);
void saveToFile(Element *firstElement, const char *fileName);

#endif