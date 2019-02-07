// Searchtreetester.cpp
// Brett Barinaga
// 3/19/2018

#include <iostream>
//#include "BinarySearchTree.h"

using namespace std;

void printMenu();
char getOption();
bool isNotExit(char select);
void doOption();


int main()
{
	printMenu();
	char choice;
	choice = getOption();
	while (isNotExit(choice))
	{
		doOption();
		printMenu();
		choice = getOption();
	}
	return 0;
}


void printMenu()
{
	cout << "----------------------------------------------------------------------------------------------" << endl;
	cout << "Your options are:\n\n";
	cout <<
	"f  : find the name of the contact, given her/his phone number\n" <<
	"i  : insert a new item (phone number and name ) into the dictionary\n" <<
	"l  : list the items in the entire dictionary on the screen in inorder fashion\n" <<
	"p  : print the tree in pretty fashion (showing only the phone numbers)\n" <<
	"r  : rebalance the tree\n" <<
	"s  : save the dictionary to the file in sorted order – inorder --  ready to be read\n" <<
	"e  : exit the program which automatically does option s\n\n" <<

	"Enter your option > ";
}

char getOption()
{
	char choice, newline;
	cin.get(choice);
	cin.get(newline);
	return choice;
}

bool isNotExit(char select)
{
	if (select == 'e')
		return false;
	else
		return true;
}

void doOption()
{

}












//
