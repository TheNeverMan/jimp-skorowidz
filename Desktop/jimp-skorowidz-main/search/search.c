#include <string.h>
#include "../data/stack.h"
#include "../print/print.h"

void addLine(LineList** list, int lineNumber) {
    LineList* newLine = malloc(sizeof(LineList));
    newLine->lineNumber = lineNumber;
    newLine->next = *list;
    *list = newLine;
}

LineList* searchWord(Stack* fileStack, const char* targetWord) {
    LineList* resultList = NULL;
    stackElement* currentElement = fileStack->last;
    char line[1024];
    int lineNumber = 0;

    while (currentElement != NULL) {
        FILE* file = (FILE*)currentElement->data;
        
        if (file) {
            lineNumber = 0;
            while (fgets(line, sizeof(line), file) != NULL) {
                lineNumber++;
                printf("linia %d, target słowo %s: %s", lineNumber, targetWord, line);
                if (strstr(line, targetWord)) {
                    addLine(&resultList, lineNumber);
                }
            }
        }

        currentElement = currentElement->prev;
    }

    return resultList;
}

void freeLineList(LineList* list) {
    while (list != NULL) {
        LineList* temp = list;
        list = list->next;
        free(temp);
    }
}
