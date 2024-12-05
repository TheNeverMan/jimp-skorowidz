#include <stdio.h>
#include "print.h"

void printLoadedStack(Stack* testStack) {
    Stack* lineStack = (Stack*)popFromStack(testStack);
    printf("{ \n");
    while (lineStack) {
        char* word = (char*)popFromStack(lineStack);
        printf("{ ");
        while (word) {
            printf("%s, ", word);
            free(word);  // Pamięć musi być zwolniona
            word = (char*)popFromStack(lineStack);
        }
        printf("}, \n");
        free(lineStack); // Zwolnienie pamięci po linii
        lineStack = (Stack*)popFromStack(testStack);
    }
    printf("}\n");
    free(testStack); // Zwolnienie pamięci po całym pliku
}

void printStack(const Stack* stack) {
    stackElement* current = stack->last;
    while (current) {
        printf("%s\n", (char*)current->data);
        current = current->prev;
    }
}