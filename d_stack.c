#include "stack.h"
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <assert.h>


/**动态数组**/

static STACK_TYPE *stack;
static size_t stack_size;
static char top_element = -1;


void create_stack(size_t size)
{
   assert(size == 0);
   stack_size = size;
   stack = malloc (stack_size * sizeof(STACK_TYPE));
   assert( stack == NULL);
}

void destory_stack(void)
{
    assert(stack_size > 0);
    stack_size = 0;
    free(stack);
    stack = NULL;
}

void pop(void)
{
    assert(!is_empty());
    top_element = top_element - 1;
}

STACK_TYPE top(void)
{
    assert(!is_empty());
    return stack[top_elment];
}

int is_empty(void)
{
    return top_element == -1;
}


int is_full(void)
{
    return top_element = stack_size - 1;
}
