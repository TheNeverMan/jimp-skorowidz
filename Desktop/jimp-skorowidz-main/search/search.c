#include "search/search.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void initStack(Stack* stack, int capacity) {
    stack->data = malloc(sizeof(Word) * capacity);
    stack->top = -1;
    stack->capacity = capacity;
}

void freeStack(Stack* stack) {
    for (int i = 0; i <= stack->top; i++) {
        free(stack->data[i].word);
        free(stack->data[i].lines.data);
    }
    free(stack->data);
}

void findWordAndPushLine(Stack* stack, const char* word, int line) {
    for (int i = 0; i <= stack->top; i++) {
        if (strcmp(stack->data[i].word, word) == 0) {
            IntStack* lines = &stack->data[i].lines;
            for (int j = 0; j <= lines->top; j++) {
                if (lines->data[j] == line) {
                    return;
                }
            }
            if (lines->top + 1 >= lines->capacity) {
                lines->capacity *= 2;
                lines->data = realloc(lines->data, sizeof(int) * lines->capacity);
            }
            lines->data[++lines->top] = line;
            return;
        }
    }

    if (stack->top + 1 >= stack->capacity) {
        stack->capacity *= 2;
        stack->data = realloc(stack->data, sizeof(Word) * stack->capacity);
    }

    Word* newWord = &stack->data[++stack->top];
    newWord->word = malloc(strlen(word) + 1);
    strcpy(newWord->word, word);
    newWord->lines.data = malloc(sizeof(int) * 10);
    newWord->lines.top = 0;
    newWord->lines.capacity = 10;
    newWord->lines.data[0] = line;
}

void printStack(const Stack* stack) {
    for (int i = 0; i <= stack->top; i++) {
        printf("Word: %s, Lines: ", stack->data[i].word);
        for (int j = 0; j <= stack->data[i].lines.top; j++) {
            printf("%d ", stack->data[i].lines.data[j]);
        }
        printf("\n");
    }
}
