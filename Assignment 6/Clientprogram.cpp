//Author Hunter COngress
// Program: Menu Tester

#include <iostream>
#include <fstream>
#include "BinarySearchTree.h"
#include "Item.h"
#include "Exception.h"

using namespace std;

void printMenu();
void getOption(char option);
bool isNotExit(char option);
void doOption(char option, Item theItem, BinarySearchTree tree, ofstream& outfile);
void OpenInputFile(ifstream& inputFile, string filename);
void makeTree(ifstream& inputFile, BinarySearchTree tree);
void saveFile(ofstream& outfile, string fileName, BinarySearchTree& tree);
//prints an exception message
//pre except has been thrown
//post except is printed to the screen with two newlines before and after
//usage PrintExceptionMessage(except);
void PrintExceptionMessage(const Exception& except, ofstream& outfile);



int main()
{
	BinarySearchTree mytree;
	Item theItem;
	ifstream infile;
	OpenInputFile(infile, "Input.dat");
	ofstream outfile;
	char option = '0';
	char newLine;
	while(isNotExit(option))
	{
		printMenu();
		cin.get(option);
		cin.get(newLine);
		getOption(option);
		doOption(option, theItem, mytree, outfile);
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
	cout<< "----------------------------------------------------------------------------------------------"<< endl;
	cout <<" Your options are: " << endl << endl;


	cout << "f  : find the name of the contact, given her/his phone number" << endl;
	cout << "i  : insert a new item (phone number and name ) into the dictionary" << endl;
	cout<< "l  : list the items in the entire dictionary on the screen in inorder fashion" << endl;
	cout << "p  : print the tree in pretty fashion (showing only the phone numbers)" << endl;
	cout<< "r  : rebalance the tree" << endl;
	cout<<"s  : save the dictionary to the file in sorted order – inorder --  ready to be read" << endl;
	cout <<"e  : exit the program which automatically does option s" << endl;

	cout << "Enter your option > ";

}
//gets the option from the user
//pre a character of the first letter of the options
//post it will print out the option selected
// 		if not the function will ask for another selection
//usage getOption(option);
void getOption(char option)
{
	char enter;
	if (option == 'f')
		cout << "f  : find the name of the contact, given her/his phone number" << endl;
	else if(option == 'i')
		cout << "i  : insert a new item (phone number and name ) into the dictionary" << endl;
	else if(option == 'l')
		cout<< "l  : list the items in the entire dictionary on the screen in inorder fashion" <<endl ;
	else if(option == 'p')
		cout << "p  : print the tree in pretty fashion (showing only the phone numbers)" << endl ;
	else if(option =='r')
		cout<< "r  : rebalance the tree" << endl ;
	else if(option == 's')
		cout<<"s  : save the dictionary to the file in sorted order – inorder --  ready to be read" << endl;
	else if(option == 'e')
		cout <<"e  : exit the program which automatically does option s" << endl;
	else
	{
		cout << "Please reenter your option choice > ";
		cin.get(option);
		cin.get(enter);
		getOption(option);
	}
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
void doOption(char option, Item theItem, BinarySearchTree tree, ofstream& outfile)
{
	char enter;
	Key targetPhoneNumber;
	if (option == 'f')
	{
		cout << "Please enter a phone.> ";
		cin >> targetPhoneNumber;
		  try
		   {
			 	tree.search(targetPhoneNumber, theItem);
				cout << theItem;
		   }
		   catch (Exception search)
		   {
			 	PrintExceptionMessage(search, outfile);
		   }
	}
	else if (option == 'i')
	{
		cout << "Please enter 7 digits and then a name.> ";
		cin >> theItem;
			try
		   {
				tree.insert(theItem);
				cout<<"The contact has been stored"<< endl;
		   }
		   catch (Exception insert)
		   {
			 	PrintExceptionMessage(insert, outfile);
		   }
	}
	else if(option == 'l')
	{
		tree.BinaryTree::inorderTraverse();
	}
	else if(option == 'p')
	{
		tree.prettyDisplay();
	}
	else if (option == 'r')
	{
		cout << "Please enter a phone.> ";
		cin >> targetPhoneNumber;
			try
		   {
				tree.remove(targetPhoneNumber);
				cout <<" The Item has been removed" << endl;
		   }
		   catch (Exception remove)
		   {
			 	PrintExceptionMessage(remove, outfile);
		   }
	}
	else if (option == 's')
	{
		saveFile(outfile, "Input.dat", tree);
	}

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
void makeTree(ifstream& inputFile, BinarySearchTree tree)
{
	int numberOfItems;
	inputFile >> numberOfItems;
	for(int i = 0; i < numberOfItems; i++)
	{
		Item newGuy;
		inputFile >> newGuy;
		tree.insert(newGuy);
	}
	inputFile.close();
}
//opens an output file with a chosen name
//pre filename is assigned and binary search tree is constructed
//post if filename exists in the same directory as the program, it is opened and
//			written to the file
//      with its file pointer at the beginning of the file
//      else an error message is printed
//usage saveFile(outfile, filename, tree);
void saveFile(ofstream& outfile, string fileName, BinarySearchTree& tree)
{
	outfile.open(fileName);
   if (outfile.fail())
   {
      cout << "File failed to open!!!!" << endl;

   }
   else{
		outfile.get(tree.inorderTraversal(outfile));
		outfile.close();
   }
}

//prints an exception message
//pre except has been thrown
//post except is printed to the screen with two newlines before and after
//usage PrintExceptionMessage(except);
void PrintExceptionMessage(const Exception& except, ofstream& output)
{
   output << endl << endl;
   output << except.What();
   output << endl << endl;
}
