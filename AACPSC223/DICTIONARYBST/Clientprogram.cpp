// Brett Barinaga
// Hunter Congress
// Clientprogram.cpp
// Data Structures 223
// A main class that displays a menu with multiple options for the user to select
// the options consist of inserting, finding, printing pretty, listing, and saving of
// a binary search tree.
#include <iostream>
#include <fstream>
#include "BinarySearchTree.h"
#include "Item.h"
#include "Exception.h"

using namespace std;

//prints the menu for the user
//pre none
//post prints out a first letter of the word
//then a descriptiopn of the function
//usage printMenu();
void printMenu();

//gets the option from the user
//pre a character of the first letter of the options
//post it will print out the option selected
// 		if not the function will ask for another selection
//usage getOption(option);
char getOption();

//exits the program once user enters e
//pre a character of the first letter of the the exit otpion
//post it will exit the program
//usage isNotExit(option);
bool isNotExit(char option);

//does the option selected by the user
//pre a an input file that is defined,  an Item that is constructed, a binary search tree
//		that is constructed, and an output file that is defined
//post it will find a file target phone numbers
//		or it will insert another node into the search tree
// 		or it will list all the contacts within the treep
//		or it will print out the tree in a pretty way
// 		or it rebalnce the tree
//		or it will save the tree to a file
void doOption(char option, BinarySearchTree& tree, ifstream& infile);

//makes a binary tree
//pre file is open and tree is constructed
// post makes search tree with inorder
//usage makeTree(inputFile, tree)
void makeTree(ifstream& inputFile, BinarySearchTree& tree);


// it will search the tree to find the item
//pre a binary search tree needs to be constructed and filled
// post it will find a person by using a the phone number
//usage findName(tree)
void findName(BinarySearchTree& tree);

//inserts a file an item to the tree
//pre a binary search tree needs to be constructed
//post takes an item and inserts into an appropriate spot in the tree
//usage insertToDictionary(tree)
void insertToDictionary(BinarySearchTree& tree);

//prints out all the items
//pre a tree must be constructed and filled
//post it will list all the items in inorder
//Ex.		745-4345 Phil Colins
//			565-1326 Bon Jovi
//			145-7658 Doug Dylans
//usage	listItems(tree)
void listItems(BinarySearchTree& tree);

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

// rebalances binary search tree in inorder fashion
// pre a binary search tree must be constructed and infile must exist
// post items from binary search tree will be saved to infile
// usage rebalanceTree(tree, infile);
void rebalanceTree(BinarySearchTree& tree, ifstream& infile);

//opens an output file with a chosen name
//pre filename is assigned and binary search tree is constructed
//post if filename exists in the same directory as the program, it is opened and
//			written to the file
//      with its file pointer at the beginning of the file
//      else an error message is printed
//usage saveFile(outfile, filename, tree);
void saveToFile(ofstream& outfile, ifstream& infile, BinarySearchTree& tree);


//prints an exception message
//pre except has been thrown
//post except is printed to the screen with two newlines before and after
//usage PrintExceptionMessage(except);
void PrintExceptionMessage(const Exception& except);

//opens an input file with a chosen name
//pre filename is assigned
//post if filename exists in the same directory as the program, it is opened
//      with its file pointer at the beginning of the file
//      else an error message is printed
//usage OpenInputFile(infile, filename);
void OpenInputFile(ifstream& inputFile);

//opens an output file with a chosen name
//pre filename is assigned
//post if filename exists in the same directory as the program, it is opened
//      with its file pointer at the beginning of the file
//      else an error message is printed
//usage OpenInputFile(outputFile, filename);
void OpenOutputFile(ofstream& outputFile);



int main()
{
	ifstream infile;
	OpenInputFile(infile);

	char choice;
	choice = ' ';

	BinarySearchTree bstTree;

	makeTree(infile, bstTree);


	while(isNotExit(choice))
	{
		try
		{
			printMenu();
			choice = getOption();
			doOption(choice, bstTree, infile);
		}
		catch (Exception except)
		{
			PrintExceptionMessage(except);
		}

	}
	return 0;
}
//prints the menu for the user
//pre none
//post prints out a first letter of the word
//			then a descriptiopn of the function
//usage printMenu();
void printMenu()
{
	cout << "----------------------------------------------------------------------------------------------" << endl;
	cout <<" Your options are: " 																																	<< endl << endl;


	cout << "f  : find the name of the contact, given her/his phone number" 											<< endl;
	cout << "i  : insert a new item (phone number and name ) into the dictionary" 								<< endl;
	cout << "l  : list the items in the entire dictionary on the screen in inorder fashion" 			<< endl;
	cout << "p  : print the tree in pretty fashion (showing only the phone numbers)" 							<< endl;
	cout << "r  : rebalance the tree" 																														<< endl;
	cout << "s  : save the dictionary to the file in sorted order – inorder --  ready to be read" << endl;
	cout << "e  : exit the program which automatically does option s" 														<< endl << endl;

	cout << "Enter your option > ";
}
//gets the option from the user
//pre a character of the first letter of the options
//post it will print out the option selected
// 		if not the function will ask for another selection
//usage getOption(option);
char getOption()
{
	char option, newLine;
	cin.get(option);
	cin.get(newLine);
	return option;
}
//exits the program once user enters e
//pre a character of the first letter of the the exit otpion
//post it will exit the program
//usage isNotExit(option);
bool isNotExit(char option)
{
	if(option == 'e')
		return false;
	else
		return true;
}
//does the option selected by the user
//pre a an input file that is defined,  an Item that is constructed, a binary search tree
//		that is constructed, and an output file that is defined
//post it will find a file target phone numbers
//		or it will insert another node into the search tree
// 		or it will list all the contacts within the treep
//		or it will print out the tree in a pretty way
// 		or it rebalnce the tree
//		or it will save the tree to a file
//usage doOption(option, theItem, tree, outfile);
void doOption(char option, BinarySearchTree& tree, ifstream& infile)
{
	ofstream outfile;
	switch (option)
	{
		case 'f':
			findName(tree);
		break;

		case 'i':
			insertToDictionary(tree);
		break;

		case 'l':
			listItems(tree);
		break;

		case 'p':
			printBST(tree);
		break;

		case 'r':
			rebalanceTree(tree, infile);
		break;

		case 's':
			saveToFile(outfile, infile, tree);
		break;
		default:
		break;
	}
}

// it will search the tree to find the item
//pre a binary search tree needs to be constructed and filled
// post it will find a person by using a the phone number
//usage findName(tree)
void findName(BinarySearchTree& tree)
{
	Key targetKey;
	Item theItem;
	char newline;
	cout << "Please enter a 7 digit phone number to search for > (example 1234567) > ";
	cin >> targetKey;
	tree.search(targetKey, theItem);
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

//prints out all the items
//pre a tree must be constructed and filled
//post it will list all the items in inorder
//Ex.		745-4345 Phil Colins
//			565-1326 Bon Jovi
//			145-7658 Doug Dylans
void listItems(BinarySearchTree& tree)
{
	tree.BinaryTree::inorderTraverse();
}

//prints out a binary search tree
// pre a binary search tree must be constructed and filled
// post will be a 90 degree turn of a binary search tree
//							6781254
//							/
//				root -> 7601234
//							\
//							8941765
//usage printBST(tree)
void printBST(BinarySearchTree& tree)
{
	tree.prettyDisplay();
}

// rebalances binary search tree in inorder fashion
// pre a binary search tree must be constructed and infile must exist
// post items from binary search tree will be saved to infile
// usage rebalanceTree(tree, infile);
void rebalanceTree(BinarySearchTree& tree, ifstream& infile)
{
	ofstream outfile;
	OpenOutputFile(outfile);
	tree.inorderTraverse(outfile, infile);
}

//opens an output file with a chosen name
//pre filename is assigned and binary search tree is constructed
//post if filename exists in the same directory as the program, it is opened and
//			written to the file
//      with its file pointer at the beginning of the file
//      else an error message is printed
//usage saveFile(outfile, filename, tree);
void saveToFile(ofstream& outfile, ifstream& infile, BinarySearchTree& tree)
{
	OpenOutputFile(outfile);
	rebalanceTree(tree, infile);
	outfile.close();
}



//opens an input file with a chosen name
//pre filename is assigned
//post if filename exists in the same directory as the program, it is opened
//      with its file pointer at the beginning of the file
//      else an error message is printed
//usage OpenInputFile(infile, filename);
void OpenInputFile(ifstream& inputFile)
{
   inputFile.open("Dictionary.dat");
   if (inputFile.fail())
   {
      cout << "File failed to open!!!!" << endl;
      exit(1);
   }
}

//opens an output file with a chosen name
//pre filename is assigned
//post if filename exists in the same directory as the program, it is opened
//      with its file pointer at the beginning of the file
//      else an error message is printed
//usage OpenInputFile(outputFile, filename);
void OpenOutputFile(ofstream& outputFile)
{
   outputFile.open("Dictionary.dat");
   if (outputFile.fail())
   {
      cout << "File failed to open!!!!" << endl;
   }
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
