#include <stdio.h>
#include <stdlib.h>

void printLineNumber(int* list, int resultSize, const char* targetWord) {
    if (list == NULL || resultSize == 0) {
        printf("No occurrences of '%s' found.\n", targetWord);
        return;
    }

    printf("Occurrences of '%s' found in the following lines:\n", targetWord);
    for (int i = 0; i < resultSize; i++) {
        printf("Line %d\n", list[i]);
    }
}
