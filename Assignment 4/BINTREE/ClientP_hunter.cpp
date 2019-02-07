#include <fstream>
#include <iostream>
#include <cstdlib>

#include "Item.h"
#include "BinaryTree.h"

using namespace std;

// opens an input file
// pre: unopened file
// post: file has been opened or program has
//		 exited due to error.
// usage: openInputFile(input);
void openInputFile(ifstream &infile)
{
    infile.open("Input.dat");
    if (infile.fail())
    {
        cout << "ERROR in opening Input.dat!!!" << endl;
        exit(1);
    }
}
// reads one Node from file
// pre: an item with inputs for left and right
// post: inserts into a tree
// usage: readOneTreeNode(item,left,right);
void readOneTreeNode(ifstream &infile, Item& newItem, int& left, int& right)
{
	char newLine;

	infile >> newItem;
	infile >> left;
	infile >> right;
	infile.get(newLine);


}
// reads multiple Node from file and inserts them into tree
// pre: needs file with multiple nodes and left and right indicators
// post: reads file and inserts to tree
// usage: readTreeNodesAndInsert(input, tree);
void readTreeNodesAndInsert(ifstream &infile, BinaryTree& tree)
{
	int numberOfNodes;
	char newLine;
	Item newItem;
	int left, right;

	infile >> numberOfNodes;
	infile.get(newLine);

	for(int i = 0; i < numberOfNodes; i++)
	{
		readOneTreeNode(infile, newItem, left, right);
		tree.insert(newItem, left, right);

	}

}
// prints out the array in the tree in three different orders: preorder,inorder,and postorder
// pre: takes in a tree
// post:
// usage: readTreeNodesAndInsert(tree);
void printArray(BinaryTree& tree)
{
 		cout << tree.preorder() << endl << endl;
		cout << tree.inorder() <<endl << endl;
		cout << tree.postorder() << endl< <endl;
}
// inserts input file into dictionary
// pre: empty dictionary
// post: dictionary is populated with items from input file
// usage: insertItems(inputFile, dictionary);


int main()
{
    ifstream infile;
	openInputFile(infile);
	BinaryTree treeA, treeB;
	readTreeNodesAndInsert(Input.dat,treeA);
	readTreeNodesAndInsert(Input.dat,treeB);
	cout << printArray(treeA) << endl;
	cout< < printArray(treeB) << endl;



    return 0;
}
