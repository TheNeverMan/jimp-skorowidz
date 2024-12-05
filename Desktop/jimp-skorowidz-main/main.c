#include <stdio.h>

#include "read/read.h"

int main(int argv, char** argc)
{
  Stack* dataFromFile = NULL;
  if(argv == 1)
  {
    puts("Brak podanych argumentów!");
    return -1;
  }
  dataFromFile = readFile(argc[1]);
  if(!dataFromFile)
  {
    puts("Nie udało się otworzyć pliku lub plik nie istnieje!");
    return -1;
  }
  return 0;
}
