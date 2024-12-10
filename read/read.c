#include "read.h"

Stack* readFile(char* filename)
{
  Stack* out = NULL;
  FILE* file = fopen(filename,"r");
  char buffer[BUFFER_SIZE];
  if(!file)
    return out;
  out = createNewEmptyStack();
  while(!(feof(file) || ferror(file)) && fgets(buffer,sizeof(buffer),file) != NULL)
  {
    Stack* lineStack = createNewEmptyStack();
    char* word;
    buffer[strcspn(buffer, "\r\n")] = '\0';
    word = strtok(buffer," ");
    pushToStack(out,lineStack);
    while (word != NULL)
    {
      char* toStack = malloc(sizeof(char)*(strlen(word)+1));
      memcpy(toStack,word,sizeof(char)*(strlen(word)+1));
      word = strtok(NULL, " ");
      pushToStack(lineStack,toStack);
    }
  }
  fclose(file);
  return out;
}
