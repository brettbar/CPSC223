// Specification of ADT Binary Search Tree
//    Data object: A binary search tree T that is either empty or in the form
//                                     r
//                                  /    \
//                                TL     TR
//                  where TL and TR are binary trees and where TL < r < TR
//    Operations: (a scaled-down version)
//       create, destroy, copy, operator=,
//       traversals (preorder, inorder, postorder)
// Contract: Assumes the this class can access private data members of class Node.
//    Those data members are: Item item, Node* leftptr, Node* rightptr.
//    There is a constructor that allows caller to give item, left and right ptrs.
//
#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H

#include "BinaryTree.h"

using namespace std;

class BinarySearchTree : public BinaryTree

{
public:

// constructs the Binary Search Tree by
// initializing the number of items to 0;
// pre: BinarySearchTree object doesn't exist
// post: SearchTree object exists and numberOfItems = 0
// usage: BinarySearchTree mytree;
BinarySearchTree();

//releases the memory of a binary search tree
//pre: object exists
//post: memory for the object has been released.
~BinarySearchTree();
	 
// search the tree for a phone number
// pre: treep is a treeNode, targetPhone is a phoneNumber, anItem is empty
// post: anItem is assigned to the found Item, otherwise an exception is thrown
// usage: mytree.search(targetPhone, anItem);
void search (const Key& targetPhone, Item& theItem) throw (Exception);

// inserts an item into the tree
// pre: anItem an item waiting to be inserted into the tree
// post: anItem has been inserted into the tree
// usage: mytree.search(anItem);
void insert (const Item& newItem) throw (Exception);
	 
// traverses the tree in inorder and prints to the output
// includnig the number of items at the top
// pre: output is opened for outputing
// post: output contains the items in inorder
// usage: mytree.inorderTraverse(output);
void inorderTraverse(ostream& output);

// prints out the tree in a pretty display format
// post: the tree is printed out to the console
// usage: mytree.prettyDisplay();
void prettyDisplay();

// rebalances the tree by saving it and then making it more optimal for searching
// pre: mytree exists, infile and outfile are to be opened for reading and outputing
// post: mytree is now optimized, and the outfile contains the items in order
// usage: mytree.rebalanceTree(mytree, infile, outfile);
void rebalanceTree(ofstream& outfile);
	
protected:
    int numberOfItems;

};

#endif
