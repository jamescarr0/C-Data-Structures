//
// Created by James Carr on 23/03/2022.
//

#ifndef C_DATA_STRUCTURES_BINARYTREE_H
#define C_DATA_STRUCTURES_BINARYTREE_H

typedef struct {
    int value;
    struct Node_t *left;
    struct Node_t *right;
} Node_t;

typedef struct {
    Node_t *root;
    size_t length;
} BinaryTree_t;

void bt_insert(BinaryTree_t *tree, Node_t *new_node);
void traverse(BinaryTree_t *tree, int *buf);
#endif //C_DATA_STRUCTURES_BINARYTREE_H
