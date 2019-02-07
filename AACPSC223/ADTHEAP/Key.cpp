//filename Key.cpp
//Specification of Abstract Data Type Key
//
//   data object: a key which is a unique 7-digit phone humber
//   operations: create, destroy, copy, input, output, check if same, check if less than, sum the digits

#include "Key.h"

//allows for input of a key from either the standard input device or a file
//pre input has been opened and is before a 2-digit integer as phone number
//post rightHandSideKey has been filled with a 2-digit phone number from the input
//usage cin >> mykey;
istream& operator>> (istream& input, Key& rightHandSideKey)
{
	input >> rightHandSideKey.phone;

	char enter;
	input.get(enter);
	return input;
}

//allows for the output of a key to the standard output device or a file
//pre rightHandSideKey has been filled with a 2-digit phone number; output has been opened
//post rightHandSideKey has been written to the output device 
//usage  outfile << mykey;
ostream& operator<< (ostream& output, const Key& rightHandSideKey)
{
   output << rightHandSideKey.phone;
   return output;
}

//creates an empty new phone number
//post Key object is an empty phone number
//usage Key akey;
Key::Key()
{
	phone = 0;
}

//creates a specific phone number
//pre keyText is assigned a 2-digit integer
//post Key object has a copy of the phone number in keyInteger
//usage Key akey(12); 
Key::Key(int keyInteger)
{
	phone = keyInteger;
}

//releases memory for a phone number
//pre Key object exists
//post Key object no longer exists, memory has been freed
//usage automatically done at the end of scope
Key::~Key()
{
	phone = 0;
}

//copies a phone number
//pre rightHandSideKey has been assigned a phone number
//post Key object has a copy of rightHandSideKey
//usage bkey = akey;
Key& Key::operator=(const Key& rightHandSideKey)
{
	if (this != &rightHandSideKey)
	{
		phone = rightHandSideKey.phone;
	}
	return *this;
}

//checks if two phone numbers are equal
//pre rightHandSideKey has been assigned
//post returns true if Key object is the same phone number as rightHandSideKey
//usage if (akey == bkey) { cout << "the phone numbers are equal" << endl;
bool Key::operator==(const Key& rightHandSideKey) const
{
	return phone == rightHandSideKey.phone;
}

//checks if one phone number is less than another
//pre rightHandSideKey has been assigned
//post returns true if Key object is less than the phone number in rightHandSideKey
//usage if (akey < bkey) { cout << "left phone number is less than right phone number" << endl;
bool Key::operator<(const Key& rightHandSideKey) const
{
	return phone < rightHandSideKey.phone;
}






