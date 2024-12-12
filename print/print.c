#include <stdio.h>
#include <stdlib.h>

void printLineNumber(int* list, int resultSize, const char* targetWord) {
    if (list == NULL || resultSize == 0) {
        printf("Nie znaleziono słowa '%s'.\n", targetWord);
        return;
    }

    printf("Słowo '%s' zostało znalezione w liniach: ", targetWord);
    int i = 0;
    for (i=0; i < resultSize; i++) {
        printf("%d, ", list[i]);
    }
    puts(" ");
}
