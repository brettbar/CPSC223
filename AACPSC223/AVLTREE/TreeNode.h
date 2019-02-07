
//file TreeNode.h
//author Dr. Y
//date Oct 16, 2013

//ADT TreeNode for a binary tree: data object a node with
//                            an item and a pointer to left and right children
// operations: constructors

// Especially designed for the BinaryTree class
#ifndef NODE_H
#define NODE_H

#include <cstdlib>
#include "Item.h"
using namespace std;

class TreeNode
{
public:

//YOU DO
TreeNode();

//YOU DO
TreeNode(const Item& newItem, TreeNode* theLeft, TreeNode* theRight);

Item item;
TreeNode* leftChild;
TreeNode* rightChild;
int balance; // height (TR) - height (TL)
};
#endif
