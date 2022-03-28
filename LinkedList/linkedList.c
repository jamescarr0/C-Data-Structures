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

LinkedList *new_list() {
    LinkedList *p = malloc(sizeof(LinkedList));
    if(!p) {
        fprintf(stderr, "Memory allocation failed. Terminating.\n");
        exit(EXIT_FAILURE);
    }

    p->insert = &LinkedList__insert;
    p->insert_at = &LinkedList__insert_at;
    p->insert_head = &LinkedList__insert_head;
    p->delete = &LinkedList__delete;
    p->delete_head = &LinkedList__delete_head;
    p->is_empty = &LinkedList__is_empty;
    p->print_list = &LinkedList__print_list;
    p->length = &LinkedList__list_length;
    p->remove_all = &LinkedList__remove_all;
    p->free = &LinkedList__free_list;

    return p;
}

static void LinkedList__insert(LinkedList *list, char value) {
    // Pointer-to-pointer tracks the ADDRESS of the current node
    node_t **node_ptr = &list->head;        // Set node_ptr to address of the head (current) node.
    node_t *new_node = __LinkedList__create_node(value);

    // Iterate the list until we get to the last pointer.
    while (*node_ptr) {
        node_ptr = &(*node_ptr)->next;
    }

    // This is the last pointer in the list which would point to NULL.
    // Assign to pointer the address of our new node.
    *node_ptr = new_node;
    list->list_length++;
}

void LinkedList__insert_head(LinkedList *list, char value) {
    node_t **head_ptr = &list->head;
    node_t *new_node = __LinkedList__create_node(value);
    new_node->next = *head_ptr;     // New node points to the head node.
    *head_ptr = new_node;           // Update the head node pointer to the new nodes address.
    list->list_length++;
}

int LinkedList__insert_at(LinkedList *list, char value, int index) {
    int insert_used = 0;    // If insert has been called the list length has been increment.

    // Index out of bounds.
    if (index > list->length(list)) {
        return -1;
    }

    // Index == last item of the list, just insert a new node.
    if (index == list->length(list)) {
        list->insert(list, value);
        insert_used = 1;
    }

    node_t **current = &list->head;

    // Iterate the list until we arrive at the point of insertion.
    for (int i = 0; i < index; ++i) {
        current = &(*current)->next;
    }

    node_t *node = __LinkedList__create_node(value);
    node->next = (*current);
    *current = node;

    if(insert_used==1) goto skip;

    list->list_length++;

    skip:
    return 0;
}

int LinkedList__delete(LinkedList *list, char value) {
    node_t **indirect = &list->head;
    node_t *node = __LinkedList__find_node(list, value);
    if (!node) {
        return -1;
    }

    while ((*indirect) != node) {
        indirect = &(*indirect)->next;
    }
    *indirect = node->next;
    free(node);
    list->list_length--;

    return 0;
}

int LinkedList__delete_head(LinkedList *list) {
    // Cannot remove a head with no nodes / empty list.
    if (list->length(list) == 0) {
        return -1;
    }
    node_t *node = list->head;
    list->head = node->next;
    free(node);
    list->list_length--;
    return 0;
}

void LinkedList__print_list(LinkedList *list) {
    if (list->is_empty(list)) {
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

int LinkedList__is_empty(LinkedList *list) {
    return list->head == NULL;
}

int LinkedList__list_length(LinkedList *list) {
    return list->list_length;
}

void LinkedList__remove_all(LinkedList *list) {
    node_t *node = NULL;

    while (list->head) {
        node = list->head->next;
        free(list->head);
        list->head = node;
    }
    list->head = NULL;
}

void LinkedList__free_list(LinkedList *list) {
    list->remove_all(list);
    free(list);
}

// Malloc a new node and return the pointer.
node_t *__LinkedList__create_node(char value) {
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
node_t *__LinkedList__find_node(LinkedList *list, char value) {
    node_t *node = list->head;
    while (node != NULL && node->data != value) {
        node = node->next;
    }
    return node;
}