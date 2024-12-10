#include <stdio.h>
#include "../read/read.h"
#include "../search/search.h"
#include "../print/print.h"

void printLoadedStack(Stack* testStack)
{
    Stack* lineStack = (Stack*)popFromStack(testStack);
    printf("{ \n");
    while(lineStack)
    {
        char* word = (char*)popFromStack(lineStack);
        printf("{ ");
        while(word)
        {
            printf("%s, ", word);
            free(word);
            word = (char*)popFromStack(lineStack);
        }
        printf("}, \n");
        free(lineStack);
        lineStack = (Stack*)popFromStack(testStack);
    }
    printf("}\n");
    free(testStack);
}

void testPrintWithData()
{
    printf("Testing Print with Hardcoded Data:\n");
    Stack* testStack;
    Stack* line1;
    Stack* line2;
    Stack* line3;
    const char* targetWords[] = {"ma", "Ola", "notfound"};
    testStack = createNewEmptyStack();
    
    line1 = createNewEmptyStack();
    pushToStack(line1, "Hello");
    pushToStack(line1, "world");
    pushToStack(testStack, line1);

    line2 = createNewEmptyStack();
    pushToStack(line2, "This");
    pushToStack(line2, "is");
    pushToStack(line2, "a");
    pushToStack(line2, "test");
    pushToStack(testStack, line2);

    line3 = createNewEmptyStack();
    pushToStack(line3, "Another");
    pushToStack(line3, "line");
    pushToStack(testStack, line3);

    printLoadedStack(testStack);
}

void testSearchWord() {
    Stack* testStack = readFile("testfile.txt");
    if (testStack == NULL) {
        printf("Error loading file!\n");
        return;
    }

    const char* targetWords[] = {"ma", "Ola"};
    size_t wordCount = sizeof(targetWords) / sizeof(targetWords[0]);

    size_t i;
    int* result;
    int resultSize;

    for (i = 0; i < wordCount; i++) {
        const char* targetWord = targetWords[i];
        printf("Searching for word: '%s'\n", targetWord);

        result = searchWord(testStack, targetWord, &resultSize);

        if (result != NULL) {
            printf("Found occurrences of '%s':\n", targetWord);
            for (int j = 0; j < resultSize; j++) {
                printf("Line %d\n", result[j]);
            }
            free(result);
        } else {
            printf("No occurrences of '%s' found.\n", targetWord);
        }
    }
}

void testLoadingFile()
{
    Stack* testStack = readFile("testfile.txt");
    puts("Test Loading File");
    puts("testfile.txt loaded to stack structure:");
    printLoadedStack(testStack);
}

int main()
{
    testSearchWord();  
    testLoadingFile();
    testPrintWithData();
    
    return 0;
}
