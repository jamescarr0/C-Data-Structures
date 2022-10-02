/**
 * Driver code for testing list data structure.
 */

#include <stdio.h>
#include <stdlib.h>
#include "LinkedList/linkedList.h"
#include "Stack/stack.h"
#include "Queue/queue.h"
#include "BinaryTree/binaryTree.h"

int main() {
    int example_data[] = {25, 15, 50, 10, 22, 35, 70, 4, 12, 18, 24, 31, 44, 66, 90};
    BinaryTree_t binaryTree = {.root = NULL, .length=0};

    for (int i = 0; i < 15; ++i) {
        Node_t *node = malloc(sizeof(Node_t));
        node->value = example_data[i];
        node->left = NULL;
        node->right = NULL;
        bt_insert(&binaryTree, node);
    }

    int *inorder_buf = malloc(sizeof(int) * binaryTree.length);
    traverse(&binaryTree, inorder_buf);
    for (int i = 0; i < binaryTree.length; ++i) {
        printf("%d%s", inorder_buf[i], i != binaryTree.length - 1 ? ", " : "");
    }

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
//
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
//
//    // Create a new linked list.
//    LinkedList *list = new_list();
//
//    // Create some nodes.
//    if (list->is_empty(list)) {
//        printf("Creating a list..\n");
//        list->insert_head(list, 'Y');     // Will be deleted with delete function later in code.
//        list->insert(list, 'A');
//        list->insert(list, 'l');
//        list->insert(list, 'i');
//        list->insert(list, 's');
//        list->insert(list, 't');
//    }
//
//    // Insert character X at position 3.
//    printf("Inserting X at position 3..\n");
//    if (list->insert_at(list, 'X', 3)) {
//        printf("Error: Insertion failed.\n");
//    } else {
//        printf("Successfully inserted node.\n");
//    }
//
//    // Delete the newly inserted node containing character 'X'
//    printf("Deleting node containing value X..\n");
//    if (list->delete(list, 'X')) {
//        printf("Error: Node not found.\n");
//    } else {
//        printf("Successfully deleted node.\n");
//    }
//
//    // Remove a head node.
//    printf("Removing head node..\n");
//    if (list->delete_head(list)) {
//        printf("Empty list, cannot remove a head with no nodes\n");
//    } else {
//        printf("Head successfully removed\n");
//    }
//
//    list->print_list(list);                                       // Print the list.
//    printf("Linked list length: %d\n", list->length(list));  // Print list length (number of nodes)
//
//    list->remove_all(list);                                       // Remove all nodes from list.
//    list->print_list(list);                                       // Check the list is empty.
//    list->free(list);                                        // Deallocate list (including any nodes).

    return 0;
}

