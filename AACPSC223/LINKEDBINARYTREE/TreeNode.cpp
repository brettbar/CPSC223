//file TreeNode.h
//author Dr. Y
//date Oct 16, 2013

//ADT TreeNode for a binary tree: data object a node with
//                            an item and a pointer to left and right children
// operations: constructors

// Especially designed for the BinaryTree class
#include "TreeNode.h"

//makes an empty node
//post an empty TreeNode object exists
//usage TreeNode node;

TreeNode::TreeNode()
{
   leftChild = nullptr;
   rightChild = nullptr;
}
//makes a node containing a specific item and left and right children
//pre newItem, theLeft, theRight are assigned
//post a node containing nodeItem with left child left and right child right exists
//usage TreeNode ( ItemOne, leftChild, rightChild)
TreeNode::TreeNode(const Item& newItem, TreeNode* theLeft, TreeNode* theRight)
{
   item = newItem;
   leftChild = theLeft;
   rightChild = theRight;
}
