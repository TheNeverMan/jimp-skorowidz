#include <stdio.h>
#include "read/read.h"
#include "search/search.h"
#include "print/print.h"

int main(int argc, char** argv)
{
  Stack* dataFromFile = NULL;
  int i;

  if (argc < 3) {
    puts("Brak podanych argumentów! Użycie: ./skorowidz <plik> <słowo1> [słowo2] ...");
    return -1;
  }

  dataFromFile = readFile(argv[1]);
  if (!dataFromFile) {
    puts("Nie udało się otworzyć pliku lub plik nie istnieje!");
    return -1;
  }

  for (i = 2; i < argc; i++) {
    int resultSize = 0;
    int* result = NULL;
    const char* targetWord = argv[i];
    printf("Szukam słowa: '%s'\n", targetWord);

    result = searchWord(dataFromFile, targetWord, &resultSize);

    if (result) {
      printLineNumber(result, resultSize, targetWord);
      free(result);
    } else {
      printf("Nie znaleziono słowa '%s' w pliku.\n", targetWord);
    }
  }

  return 0;
}
