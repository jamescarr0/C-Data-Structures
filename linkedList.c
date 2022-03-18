#include <stdio.h>
#include <stdlib.h>
#include "linkedList.h"

void insert(LinkedList_t *list, char value) {
    // Pointer-to-pointer tracks the ADDRESS of the current node
    // This (**ptr) pointer is a pointer to the ADDRESS of the current node
    // De-referencing the pointer (*ptr) gives the ADDRESS of the current node.
    node_t **indirect = &list->head;

    node_t *new_node = _create_node(value);

    while(*indirect) {
        indirect = &(*indirect)->next;
    }

    *indirect = new_node;
}

void insertHead(LinkedList_t *list, char value) {
    node_t *new_node = _create_node(value);
    if (listLength(list) > 0) new_node->next = list->head;
    list->head = new_node;
}

int insertAt(LinkedList_t *list, char value, int index) {
    // Position 0 - Insert a new head.
    if (index == 0) insertHead(list, value);

    // Insertion error: index exceeds the length of the list.
    if (index > listLength(list)) return -1;

    node_t *current = list->head;
    node_t *prev, *newNode;
    int count = 0;
    while (current) {
        prev = current;
        current = current->next;

        if (++count == index) {
            newNode = _create_node(value);
            newNode->next = current;
            prev->next = newNode;
        }
    }
    return 0;
}

int delete(LinkedList_t *list, char value) {
    node_t *current = list->head;
    node_t *prev;

    while (current) {
        // Node found, adjust previous and next links and free memory.
        if (current->data == value) {
            prev->next = current->next;
            free(current);
            return 0;
        }
        prev = current;
        current = current->next;
    }

    return -1;
}

int deleteHead(LinkedList_t *list) {
    // Cannot remove a head with no nodes / empty list.
    if (listLength(list) == 0) return -1;
    node_t *oldHead = list->head;
    list->head = oldHead->next;
    free(oldHead);
    return 0;
}

void printList(LinkedList_t *list) {
    if (isEmpty(list) == 1) {
        printf("List empty\n");
        return;
    }

    node_t *current = list->head;
    while (current) {
        printf("List data: %c\n", current->data);
        current = current->next;
    }
}

int isEmpty(LinkedList_t *list) {
    return list->head == NULL;
}

int listLength(LinkedList_t *list) {
    return _listLength(list->head);
}

int _listLength(node_t *head) {
    if (!head) return 0;
    return 1 + _listLength(head->next);
}

void removeAll(LinkedList_t *list) {
    node_t *next = NULL;
    while (list->head) {
        next = list->head->next;
        free(list->head);
        list->head = next;
    }
    list->head = NULL;
}

void freeList(LinkedList_t *list) {
    removeAll(list);
    free(list);
}

/*** Helper Functions ***/
node_t *_create_node(char value) {
    node_t *new_node = malloc(sizeof(node_t));
    new_node->data = value;
    new_node->next = NULL;
    return new_node;
}