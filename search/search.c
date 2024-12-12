#include <string.h>
#include "../data/stack.h"
#include "../print/print.h"


int* searchWord(Stack* stack, const char* targetWord, int* resultSize) {
    stackElement* iterator;
    *resultSize = 0;
    int* result = NULL;

    assert(stack != NULL);
    iterator = stack->last;

    int lineNumber = getStackLength(stack);

    while (iterator != NULL) {
        Stack* lineStack = (Stack*)iterator->data;
        stackElement* wordIterator = lineStack->last;
        while(wordIterator)
        {
          char* word =(char*) wordIterator->data;
          if (strcmp(word,targetWord) == 0) {
              (*resultSize)++;
              result = realloc(result, (*resultSize) * sizeof(int));

              if (result == NULL) {
                  perror("Reallocation failed");
                  exit(1);
              }
              result[(*resultSize) - 1] = lineNumber;
              break;
        }
          wordIterator = wordIterator->prev;
        }

        iterator = iterator->prev;
        lineNumber--;
    }

    return result;
}
