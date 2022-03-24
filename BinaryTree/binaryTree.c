//
// Created by James Carr on 23/03/2022.
//

/*
  Traversals:
  - Inorder   (Left Subtree, Root, Right Subtree)
  - Preorder  (Root, Left Subtree, Right subtree)
  - Postorder (Left Subtree, Right Subtree, Root)

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

#include "binaryTree.h"

