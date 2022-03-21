//
// Created by James Carr on 21/03/2022.
//

#ifndef LINKED_LIST_STACK_H
#define LINKED_LIST_STACK_H

#define INIT_STACK_SIZE 5
#define EMPTY_STACK 0
#define REALLOC_MULTIPLIER 2

typedef struct Stack_s {
    int length;
    int *array;
    int buf_size;
} Stack;

Stack *stack_init();

void push(Stack *stack, int value);

void pop(Stack *stack);

int *peek(Stack *stack);

int stack_is_empty(Stack *stack);

void print_stack();

void realloc_stack(Stack *stack);

#endif //LINKED_LIST_STACK_H
