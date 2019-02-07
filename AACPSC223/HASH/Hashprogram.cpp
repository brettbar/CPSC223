// inserting items (integers) into a dictionary (hash table)
// Brett Barinaga
// Hashprogram.cpp

#include <iostream>

using namespace std;

const int MAXSIZE = 7;

int hashFunction(int item);
void print(int hashTable[]);
void input (int hashTable[]);

int main()
{
	int hashTable[MAXSIZE];
	
	return 0;
}

int hashFunction(int item)
{
	return item % MAXSIZE;
}

void print(int hashTable[])
{
	for (int k = 0; k < MAXSIZE; k++)
	{
		cout << k << " : " << hashTable[k] << endl;
	}
}

void input (int hashTable[])
{
	int item;
	for (int a = 0; a < 3; a++)
	{
		cout << "Enter an integer -> ";
		cin >> item;
		hashTable[hashFunction(item)] = item;
	}
}