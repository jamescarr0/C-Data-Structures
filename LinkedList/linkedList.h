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

// Data type the node is working with.
#define LL_DATA_TYPE char

/**
 * Node Item contains a character value.
 */
typedef struct node_s {
    LL_DATA_TYPE data;
    struct node_s *next;
} node_t;

/**
 * Linked List Type.
 * @param head pointer to the head node.
 * @param list_length tracks the length of the linked list so we do not have to traverse the list and count the nodes
 * to find the size of the list.
 */
typedef struct LinkedList_s {
    node_t *head;
    int list_length;
} LinkedList_t;

/**
 * Initialise a new linked list
 * @return pointer to linked list.
 */
LinkedList_t *init_list();

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

#endif //LINKEDLIST_H
