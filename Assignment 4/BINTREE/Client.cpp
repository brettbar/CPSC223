// Client.cpp

#include <iostream>
#include <fstream>

using namespace std;

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

int main()
{
  ifstream infile;
  openInputFile(infile);
}

void openInputFile(ifstream& infile)
{
  infile.open("Input.dat");
  if (infile.fail())
  {
    cout << "ERROR in opening Input.dat !!!" << endl;
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
  infile.get(newline);
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


















//
