#include <stdio.h>
#include <stdlib.h>
#include "linkedList.h"

void insert(LinkedList_t *list, char value) {
    node_t *current = list->head;
    node_t *prev, *newNode;

    newNode = malloc(sizeof(node_t));
    newNode->data = value;
    newNode->next = NULL;

    while (current) {
        prev = current;
        current = current->next;
    }

    prev->next = newNode;
}

void insertHead(LinkedList_t *list, char value) {
    node_t *new_node = malloc(sizeof(node_t));
    new_node->data = value;
    new_node->next = NULL;
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
            newNode = malloc(sizeof(node_t));
            newNode->data = value;
            newNode->next = current;
            prev->next = newNode;
        }
    }

    return 0;
}

/**
 * Delete a node containing char value.
 *
 * @param head
 * @param value
 * @return 0 if node is successfully deleted.
 */
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

/**
 * isEmpty: Check if a linked list contains nodes or is empty.
 *
 * @param head Head of the linked list.
 * @return 1 if list is empty, 0 if list is not empty.
 */
int isEmpty(LinkedList_t *list) {
    return list->head == NULL;
}

int listLength(LinkedList_t *list) {
    node_t *current = list->head;
    int count = 0;

    while (current) {
        ++count;
        current = current->next;
    }
    return count;
}

void removeAll(LinkedList_t *list) {
    node_t *next;
    while (list->head) {
        next = list->head->next;
        free(list->head);
        list->head = next;
    }
    list->head = NULL;
}

/**
 * Remove all elements, deallocate all memory including linked list handle.
 * @param list
 */
void freeList(LinkedList_t *list) {
    removeAll(list);
    free(list);
}