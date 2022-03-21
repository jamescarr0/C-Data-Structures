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
    if (stack->buf_size == stack->length) grow_stack(stack);
    stack->array[stack->length++] = value;
}

void pop(Stack *stack) {
    stack->array[--stack->length];
    if (stack->buf_size > (stack->length * 2) + INIT_STACK_SIZE) shrink_stack(stack);
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

void stack_remove_all(Stack *stack) {
    stack->length = 0;
    shrink_stack(stack);
}

void free_stack(Stack *stack) { free(stack); }

void grow_stack(Stack *stack) { realloc_stack(stack, GROW_STACK); }

void shrink_stack(Stack *stack) { realloc_stack(stack, SHRINK_STACK); }

void realloc_stack(Stack *stack, int action) {
    int new_size;

    if (action == GROW_STACK) {
        new_size = (stack->buf_size += INIT_STACK_SIZE);
    }

    if (action == SHRINK_STACK) {
        new_size = (stack->buf_size = (stack->length + INIT_STACK_SIZE));
    }

    int *p = realloc(stack->array, new_size * sizeof(int));
    if (!p) {
        fprintf(stderr, "Memory reallocation failure");
        exit(EXIT_FAILURE);
    }

    stack->buf_size = new_size;
    stack->array = p;
}
