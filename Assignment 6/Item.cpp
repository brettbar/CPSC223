// Implementation of ADT Item
//     data object: a name associated with a phone number
//     data structures: dynamic arrays of char for phone number and name
//     operations: create, destroy, copy create, copy
//                 input, output

#include "Item.h" 

const int MAXITEMSIZE = 30;

//allows for input of an item from either the standard input device or a file
//pre input has been opened and readied for the input of
//    7-digit phone number without dashes followed by one space and first-name followed by
//    space and second-name followed by a newline. For example
//    123-4567 Frosty Snowperson
//post rightHandSideItem has been filled with a 7-digit phone number and first-name
//     and last-name from the input. The name data ends with the null character
//usage cin >> myitem;
istream& operator>> (istream& input, Item& rightHandSideItem)
{
   char firstSpace, nextChar;
   
	for (int k = 0; k < KEYSIZE; k++)
	{
		input.get(rightHandSideItem.phonePtr[k]);
	}
   input.get(firstSpace);
   input.get(nextChar);
   int k = 0;
   while (nextChar != '\n' and k < MAXITEMSIZE)
   {
      rightHandSideItem.namePtr[k] = nextChar;
      k++;
      input.get(nextChar);
   }
   rightHandSideItem.namePtr[k] = '\0';
   
	return input;
}

//allows for the output of an item to the standard output device or a file
//pre rightHandSideItem has been filled with a 7-digit phone number and name; 
//    output has been opened
//post rightHandSideItem has been written to the output device
//     123-4567 Frosty Snowperson
//     there is a newline after the last name
//usage  outfile << myitem;
ostream& operator<< (ostream& output, const Item& rightHandSideItem)
{
   for (int k = 0; k < KEYSIZE; k++)
	{
		if (k == 3) {
			output << '-';
		}
		output << rightHandSideItem.phonePtr[k];
	}
   output << ' ';
   int k = 0;
   char nextChar = rightHandSideItem.namePtr[k];
   while (nextChar != '\0')
   {
      output.put(nextChar);
      k++;
      nextChar = rightHandSideItem.namePtr[k];
   }
   output << endl;
	return output;
}

//creates an empty item (phone number and name)
//post Item object is an empty phone number and name
//usage Item aitem;
Item::Item()
{
   namePtr = new char [MAXITEMSIZE + 1];
   namePtr[0] = '\0';
}

//releases memory for a phone number and name
//pre Item object exists
//post Item object no longer exists, memory has been freed
//usage automatically done at the end of scope
Item::~Item()
{
   delete [] namePtr;
   // namePtr = nullptr;
}

//creates a new item and copies the right hand side item into item
//pre rightHandSideItem has been assigned a phone number and name
//post Item object is a copy of rightHandSideItem
//usage Item bitem(rhsItem);
Item::Item(const Item& rightHandSideItem)
{
   namePtr = new char [MAXITEMSIZE + 1];
   namePtr[0] = '\0';
   operator=(rightHandSideItem);
}

//copies a phone number and a name
//pre rightHandSideItem has been assigned a phone number and name
//post Item object has a copy of rightHandSideItem
//usage bitem = aitem;
Item& Item::operator=(const Item& rightHandSideItem)
{
   if (this != &rightHandSideItem)
   {
      for (int k = 0; k < KEYSIZE; k++)
		{
			phonePtr[k] = rightHandSideItem.phonePtr[k];
		}
      for (int k = 0; k < MAXITEMSIZE; k++)
		{
			namePtr[k] = rightHandSideItem.namePtr[k];
		}
   }
   return *this;
}

//determines of an item is empty
//pre Item object exists
//post if Item object is empty returns true else returns false
//usage if(aitem.isEmpty())
bool Item::isEmpty()
{
   return (phonePtr[0] == '0');
}

//makes an Item object previously assigned now assigned a special value_comp
//pre Item object is assigned
//post Item object is assigned so first digit is *
void Item::setUsed()
{
   phonePtr[0] = '*';
}

// checks to see if an Item has been assigned previously
// pre Item object is assigned
// post if Item object has been set as used then returns true else returns false
// usage if (anItem.isUsed)
bool Item::hasBeenUsed()
{
   return (phonePtr[0] == '*');
}


        