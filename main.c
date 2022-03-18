#include <stdio.h>
#include <stdlib.h>
#include "linkedList.h"

int listLength2(LinkedList_t *list);

int main() {
    LinkedList_t *list = malloc(sizeof(LinkedList_t));
    list->head = 0;

    if(isEmpty(list)) {
        printf("Creating a list..\n");
        insertHead(list, 'A'); // Will be deleted with delete function later in code.
        insert(list, 'A');
        insert(list, 'l');
        insert(list, 'i');
        insert(list, 's');
        insert(list, 't');

    }

    printf("Inserting X at position 5..\n");
    if (insertAt(list, 'X', 5)) {
        printf("Error: Insertion failed.\n");
    } else {
        printf("Successfully inserted node.\n");
    }

    printf("Deleting node containing value X..\n");
    if (delete(list, 'X')) {
        printf("Error: Node not found.\n");
    } else {
        printf("Successfully deleted node.\n");
    }

    printf("Removing head node..\n");
    if (deleteHead(list)){
        printf("Empty list, cannot remove a head with no nodes\n");
    } else {
        printf("Head successfully removed\n");
    }

    printList(list);

    printf("Linked list length: %d\n", listLength(list));

    removeAll(list);

    printList(list);

    freeList(list);

    return 0;
}

