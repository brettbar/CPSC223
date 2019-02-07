// Brett Barinaga, Kevin Mattappally
// 4/14/2018
// AVLTree.cpp
//   Implementation of ADT AVLTree
//   Data object: An AVLtree is a binary search tree, that is is either empty or in the form
//                where T is an AVLTree
//                                     r
//                                  /    \
//                                TL     TR
//             where the |height of TR – height of TL| <= 1 and TL, TR are AVL trees.
//  Data Structure: linked binary tree
//  Operations: insert and make search path, insert, fixbalances, writePretty,
//              various rotations


#ifndef AVLTREE_H
#define AVLTREE_H

#include "BinarySearchTree.h"
#include "Exception.h"
#include "TreeNode.h"
#include "Item.h"

class AVLTree: public BinarySearchTree
{
public:

AVLTree(); //inherited from BST

~AVLTree();//inherited from BST

// Inserts a newItem into the AVLTree, fixing the AVLTree with various
// methods when needed, and fixes Tree balances.
// Pre: An AVLTree exists, and a newItem is passed
// Post: A node is inserted into the tree, and the tree is rotated if needed
//      and the balances are fixed.
// usage myAVLTree.insert(newguy);
void insert(const Item& newItem) throw (Exception);

// Prints the tree to the outfile in a readable manner
// Pre: an outfile is open, and a root exists pointing to an AVLTree
// Post: the root and AVLTree are printed in a nice manner to the outfile
// usage: myAVLTree.prettyDisplay(outfile);
void prettyDisplay(ofstream& outfile);
};
#endif
