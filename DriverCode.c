/**
 * Driver code for testing list data structure.
 */

#include <stdio.h>
#include <stdlib.h>
#include "LinkedList/linkedList.h"
#include "Stack/stack.h"
#include "Queue/queue.h"

int main() {

//    Queue *que = queue_init();
//
//    for (int i = 0; i < 5; ++i) {
//        enqueue(que, i);
//    }
//    print_que(que);
//
//    dequeue(que);
//    dequeue(que);
//    dequeue(que);
//    dequeue(que);
//    dequeue(que);
//    print_que(que);

//    Stack *stack = stack_init();
//    for (int i = 0; i < 500; ++i) push(stack, i);
//    for (int i = 0; i < 450; ++i) pop(stack);
//    int top = peek(stack);
//    if(!top) {
//        printf("Stack is empty!\n");
//    } else {
//        printf("Value of top: %d\n", *peek(stack));
//    }
//
//    stack_remove_all(stack);
//
//    print_stack(stack);
//
//    free_stack(stack);

    // Create a new linked list.
    LinkedList_t *list = init_list();

    // Create some nodes.
    if (is_empty(list)) {
        printf("Creating a list..\n");
        insert_head(list, 'Y');     // Will be deleted with delete function later in code.
        insert(list, 'A');
        insert(list, 'l');
        insert(list, 'i');
        insert(list, 's');
        insert(list, 't');
    }

    // Insert character X at position 3.
    printf("Inserting X at position 3..\n");
    if (insert_at(list, 'X', 3)) {
        printf("Error: Insertion failed.\n");
    } else {
        printf("Successfully inserted node.\n");
    }

    // Delete the newly inserted node containing character 'X'
    printf("Deleting node containing value X..\n");
    if (delete(list, 'X')) {
        printf("Error: Node not found.\n");
    } else {
        printf("Successfully deleted node.\n");
    }

    // Remove a head node.
    printf("Removing head node..\n");
    if (delete_head(list)) {
        printf("Empty list, cannot remove a head with no nodes\n");
    } else {
        printf("Head successfully removed\n");
    }

    print_list(list);                                       // Print the list.

    printf("Linked list length: %d\n", list_length(list));  // Print list length (number of nodes)

    remove_all(list);                                       // Remove all nodes from list.

    print_list(list);                                       // Check the list is empty.

    free_list(list);                                        // Deallocate list (including any nodes).

    return 0;
}

