// Clientprogram.cpp

#include <iostream>
#include <fstream>
#include <cstdlib>
#include "Dictionary.h"
#include "Item.h"

using namespace std;

void openInputFile(ifstream& infile);

void readItem (ifstream& infile, Dictionary)

int main()
{

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

void readItem()
{

}
