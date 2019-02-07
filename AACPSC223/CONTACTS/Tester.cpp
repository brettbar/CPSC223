// testing file for class Key
// Tester.cpp

#include "Key.h"
#include "Item.h"

int main()
{
	Key akey, bkey;
	Item aitem, bitem;
	
	// Testing sumDigits for key and item objects
	cout << "First testing sumDigits for key objects..." << endl;
	cout << "Enter a 7-digit phone number without spaces or dashes -> ";
	cin >> akey;
	cout << akey << endl;
	cout << "Test was succesful if terminal displays sum of phone number entered..." << endl;
	cout << akey.sumDigits() << endl;
	cout << "Now testing sumDigits for item objects..." << endl;
	cout << "Enter a 7-digit phone number then a space then a first name space last name -> ";
	cin >> aitem;
	cout << aitem << endl;
	cout << "Test was succesful if terminal displays sum of phone number entered..." << endl;
	cout << aitem.sumDigits() << endl;
	
	// Testing operator== for key objects
	cout << "Now testing operator== for key objects..." << endl;
	cout << "Enter a 7-digit phone number without spaces or dashes -> ";
	cin >> akey;
	cout << akey << endl;
	cout << "Enter a 7-digit phone number without spaces or dashes -> ";
	cin >> bkey;
	cout << bkey << endl;
	cout << "If these key objects are equal the terminal will tell you they are the same, or different if they aren't..." << endl;
	cout << endl;
	if (akey == bkey)
		cout << "keys are the same" << endl;
	else
		cout << "keys are not the same" << endl;

	// Testing operator== for item objects
	cout << "Now testing operator== for item objects..." << endl;
	cout << "Enter a 7-digit phone number then a space then a first name space last name -> ";
	cin >> aitem;
	cout << aitem << endl;
	cout << "Enter a 7-digit phone number then a space then a first name space last name -> ";
	cin >> bitem;
	cout << bitem << endl;
	cout << "If these item objects are equal the terminal will tell you they are the same, or different if they aren't..." << endl;
	cout << endl;
	if (akey == bkey)
		cout << "items are the same" << endl;
	else
		cout << "items are not the same" << endl;

	// Testing operator< for key objects
	cout << "Now testing operator< for key objects..." << endl;
	cout << "Enter a 7-digit phone number without spaces or dashes -> ";
	cin >> akey;
	cout << akey << endl;
	cout << "Enter a 7-digit phone number without spaces or dashes -> ";
	cin >> bkey;
	cout << bkey << endl;
	cout << "If akey is less than bkey, the terminal will state true, else if it will state false..." << endl;
	if (akey < bkey)
		cout << "True" << endl;
	else
		cout << "False" << endl;

	// Testing operator< for item objects
	cout << "Now testing operator< for item objects..." << endl;
	cout << "Enter a 7-digit phone number then a space then a first name space last name -> ";
	cin >> aitem;
	cout << aitem << endl;
	cout << "Enter a 7-digit phone number then a space then a first name space last name -> ";
	cin >> bitem;
	cout << bitem << endl;
	cout << "If aitem is less than bitem, the terminal will state true, else if it will state false..." << endl;
	if (aitem < bitem)
		cout << "True" << endl;
	else
		cout << "False" << endl;

	// Testing copy constructor for key objects
	cout << "Now testing the copy constructor for key objects..." << endl;
	cout << "Enter a 7-digit phone number without spaces or dashes, this will be your base key object -> ";
	cin >> akey;
	Key testKey(akey);
	cout << "This test will have been successful if you see the phone number you entered in the next line..." << endl;
	cout << testKey << endl;

	// Testing copy constructor for item objects
	cout << "Now testing the copy constructor for item objects..." << endl;
	cout << " Enter a 7-digit phone number, followed by a first and last name, this will be your base item object -> ";
	cin >> aitem;
	Item testItem(aitem);
	cout << "This test will have been successful if you see the phone number and name you entered in the next line..." << endl;
	cout << testItem << endl;


	return 0;
}