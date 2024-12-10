#include "print.h"
#include <stdio.h>

void printLineNumbers(LineList* list, const char* targetWord) {
    while (list != NULL) {
        printf("Found '%s' at line %d\n", targetWord, list->lineNumber);
        list = list->next;
    }
}
