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

void testSearchWord() {
    Stack* testStack = readFile("testfile.txt");
    if (testStack == NULL) {
        printf("Error loading file!\n");
        return;
    }

    const char* targetWords[] = {"ma", "Ola"};
    size_t wordCount = sizeof(targetWords) / sizeof(targetWords[0]);

    size_t i;
    LineList* result;

    for (i = 0; i < wordCount; i++) {
        const char* targetWord = targetWords[i];
        printf("Searching for word: '%s'\n", targetWord);

        result = searchWord(testStack, targetWord);

        if (result != NULL) {
            printf("Found occurrences of '%s':\n", targetWord);
            printLineNumbers(result, targetWord); 
            freeLineList(result); 
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
    testLoadingFile();
    testSearchWord();  
    return 0;
}
