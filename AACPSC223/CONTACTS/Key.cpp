//filename Key.cpp
//Specification of Abstract Data Type Key
//
//   data object: a key which is a unique 7-digit phone humber
//   operations: create, destroy, copy, input, output, check if same, check if less than, sum the digits

#include "Key.h"

//allows for input of a key from either the standard input device or a file
//pre input has been opened and a prompt has been given to enter the 7-digit phone number without dashes
//post rightHandSideKey has been filled with a 7-digit phone number from the input
//usage cin >> mykey;
istream& operator>> (istream& input, Key& rightHandSideKey)
{
	for (int i = 0; i < KEYSIZE; i++)
	{
		input.get(rightHandSideKey.phonePtr[i]);
	}
	char enter;
	input.get(enter);
	return input;
}

// friend functions are NOT member functions of a class. In Key.cpp there is no Key:: in their headers.

//allows for the output of a key to the standard output device or a file
//pre rightHandSideKey has been filled with a 7-digit phone number; output has been opened
//post rightHandSideKey has been written to the output device in standard format like 313-3914
//usage  outfile << mykey;
ostream& operator<< (ostream& output, const Key& rightHandSideKey)
{
	for (int i = 0; i < KEYSIZE; i++)
	{
		if (i == 3)
		{
			output << '-';
		}
		output << rightHandSideKey.phonePtr[i];
	}
	return output;
}


//creates an empty new phone number
//post Key object is an empty phone number
//usage Key akey;
Key::Key()
{
	phonePtr = new char[KEYSIZE];
	for (int i = 0; i < KEYSIZE; i++)
	{
		phonePtr[i] = '0';
	}
}

//creates a specific phone number
//pre keyText is assigned a string of 7 digits without dashes
//post Key object has a copy of the phone number in keyText
//usage Key akey("1112222"); 
Key::Key(string keyText)
{
	phonePtr = new char[KEYSIZE];
	for (int i = 0; i < KEYSIZE; i++)
	{
		phonePtr[i] = keyText.at(i);
	}
}

//releases memory for a phone number
//pre Key object exists
//post Key object no longer exists, memory has been freed
//usage automatically done at the end of scope
Key::~Key()
{
	delete[] phonePtr;
	phonePtr = NULL;
}

//copies a phone number
//pre rightHandSideKey has been assigned a phone number
//post Key object has a copy of rightHandSideKey
//usage bkey = akey;
Key& Key::operator=(const Key& rightHandSideKey)
{
	if (this != &rightHandSideKey)
	{
		for (int k = 0; k < KEYSIZE; k++)
		{
			phonePtr[k] = rightHandSideKey.phonePtr[k];
		}
	}
	return *this;
}

//adds up all of the digits in the phone number
//pre Key object exists
//post returns the sum of the digits in the phone number
//usage cout << akey.sumDigits();
int Key::sumDigits() const
{
	// to convert digit chars to corresponding integer values 
	int sum = 0;
	for (int i = 0; i < KEYSIZE; i++)
	{
		sum += (phonePtr[i] - '0');
	}
	return sum;
}

//checks if two phone numbers are equal
//pre rightHandSideKey has been assigned
//post returns true if Key object is the same phone number as rightHandSideKey
//usage if (akey == bkey) { cout << "the phone numbers are equal" << endl;
bool Key::operator==(const Key& rightHandSideKey) const
{
	for (int i = 0; i < KEYSIZE; i++)
	{
		if (phonePtr[i] != rightHandSideKey.phonePtr[i])
			return false;
	}
	return true;
}


//checks if one phone number is less than another
//pre rightHandSideKey has been assigned
//post returns true if Key object is less than the phone number in rightHandSideKey
//usage if (akey < bkey) { cout << "left phone number is less than right phone number" << endl;

bool Key::operator<(const Key& rightHandSideKey) const
{
	for (int i = 0; i < KEYSIZE; i++)
	{
		if (phonePtr[i] < rightHandSideKey.phonePtr[i])
			return true;
	}
	return false;
}








