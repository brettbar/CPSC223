// Brett Barinaga, Hunter Congress
// 3/5/2018
// Clientprogram.cpp
// Description: This clientprogram will open an input file, read off items,
// populate a full binary tree of height 2, and a complete but not full binary
// tree of height 3. It will also print these trees symbolically, as well as
// in preorder, inorder, and postorder traversal manners. This program will
// also throw and catch exceptions defined in the Exception.cpp/.h files.



#include "BinaryTree.h"
#include "Exception.h"
#include <string>
#include <fstream>
using namespace std;

//opens an input file with a chosen name
//pre filename is assigned
//post if filename exists in the same directory as the program, it is opened
//      with its file pointer at the beginning of the file
//      else an error message is printed
//usage OpenInputFile(infile, filename);
void OpenInputFile(ifstream& inputFile, string filename);

//prints an exception message
//pre except has been thrown
//post except is printed to the screen with two newlines before and after
//usage PrintExceptionMessage(except);
void PrintExceptionMessage(const Exception& except);

int main()
{
   BinaryTree mytree, otherTree, testTree;
   ifstream infile;

   OpenInputFile(infile, "Input.dat");

   cout << "Creating a full binary tree of height 2...\n\n";
   try
   {
      mytree.makeTreeOne(infile);
      mytree.prettyDisplay();
      cout << endl;
      cout << "Preorder traversal...\n";
      mytree.preorderTraverse();
      cout << endl;
      cout << "Inorder traversal...\n";
      mytree.inorderTraverse();
      cout << endl;
      cout << "Postorder traversal...\n";
      mytree.postorderTraverse();
      cout << endl;
   }
   catch (Exception exceptTreeOne)
   {
     PrintExceptionMessage(exceptTreeOne);
   }

   cout << "Creating a complete but not full binary tree of height 3..." << endl;
   try
   {
     otherTree.makeTreeTwo(infile);
   }
   catch (Exception exceptTreeTwo)
   {
     PrintExceptionMessage(exceptTreeTwo);
   }
   cout << endl;
   otherTree.prettyDisplay();
   cout << "Preorder traversal...\n";
   otherTree.preorderTraverse();
   cout << endl;
   cout << "Inorder traversal...\n";
   otherTree.inorderTraverse();
   cout << endl;
   cout << "Postorder traversal...\n";
   otherTree.postorderTraverse();
   cout << endl;

   return 0;
}

//opens an input file with a chosen name
//pre filename is assigned
//post if filename exists in the same directory as the program, it is opened
//      with its file pointer at the beginning of the file
//      else an error message is printed
//usage OpenInputFile(infile, filename);
void OpenInputFile(ifstream& inputFile, string filename)
{
   inputFile.open(filename);
   if (inputFile.fail())
   {
      cout << "File failed to open!!!!" << endl;
      exit(1);
   }
}

//prints an exception message
//pre except has been thrown
//post except is printed to the screen with two newlines before and after
//usage PrintExceptionMessage(except);
void PrintExceptionMessage(const Exception& except)
{
   cout << endl << endl;
   cout << except.What();
   cout << endl << endl;
}
