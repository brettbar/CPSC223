// Implementation of Binary Search Tree
//		abstract definition
//
//
//		data structure: a linked binary tree

#include <iostream>
#include <fstream>
#include "BinarySearchTree.h"

// helps to search the tree for a phone number
// pre: treep is a treeNode, targetPhone is a phoneNumber, anItem is empty
// post: anItem is assigned to the found Item, otherwise an exception is thrown
// usage: searchHelper(treep, targetPhone, anItem);
void searchHelper (TreeNode* treep, const Key& targetPhone, Item& anItem) throw (Exception)
{
	if (treep == nullptr)
	{
        throw Exception("Sorry, we were unable to find that phone number in the dictionary.");
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

// helps to insert an item into the tree
// pre: anItem an item waiting to be inserted into the tree
// post: anItem has been inserted into the tree
// usage: insertHelper(treep, newItem, itemCount);
void insertHelper(TreeNode*& treep, const Item& newItem, int& itemCount) throw (Exception)
{
    if (treep == nullptr)
    {
        treep = new (nothrow) TreeNode(newItem, nullptr, nullptr);
        itemCount++;
        if (treep == nullptr)
        {
            throw Exception("Error: There is no more room in the dictionary for another item");
        }
    }
    else if (newItem == treep -> item)
    {
        throw Exception("Error: This phone number is already in the dictionary");
    }
    else if (newItem < treep -> item)
    {
        insertHelper(treep -> leftChild, newItem, itemCount);
    }
    else
    {
        insertHelper(treep -> rightChild, newItem, itemCount);
    }
}

// helps to traverses the tree in inorder and prints to the output
// pre: treep exists
// post: each item of the tree has been printed out
// usage: inorderHelper(treep);
void inorderHelper(TreeNode* treep)
{
    if (treep != nullptr)
    {
        inorderHelper(treep -> leftChild);
        cout << treep -> item;
        inorderHelper(treep -> rightChild);
    }
}

// helps to print out the tree in a pretty display format
// pre: treep is a treeNode and level is the treeNode level
// post: the tree is printed out to the console
// usage: writePrettyNumbers(treep, level);
void writePrettyNumbers (TreeNode* treep, int level)
{
    if (treep != nullptr)
    {
        Key akey;
        writePrettyNumbers(treep -> rightChild, level + 1);
        if (treep -> rightChild != nullptr)
        {
            for (int i = 0; i < level; i++)
            {
                cout << "        ";
            }
            cout << "/" << endl;
        }
        if (level == 1)
        {
            cout << "root -> ";
        }
        else
        {
            for (int i = 0; i < level - 1; i++)
            {
                cout << "        ";
            }
        }
        akey = treep -> item;
        cout << akey << endl;
        if (treep -> leftChild != nullptr)
        {
            for (int i = 0; i < level; i++)
            {
                cout << "        ";
            }
            cout << "\\" << endl;
            writePrettyNumbers(treep -> leftChild, level + 1);
        }
    }
}

// helps to rebalance the tree by reading it in using an algorithm
// pre: infile has been opened, treep is a treeNode
// post: an optimized tree has been created
// usage: readTree(infile, treep, itemCount);
void readTree(ifstream& infile, TreeNode*& treep, int itemCount)
{
    if (itemCount > 0)
    {
        treep = new TreeNode();
        readTree(infile, treep -> leftChild, itemCount / 2);
        infile >> treep -> item;
        readTree(infile, treep -> rightChild, (itemCount - 1) / 2);
    }
}

// constructs the Binary Search Tree by
// initializing the number of items to 0;
// pre: BinarySearchTree object doesn't exist
// post: SearchTree object exists and numberOfItems = 0
// usage: BinarySearchTree mytree;
BinarySearchTree::BinarySearchTree()
{
    numberOfItems = 0;
}

//releases the memory of a binary search tree
//pre: object exists
//post: memory for the object has been released.
BinarySearchTree::~BinarySearchTree()
{

}

// search the tree for a phone number
// pre: treep is a treeNode, targetPhone is a phoneNumber, anItem is empty
// post: anItem is assigned to the found Item, otherwise an exception is thrown
// usage: mytree.search(targetPhone, anItem);
void BinarySearchTree::search (const Key& targetPhone, Item& theItem) throw (Exception)
{
    searchHelper(root, targetPhone, theItem);
}

// inserts an item into the tree
// pre: anItem an item waiting to be inserted into the tree
// post: anItem has been inserted into the tree
// usage: mytree.search(anItem);
void BinarySearchTree::insert (const Item& newItem) throw (Exception)
{
    insertHelper(root, newItem, numberOfItems);
}

// traverses the tree in inorder and prints to the output
// includnig the number of items at the top
// pre: output is opened for outputing
// post: output contains the items in inorder
// usage: mytree.inorderTraverse(output);
void BinarySearchTree::inorderTraverse (ostream& output)
{
    output << numberOfItems << endl;
    BinaryTree::inorderTraverse();
}

// prints out the tree in a pretty display format
// post: the tree is printed out to the console
// usage: mytree.prettyDisplay();
void BinarySearchTree::prettyDisplay()
{
    writePrettyNumbers(root, 1);
}

// destroys the nodes in the tree
// pre: treep nodes exists
// post: all nodes are deleted
// usages: destroyTreeNodes(treep);
void destroyTreeNodes(TreeNode*& treep)
{
    if (treep != nullptr)
    {
        destroyTreeNodes(treep -> leftChild);
        destroyTreeNodes(treep -> rightChild);
        delete treep;
        treep = nullptr;
    }
}

// rebalances the tree by saving it and then making it more optimal for searching
// pre: mytree exists, infile and outfile are to be opened for reading and outputing
// post: mytree is now optimized, and the outfile contains the items in order
// usage: mytree.rebalanceTree(mytree, infile, outfile);
void BinarySearchTree::rebalanceTree(ofstream& outfile)
{
    ifstream infile;
    infile.open("Dictionary.dat");
    char newLine;
    int itemCount;
    infile >> itemCount;
    infile.get(newLine);
    destroyTreeNodes(root);
    readTree(infile, root, itemCount);
}
