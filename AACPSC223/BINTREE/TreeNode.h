//file TreeNode.h
//author Dr. Y
//date February 13, 2018

//Specification of ADT TreeNode
//    data object: a node in a binary tree with an item
//                 and left and right children
//    operations: create an empty node, create a particular node,
//                set contents of a node, get an item of a node,
//                find the left child, find the right child

#ifndef _TREENODE_H
#define _TREENODE_H

#include "Item.h"

class TreeNode
{
public:

//makes an empty node
//post an empty TreeNode object exists
//usage TreeNode node;
TreeNode();

//makes a node containing a specific item and left and right children
//pre nodeItem, left, right are assigned
//post a node containing nodeItem with left child left and right child right exists
//usage YOU DO
TreeNode(const Item& nodeItem, int left, int right);

//assigns an item and children in a node
//pre nodeItem, left, and right are assigned and TreeNode object exists
//post node contains nodeItem as the item and left, right as its children
//usage myNode.setNode(myItem, 1, 2);
void setNode(const Item& nodeItem, int left, int right);

//gets the item in a node
//pre TreeNode object exists
//post nodeItem contains the item in the TreeNode object
//usage myNode.getItem(itsItem);
void getItem(Item& nodeItem);

//find the left child of a node
//pre TreeNode object exists
//post returns its left child
//usage lefty = myNode.getLeftChild();
int getLeftChild();

//find the right child of a node
//pre TreeNode object exists
//post returns its right child
//usage righty = myNode.getRightChild();
int getRightChild();

private:
   Item item;
   int leftChild; int rightChild;
};
#endif
