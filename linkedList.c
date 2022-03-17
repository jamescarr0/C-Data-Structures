#include <stdio.h>
#include <stdlib.h>
#include "linkedList.h"

void insert(node_t **head, char value) {
    node_t *current = *head;
    node_t *prev;
    node_t *newNode;

    newNode = malloc(sizeof(node_t));
    newNode->data = value;
    newNode->next = NULL;

    while (current) {
        prev = current;
        current = current->next;
    }

    prev->next = newNode;
}

void insertHead(node_t **head, char value) {
    node_t *new_node = malloc(sizeof(node_t));
    new_node->data = value;
    new_node->next = *head;
    *head = new_node;
}

int insertAt(node_t **head, char value, int index) {
    // Position 0 - Insert a new head.
    if (index == 0) insertHead(head, value);

    // Insertion error: index exceeds the length of the list.
    if (index > listLength(*head)) return -1;

    node_t *current = *head;
    node_t *prev;
    node_t *newNode;
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
int delete(node_t **head, char value) {
    node_t *current = *head;
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

int deleteHead(node_t **head) {
    // Cannot remove a head with no nodes / empty list.
    if (listLength(*head) == 0) return -1;
    node_t *oldHead = *head;
    *head = oldHead->next;
    free(oldHead);
    return 0;
}

void printList(node_t *head) {
    while (head) {
        printf("List data: %c\n", head->data);
        head = head->next;
    }
}

/**
 * isEmpty: Check if a linked list contains nodes or is empty.
 *
 * @param head Head of the linked list.
 * @return 1 if list is empty, 0 if list is not empty.
 */
int isEmpty(void *head) { return head == NULL; }

int listLength(node_t *head) {
    int count = 0;
    while (head) {
        ++count;
        head = head->next;
    }
    return count;
}