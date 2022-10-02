//
// Created by James Carr on 23/03/2022.
//

/*
  Traversals:
  - Inorder   (Left Subtree, Root, Right Subtree)


  Example data { 25, 15, 50, 10, 22, 35, 70, 4, 12, 18, 24, 31, 44, 66, 90 }

               ROOT
              [ 25 ]
             /      \
            /        \
           /          \
          /            \
        15              50
        / \            / \
       /   \          /   \
      /     \        /     \
     10      22      35     70
    / \      / \    / \     / \
   04 12   18  24  31 44   66 90

 Inorder = 4, 10, 12, 15, 18, 22, 24, 25, 31, 35, 44, 50, 66, 70, 90

 */
#include <stdio.h>
#include <stdlib.h>
#include "binaryTree.h"

void bt_insert(BinaryTree_t *tree, Node_t *new_node) {
    if(!tree->root)
    {
        tree->root = new_node;
        tree->length++;
    }
    else
    {
        Node_t *current_node = tree->root;
        Node_t *prev = NULL;

        while(current_node)
        {
            if(current_node->value == new_node->value) return;
            prev = current_node;
            current_node = (new_node->value > current_node->value) ? current_node->right : current_node->left;
        }

        // Insert the new node
        if((new_node->value) > (prev->value)) prev->right = new_node;
        else prev->left = new_node;
        tree->length++;
    }
}

static void _traverse_aux(Node_t *node, int **buf)
{
    if(node) {
        **buf = node->value;
        **&buf = ++(**&buf);
        _traverse_aux(node->left, *&buf);
        _traverse_aux(node->right, *&buf);
    }
    else return;
}

static int comparator (const void * a, const void * b) {
    return ( *(int*)a - *(int*)b );
}

void traverse(BinaryTree_t *tree, int *buf)
{
    int *p = buf; // preserve the pointer so the caller does not lose reference to start of array.
    Node_t *node = tree->root;
    _traverse_aux(node, &p);
    qsort(buf, tree->length, sizeof(*buf), comparator);
}