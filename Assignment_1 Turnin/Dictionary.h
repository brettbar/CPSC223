// Specification of ADT Dictionary
//     data object: a bunch of contacts (phone number and name)
//     operations: create, destroy
//                 search the dictionary for an item given its phone number
//                 insert a new item into the dictionary
//                 remove an item from the dictionary given its phone number

#ifndef DICTIONARY_H
#define  DICTIONARY_H

#include "Item.h"

struct DictionaryRecord;

class Dictionary
{
// displays a dictionary
// pre: output has been opened if it is a file
//      rightHandSideDictionary has been assigned items
// post: output contains each item on a separate line in the format with headings.
//       for example
//       phone       name
//       123-4567 Frosty Snowguy
//       111-2222 Icy Dog 
// usage: outfile << myDictionary;    
friend ostream& operator<< (ostream& output, const Dictionary& rightHandSideDictionary);

// inputs items into a dictionary
// pre: input has been opened if it is a file
//      items are arranged in the following format
//      1234567 Frosty Snowguy
//      1112222 Icy Dog
// post: if there is room, 
//       all items in the input have been stored in rightHandSideDictionary
// usage: infile >> myDictionary;
friend istream& operator>> (istream& input, Dictionary& rightHandSideDictionary);

public:

// creates a new dictionary
// post: Dictionary object exists but is empty
// usage: Dictionary myDictionary;
Dictionary();

// destroys a dictionary
// pre: Dictionary object exists
// post: all memory for Dictionary object has been freed
// usage: automatically done at the end of scope
~Dictionary();

// searchs for a contact with a particular phone number
// pre targetPhone has been assigned a 7-digit phone number
// post if an item with phone number the same as targetPhone is found then
//          isFound is true and theItem is that item
//       else isFound is false
// usage  contacts.search(targetPhone, anItem, isFound);
void search (const Key& targetPhone, Item& theItem, bool& isFound);

// inserts a new contacts' item into the dictionary
// pre: newItem has been assigned
// post: if there is room in the Dictionary object, isFull is false
//            and newItem is appropriately added
//       else isFull is false
// usage: myDictionary.insert(myItem, isFull);
void insert (const Item& newItem, bool& isFull);

// removes the item associated with a given phone number from the dictionary
// pre: targetPhone is assigned
// post: if targetPhone is found in Dictionary object, isDone is true
//           and the associated Item object (phone and name) has been 
//           removed from the Dictionary
//       else isDone is false
// usage: myDictionary.remove(myPhone, isFound);
void remove (const Key& targetPhone, bool& isDone);

private:
   DictionaryRecord* dictionaryPtr;
};
#endif