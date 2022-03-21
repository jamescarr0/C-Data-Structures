//
// Created by James Carr on 21/03/2022.
//

#include "stack.h"
#include <stdlib.h>
#include <printf.h>

Stack *stack_init() {
    Stack *stack = malloc(sizeof(Stack));
    stack->array = malloc(INIT_STACK_SIZE * sizeof(int));
    stack->length = EMPTY_STACK;
    stack->buf_size = INIT_STACK_SIZE;
    return stack;
}

void push(Stack *stack, int value) {
    if (stack->buf_size == stack->length) realloc_stack(stack);
    stack->array[stack->length++] = value;
}

void realloc_stack(Stack *stack) {
    int new_size = stack->buf_size * REALLOC_MULTIPLIER;

    int *tmp = realloc(stack->array, new_size * sizeof(*stack->array));
    if (!tmp) {
        printf("Memory reallocation failed, terminating.\n");
        exit(EXIT_FAILURE);
    }

    stack->buf_size = new_size;
    stack->array = tmp;
}

void pop(Stack *stack) {
    stack->array[--stack->length];
}

// Return a pointer to the top of the stack.  If the stack is empty return NULL.
int *peek(Stack *stack) {
    if (stack_is_empty(stack)) return NULL;
    return &stack->array[(stack->length) - 1];
}

int stack_is_empty(Stack *stack) {
    if (stack->length == EMPTY_STACK) return 1;
    return 0;
}

void print_stack(Stack *stack) {
    if (stack_is_empty(stack)) return;
    for (int i = stack->length - 1; i > -1; --i) {
        printf("[ %d ]\n", stack->array[i]);
    }
}

    // TODO: Dealloc memory when stack size has grown to big compared to the number of elements
