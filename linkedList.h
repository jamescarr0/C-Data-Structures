//
// Created by James Carr on 17/03/2022.
//

#ifndef LINKEDLIST_H
#define LINKEDLIST_H

typedef struct node_s {
    char data;
    struct node_s *next;
} node_t;

typedef struct LinkedList_s {
    node_t *head;
} LinkedList_t;

void insert(LinkedList_t *list, char value);

int insertAt(LinkedList_t *list, char value, int index);

void insertHead(LinkedList_t *list, char value);

int delete(LinkedList_t *list, char value);

int deleteHead(LinkedList_t *list);

int isEmpty(LinkedList_t *list);

void printList(LinkedList_t *list);

int listLength(LinkedList_t *list);

void freeList(LinkedList_t *list);

void removeAll(LinkedList_t *list);

#endif //LINKEDLIST_H
