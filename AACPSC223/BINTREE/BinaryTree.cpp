//file BinaryTree.cpp
//author Dr. Y
//date February 13. 2018

//Specification of ADT Binary Tree
//     Data object: a binary tree which is either empty or
//                  in the form of     r
//                                  /    \
//                                TL     TR
//                  where TL and TR are binary trees
//     Data Structure: YOU DO

//     Operations: create, destroy, insert a new node,
//                 traversals: preorder, inorder, postorder
#include <iostream>
#include "BinaryTree.h"
using namespace std;

//recursive helper
void preorderHelper(TreeNode tree[], int myroot)
{
	Item newItem;
  if (myroot != -1)
  {
    tree[myroot].getItem(newItem);
		cout << "\t" << newItem;
    preorderHelper(tree, tree[myroot].getLeftChild());
    preorderHelper(tree, tree[myroot].getRightChild());
  }
}

//recursive helper
void inorderHelper(TreeNode tree[], int myroot)
{
	Item newItem;
  if (myroot != -1)
  {
    inorderHelper(tree, tree[myroot].getLeftChild());
		tree[myroot].getItem(newItem);
		cout << "\t" << newItem;
    inorderHelper(tree, tree[myroot].getRightChild());
  }
}

//recursive helper
void postorderHelper(TreeNode tree[], int myroot)
{
	Item newItem;
  if (myroot != -1)
  {
    postorderHelper(tree, tree[myroot].getLeftChild());
    postorderHelper(tree, tree[myroot].getRightChild());
		tree[myroot].getItem(newItem);
		cout << "\t" << newItem;
  }
}


//creates an empty binary tree
//post an empty BinaryTree object exists
BinaryTree::BinaryTree()
{
    root = -1;
    numberOfItems = 0;
}

//releases a binary tree
//pre a BinaryTree object exists
//post the BinaryTree object no longer exists

BinaryTree::~BinaryTree()
{
    root = -1;
    numberOfItems = 0;
}

//inserts a new node into a binary tree
//pre BinaryTree object exists. newItem, left, right are assigned
//post a node containing newItem with children left and right
//     has been added to the BinaryTree object
//usage tree.insert(myItem, 1, 2);
void BinaryTree::insert(const Item& newItem, int left, int right)
{
    if (numberOfItems < MAXITEMS)
    {
      if (root == -1)
        root = 0;
      binaryTree[numberOfItems].setNode(newItem, left, right);
      numberOfItems++;
    }
}

//performs a Pre-Order traversal of a binary tree
//pre BinaryTree object exists
//post the items of the BinaryTree object are printed in Pre-Order
//     with items separated by a semi-colon
//     There is a newline after the last one
//usage tree.preorder();
void BinaryTree::preorder()
{
    preorderHelper(binaryTree, 0); // this line is not correct
    cout << endl;
}

//performs an In-Order traversal of a binary tree
//pre BinaryTree object exists
//post the items of the BinaryTree object are printed in In-Order
//     with items separated by a semi-colon
//     There is a newline after the last one
//usage tree.inorder();
void BinaryTree::inorder()
{
    inorderHelper(binaryTree, 0); // this line is not correct
    cout << endl;
}

//performs a Post-Order traversal of a binary tree
//pre BinaryTree object exists
//post the items of the BinaryTree object are printed in Post-Order
//     with items separated by a semi-colon
//     There is a newline after the last one
//usage tree.postorder();
void BinaryTree::postorder()
{
    postorderHelper(binaryTree, 0); // this line is not correct
    cout << endl;
}
