// Specification of ADT 2-3-4 Tree Node
//    data object: a node in a 2-3-4 Tree
//        contains room for 1-3 data items (just using keys)
//        contains room for 0-4 children
//    operations: several creates, destroy,
//       cleanUpNode,
// Built on class Key

// This class will be used by class Two34Tree.
//     All members are public to give Two34Tree access.
// Alternatively, we could make Two34Tree a friend class
//     of this class and all members would be private.
// Programmer: dr y    Date: April 21, 2003
// Filename: Two34TreeNode.h

#ifndef TWO34TREENODE_H
#define TWO34TREENODE_H

#include "Key.h"
#include <cstdlib>
#include <cstddef>

class Two34TreeNode
{
public:
   // Creates an empty node
   // post: node object is empty
   // usage: Two34TreeNode node;
   Two34TreeNode ();

   // Creates a leaf node with one item
   // pre: newKey is assigned.
   // post: newKey is in a 2-3-4 Tree Node with empty children
   // usage: root = new Two34TreeNode (newKey);
   Two34TreeNode (const Key& newKey);

   // Creates a non-leaf 2-node
   // pre: newKey, left and right are assigned
   // post: newKey is in a 2-3-4 Tree Node (like a binary tree)
   //       with children left and right
   // usage: mroot = new Two34TreeNode (newKey, leftchild, rightchild);
   Two34TreeNode (const Key& newKey,
		      Two34TreeNode* left, Two34TreeNode* right);

   // Destroys a node
   // pre: node exists
   // post: node does not exist
   // usage: automatically called at the end of scope
   ~Two34TreeNode();

   // Cleans up a node to become a 2-node
   // pre: the node exists with an item
   //    in leftmost position and left,right children
   //    in leftmost positions and others
   // Calls emptyIt from citem
   // post: the node's two data rightmost positions
   //    have been emptied and two rightmost children
   //    have been given away by social services.
   // usage: treep->cleanUpNode();
   void cleanUpNode();

   // data members
   Key keys[3]; // 1-3 data keys in a node
   Two34TreeNode* kids[4]; // 2-4 children of a node
};
#endif
