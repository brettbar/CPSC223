// Brett Barinaga, Kevin Mattappally
// 5/3/2018
// Clientprogram.cpp
// This program tests various insertion cases of the ADT Two34Tree, and
// prints out results to an output file.

#include <iostream>
#include <fstream>
#include "Two34Tree.h"
#include "Two34TreeNode.h"

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

// Tests various cases of: Inserts 3 keys into a root node with no splliting in
// all its possible orders and prints the pre and post trees.
// pre: an infile is open with necessary keys, and an outfile is also open
// post: the resulting root node is printed to the outfile
// usage: insertIntoRootInitial(infile, outfile);
void insertIntoRootInitial(ifstream& infile, ofstream& outfile); // 6 cases

// Tests various cases of:
// Inserts new key causing the root node to split, and adds to either left or
// right child of root in its four cases
// pre: an infile is open with necessary keys, and an outfile is also open
// post: the resulting tree is printed to the outfile
// usage: rootSplitAndInsert(infile, outfile);
void rootSplitAndInsert(ifstream& infile, ofstream& outfile); // 4 cases

// Tests various cases of:
// Inserts new key into a level 2 node after a rootSplitAndInsert scenario
// pre: an infile is open with necessary keys, and an outfile is also open
// post: the resulting tree is printed to the outfile
// usage: levelTwoInserts(infile, outfile);
void levelTwoInserts(ifstream& infile, ofstream& outfile);

// Tests various cases of:
// Inserts new key to a 234 tree, which causes a split of a level 2 node,
// resulting in 3 children and having the new key go to each of the tree
// children in different cases
// pre: an infile is open with necessary keys, and an outfile is also open
// post: the resulting tree is printed to the outfile
// usage: levelTwoSplitThreeChildren(infile, outfile);
void levelTwoSplitThreeChildren(ifstream& infile, ofstream& outfile);

// Tests various cases of:
// Inserts a new key, to each of the three children in level 2 of a 234 tree,
// after the insert causing the split in case levelTwoSplitThreeChildren
// pre: an infile is open with necessary keys, and an outfile is also open
// post: the resulting tree is printed to the outfile
// usage: threeChildrenInserts(infile, outfile);
void threeChildrenInserts(ifstream& infile, ofstream& outfile);

// Tests various cases of: Inserts a new key to cause the split of a level 2
// node so now there are 4 children and inserts into the children
// pre: an infile is open with necessary keys, and an outfile is also open
// post: the resulting tree is printed to the outfile
// usage: fourChildrenInserts(infile, outfile);
void fourChildrenInserts(ifstream& infile, ofstream& outfile);

// Inserts a specific number of keys to prepare a tree for a test.
// pre: infile and outfile are open, nothing is in the tree
// post: a tree is inserted with a designated number of keys from the infile
// usage: preConditionInsertation(infile, outfile, 2);
void preConditionInsertation(ifstream& infile, ofstream& outfile, int keys);

// Displays a given test, inserting items from the infile when needed, and
// displays the trees and conditions to the outfile
// Pre: An infile populated with 3 digit items is open, as well as an outfile
//      being open. Additionally, an tree is prepared and ready to recieve
//      new nodes.
// Post: An outfile is filled with the printed conditions and printed trees.
// Usage: displayConditionsAndInsert(infile, outfile, mytree, newKey);
void displayConditionsAndInsert(ifstream& infile, ofstream& outfile, Two34Tree& myTreeOne, Key& myKey);


int main()
{
    ifstream infile;
    ofstream outfile;
    openInputFile(infile);
    openOutputFile(outfile);

    insertIntoRootInitial(infile, outfile); // 6 cases
    rootSplitAndInsert(infile, outfile); // 4 cases
    levelTwoInserts(infile, outfile);
    levelTwoSplitThreeChildren(infile, outfile);
    threeChildrenInserts(infile, outfile);
    fourChildrenInserts(infile, outfile);

    infile.close();
    outfile.close();
    return 0;
}

// Inserts 3 keys into a root node with no splliting in all its possible orders
// and prints the pre and post trees.
// pre: an infile is open with necessary keys, and an outfile is also open
// post: the resulting root node iS printed to the outfile
// usage: insertIntoRootInitial(infile, outfile);
void insertIntoRootInitial(ifstream& infile, ofstream& outfile) // 6 cases
{
  outfile << "\t\tCASE 1 OF INSERT: INTO ROOT NO SPLITTING" << endl << endl;
  outfile << "SUBCASE 1: insert(100) , insert(105), insert (110)" << endl;
  preConditionInsertation(infile, outfile, 2);
  outfile << "SUBCASE 2: insert(105) , insert(100), insert (110)" << endl;
  preConditionInsertation(infile, outfile, 2);
  outfile << "SUBCASE 3: insert(105) , insert(110), insert (100)" << endl;
  preConditionInsertation(infile, outfile, 2);
  outfile << "SUBCASE 4: insert(100) , insert(110), insert (105)" << endl;
  preConditionInsertation(infile, outfile, 2);
  outfile << "SUBCASE 5: insert(110) , insert(105), insert (100)" << endl;
  preConditionInsertation(infile, outfile, 2);
  outfile << "SUBCASE 6: insert(110) , insert(100), insert (105)" << endl;
  preConditionInsertation(infile, outfile, 2);
}

// Inserts new key causing the root node to split, and adds to either left or
// right child of root in its four cases
// pre: an infile is open with necessary keys, and an outfile is also open
// post: the resulting tree is printed to the outfile
// usage: rootSplitAndInsert(infile, outfile);
void rootSplitAndInsert(ifstream& infile, ofstream& outfile) // 4 cases
{
  outfile << "\t\tCASE 2 OF INSERT: ROOT SPLIT AND INSERT" << endl << endl;
  outfile << "SUBCASE 1: Splitting root, inserting into left" << endl;
  preConditionInsertation(infile, outfile, 3);
  outfile << "SUBCASE 2: Splitting root, inserting into left" << endl;
  preConditionInsertation(infile, outfile, 3);
  outfile << "SUBCASE 3: Splitting root, inserting into right" << endl;
  preConditionInsertation(infile, outfile, 3);
  outfile << "SUBCASE 4: Splitting root, inserting into right" << endl;
  preConditionInsertation(infile, outfile, 3);
}

// Inserts new key into a level 2 node after a rootSplitAndInsert scenario
// pre: an infile is open with necessary keys, and an outfile is also open
// post: the resulting tree is printed to the outfile
// usage: levelTwoInserts(infile, outfile);
void levelTwoInserts(ifstream& infile, ofstream& outfile)
{
  outfile << "\t\tCASE 3 OF INSERT: ROOT SPLIT AND INSERT" << endl << endl;
  outfile << "SUBCASE 1: inserting into right child of a case 2 tree" << endl;
  preConditionInsertation(infile, outfile, 4);
  outfile << "SUBCASE 2: inserting into left child of a case 2 tree" << endl;
  preConditionInsertation(infile, outfile, 4);
  outfile << "SUBCASE 3: inserting into left child of a case 2 tree" << endl;
  preConditionInsertation(infile, outfile, 4);
  outfile << "SUBCASE 4: inserting into right child of a case 2 tree" << endl;
  preConditionInsertation(infile, outfile, 4);
}

// Inserts new key to a 234 tree, which causes a split of a level 2 node,
// resulting in 3 children and having the new key go to each of the tree
// children in different cases
// pre: an infile is open with necessary keys, and an outfile is also open
// post: the resulting tree is printed to the outfile
// usage: levelTwoSplitThreeChildren(infile, outfile);
void levelTwoSplitThreeChildren(ifstream& infile, ofstream& outfile)
{
  outfile << "\n\t\tCASE 4 OF INSERT: LEVEL 2 NODE SPLIT" << endl << endl;
  outfile << "\nSUBCASE 1: Splitting left node, inserting into left" << endl;
  preConditionInsertation(infile, outfile, 5);
  outfile << "\nSUBCASE 2: Splitting left node, inserting into left" << endl;
  preConditionInsertation(infile, outfile, 5);
  outfile << "\nSUBCASE 3: Splitting left node, inserting into middle" << endl;
  preConditionInsertation(infile, outfile, 5);
  outfile << "\nSUBCASE 4: Splitting left node, inserting into middle" << endl;
  preConditionInsertation(infile, outfile, 5);
  outfile << "\nSUBCASE 5: Splitting right node, inserting into middle" << endl;
  preConditionInsertation(infile, outfile, 5);
  outfile << "\nSUBCASE 6: Splitting right node, inserting into middle" << endl;
  preConditionInsertation(infile, outfile, 5);
  outfile << "\nSUBCASE 7: Splitting right node, inserting into right" << endl;
  preConditionInsertation(infile, outfile, 5);
  outfile << "\nSUBCASE 8: Splitting right node, inserting into right" << endl;
  preConditionInsertation(infile, outfile, 5);
}

// Inserts a new key, to each of the three children in level 2 of a 234 tree,
// after the insert causing the split in case levelTwoSplitThreeChildren
// pre: an infile is open with necessary keys, and an outfile is also open
// post: the resulting tree is printed to the outfile
// usage: threeChildrenInserts(infile, outfile);
void threeChildrenInserts(ifstream& infile, ofstream& outfile)
{
  outfile << "\n\t\tCASE 5 OF INSERT: INSERTING TO THREE CHILDREN" << endl << endl;
  outfile << "\nSUBCASE 1: Inserting into left node" << endl;
  preConditionInsertation(infile, outfile, 6);
  outfile << "\nSUBCASE 2: Inserting into middle node" << endl;
  preConditionInsertation(infile, outfile, 7);
  outfile << "\nSUBCASE 3: Inserting into middle node" << endl;
  preConditionInsertation(infile, outfile, 8);
  outfile << "\nSUBCASE 4: Inserting into right node" << endl;
  preConditionInsertation(infile, outfile, 9);
  outfile << "\nSUBCASE 5: Inserting into right node" << endl;
  preConditionInsertation(infile, outfile, 10);
}

// Tests various cases of: Inserts a new key to cause the split of a level 2
// node so now there are 4 children and inserts into the children
// pre: an infile is open with necessary keys, and an outfile is also open
// post: the resulting tree is printed to the outfile
// usage: fourChildrenInserts(infile, outfile);
void fourChildrenInserts(ifstream& infile, ofstream& outfile)
{
  outfile << "\n\t\tCASE 6 OF INSERT: SPLIT RESULTING IN FOUR CHILDREN" << endl << endl;
  outfile << "\nSUBCASE 1: Splitting left node, inserting into left" << endl;
  preConditionInsertation(infile, outfile, 7);
  outfile << "\nSUBCASE 2: Splitting left node, inserting into left" << endl;
  preConditionInsertation(infile, outfile, 7);
  outfile << "\nSUBCASE 3: Splitting left node, inserting into right" << endl;
  preConditionInsertation(infile, outfile, 7);
  outfile << "\nSUBCASE 4: Splitting left node, inserting into right" << endl;
  preConditionInsertation(infile, outfile, 7);
  outfile << "\nSUBCASE 5: Splitting middle node, inserting into left" << endl;
  preConditionInsertation(infile, outfile, 7);
  outfile << "\nSUBCASE 6: Splitting middle node, inserting into left" << endl;
  preConditionInsertation(infile, outfile, 7);
  outfile << "\nSUBCASE 7: Splitting middle node, inserting into right" << endl;
  preConditionInsertation(infile, outfile, 7);
  outfile << "\nSUBCASE 8: Splitting middle node, inserting into right" << endl;
  preConditionInsertation(infile, outfile, 7);
  outfile << "\nSUBCASE 9: Splitting right node, inserting into left" << endl;
  preConditionInsertation(infile, outfile, 7);
  outfile << "\nSUBCASE 10: Splitting right node, inserting into left" << endl;
  preConditionInsertation(infile, outfile, 7);
  outfile << "\nSUBCASE 11: Splitting right node, inserting into right" << endl;
  preConditionInsertation(infile, outfile, 7);
  outfile << "\nSUBCASE 12: Splitting right node, inserting into right" << endl;
  preConditionInsertation(infile, outfile, 7);
}

// Open the file to be read from in the main program
// pre: infile is not open to a file
// post: infile can be used to read from a file
// usage: openInputFile(infile);
void openInputFile(ifstream& infile)
{
    infile.open("input.dat");
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
    outfile.open("Two.dat");
    if(outfile.fail())
    {
        cout << "Sorry there was an error in opening the output Dicionary file";
        exit(1);
    }
}

// Inserts a specific number of keys to prepare a tree for a test.
// pre: infile and outfile are open, nothing is in the tree
// post: a tree is inserted with a designated number of keys from the infile
// usage: preConditionInsertation(infile, outfile, 2);
void preConditionInsertation(ifstream& infile, ofstream& outfile, int keys)
{
    Two34Tree myTree;
    Key myKey;
    for (int i = 0; i < keys; i++)
    {
        infile >> myKey;
        myTree.insert(myKey);
    }
    displayConditionsAndInsert(infile, outfile, myTree, myKey);
}

// Displays a given test, inserting items from the infile when needed, and
// displays the trees and conditions to the outfile
// Pre: An infile populated with 3 digit items is open, as well as an outfile
//      being open. Additionally, an tree is prepared and ready to recieve
//      new nodes.
// Post: An outfile is filled with the printed conditions and printed trees.
// Usage: displayConditionsAndInsert(infile, outfile, mytree, newKey);
void displayConditionsAndInsert(ifstream& infile, ofstream& outfile, Two34Tree& myTreeOne, Key& myKey)
{
    outfile << "Pre-insert Tree:" << endl << endl;
    myTreeOne.display(outfile, 'p');
    infile >> myKey;
    outfile << "Now inserting " << myKey << endl << endl;
    myTreeOne.insert(myKey);
    outfile << "Post-insert Tree:" << endl << endl;
    myTreeOne.display(outfile, 'p');
    outfile << endl;
}
