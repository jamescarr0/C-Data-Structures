#include <stdio.h>
#include "linkedList.h"

int main() {
    node_t *head = NULL;

    if(isEmpty(head)) {
        printf("Creating a list..\n");

        insertHead(&head, 'A');
        insert(&head, 'l');
        insert(&head, 'i');
        insert(&head, 's');
        insert(&head, 't');
    }

    printf("Inserting X at position 5..\n");
    if (insertAt(&head, 'X', 2)) {
        printf("Error: Insertion failed.\n");
    } else {
        printf("Successfully inserted node.\n");
    }

    printf("Deleting node containing value X..\n");
    if (delete(&head, 'X')) {
        printf("Error: Node not found.\n");
    } else {
        printf("Successfully deleted node.\n");
    }

    printf("Removing head node..\n");
    if (deleteHead(&head)){
        printf("Empty list, cannot remove a head with no nodes\n");
    } else {
        printf("Head successfully removed\n");
    }

    printList(head);

    printf("Linked list length: %d\n", listLength(head));

    return 0;
}

