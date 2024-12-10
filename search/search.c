#include <string.h>
#include "../data/stack.h"
#include "../print/print.h"


int* searchWord(Stack* stack, const char* targetWord, int* resultSize) {
    stackElement* iterator;
    *resultSize = 0;
    int* result = NULL;

    assert(stack != NULL);
    iterator = stack->last;

    int lineNumber = 1;

    while (iterator != NULL) {
        char* line = (char*)iterator->data;
        if (strstr(line, targetWord) != NULL) {
            (*resultSize)++;
            result = realloc(result, (*resultSize) * sizeof(int));

            if (result == NULL) {
                perror("Reallocation failed");
                exit(1);
            }

            result[(*resultSize) - 1] = lineNumber;
        }
        iterator = iterator->prev;
        lineNumber++;
    }

    return result;
}



