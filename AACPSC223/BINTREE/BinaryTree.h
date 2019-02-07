//file BinaryTree.h
//author Dr. Y
//date February 13, 2018

//Specification of ADT Binary Tree
//     Data object: a binary tree which is either empty or
//                  in the form of     r
//                                  /    \
//                                TL     TR
//                  where TL and TR are binary trees
//     Operations: create, destroy, insert a new node,
//                 traversals: preorder, inorder, postorder

#ifndef _BINARYTREE_H
#define _BINARYTREE_H

#include "TreeNode.h"
#include "Item.h"

const int MAXITEMS = 20;

class BinaryTree
{
public:

//creates an empty binary tree
//post an empty BinaryTree object exists
BinaryTree();

//releases a binary tree
//pre a BinaryTree object exists
//post the BinaryTree object no longer exists
~BinaryTree();

//inserts a new node into a binary tree
//pre BinaryTree object exists. newItem, left, right are assigned
//post a node containing newItem with children left and right
//     has been added to the BinaryTree object
//usage tree.insert(myItem, 1, 2);
void insert(const Item& newItem, int left, int right);

//performs a Pre-Order traversal of a binary tree
//pre BinaryTree object exists
//post the items of the BinaryTree object are printed in Pre-Order
//     with items separated by a semi-colon
//usage tree.preorder();
void preorder();

//performs a In-Order traversal of a binary tree
//pre BinaryTree object exists
//post the items of the BinaryTree object are printed in In-Order
//     with items separated by a semi-colon
//     There is a newline after the last one
//usage tree.inorder();
void inorder();

//performs a Post-Order traversal of a binary tree
//pre BinaryTree object exists
//post the items of the BinaryTree object are printed in Post-Order
//     with items separated by a semi-colon
//     There is a newline after the last one
//usage tree.postorder();
void postorder();


private:

int root;
int numberOfItems;
TreeNode binaryTree[MAXITEMS];

};

#endif
