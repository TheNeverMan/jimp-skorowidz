#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "read/read.h"
#include "search/search.h"

// Funkcja do wypisywania zawartości stosu
void printStack(const Stack* stack) {
    for (int i = 0; i <= stack->top; i++) {
        printf("Word: %s, Lines: ", stack->data[i].word);
        for (int j = 0; j <= stack->data[i].lines.top; j++) {
            printf("%d ", stack->data[i].lines.data[j]);
        }
        printf("\n");
    }
}

// Testowanie wczytania pliku i jego struktury
void testLoadingFile() {
    Stack* testStack = readFile("testfile.txt");
    puts("Test Loading File");
    puts("testfile.txt loaded to stack structure:");
    printStack(testStack);  // Drukowanie całego stosu
    free(testStack);
}

// Testowanie integracji wyszukiwania
void testSearchIntegration() {
    // Wczytanie pliku do stosu
    Stack* fileStack = readFile("testfile.txt");

    // Inicjalizacja stosu dla słów
    Stack wordStack;
    initStack(&wordStack, 5);  // Zakładając, że initStack alokuje odpowiednią pamięć

    // Przetwarzanie pliku (mapowanie słów na numery linii)
    processFileWithSearch(fileStack, &wordStack);

    puts("Test Search Integration");
    printStack(&wordStack);  // Funkcja do wypisania zawartości stosu słów

    // Zwolnienie pamięci
    freeStack(&wordStack);
    free(fileStack);
}

int main() {
    // Testowanie wczytania pliku
    testLoadingFile();

    // Testowanie integracji wyszukiwania
    testSearchIntegration();

    return 0;
}
