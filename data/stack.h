#pragma once
#include<stdlib.h>
#include<assert.h>

#define FALSE 0
#define TRUE 255

typedef struct stackElement
{
  void* data;
  struct stackElement* prev;
} stackElement;

typedef struct Stack
{
  stackElement* last;
} Stack;

typedef int bool;

Stack* createNewEmptyStack();
void pushToStack(Stack* stack, void* data);
void* popFromStack(Stack* stack);
size_t getStackLength(Stack* stack);
bool isStackEmpty(Stack* stack);
