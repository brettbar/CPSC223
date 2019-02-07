// Specification of ADT Item
//     data object: a name associated with a phone number
//     operations: create, destroy, copy create, copy
//                 input, output

#ifndef ITEM_H
#define ITEM_H

#include "Key.h" 
using namespace std;

class Item : public Key
{

	//allows for input of an item from either the standard input device or a file
	//pre input has been opened and readied for the input of
	//    7-digit phone number without dashes followed by one space and first-name followed by
	//    space and second-name followed by a newline. For example
	//    123-4567 Frosty Snowperson
	//post rightHandSideItem has been filled with a 7-digit phone number and first-name
	//     and last-name from the input
	//usage cin >> myitem;
	friend istream& operator>> (istream& input, Item& rightHandSideItem);

	//allows for the output of an item to the standard output device or a file
	//pre rightHandSideItem has been filled with a 7-digit phone number and name; 
	//    output has been opened
	//post rightHandSideItem has been written to the output device
	//     123-4567 Frosty Snowperson
	//usage  outfile << myitem;
	friend ostream& operator<< (ostream& output, const Item& rightHandSideItem);

public:

	//creates an empty new name
	//post Item object is an empty name
	//usage Item aitem;
	Item();

	//releases memory for a name
	//pre Item object exists
	//post Item object no longer exists, memory has been freed
	//usage automatically done at the end of scope
	~Item();

	//creates a new Item object with the same info as another Item object
	//pre rightHandSideItem 
	//post Item object is a copy of rightHandSideItem
	//usage Item bitem(aitem);
	Item(const Item& rightHandSideItem);

	//copies a name
	//pre rightHandSideItem has been assigned a name
	//post Item object has a copy of rightHandSideItem
	//usage bitem = aitem;
	Item& operator=(const Item& rightHandSideItem);

	//makes an Item object previously assigned now assigned a special value_comp
	//pre Item object is assigned
	//post Item object is assigned so first digit is *
	void Item::setUsed();

	// checks to see if an Item has been assigned previously
	// pre Item object is assigned
	// post if Item object has been set as used then returns true else returns false
	// usage if (anItem.isUsed)
	bool Item::isUsed();

private:
	char* namePtr;
};
#endif         