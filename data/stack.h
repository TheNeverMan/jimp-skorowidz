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

/* puts element at the end of the stack, data is pointer to element
which will be inserted */
void pushToStack(Stack* stack, void* data);

/* removes element from top of the stack and returns it, if stack is empty returns
NULL. You are responsible for freeing the element
*/
void* popFromStack(Stack* stack);

/*returns number of elements on stack*/
size_t getStackLength(Stack* stack);

/* returns true if given stack is empty*/
bool isStackEmpty(Stack* stack);
