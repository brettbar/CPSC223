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
 
//makes an empty node
//post an empty TreeNode object exists
//usage TreeNode node;

TreeNode();

//makes a node containing a specific item and left and right children
//pre newItem, theLeft, theRight are assigned
//post a node containing nodeItem with left child left and right child right exists
//usage TreeNode ( ItemOne, leftChild, rightChild)

TreeNode(const Item& newItem, TreeNode* theLeft, TreeNode* theRight);
   
Item item;
TreeNode* leftChild;
TreeNode* rightChild;

};
#endif


