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

/**
 * Delete a node containing char value.
 *
 * @param head
 * @param value
 * @return 0 if node is successfully deleted.
 */
int delete(LinkedList_t *list, char value);

int deleteHead(LinkedList_t *list);

/**
 * isEmpty: Check if a linked list contains nodes or is empty.
 *
 * @param head Head of the linked list.
 * @return 1 if list is empty, 0 if list is not empty.
 */
int isEmpty(LinkedList_t *list);

void printList(LinkedList_t *list);

int listLength(LinkedList_t *list);

int _listLength(node_t *head);  // Helper function

/**
 * Remove all elements, deallocate all memory including linked list handle.
 * @param list
 */
void freeList(LinkedList_t *list);

void removeAll(LinkedList_t *list);

node_t *_create_node(char value);

#endif //LINKEDLIST_H
