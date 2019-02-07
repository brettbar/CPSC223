// Brett Barinaga, Hunter Congress
// 2/23/2018
// Clientprogram.cpp
// Description: This clientprogram will open an input file, read off nodes, populate
// a binary tree with said nodes, and will print a diagram representing the tree.
// It will also print out the trees in a preorder fashion, and inorder fashion,
// and a postorder fashion.

#include <iostream>
#include <fstream>
#include <cstdlib>

#include "Item.h"
#include "BinaryTree.h"

using namespace std;

// opens an input file
// pre: infile is not opened
// post: infile has been opened or program has
//		 exited due to error.
// usage: openInputFile(infile);
void openInputFile(ifstream& infile);

// takes the input file and reads one tree node from input file
// pre: infile must be open
// 		infile's pointer is as the beginning of a line
// 		the item is on a line
// 		the next line are two integers representing children
// 		Example:
// 		1111111 Alli F
// 		1 2
// post: reads newItem, left, and right from infile
// 		 infile's pointer is after the newline following the 2nd integer
// usage: readOneTreeNode(infile, someItem, leftChild, rightChild);
void readOneTreeNode(ifstream& infile, Item& newItem, int& left, int& right);

// reads an entire tree
// pre: infile is open
// 		infile's pointer is before the first integer
//		the first line has the number of nodes to be read
// 		infile has next item on a line
// 		the next line are the two integers for the children
// 		then the next item is on a line
// 		the next line are the two integers for the children
//		Example:
//		2
// 		1111111 Alli F
// 		1 2
// 		2222222 Drew B
// 		2 -1
// post: the tree will be populated with data from infile
// 		infile's pointer is left after the newline following the last set of children
// usage: readTreeNodesAndInsert(infile, tree);
void readTreeNodesAndInsert(ifstream& infile, BinaryTree& tree);

// prints header and binary tree diagram for first tree
// pre: binary tree has a defined height
// post: header is printed with height and diagram of tree
// usage: printTopFirstTree(height);
void printTopFirstTree(int height);

// prints header and binary tree diagram for second tree
// pre: binary tree has a defined height
// post: header is printed with height and diagram of tree
// usage: printTopSecondTree(height);
void printTopSecondTree(int height);

// prints binary tree in three traversal orders, preorder, inorder, and postorder
// pre: tree is populated with nodes
// post: tree is printed in preorder fashion, inorder fashion, and postorder fashion
// usage printTree(tree);
void printTree(BinaryTree& tree);

int main()
{
  ifstream infile;
  BinaryTree treeA, treeB;

  openInputFile(infile);

  readTreeNodesAndInsert(infile, treeA);
  readTreeNodesAndInsert(infile, treeB);

  printTopFirstTree(3);
  printTree(treeA);

  printTopSecondTree(4);
  printTree(treeB);

  return 0;
}

// opens an input file
// pre: infile is not opened
// post: infile has been opened or program has
//		 exited due to error.
// usage: openInputFile(infile);
void openInputFile(ifstream &infile)
{
    infile.open("Input.dat");
    if (infile.fail())
    {
        cout << "ERROR in opening Input.dat!!!" << endl;
        exit(1);
    }
}

// takes the input file and reads one tree node from input file
// pre: infile must be open
// 		infile's pointer is as the beginning of a line
// 		the item is on a line
// 		the next line are two integers representing children
// 		Example:
// 		1111111 Alli F
// 		1 2
// post: reads newItem, left, and right from infile
// 		 infile's pointer is after the newline following the 2nd integer
// usage: readOneTreeNode(infile, someItem, leftChild, rightChild);
void readOneTreeNode(ifstream& infile, Item& newItem, int& left, int& right)
{
  char newLine;

  infile >> newItem;
  infile >> left;
  infile >> right;
  infile.get(newLine);
}

// reads an entire tree
// pre: infile is open
// 		infile's pointer is before the first integer
//		the first line has the number of nodes to be read
// 		infile has next item on a line
// 		the next line are the two integers for the children
// 		then the next item is on a line
// 		the next line are the two integers for the children
//		Example:
//		2
// 		1111111 Alli F
// 		1 2
// 		2222222 Drew B
// 		2 -1
// post: the tree will be populated with data from infile
// 		infile's pointer is left after the newline following the last set of children
// usage: readTreeNodesAndInsert(infile, tree);
void readTreeNodesAndInsert(ifstream& infile, BinaryTree& tree)
{
  int numberOfNodes;
  char newLine;
  Item newItem;
  int left, right;

  infile >> numberOfNodes;
  infile.get(newLine);
  for (int i = 0; i < numberOfNodes; i++)
  {
    readOneTreeNode(infile, newItem, left, right);
    tree.insert(newItem, left, right);
  }
}

// prints header and binary tree diagram for first tree
// pre: binary tree has a defined height
// post: header is printed with height and diagram of tree
// usage: printTopFirstTree(height);
void printTopFirstTree(int height)
{
  Item currentItem;
  cout << "A Full Tree of Height " << height << endl;

  cout << "                      111-1111 Robert Plant           " << endl;
  cout << "                     /                      \\                 " << endl;
  cout << "          2222222 Jimmy Page                  5555555 John PaulJones " << endl;
  cout << "          /             \\                       /                 \\ " << endl;
  cout << "3333333 Jon Bonham      4444444 Geddy Lee  6666666 Alex Lifeson     7777777 Neil Pertt" << endl;
  cout << endl;
}

// prints header and binary tree diagram for second tree
// pre: binary tree has a defined height
// post: header is printed with height and diagram of tree
// usage: printTopSecondTree(height);
void printTopSecondTree(int height)
{
  Item currentItem;
  cout << "A Degenerate Tree of Height " << height << endl;

  cout << "                           123-4567 John Lennon          " << endl;
  cout << "                           /                              " << endl;
  cout << "                765-4321 George Harrison                  " << endl;
  cout << "                   /                                         " << endl;
  cout <<   "          867-5309 Ringo Starr                              " << endl;
  cout << "                 /                                         " << endl;
  cout<< "    180-0588 Paul Macartney                                 " << endl;
  cout << endl;
}

// prints binary tree in three traversal orders, preorder, inorder, and postorder
// pre: tree is populated with nodes
// post: tree is printed in preorder fashion, inorder fashion, and postorder fashion
// usage printTree(tree);
void printTree(BinaryTree& tree)
{
  cout << "Preorder Traversal: " << endl << endl;
  tree.preorder();
  cout << "Inorder Traversal: " << endl << endl;
  tree.inorder();
  cout << "Postorder Traversal: " << endl << endl;
  tree.postorder();
}



































//
