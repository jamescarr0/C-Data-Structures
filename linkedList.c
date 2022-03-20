/**
 * Linked List Data Structure.
 * Based on the Linus Torvalds idea of good taste and elegance.
 *
 * Rather than use previous & next, use double pointers and change address by Creating a pointer to pointer
 * that points to the address of the head/current node of the linked list and updating the address accordingly.
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include "linkedList.h"

void insert(LinkedList_t *list, char value) {
    // Pointer-to-pointer tracks the ADDRESS of the current node
    node_t **node_ptr = &list->head;        // Set node_ptr to address of the head (current) node.
    node_t *new_node = h_create_node(value);

    // Iterate the list until we get to the last pointer.
    while (*node_ptr) {
        node_ptr = &(*node_ptr)->next;
    }

    // This is the last pointer in the list which would point to NULL.
    // Assign to pointer the address of our new node.
    *node_ptr = new_node;
}

void insert_head(LinkedList_t *list, char value) {
    node_t **head_ptr = &list->head;
    node_t *new_node = h_create_node(value);

    new_node->next = *head_ptr;     // New node points to the head node.
    *head_ptr = new_node;           // Update the head node pointer to the new nodes address.
}

int insert_at(LinkedList_t *list, char value, int index) {
    // Index out of bounds.
    if (index > list_length(list)) {
        return -1;
    }

    // Index == last item of the list, just insert a new node.
    if (index == list_length(list)) {
        insert(list, value);
    }

    node_t **current = &list->head;

    // Iterate the list until we arrive at the point of insertion.
    for (int i = 0; i < index; ++i) {
        current = &(*current)->next;
    }

    node_t *node = h_create_node(value);
    node->next = (*current);
    *current = node;

    return 0;
}

int delete(LinkedList_t *list, char value) {
    node_t **indirect = &list->head;
    node_t *node = h_find_node(list, value);
    if (!node) {
        return -1;
    }

    while ((*indirect) != node) {
        indirect = &(*indirect)->next;
    }
    *indirect = node->next;
    free(node);

    return 0;
}

int delete_head(LinkedList_t *list) {
    // Cannot remove a head with no nodes / empty list.
    if (list_length(list) == 0) {
        return -1;
    }
    node_t *node = list->head;
    list->head = node->next;
    free(node);
    return 0;
}

void print_list(LinkedList_t *list) {
    if (is_empty(list)) {
        printf("List empty\n");
        return;
    }

    node_t *current = list->head;
    printf("HEAD -> ");
    while (current) {
        printf("[ %c ] -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

int is_empty(LinkedList_t *list) {
    return list->head == NULL;
}

int list_length(LinkedList_t *list) {
    return h_list_length(list->head);
}

void remove_all(LinkedList_t *list) {
    node_t *node = NULL;

    while (list->head) {
        node = list->head->next;
        free(list->head);
        list->head = node;
    }
    list->head = NULL;
}

void free_list(LinkedList_t *list) {
    remove_all(list);
    free(list);
}

/*** Helper Functions ***/
int h_list_length(node_t *head) {
    // Recursively count the number of nodes in the list.
    if (!head) return 0;
    return 1 + h_list_length(head->next);
}

// Malloc a new node and return the pointer.
node_t *h_create_node(char value) {
    node_t *new_node = malloc(sizeof(node_t));
    if (!new_node) {
        printf("Error: Memory allocation failed, terminating.\n");
        exit(EXIT_FAILURE);
    }
    new_node->data = value;
    new_node->next = NULL;
    return new_node;
}

// Find a node entry based on the character value.
node_t *h_find_node(LinkedList_t *list, char value) {
    node_t *node = list->head;
    while (node != NULL && node->data != value) {
        node = node->next;
    }
    return node;
}