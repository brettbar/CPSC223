//file BinaryTree.h
//author Dr. Y
//date october 16, 2013 mopdified on February 21, 2018

// Specification of ADT Binary Tree
//    Data object: A binary tree T that is either empty or in the form
// of a full tree of height and and complete tree of height 3
//			 r 						    r
//		   / \					   / \
//      Lc  Rc				  Lc  Rc
//								     /  \
//								    Lc   Rc
//
//  Operations: (a scaled-down version)
//       create, destroy,
//       copy one tree to another with same data members
//       operator= to use in the client program to invoke the copy function
//       traversals (preorder, inorder, postorder) to display the tree in different ways
//
// Contract: Assumes the this class can access private data members of class Node.
//    Those data members are: Item item, Node* leftptr, Node* rightptr.
//    There is a constructor that allows caller to give item, left and right ptrs.

#ifndef BINARYTREE_H
#define BINARYTREE_H

#include "TreeNode.h"
#include "Exception.h"
#include <iostream>
using namespace std;

class BinaryTree
{
public:
   //creates an empty binary tree
   //post: object is an empty binary tree
   //usage: BinaryTree zags;
   BinaryTree();

   //creates a new binary tree that is a copy of an existing tree
   //post object is a copy of rightHandSideTree
   //throws an exception if there is not enough room in the heap for
   //       an copied tree
   //usage: BinaryTree zags (bulldog);
   BinaryTree(const BinaryTree& rightHandSideTree) throw (Exception);

   //releases the memory of a binary tree
   //pre: object exists
   //post: memory for the object has been released. object theoretically does not exist
   //       but in practice, it is empty.
   ~BinaryTree();

   // ******************** member functions ********************************************
   //pre: binary tree object exists
   // **********************************************************************************
   //checks for an empty tree
   //post: returns true if the object is empty; else returns false
   //usage: if (tree.isEmpty())
   bool isEmpty() const;

   //copies one tree to another
   //pre: rhstree is an assigned tree.
   //post: object is a copy of rightHandSideTree
   //throws an exception if there is not enough room in the heap for
   //       an copied tree
   //usage: atree = btree = ctree;
   BinaryTree& operator=(const BinaryTree& rightHandSideTree) throw (Exception);

   //prints the tree to look like a computer science tree
   //post: outputs the tree as in the example below
   //
   //                        bar
   //                  foo
   //                        geeU
   //  root ->  queue
   //                        stack
   //                  list
   //                        array
   //nodes at the same level are indented the same.
   //Viewer must rotate head 90 degrees in order to look like a cs tree
   //usage: tree.prettyDisplay();
   void prettyDisplay();

   // *************** on the following traversals
   //uses: operator<< from class Item
   //post: prints the objects in the tree in order specified
   //usage: tree.preorderTraverse();
   //similarly for the other traversals
   // *****************************************************
   void preorderTraverse ();
   void inorderTraverse ();
   void postorderTraverse();

   //makes a full binary tree of height 2
   //pre input is either cin or an open file
   //post: object is a full binary tree of height 2
   //throws an exception if there is not enough room in the
   //       heap to make the tree
   //usage: tree.makeTreeOne();
   void makeTreeOne(istream& input) throw (Exception);

   //makes a complete binary tree of height 3
   //pre input is either cin or an open file
   //post: object is a complete binary tree of height 3
   //throws an exception if there is not enough room in the
   //       heap to make the tree
   //usage: tree.makeTreeTwo()
   void makeTreeTwo(istream& input) throw (Exception);

protected:

    TreeNode* root;
};
#endif
