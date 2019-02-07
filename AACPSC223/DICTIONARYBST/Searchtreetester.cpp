//  Brett Baringa
//  Hunter Congress
//  SearchtreeTester.cpp
//  Data Structures 223
//  A tester class to test insert, display, find, and print


#include "BinarySearchTree.h"
#include "Exception.h"
#include <string>
#include <fstream>

using namespace std;

//opens an input file with a chosen name
//pre filename is assigned
//post if filename exists in the same directory as the program, it is opened
//      with its file pointer at the beginning of the file
//      else an error message is printed
//usage OpenInputFile(infile, filename);
void OpenInputFile(ifstream& inputFile, string filename);

//prints an exception message
//pre except has been thrown
//post except is printed to the screen with two newlines before and after
//usage PrintExceptionMessage(except);
void PrintExceptionMessage(const Exception& except);

//makes a binary tree
//pre file is open and tree is constructed
// post makes search tree with inorder
//usage makeTree(inputFile, tree)
void makeTree(ifstream& inputFile, BinarySearchTree& tree);

//inserts a file an item to the tree
//pre a binary search tree needs to be constructed
//post takes an item and inserts into an appropriate spot in the tree
//usage insertToDictionary(tree)
void insertToDictionary(BinarySearchTree& tree);

// it will search the tree to find the item
//pre a binary search tree needs to be constructed and filled
// post it will find a person by using a the phone number
//usage findName(tree)
void findName(BinarySearchTree& tree);

//prints out a binary search tree
// pre a binary search tree must be constructed and filled
// post will be a 90 degree turn of a binary search tree
//							6781254
//							/
//				root -> 7601234
//							\
//							8941765
//usage printBST(tree)
void printBST(BinarySearchTree& tree);

//prints out all the items
//pre a tree must be constructed and filled
//post it will list all the items in inorder
//Ex.		745-4345 Phil Colins
//			565-1326 Bon Jovi
//			145-7658 Doug Dylans
//usage	listItems(tree)
void listItems(BinarySearchTree& tree);
int main()
{
	ifstream infile;
	OpenInputFile(infile, "Dictionary.dat");
	BinarySearchTree myBST;
	try
	{
		makeTree(infile, myBST);
		listItems(myBST);
		insertToDictionary(myBST);
		printBST(myBST);
		findName(myBST);
		printBST(myBST);
		listItems(myBST);
	}
	catch (Exception except)
	{
		PrintExceptionMessage(except);
	}
  return 0;
}


//opens an input file with a chosen name
//pre filename is assigned
//post if filename exists in the same directory as the program, it is opened
//      with its file pointer at the beginning of the file
//      else an error message is printed
//usage OpenInputFile(infile, filename);
void OpenInputFile(ifstream& inputFile, string filename)
{
   inputFile.open(filename);
   if (inputFile.fail())
   {
      cout << "File failed to open!!!!" << endl;
      exit(1);
   }
}

//prints an exception message
//pre except has been thrown
//post except is printed to the screen with two newlines before and after
//usage PrintExceptionMessage(except);
void PrintExceptionMessage(const Exception& except)
{
   cout << endl << endl;
   cout << except.What();
   cout << endl << endl;

}
//makes a binary tree
//pre file is open and tree is constructed
// post makes search tree with inorder
//usage makeTree(inputFile, tree)
void makeTree(ifstream& inputFile, BinarySearchTree& tree)
{
	int numberOfItems = 0;
	char newline;
	Item newItem;


	inputFile >> numberOfItems;
	inputFile.get(newline);

	for(int i = 0; i < numberOfItems; i++)
	{
		inputFile >> newItem;
		tree.insert(newItem);
	}

}
//inserts a file an item to the tree
//pre a binary search tree needs to be constructed
//post takes an item and inserts into an appropriate spot in the tree
//usage insertToDictionary(tree)
void insertToDictionary(BinarySearchTree& tree)
{
	Item theItem;
	cout << "Please enter a 7 digit phone number and then a name. (example 1234567 jane doe) > ";
	cin >> theItem;
	tree.insert(theItem);
	cout << "The contact has been stored..." << endl;
}

// it will search the tree to find the item
//pre a binary search tree needs to be constructed and filled
// post it will find a person by using a the phone number
//usage findName(tree)
void findName(BinarySearchTree& tree)
{
	Key targetKey;
	Item theItem;
	cout << "Please enter a 7 digit phone number to search for (example 1234567 jane doe) > ";
	cin >> targetKey;
	tree.search(targetKey, theItem);
}

//prints out a binary search tree
// pre a binary search tree must be constructed and filled
// post will be a 90 degree turn of a binary search tree
//	Ex.						6781254
//							/
//				root -> 7601234
//							\
//							8941765
//usage printBST(tree)
void printBST(BinarySearchTree& tree)
{
	tree.prettyDisplay();
}

//prints out all the items
//pre a tree must be constructed and filled
//post it will list all the items in inorder
//Ex.		745-4345 Phil Colins
//			565-1326 Bon Jovi
//			145-7658 Doug Dylans
//usage	listItems(tree)
void listItems(BinarySearchTree& tree)
{
	tree.BinaryTree::inorderTraverse();
}
