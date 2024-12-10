#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../data/stack.h"

#define BUFFER_SIZE 8192

/*
reads text file, outputs valid Stack pointer if successfull and NULL otherwise
output stack is a stack of stacks of char*.
Every cell is a line and contains a stack of words in that line
*/
Stack* readFile(char* filename);
