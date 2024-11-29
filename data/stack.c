#include "stack.h"

Stack* createNewEmptyStack()
{
  Stack* out = malloc(sizeof(Stack));
  out->last = NULL;
  return out;
}

size_t getStackLength(Stack* stack)
{
  stackElement* iterator;
  size_t out = 0;
  assert(stack != NULL);
  iterator = stack->last;
  while(iterator)
  {
    out++;
    iterator = iterator->prev;
  }
  return out;
}

void pushToStack(Stack* stack, void* data)
{
  stackElement* newElement;
  assert(stack != NULL);
  newElement = malloc(sizeof(stackElement));
  newElement->data = data;
  newElement->prev = stack->last;
  stack->last = newElement;
}

void* popFromStack(Stack* stack)
{
  stackElement* last;
  void* out;
  assert(stack != NULL);
  if(stack->last == NULL)
   return NULL;
  last = stack->last;
  out = last->data;
  stack->last = stack->last->prev;
  free(last);
  return out;
}

bool isStackEmpty(Stack* stack)
{
  return (stack->last == NULL) ? TRUE : FALSE;
}
