// Implementation of Binary Search TreeNode
//    abstract definition
//
//
//    data structure: a linked binary tree

#include "BinarySearchTree.h"


// ************** Recursive Helpers******************
void searchHelper(TreeNode* treep, const Key& targetPhone, Item& anItem) throw (Exception)
{
	if (treep == nullptr)
	{
		throw ("Not found");
	}
	else if (targetPhone == treep -> item)
	{
		anItem = treep -> item;
	}
	else if (targetPhone < treep -> item)
	{
		searchHelper(treep -> leftChild, targetPhone, anItem);
	}
	else
	{
		searchHelper(treep -> rightChild, targetPhone, anItem);
	}
}

void insertHelper(TreeNode* &treep, const Item& newItem, int& numberOfEntries) throw (Exception)
{
	if (treep == nullptr)
	{
		treep = new (nothrow) TreeNode(newItem, nullptr, nullptr);
		numberOfEntries++;
		if (treep == nullptr) throw Exception("no room in the heap");
	}
	else if (newItem == treep -> item)
		throw Exception("insert: phone number is already in Dictionary");
	else if (newItem < treep -> item)
		insertHelper(treep -> leftChild, newItem, numberOfEntries);
	else
		insertHelper(treep -> rightChild, newItem, numberOfEntries);
}


void inorder(TreeNode* treep, ofstream& output, int count)
{
	if (count == 1)
	{
		output << numberOfEntries << endl;
	}
	if (treep != nullptr)
	{
		inorder(treep -> leftChild, count++);
		output << treep -> item;
		inorder(treep -> rightChild, count++);
	}
}

///////////////////////////////////////////////////////////////
BinarySearchTree::BinarySearchTree()
{
	numberOfEntries = 0;
}

BinarySearchTree::~BinarySearchTree()
{
	// Inherits destructor from BinaryTree
}


BinarySearchTree::BinarySearchTree(const BinarySearchTree& rhsBinarySearchTree)
{
 	// Inherits copy constructor from BinaryTree
}

// we get operator=, traversals for free

// new operators: search, remove, insert

void BinarySearchTree::search(const Key& targetPhone, Item& theItem) throw (Exception)
{
	searchHelper(root, targetPhone, theItem);
}

void BinarySearchTree::insert(const Item& newItem) throw (Exception)
{
	insertHelper(root, newItem, numberOfEntries);
}

void BinarySearchTree::remove(const Key& targetPhone) throw (Exception)
{

}

void BinarySearchTree::inorderTraverse()
{
	inorder(root, output, 1);
}
