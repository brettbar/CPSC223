// Brett Barinaga
// 4/23/2018
// Clientprogram.cpp
// This program will test the operations in class Heap and revised class Key

#include "Exception.h"
#include <fstream>
#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;

#include "Key.h"
#include "Heap.h"

//opens an input file with a chosen name
//post if name for inputFile exists in directory, it is opened
//      with its file pointer at the beginning of the file
//      else an error message is printed
//usage openInputFile(infile, filename);
void openInputFile(ifstream& inputFile);

int main()
{
   ifstream infile;
   Heap maxheap;
   Key maxKey;

   openInputFile(infile);

   infile >> maxheap;
   cout << "\t\t\tTWO TESTS OF INSERT" << endl;
   cout << "Test 1: Pre-insert tree:" << endl;
   cout << maxheap;
   cout << endl;
   cout << "testing insert(25): " << endl << endl;
   maxheap.insert(25);
   cout << "Post-insert tree:" << endl;
   cout << maxheap;
   cout << endl;
   cout << "Test 2: Pre-insert tree:" << endl;
   cout << maxheap;
   cout << endl;
   cout << "testing insert(15): " << endl << endl;
   maxheap.insert(15);
   cout << "Post-insert tree:" << endl;
   cout << maxheap;
   cout << endl;

   cout << "\t\t\tTWO TESTS OF REMOVE" << endl;
   cout << "Test 1: Pre-remove tree:" << endl;
   cout << maxheap;
   cout << endl;
   cout << "testing remove of maxKey (which is 25): " << endl << endl;
   maxheap.getMaximum(maxKey);
   maxheap.remove(maxKey);
   cout << "Post-remove tree:" << endl;
   cout << maxheap;
   cout << endl;
   cout << "Test 2: Pre-remove tree:" << endl;
   cout << maxheap;
   cout << endl;
   cout << "testing remove of maxKey (which is 20): " << endl << endl;
   maxheap.getMaximum(maxKey);
   maxheap.remove(maxKey);
   cout << "Post-remove tree:" << endl;
   cout << maxheap;
   cout << endl;
   return 0;
}
//opens an input file with a chosen name
//pre filename is assigned
//post if filename exists in the same directory as the program, it is opened
//      with its file pointer at the beginning of the file
//      else an error message is printed
//usage OpenInputFile(infile, filename);
void openInputFile(ifstream& inputFile)
{
   inputFile.open("Heap.dat");
   if (inputFile.fail())
   {
      cout << "File failed to open!!!!" << endl;
      exit(1);
   }
}
