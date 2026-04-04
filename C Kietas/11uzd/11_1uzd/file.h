#ifndef FILE_H
#define FILE_H

#include<stdio.h>
extern int saveCount;
extern int loadCount;

int saveToFile(const char *fileName, const int *ptr, int count);
int loadFromFile(const char *fileName, int **ptr, int *count);

#endif