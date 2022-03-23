/**
 * Array based Stack Data structure.
 */

//
// Created by James Carr on 21/03/2022.
//

#ifndef LINKED_LIST_STACK_H
#define LINKED_LIST_STACK_H

#define INIT_STACK_SIZE 20
#define EMPTY_STACK 0
#define GROW_STACK 0
#define SHRINK_STACK 1

// Data type the stack is working with.
#define STACK_DATA_TYPE int

typedef struct Stack_s {
    int length;
    STACK_DATA_TYPE *array;
    int buf_size;
} Stack;

Stack *stack_init();

void push(Stack *stack, int value);

void pop(Stack *stack);

/**
 * View the top of the stack without popping.
 * @param stack The stack to peek
 * @return Pointer to the top of the stack, NULL if stack is empty.
 */
int *peek(Stack *stack);

int stack_is_empty(Stack *stack);

void print_stack();

void grow_stack(Stack *stack);

void shrink_stack(Stack *stack);

void realloc_stack(Stack *stack, int action);

void stack_remove_all(Stack *stack);

void free_stack(Stack *stack);

#endif //LINKED_LIST_STACK_H
