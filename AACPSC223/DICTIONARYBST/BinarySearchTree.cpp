//file BinaryTree.cpp
//author Brett Barinaga and Hunter Congress
//date 3/27/2018

//data object: a binary search tree
//data structure: a linked binary search tree
//Operations: (a scaled-down version)
//       create, remove, and searc
//      inorder traversal to display the tree

#include "BinarySearchTree.h"
#include <fstream>

// ************** Recursive Helpers******************
void searchHelper(TreeNode* treep, const Key& targetPhone, Item& anItem) throw (Exception)
{
	if (treep == nullptr)
	{
		throw Exception("Not found");
	}
	else if (targetPhone == treep -> item)
	{
		anItem = treep -> item;
		cout << anItem << endl;
		throw Exception("Item found");
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

void readTree(TreeNode* treep, ifstream& infile, int numItems)
{
	if (numItems > 0)
	{
		treep = new (nothrow) TreeNode();
		readTree(treep -> leftChild, infile, (numItems) / 2);
		// infile >> treep -> item;
		readTree(treep -> rightChild, infile, (((numItems-1) / 2)));
	}
	else
		treep = nullptr;
}

void insertHelper(TreeNode* &treep, const Item& newItem, int& numberOfEntries) throw (Exception)
{
	if (treep == nullptr)
	{
		treep = new (nothrow) TreeNode(newItem, nullptr, nullptr);
		numberOfEntries++;
		if (treep == nullptr) throw Exception("no room in the heap");
	}
	else if (treep -> item == newItem )
		throw Exception("insert: phone number is already in Dictionary");
	else if (newItem < treep -> item)
		insertHelper(treep -> leftChild, newItem, numberOfEntries);
	else
		insertHelper(treep -> rightChild, newItem, numberOfEntries);
}

//post: prints the objects in the tree in order specified
//usage: tree.preorderTraverse();
//similarly for the other traversals
void inorder(TreeNode* treep, ofstream& output)
{
	if (treep != nullptr)
	{
		inorder(treep -> leftChild, output);
		output << (treep -> item);
		inorder(treep -> rightChild, output);
	}
}


///////////////////////////////////////////////////////////////
//creates an empty binary tree
//post: object is an empty binary tree
//usage: BinarySearchTree zags;
BinarySearchTree::BinarySearchTree()
{
	numberOfEntries = 0;
}

//releases the memory of a binary tree
//pre: object exists
//post: memory for the object has been released. object theoretically does not exist
//       but in practice, it is empty.
BinarySearchTree::~BinarySearchTree()
{
	// Inherits destructor from BinaryTree
}

//creates a new binary tree that is a copy of an existing tree
//post: object is a copy of rightHandSideTree
//throws an exception if there is not enough room in the
//       heap to make the copied tree
//usage: BinarySearchTree zags(bulldog);
BinarySearchTree::BinarySearchTree(const BinarySearchTree& rhsBinarySearchTree)
{
 	// Inherits copy constructor from BinaryTree
}

// we get operator=, traversals for free

// new operators: search, remove, insert

//looks for a contact within the tree
//pre a phone number and and an empty item
//post it will return the item through reference
//usage treeBST.search(targetPhone, theItem)
void BinarySearchTree::search(const Key& targetPhone, Item& theItem) throw (Exception)
{
	searchHelper(root, targetPhone, theItem);
}

//it will search for an item with the tree
//pre an item that has been is not empty
//post it find the correct spot based on the phone number
//		then it will create a new node
//		then places the item in that node
//usage treeBST.insert(theItem)
void BinarySearchTree::insert(const Item& newItem) throw (Exception)
{
	insertHelper(root, newItem, numberOfEntries);
}

void BinarySearchTree::remove(const Key& targetPhone) throw (Exception)
{

}

// Will traverse the binary search tree in an inorder fashion
// pre an infile exists and a binary search tree exists, as well as an open output file
// post writes binary search tree items into the output file in an inorder fashion
// usage treeBST.inorderTraverse(output,input);
void BinarySearchTree::inorderTraverse(ofstream& output, ifstream& infile)
{
	output << numberOfEntries << endl;
	inorder(root, output);
	readTree(root, infile, numberOfEntries);
}
