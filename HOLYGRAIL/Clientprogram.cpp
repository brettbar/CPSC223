// Brett Barinaga, Kevin Mattappally
// 4/18/2018
// Clientprogram.cpp
// This program creates and tests the abstract data type AVLTree. It opens an
// input file and constructs AVLTrees using the insert function. It tests
// the six cases of AVLTree inserts, and prints the resulting tree to an output
// file.


#include <iostream>
#include <fstream>
#include "AVLTree.h"

using namespace std;

// Open the file to be read from in the main program
// pre: infile is not open to a file
// post: infile can be used to read from a file
// usage: openInputFile(infile);
void openInputFile(ifstream& infile);

// Open the file to be written in from in the main program
// pre: outfile is not open to a file
// post: outfile can be used to read from a file
// usage: openOutputFile(output);
void openOutputFile(ofstream& outfile);

// Reads infile and creates appropriate AVLTrees to test different
// subcases of the hasNoPivot case.
// Pre: an infile populated with 3 digit items is open, as well as an
//      outfile being open.
// Post: Pre and post insertions of various subcases of hasNoPivot are printed
//      to the outfile.
// usage: testHasNoPivot(infile, outfile);
void testHasNoPivot(ifstream& infile, ofstream& outfile);

// Reads infile and creates appropriate AVLTrees to test different
// subcases of the IsAddedToShortSide case.
// Pre: an infile populated with 3 digit items is open, as well as an
//      outfile being open.
// Post: Pre and post insertions of various subcases of IsAddedToShortSide
//       are printed to the outfile.
// usage: IsAddedToShortSide(infile, outfile);
void testIsAddedToShortSide(ifstream& infile, ofstream& outfile);

// Reads infile and creates appropriate AVLTrees to test different
// subcases of the IsSingleRotateLeft case.
// Pre: an infile populated with 3 digit items is open, as well as an
//      outfile being open.
// Post: Pre and post insertions of various subcases of IsSingleRotateLeft
//       are printed to the outfile.
// usage: IsSingleRotateLeft(infile, outfile);
void testIsSingleRotateLeft(ifstream& infile, ofstream& outfile);

// Reads infile and creates appropriate AVLTrees to test different
// subcases of the IsSingleRotateRight case.
// Pre: an infile populated with 3 digit items is open, as well as an
//      outfile being open.
// Post: Pre and post insertions of various subcases of IsSingleRotateRight
//       are printed to the outfile.
// usage: IsSingleRotateRight(infile, outfile);
void testIsSingleRotateRight(ifstream& infile, ofstream& outfile);

// Reads infile and creates appropriate AVLTrees to test different
// subcases of the IsDoubleRotateLeftRight case.
// Pre: an infile populated with 3 digit items is open, as well as an
//      outfile being open.
// Post: Pre and post insertions of various subcases of IsDoubleRotateLeftRight
//       are printed to the outfile.
// usage: IsDoubleRotateLeftRight(infile, outfile);
void testIsDoubleRotateLeftRight(ifstream& infile, ofstream& outfile);

// Reads infile and creates appropriate AVLTrees to test different
// subcases of the IsDoubleRotateRightLeft case.
// Pre: an infile populated with 3 digit items is open, as well as an
//      outfile being open.
// Post: Pre and post insertions of various subcases of IsDoubleRotateRightLeft
//       are printed to the outfile.
// usage: IsDoubleRotateRightLeft(infile, outfile);
void testIsDoubleRotateRightLeft(ifstream& infile, ofstream& outfile);

// Displays a given test, inserting items from the infile when needed, and
// displays the trees and conditions to the outfile
// Pre: An infile populated with 3 digit items is open, as well as an outfile
//      being open. Additionally, an AVLTree is prepared and ready to recieve
//      new nodes.
// Post: An outfile is filled with the printed conditions and printed AVLTrees.
// Usage: displayConditionsAndInsert(infile, outfile, mytree, newItem);
void displayConditionsAndInsert(ifstream& infile, ofstream& outfile, AVLTree& mytree, Item& myItem);

int main()
{
    ifstream infile;
    ofstream outfile;
    openInputFile(infile);
    openOutputFile(outfile);
    testHasNoPivot(infile, outfile);
    testIsAddedToShortSide(infile, outfile);
    testIsSingleRotateLeft(infile, outfile);
    testIsSingleRotateRight(infile, outfile);
    testIsDoubleRotateLeftRight(infile, outfile);
    testIsDoubleRotateRightLeft(infile, outfile);

    infile.close();
    outfile.close();
}

// Reads infile and creates appropriate AVLTrees to test different
// subcases of the hasNoPivot case.
// Pre: an infile populated with 3 digit items is open, as well as an
//      outfile being open.
// Post: Pre and post insertions of various subcases of hasNoPivot are printed
//      to the outfile.
// usage: testHasNoPivot(infile, outfile);
void testHasNoPivot(ifstream& infile, ofstream& outfile) // 100's
{
    AVLTree noPivot;
    Item anItem;
    outfile << "\t\tCASE OF NO PIVOT" << endl;

    outfile << "\nTest 1: CASE OF EMPTY TREE:" << endl << endl;
    displayConditionsAndInsert(infile, outfile, noPivot, anItem);


    outfile << "\nTest 2: CASE OF FULL TREE OF HEIGHT 2" << endl;
    for (int i = 0; i < 2; i++)
    {
        infile >> anItem;
        noPivot.insert(anItem);
    }
    displayConditionsAndInsert(infile, outfile, noPivot, anItem);

    outfile << "\nTest 3: CASE OF FULL TREE OF HEIGHT 3" << endl;
    for (int i = 0; i < 3; i++)
    {
        infile >> anItem;
        noPivot.insert(anItem);
    }
    displayConditionsAndInsert(infile, outfile, noPivot, anItem);
    outfile << endl;
}

// Reads infile and creates appropriate AVLTrees to test different
// subcases of the IsAddedToShortSide case.
// Pre: an infile populated with 3 digit items is open, as well as an
//      outfile being open.
// Post: Pre and post insertions of various subcases of IsAddedToShortSide
//       are printed to the outfile.
// usage: IsAddedToShortSide(infile, outfile);
void testIsAddedToShortSide(ifstream& infile, ofstream& outfile) // 200's
{
    AVLTree shortSide;
    Item anItem;

    outfile << "\n\t\tCASE OF IS ADDED TO SHORT SIDE" << endl;
    outfile << "\nTest 1: TREE HEIGHT 2 AND LEFT SIDE INSERT" << endl;
    for (int i = 0; i < 2; i++)
    {
        infile >> anItem;
        shortSide.insert(anItem);
    }
    displayConditionsAndInsert(infile, outfile, shortSide, anItem);

    outfile << "\nTest 2: TREE HEIGHT 3, LEFT RIGHT INSERT" << endl;
    infile >> anItem;
    shortSide.insert(anItem);
    displayConditionsAndInsert(infile, outfile, shortSide, anItem);

    outfile << "\nTest 3: TREE HEIGHT 3, RIGHT RIGHT INSERT" << endl;
    displayConditionsAndInsert(infile, outfile, shortSide, anItem);

    outfile << "\nTest 4: TREE HEIGHT 3, RIGHT LEFT INSERT" << endl;
    displayConditionsAndInsert(infile, outfile, shortSide, anItem);


    outfile << "\nTest 5: TREE HEIGHT 3, LEFT RIGHT INSERT" << endl;
    infile >> anItem;
    shortSide.insert(anItem);
    displayConditionsAndInsert(infile, outfile, shortSide, anItem);

}

// Reads infile and creates appropriate AVLTrees to test different
// subcases of the IsSingleRotateLeft case.
// Pre: an infile populated with 3 digit items is open, as well as an
//      outfile being open.
// Post: Pre and post insertions of various subcases of IsSingleRotateLeft
//       are printed to the outfile.
// usage: IsSingleRotateLeft(infile, outfile);
void testIsSingleRotateLeft(ifstream& infile, ofstream& outfile) // 300's
{
  AVLTree singleLeft;
  Item anItem;

  outfile << "\n\t\tCASE OF SINGLE ROTATE LEFT" << endl;
  outfile << "\nTest 1: TREE HEIGHT 2, DEGENERATE" << endl;
  for (int i = 0; i < 2; i++)
  {
      infile >> anItem;
      singleLeft.insert(anItem);
  }
  displayConditionsAndInsert(infile, outfile, singleLeft, anItem);

  outfile << "\nTest 2: TREE HEIGHT 3, RIGHT RIGHT RIGHT INSERT" << endl;
  infile >> anItem;
  singleLeft.insert(anItem);
  displayConditionsAndInsert(infile, outfile, singleLeft, anItem);

  outfile << "\nTest 3: TREE HEIGHT 3, RIGHT RIGHT RIGHT INSERT" << endl;
  displayConditionsAndInsert(infile, outfile, singleLeft, anItem);

  outfile << "\nTest 4: TREE HEIGHT 3, RIGHT RIGHT RIGHT INSERT" << endl;
  displayConditionsAndInsert(infile, outfile, singleLeft, anItem);

  outfile << "\nTest 5: TREE HEIGHT 4, LEFT RIGHT RIGHT RIGHT INSERT" << endl;
  infile >> anItem;
  singleLeft.insert(anItem);
  displayConditionsAndInsert(infile, outfile, singleLeft, anItem);

  outfile << "\nTest 6: TREE HEIGHT 4, LEFT RIGHT RIGHT RIGHT INSERT" << endl;
  displayConditionsAndInsert(infile, outfile, singleLeft, anItem);
}

// Reads infile and creates appropriate AVLTrees to test different
// subcases of the IsSingleRotateRight case.
// Pre: an infile populated with 3 digit items is open, as well as an
//      outfile being open.
// Post: Pre and post insertions of various subcases of IsSingleRotateRight
//       are printed to the outfile.
// usage: IsSingleRotateRight(infile, outfile);
void testIsSingleRotateRight(ifstream& infile, ofstream& outfile) // 400's
{
  AVLTree singleRight;
  Item anItem;

  outfile << "\n\t\tCASE OF SINGLE ROTATE RIGHT" << endl;
  outfile << "\nTest 1: TREE HEIGHT 3, DEGENERATE" << endl;
  for (int i = 0; i < 2; i++)
  {
      infile >> anItem;
      singleRight.insert(anItem);
  }
  displayConditionsAndInsert(infile, outfile, singleRight, anItem);


  outfile << "\nTest 2: TREE HEIGHT 3, LEFT LEFT LEFT INSERT" << endl;
  infile >> anItem;
  singleRight.insert(anItem);
  displayConditionsAndInsert(infile, outfile, singleRight, anItem);

  outfile << "\nTest 3: TREE HEIGHT 3, LEFT LEFT LEFT INSERT" << endl;
  displayConditionsAndInsert(infile, outfile, singleRight, anItem);

  outfile << "\nTest 4: TREE HEIGHT 3, LEFT LEFT LEFT INSERT" << endl;
  displayConditionsAndInsert(infile, outfile, singleRight, anItem);

  outfile << "\nTest 5: TREE HEIGHT 4, RIGHT RIGHT LEFT LEFT INSERT" << endl;
  infile >> anItem;
  singleRight.insert(anItem);
  displayConditionsAndInsert(infile, outfile, singleRight, anItem);

  outfile << "\nTest 6: TREE HEIGHT 4, LEFT RIGHT LEFT LEFT" << endl;
  infile >> anItem;
  singleRight.insert(anItem);
  displayConditionsAndInsert(infile, outfile, singleRight, anItem);

}

// Reads infile and creates appropriate AVLTrees to test different
// subcases of the IsDoubleRotateLeftRight case.
// Pre: an infile populated with 3 digit items is open, as well as an
//      outfile being open.
// Post: Pre and post insertions of various subcases of IsDoubleRotateLeftRight
//       are printed to the outfile.
// usage: IsDoubleRotateLeftRight(infile, outfile);
void testIsDoubleRotateLeftRight(ifstream& infile, ofstream& outfile) // 500's
{
    AVLTree doubleLeftRight;
    Item anItem;

    outfile << "\n\t\tCASE OF DOUBLE ROTATE LEFT RIGHT" << endl;
    outfile << "\nTest 1: TREE HEIGHT 2, DEGENERATE" << endl;
    for (int i = 0; i < 2; i++)
    {
        infile >> anItem;
        doubleLeftRight.insert(anItem);
    }
    displayConditionsAndInsert(infile, outfile, doubleLeftRight, anItem);

    outfile << "\nTest 2: TREE HEIGHT 3, LEFT LEFT RIGHT INSERT" << endl;
    infile >> anItem;
    doubleLeftRight.insert(anItem);
    displayConditionsAndInsert(infile, outfile, doubleLeftRight, anItem);

    outfile << "\nTest 3: TREE HEIGHT 3, LEFT RIGHT RIGHT INSERT" << endl;
    displayConditionsAndInsert(infile, outfile, doubleLeftRight, anItem);


    outfile << "\nTest 4: TREE HEIGHT 3, LEFT LEFT RIGHT INSERT" << endl;
    displayConditionsAndInsert(infile, outfile, doubleLeftRight, anItem);

    outfile << "\nTest 5: TREE HEIGHT 4, LEFT LEFT LEFT RIGHT INSERT" << endl;
    infile >> anItem;
    doubleLeftRight.insert(anItem);
    displayConditionsAndInsert(infile, outfile, doubleLeftRight, anItem);

    outfile << "\nTest 6: TREE HEIGHT 4, LEFT LEFT RIGHT RIGHT INSERT" << endl;
    displayConditionsAndInsert(infile, outfile, doubleLeftRight, anItem);
}

// Reads infile and creates appropriate AVLTrees to test different
// subcases of the IsDoubleRotateRightLeft case.
// Pre: an infile populated with 3 digit items is open, as well as an
//      outfile being open.
// Post: Pre and post insertions of various subcases of IsDoubleRotateRightLeft
//       are printed to the outfile.
// usage: IsDoubleRotateRightLeft(infile, outfile);
void testIsDoubleRotateRightLeft(ifstream& infile, ofstream& outfile) // 600's
{
    AVLTree doubleRightLeft;
    Item anItem;

    outfile << "\n\t\tCASE OF DOUBLE ROTATE RIGHT LEFT" << endl;
    outfile << "\nTest 1: TREE HEIGHT 2, DEGENERATE" << endl;
    for (int i = 0; i < 2; i++)
    {
        infile >> anItem;
        doubleRightLeft.insert(anItem);
    }
    displayConditionsAndInsert(infile, outfile, doubleRightLeft, anItem);

    outfile << "\nTest 2: TREE HEIGHT 3, RIGHT RIGHT LEFT INSERT" << endl;
    infile >> anItem;
    doubleRightLeft.insert(anItem);
    displayConditionsAndInsert(infile, outfile, doubleRightLeft, anItem);

    outfile << "\nTest 3: TREE HEIGHT 3, RIGHT LEFT LEFT INSERT" << endl;
    displayConditionsAndInsert(infile, outfile, doubleRightLeft, anItem);

    outfile << "\nTest 4: TREE HEIGHT 3, RIGHT RIGHT LEFT INSERT" << endl;
    displayConditionsAndInsert(infile, outfile, doubleRightLeft, anItem);

    outfile << "\nTest 5: TREE HEIGHT 4, RIGHT RIGHT RIGHT LEFT INSERT" << endl;
    infile >> anItem;
    doubleRightLeft.insert(anItem);
    displayConditionsAndInsert(infile, outfile, doubleRightLeft, anItem);

    outfile << "\nTest 6: TREE HEIGHT 4, RIGHT RIGHT LEFT RIGHT INSERT" << endl;
    displayConditionsAndInsert(infile, outfile, doubleRightLeft, anItem);
}

// Displays a given test, inserting items from the infile when needed, and
// displays the trees and conditions to the outfile
// Pre: An infile populated with 3 digit items is open, as well as an outfile
//      being open. Additionally, an AVLTree is prepared and ready to recieve
//      new nodes.
// Post: An outfile is filled with the printed conditions and printed AVLTrees.
// Usage: displayConditionsAndInsert(infile, outfile, mytree, newItem);
void displayConditionsAndInsert(ifstream& infile, ofstream& outfile, AVLTree& mytree, Item& myItem)
{
    outfile << endl;
    outfile << "Pre-insert Tree:" << endl << endl;
    mytree.prettyDisplay(outfile);
    outfile << endl;
    infile >> myItem;
    outfile << "Now inserting " << myItem << endl << endl;
    try{
    mytree.insert(myItem);
    }
    catch (Exception insert)
    {
      PrintExceptionMessage(insert, outfile);
    }
    outfile << "Post-insert Tree:" << endl;
    mytree.prettyDisplay(outfile);
}

// Open the file to be read from in the main program
// pre: infile is not open to a file
// post: infile can be used to read from a file
// usage: openInputFile(infile);
void openInputFile(ifstream& infile)
{
    infile.open("in8.dat");
    if(infile.fail())
    {
        cout << "Sorry there was an error in opening the input file";
        exit(1);
    }
}

// Open the file to be written in from in the main program
// pre: outfile is not open to a file
// post: outfile can be used to read from a file
// usage: openOutputFile(output);
void openOutputFile(ofstream& outfile)
{
    outfile.open("avl.dat");
    if(outfile.fail())
    {
        cout << "Sorry there was an error in opening the output Dicionary file";
        exit(1);
    }
}
