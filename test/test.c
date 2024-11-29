#include <stdio.h>

#include "../read/read.h"

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
  return 0;
}
