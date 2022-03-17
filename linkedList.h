//
// Created by James Carr on 17/03/2022.
//

#ifndef LINKEDLIST_H
#define LINKEDLIST_H

typedef struct node_s {
    char data;
    struct node_s *next;
} node_t;

void insert(node_t **head, char value);

int insertAt(node_t **head, char value, int index);

void insertHead(node_t **head, char value);

int delete(node_t **head, char value);

int deleteHead(node_t **head);

int isEmpty(void *head);

void printList(node_t *head);

int listLength(node_t *head);

#endif //LINKEDLIST_H
