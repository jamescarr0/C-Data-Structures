/**
 * Linked List Data Structure.
 * Based on the Linus Torvalds idea of good taste and elegance.
 *
 * Rather than use previous & next, use double pointers and change address by Creating a pointer to pointer
 * that points to the address of the head/current node of the linked list and updating the address accordingly.
 *
 */

//
// Created by James Carr on 17/03/2022.
//

#ifndef LINKEDLIST_H
#define LINKEDLIST_H

/**
 * Node Item contains a character value.
 */
typedef struct node_s {
    char data;
    struct node_s *next;
} node_t;

/**
 * Linked List Type.
 */
typedef struct LinkedList_s {
    node_t *head;
} LinkedList_t;

/**
 * Insert a node at the end of the list.
 * @param list The list to insert the node
 * @param value Node data - A single character
 */
void insert(LinkedList_t *list, char value);

/**
 * Insert a node at specified index
 * @param list The list to insert the node.
 * @param value Node data - A single character
 * @param index The position where the node should be inserted.  Index 0 is the first item (head) of the list.
 * @return 0 on success, -1 if insertion failed.
 */
int insert_at(LinkedList_t *list, char value, int index);

/**
 * Insert a new head node.
 * @param list The list to insert the node.
 * @param value Node data - A single character
 */
void insert_head(LinkedList_t *list, char value);

/**
 *
 * @param list The list to insert the node.
 * @param value Node data - A single character
 * @return 0 when node is successfully removed, -1 if node could not be removed.
 */
int delete(LinkedList_t *list, char value);

/**
 * Remove a head node.
 * @param list The list to insert the node.
 * @return 0 when head is successfully removed, -1 if head could not be removed.
 */
int delete_head(LinkedList_t *list);

/**
 * is_empty: Check if a linked list contains nodes or is empty.
 *
 * @param head Head of the linked list.
 * @return 1 if list is empty, 0 if list is not empty.
 */
int is_empty(LinkedList_t *list);

/**
 * Prints the contents of the linked list.
 * @param list The list containing the nodes to be printed to stdout.
 */
void print_list(LinkedList_t *list);

/**
 * Count the number of nodes in the list.
 * @param list The list containing the number of nodes to count.
 * @return The number of nodes in the specified list.
 */
int list_length(LinkedList_t *list);

/**
 * Remove all elements, deallocate all memory including linked list handle.
 * @param list The list to remove all nodes from.
 */
void free_list(LinkedList_t *list);

/**
 * Remove all nodes in the specified list.
 * @param list The list to remove all nodes from.
 */
void remove_all(LinkedList_t *list);

/**********************************************************/
/******************** Helper functions ********************/
/**********************************************************/

/**
 * Helper function to create a new node.
 * @param value A character value for the nodes data item.
 * @return pointer to a node of type node_t.
 */
node_t *h_create_node(char value);

/**
 * Find the first node in a list based on the character specified.
 * @param list The list to search
 * @param value The value/character of the node to.
 * @return Pointer to the first node found matching the character value.
 */
node_t *h_find_node(LinkedList_t *list, char value);

/**
 * Helper function to count the number of nodes in a list.
 * @param head Head node of a linked list.
 * @return The number of nodes in the list.
 */
int h_list_length(node_t *head);  // Helper function

#endif //LINKEDLIST_H
