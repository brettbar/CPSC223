////Written By Christian Kruep & Brett Barinaga
//Clientprogram.cpp
//Is a client program that utilizes the appropriate member function of class Dictionary

// Implementation of ADT Dictionary
//     data object: a bunch of contacts (phone number and name)
//     data structure: a header record in the heap with number of items and
//                    a dynamic array of Stack items using Separate Chaining
//     operations: create, destroy
//                 search the dictionary for an item given its phone number
//                 insert a new item into the dictionary
//                 remove an item from the dictionary given its phone number
#include <iostream>
#include <fstream>
#include <cstdlib>
#include "Dictionary.h"
#include "Item.h"
#include "Key.h"
#include "Stack.h"

using namespace std;

//Prints the requested amount of lines as output
//Post: The desired number of lines has been outputed. 
//Usage: printLines(2);
void printLines(int lines);

//opens an input file named Input.dat
//post: infile has been opened with infile's pointer at beginning of the file 
//usage: openInputFile(inFile);
void openInputFile(ifstream& infile);

//Prints out a message as inputed by the user
//Post: The desired message has been outputed
//Usage: printMessage("this is how you use this function");
void printMessage(string message);

//Reads the specified number of items from the file into readingDictionary
//Pre: infile and readingDictionary must exist
//Post: readingDictionary is filled with the number of specified items in the correctly hashed locations
//usage: addingMoreItems(infile, readingDictionary, 3);
void addingMoreItems(ifstream& infile, Dictionary readingDictionary, int numberOfLinesRead);

//Reads items from the file and puts them into the dictionary.
//Pre: newDictionary must exist as well as infile.
//Post: newDictionary is filled with objects.
//Usage: sendToDictionary(infile, searchingDictionary);
void sendToDictionary(ifstream& infile, Dictionary& newDictionary);

//Reads a Key from the file and stores it into newKey
//Pre: infile must exist and newKey as well.
//Post: newKey has been filled with a 7-digit phone number from the file
//Usage: sendToKey(infile, newKey);
void sendToKey(ifstream& infile, Key& newKey);

//Searches for newKey in newDictionary outputs the appropriate response 
//		depending if newKey is in the dictionary or not.
//Pre: newDictionary and newKey must exist.
//Post: depending on if newKey exists or not in newDictionary it outputs a response.
//Usage: searchForItem(newDictionary, newKey);
void searchForItem(Dictionary& newDictionary, Key& newKey);

//Searches for newKey in newDictionary, and if it exists removes it from newDictionary,
//		and out puts the appropriate response.
//Pre: newDictionary and newKey must exist. newKey must be filled.
//Post: If newKey is contained in newDictionary then it is removed. 
//Usage: removeItem(newDictionary, newKey);
void removeItem(Dictionary& newDictionary, Key& newKey);

//Prints out newDictionary
//Pre: newDictionary must exist.
//Post: newDictionary has been outputed along with appropriate headers.
//Usage: printDictionary(newDictionary);
void printDictionary(Dictionary& newDictionary);

int main()
{
  printLines(2);
  
  Dictionary testDictionary;
  ifstream infile;
  
  openInputFile(infile);
  
  printMessage("Inputting first four numbers into dictionary.");
  infile >> testDictionary;
  printDictionary(testDictionary);
  printLines(2);
  
  printMessage("Inputting next 3 numbers. They all hash into the same location as an earlier number.");
  addingMoreItems(infile, testDictionary, 3);
  printDictionary(testDictionary);
  printLines(2);
  
  Key searchKey;
  sendToKey(infile, searchKey);
  searchForItem(testDictionary, searchKey);
  printLines(1);
  
  sendToKey(infile, searchKey);
  searchForItem(testDictionary, searchKey);
  printLines(2);
  
  sendToKey(infile, searchKey);
  removeItem(testDictionary, searchKey);
  printDictionary(testDictionary);
  printLines(2);
  
  printMessage("Searching For final number in Input.dat");
  sendToKey(infile, searchKey);
  searchForItem(testDictionary, searchKey);
  printDictionary(testDictionary);
  
  return 0;
}

//Prints the requested amount of lines as output
//Post: The desired number of lines has been outputed. 
//Usage: printLines(2);
void printLines(int lines)
{
	for(int k = 0; k < lines; k++)
		cout << endl;
}

//opens an input file named Input.dat
//post: infile has been opened with infile's pointer at beginning of the file 
//usage: openInputFile(inFile);
void openInputFile(ifstream& infile)
{
	infile.open("Input.dat");
	if (infile.fail())
	{
		cout << "ERROR in opening Input.dat !!!" << endl;
		exit(1);
	}
}

//Prints out a message as inputed by the user
//Post: The desired message has been outputed
//Usage: printMessage("this is how you use this function");
void printMessage(string message)
{
	cout << message << endl;
}

//Reads the specified number of items from the file into readingDictionary
//Pre: infile and readingDictionary must exist
//Post: readingDictionary is filled with the number of specified items in the correctly hashed locations
//usage: addingMoreItems(infile, readingDictionary, 3);
void addingMoreItems(ifstream& infile, Dictionary readingDictionary, int numberOfLinesRead)
{
	Item adderItem;
	bool isAdded;
	for(int k = 0; k < numberOfLinesRead; k++)
	{
		infile >> adderItem;
		readingDictionary.insert(adderItem, isAdded);
	}
}

//Reads objects from the file and puts them into the dictionary.
//Pre: newDictionary must exist as well as infile.
//Post: newDictionary is filled with objects.
//Usage: sendToDictionary(infile, searchingDictionary);
void sendToDictionary(ifstream& infile, Dictionary& newDictionary)
{
	infile >> newDictionary;
}

//Reads a Key from the file and stores it into newKey
//Pre: infile must exist and newKey as well.
//Post: newKey has been filled with a 7-digit phone number from the file
//Usage: sendToKey(infile, newKey);
void sendToKey(ifstream& infile, Key& newKey)
{
	infile >> newKey;
}

//Searches for newKey in newDictionary outputs the appropriate response 
//		depending if newKey is in the dictionary or not.
//Pre: newDictionary and newKey must exist.
//Post: depending on if newKey exists or not in newDictionary it outputs a response.
//Usage: searchForItem(newDictionary, newKey);
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

//Searches for newKey in newDictionary, and if it exists removes it from newDictionary,
//		and out puts the appropriate response.
//Pre: newDictionary and newKey must exist. newKey must be filled.
//Post: If newKey is contained in newDictionary then it is removed. 
//Usage: removeItem(newDictionary, newKey);
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


//Prints out newDictionary
//Pre: newDictionary must exist.
//Post: newDictionary has been outputed along with appropriate headers.
//Usage: printDictionary(newDictionary);
void printDictionary(Dictionary& newDictionary)
{
	cout << newDictionary;
}
