// Michael Hepburn and Kevin Mattappally
// BINARYTREE
// 2-23-18
// Clientprogram.cpp
// dropoff using kmattappally
//
// A main class that:
// First, makes two trees by reading from a file. The first tree is a full tree
// 	of height 3. The second tree is a degenerate tree of height 4.
// Second, it prints out a sketch of the full tree, and then prints the tree out
//			in preorder, inorder, and postorder.
// Third, it prints out a sketch of the degenerate tree, and then prints the tree out
//			in preorder, inorder, and postorder.


#include <fstream>
#include <iostream>
#include <cstdlib>
#include "Item.h"
#include "BinaryTree.h"
using namespace std;

// Open the file to be read from in the main program
// pre: infile is not open to a file
// post: infile can be used to read from a file
// usage: openInputFile(infile);
void openInputFile(ifstream& infile);

// Read from a file and put the tree nodes into two different tree
// pre: infile is formatted to start with the number of things to read, then
//			a single enter character, then the phone number, a space, the first name
// 		a space, and, finally, the last name. Pattern repeats for every item.
//			This must repeat twice. Additionally, fullTree and degenerateTree should
//			be empty.
//			1
//			1111111 Some Name
//
// post: fullTree is filled with tree nodes from the first set from infile, and
//			degenerateTree is filled with tree nodes from the second set from infile.
// usage: readTwoTrees(infile, atree, btree);
void readTwoTrees(ifstream& infile, BinaryTree& fullTree, BinaryTree& degenerateTree);

// Read from a file and put the tree nodes into a tree
// pre: infile is open.
//			infile is formatted to start with the number of things to read, then
//			a single enter character, then the phone number, a space, the first name
// 		a space, and, finally, the last name. Pattern repeats for every item.
//			1
//			1111111 Some Name
//
//			Additionally, theTree should be empty.
//
// post: theTree is filled with tree nodes from infile.
//			infile's pointer is left after the newline following the last set of children.
// usage: readTreeNodesAndInsert(infile, someTree);
void readTreeNodesAndInsert(ifstream& infile, BinaryTree& theTree);

// Read a single item with left and right nodes to copy to a tree from a file
// pre: infile is open.
//			infile is formatted to start with the phone number, a space, the first name
// 		a space, and, finally, the last name.
// post: newItem has an item, left can indicate the left child, and right can
// 		indicate the right child.
//			infile's pointer is left after the newline.
// usage: readOneTreeNode(infile, someItem, left, right);
void readOneTreeNode(ifstream& infile, Item& newItem, int& left, int& right);

// Print out a sketch of the specific full tree. Then print out that tree in preoder,
//		inorder, and postorder.
// pre: theTree should have all the values of the full tree referenced.
// post: theTree has been printed as a tree, then in the three orders
// usage: printFullTree(fullTree);
void printFullTree(BinaryTree& theTree);

// Print out a sketch of the specific full tree.
// pre: none
// post: theTree has been printed as a tree
// usage: printFullTreeSketch();
void printFullTreeSketch();

// Print out a sketch of the specific degenerate tree. Then print out that tree in preoder,
//		inorder, and postorder.
// pre: theTree should have all the values of the full tree referenced.
// post: theTree has been printed as a tree, then in the three orders
// usage: printDegenerateTree(degenerateTree);
void printDegenerateTree(BinaryTree& theTree);

// Print out a sketch of the specific degenerate tree.
// pre: none
// post: theTree has been printed as a tree
// usage: printDegenerateTreeSketch();
void printDegenerateTreeSketch();

// Print out two trees each preorder, inorder, and postorder.
// pre: fullTree and degenerateTree should have at least one node.
// post: both trees have been printed
// usage: printTwoTrees(atree, btree);
void printTwoTrees(BinaryTree& fullTree, BinaryTree& degenerateTree);

// Print out one tree in preorder, inorder, and postorder.
// pre: theTree should have at least one node.
// post: theTrees have been printed.
// usage: printTreeThreeWays(someTree);
void printTreeThreeWays(BinaryTree& theTree);


int main()
{
  	ifstream infile;
  	BinaryTree atree, btree;
  	openInputFile(infile);

  	readTwoTrees(infile, atree, btree);

	printFullTree(atree);

	printDegenerateTree(btree);

	return 0;
}


void openInputFile(ifstream& infile)
{
  	infile.open("Input.dat");
  	if(infile.fail())
    {
    	cout << "ERROR IN OPENING 'Input.dat'" ;
    	exit(1);
  	}
}

void readTwoTrees(ifstream& infile, BinaryTree& fullTree, BinaryTree& degenerateTree)
{
	readTreeNodesAndInsert(infile, fullTree);
	readTreeNodesAndInsert(infile, degenerateTree);
}

void readTreeNodesAndInsert(ifstream& infile, BinaryTree& theTree)
{
	Item newItem;
	int numberOfNodes, left, right;
	char newLine;

	infile >> numberOfNodes;
	infile.get(newLine);

	for(int i = 0; i < numberOfNodes; i++)
    {
		readOneTreeNode(infile, newItem, left, right);
		theTree.insert(newItem, left, right);
	}
}

void readOneTreeNode(ifstream& infile, Item& newItem, int& left, int& right)
{
  	char newLine;
  	infile >> newItem;
    infile >> left;
  	infile >> right;
  	infile.get(newLine);
}

void printFullTree(BinaryTree& theTree)
{
	printFullTreeSketch();
	printTreeThreeWays(theTree);
}

void printFullTreeSketch()
{
	cout << "A full list of height 3: " << endl
		<< "                                111-1111" << endl
		<< "                              Lindsey Vonn" << endl
		<< "                             /           |" << endl
		<< "                       222-2222          333-3333" << endl
		<< "                 Julia Manchuso          Picabo Street" << endl
		<< "                /            |           /           |" << endl
		<< "         444-4444         555-5555    666-6666       777-7777" << endl
		<< "        Tommy Moe   Alberto Tomba     Hermann Maier  Benjamin Raich" << endl << endl;
}

void printDegenerateTree(BinaryTree& theTree)
{
	printDegenerateTreeSketch();
	printTreeThreeWays(theTree);
}

void printDegenerateTreeSketch()
{
	cout << "A degenerate list of height 4:	" << endl
		<< "                      121-2121 Sean White" << endl
		<< "                      /" << endl
		<< "                    232-3232 Hannah Teter" << endl
		<< "                    /" << endl
		<< "                  343-4343 Torah Bright" << endl
		<< "                  /" << endl
		<< "                454-5454 Torstein Horgmo" << endl << endl;
}


void printTreeThreeWays(BinaryTree& theTree)
{
	cout << "Preorder: " << endl;
	theTree.preorder();
	cout << endl << "Inorder: " << endl;
	theTree.inorder();
	cout << endl << "Postorder: " << endl;
	theTree.postorder();
}
