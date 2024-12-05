#ifndef SEARCH_H
#define SEARCH_H

typedef struct {
    int* data;         
    int top;           
    int capacity;     
} IntStack; // nr.lini 

typedef struct {
    char* word;       
    IntStack lines;    
} Word;// słowa

typedef struct {
    Word* data;        
    int top;          
    int capacity;     
} Stack;// line


void initStack(Stack* stack, int capacity);
void freeStack(Stack* stack);
void findWordAndPushLine(Stack* stack, const char* word, int line);
void printStack(const Stack* stack);

#endif 
