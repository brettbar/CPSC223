// filename Dictionary.cpp

#include "Dictionary.h"

const int TABLESIZE = 7;

struct DictionaryRecord
{
	Item* hashTablePtr;
	int numberStored;
};

Dictionary::Dictionary()
{
	dictionaryPtr->hashTablePtr = new Item[TABLESIZE];
}

Dictionary::~Dictionary()
{
	delete[] dictionaryPtr;
	dictionaryPtr = NULL;
}

void Dictionary::insert(const Item& newItem, bool& isFull)
{
	int address;
	if (isFull == true)
		cout << "Contacts are full!\n";
	else
	{
		dictionaryPtr->numberStored++;
		address = newItem.sumDigits();
		dictionaryPtr->hashTablePtr[address] = newItem;
	}
}