//file TreeNode.cpp
//author Dr. Y
//date February 13, 2018

//Implementation of ADT TreeNode
//    data object: a node in a binary tree with an item and left and right children
//    data structure: Item object item with integer left and right children
//    operations: create an empty node, create a particular node, set contents of a node
//                 get an item of a node, find the left child, find the right child

#include "TreeNode.h"

//makes an empty node
//post an empty TreeNode object exists
//usage TreeNode node;
TreeNode::TreeNode()
{
    leftChild = -1;
    rightChild = -1;
}

//makes a node containing a specific item and left and right children
//pre nodeItem, left, right are assigned
//post a node containing nodeItem with left child left and right child right exists
//usage TreeNode node(nodeItem, left, right);
TreeNode::TreeNode(const Item& nodeItem, int left, int right)
{
  setNode(nodeItem, left, right);
}

//assigns an item and children in a node
//pre nodeItem, left, and right are assigned and TreeNode object exists
//post node contains nodeItem as the item and left, right as its children
//usage myNode.setNode(myItem, 1, 2);
void TreeNode::setNode(const Item& nodeItem, int left, int right)
{
  item = nodeItem;
  leftChild = left;
  rightChild = right;
}

//gets the item in a node
//pre TreeNode object exists
//post nodeItem contains the item in the TreeNode object
//usage myNode.getItem(itsItem);
void TreeNode::getItem(Item& theItem)
{
    theItem = item;
}

//find the left child of a node
//pre TreeNode object exists
//post returns its left child
//usage lefty = myNode.getLeftChild();

int TreeNode::getLeftChild()
{
    return leftChild;
}

//find the right child of a node
//pre TreeNode object exists
//post returns its right child
//usage righty = myNode.getRightChild();
int TreeNode::getRightChild()
{
    return rightChild;
}
