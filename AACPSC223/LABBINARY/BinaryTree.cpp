//file BinaryTree.cpp
//author and
//date

//data object: a binary tree which is YOU DO
//data structure: a linked binary tree
//operations: YOU DO

#include "BinaryTree.h"
#include <iostream>
using namespace std;

// ***************** recursive helpers *****************

//Copies one binary tree to another
//pre oldtreep points to the root of a binary tree
//post: newtreep points to the root of a binary tree
//  that has copies of the nodes of oldtreep's tree
//usage: copyTree (newptr, oldptr);
void copyTree (TreeNode*& newtreep, TreeNode* oldtreep) throw (Exception)
{
	if (newtreep != nullptr)
	{
		destroyTree(newtreep);
	}
	if (oldtreep == nullptr)
		newtreep = nullptr;
	else
	{
		newtreep = new (nothrow) TreeNode(oldtreep -> item, nullptr, nullptr);
		if (newtreep == nullptr)
		{
			throw Exception("operator=: no space in the heap!!!");
		}
		copyTree(newtreep -> leftChild, oldtreep -> leftChild);
		copyTree(newtreep -> rightChild, oldtreep -> rightChild);
	}
}

//Releases memory for a binary tree
//pre: treep points to the root of a binary tree
//post: releases all of the nodes in the tree pointed to by treep
//    and leaves treep empty.
//usage: destroyTree (mroot);
void destroyTree (TreeNode*& treep)
{
	if (treep != nullptr)
	{
		destroyTree(treep -> leftChild);
		destroyTree(treep -> rightChild);
		delete treep;
		treep = nullptr;
	}
}

// recursive helper for prettyDisplay. You do the doc
void writePretty (TreeNode* treep, int level)
{
}

// ********** recursive helpers for the traversals ****************
//pre: treep points to the root of a binary tree to be traversed
//post: prints the item objects in the nodes on the screen in the
//     specified order. the items are separated by commas
//usage: preorder (mroot);
//       similarly for the others
void preorder (TreeNode* treep)
{
	if (treep != nullptr)
	{
		cout << treep -> item;
		preorder(treep -> leftChild);
		preorder(treep -> rightChild);
	}
}

void inorder (TreeNode* treep)
{
	if (treep != nullptr)
	{
		inorder(treep -> leftChild);
		cout << treep -> item;
		inorder(treep -> rightChild);
	}
}


void postorder (TreeNode* treep)
{
	if (treep != nullptr)
	{
		postorder(treep -> leftChild);
		postorder(treep -> rightChild);
		cout << treep -> item;
	}
}

// **************************public methods************************


//creates an empty binary tree
//post: object is an empty binary tree
//usage: BinaryTree zags;
BinaryTree::BinaryTree()
{
   root = nullptr;
}

//creates a new binary tree that is a copy of an existing tree
//post: object is a copy of rightHandSideTree
//throws an exception if there is not enough room in the
//       heap to make the copied tree
//usage: BinaryTree zags (bulldog);
BinaryTree::BinaryTree(const BinaryTree& rightHandSideTree) throw (Exception)
{
   root = nullptr;
   copyTree(root, rightHandSideTree.root);
}

//releases the memory of a binary tree
//pre: object exists
//post: memory for the object has been released. object theoretically does not exist
//       but in practice, it is empty.
BinaryTree::~BinaryTree()
{
   destroyTree(root);
}

// ******************** member functions ********************************************
//@pre: binary tree object exists
// **********************************************************************************

//checks for an empty tree
//post: returns true if the object is empty; else returns false
//usage: if (tree.isEmpty())
bool BinaryTree::isEmpty() const
{
   return (root == nullptr);
}

//copies one tree to another
//pre: rightHandSideTree is an assigned tree.
//post: object is a copy of rightHandSideTree
//throws an exception if there is not enough room in the
//       heap to make the copied tree
//usage: atree = btree = ctree;
BinaryTree& BinaryTree::operator=(const BinaryTree& rightHandSideTree) throw (Exception)
{



}

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
void BinaryTree::prettyDisplay()
{
}

// *************** on the following traversals

//post: prints the objects in the tree in order specified
//usage: tree.preorderTraverse();
//similarly for the other traversals
// *****************************************************
void BinaryTree::preorderTraverse ()
{
   preorder(root);
}

void BinaryTree::inorderTraverse ()
{
}


void BinaryTree::postorderTraverse(){
}

//makes a full binary tree of height 2
//pre input is either cin or an open file
//    input's pointer is before the first item
//post: object is a full binary tree of height 2
//throws an exception if there is not enough room in the
//       heap to make the tree
//usage: YOU DO
void BinaryTree::makeTreeOne(istream& input) throw (Exception)
{
	Item newguy;

	input >> newguy;
	root = new (nothrow) TreeNode(newguy, nullptr, nullptr);
	if (root == nullptr)
	{
		throw Exception ("makeTreeOne: no room in the heap");
	}
	input >> newguy;
	root -> leftChild = new (nothrow) TreeNode(newguy, nullptr, nullptr);
	if (root -> leftChild == nullptr)
	{
		throw Exception ("makeTreeOne: no room in the heap");
	}
	input >> newguy;
	root -> rightChild = new (nothrow) TreeNode(newguy, nullptr, nullptr);
	if (root -> rightChild == nullptr)
	{
		throw Exception ("makeTreeOne: no room in the heap");
	}
}

//makes a complete but not full binary tree of height 3
//YOU FINISH
//throws an exception if there is not enough room in the
//       heap to make the tree
void BinaryTree::makeTreeTwo(istream& input) throw (Exception)
{
}

void searchHelper(TreeNode* treep, const Key& targetPhone, Item& anItem, bool& isFound)
{
	if (treep != nullptr)
	{
		if (targetPhone == treep -> item)
		{
			anItem = treep -> item;
			isFound = true;
		}
		else
		{
			searchHelper(treep -> leftChild, targetPhone, anItem, isFound)
			searchHelper(treep -> rightChild, targetPhone, anItem, isFound)
		}

	}
}

// Added for Lab 5, not to be in assignment 5
void BinaryTree::search(const Key& targetPhone, Item& anItem, bool& isFound)
{
	searchHelper(root, targetPhone, anItem, isFound);
}
