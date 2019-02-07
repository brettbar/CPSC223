// Clientprogram.cpp

#include <iostream>
#include <fstream>
#include <cstdlib>
#include "Dictionary.h"
#include "Item.h"
#include "Key.h"

using namespace std;

void openInputFile(ifstream& infile);
void sendToDictionary(ifstream& infile, Dictionary& newDictionary);
void sendToKey(ifstream& infile, Key& newKey);
void searchForItem(Dictionary& newDictionary, Key& newKey);
void removeItem(Dictionary& newDictionary, Key& newKey);
void printDictionary(Dictionary& newDictionary);

int main()
{
	ifstream infile;
	Dictionary mine;
	Key newKey;
	Item newItem;
	bool isFull;

	openInputFile(infile);

	// a)
	cout << "First, inserting four items to unique addresses into the hash table..." << endl;
	sendToDictionary(infile, mine);
	printDictionary(mine);
	// b)
	cout << "Next, inserting three items which share a common hashAddress in the hash table..." << endl;
	sendToDictionary(infile, mine);
	printDictionary(mine);
	// c)
	sendToKey(infile, newKey);
	searchForItem(mine, newKey);
	// c)
	sendToKey(infile, newKey);
	searchForItem(mine, newKey);
	// d)
	sendToKey(infile, newKey);
	removeItem(mine, newKey);
	printDictionary(mine);

	// e)
	sendToKey(infile, newKey);
	searchForItem(mine, newKey);
	return 0;
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

void sendToDictionary(ifstream& infile, Dictionary& newDictionary)
{
	infile >> newDictionary;
}

void sendToKey(ifstream& infile, Key& newKey)
{
	infile >> newKey;
}

void searchForItem(Dictionary& newDictionary, Key& newKey)
{
	bool isFound;
	Item desiredItem;

	cout << "Now searching for desired phone number-> " << newKey << endl;
	newDictionary.search(newKey, desiredItem, isFound);
	if (not isFound)
		cout << "Desired item not found...\n";
	else
		cout << "Desired item found-> " << desiredItem << endl;
}

void removeItem(Dictionary& newDictionary, Key& newKey)
{
	bool isDone;

	cout << "Attempting to remove desired item-> " << newKey << endl;
	newDictionary.remove(newKey, isDone);
	if(not isDone)
		cout << "The desired item was not removed...\n";
	else
		cout << "The desired item was removed...\n";
}

void printDictionary(Dictionary& newDictionary)
{
	cout << newDictionary << endl;
}
