#ifndef SEARCH_H
#define SEARCH_H

#include <stdio.h>
#include "../data/stack.h"

typedef struct LineList {
    int lineNumber;
    struct LineList* next;
} LineList;

LineList* searchWord(Stack* fileStack, const char* targetWord);
void freeLineList(LineList* list);
void printLineNumbers(LineList* list, const char* targetWord);
#endif
