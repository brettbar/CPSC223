// Brett Barinaga, Kevin Mattappally
// 4/14/2018
// AVLTree.cpp
//   Implementation of ADT AVLTree
//   Data object: An AVLtree is a binary search tree, that is is either empty or in the form
//                where T is an AVLTree
//                                     r
//                                  /    \
//                                TL     TR
//             where the |height of TR – height of TL| <= 1 and TL, TR are AVL trees.
//  Data Structure: linked binary tree
//  Operations: insert and make search path, insert, fixbalances, writePretty,
//              various rotations


#include "AVLTree.h"
#include <fstream>

using namespace std;

const int MAXHEIGHT = 10;

struct SearchPath
{
    TreeNode* path[MAXHEIGHT];
    int pathSize;
    int pivotIndex; // to be explained later
    SearchPath();
};

// Prepares a SearchPath for searching through an AVLTree
// Pre: An instance of SearchPath is called, with an empty array path of size
//      MAXHEIGHT, and an undefined pathSize, and pivotIndex.
// Post: A SearchPath is initialized, with an array path full of nullptrs,
//      pathSize equal to 0, and pivotIndex set to -1.
// Usage: SearchPath(); (used in SearchPath struct declaration).
SearchPath::SearchPath() // constructor for the struct
{
    for (int i = 0; i < MAXHEIGHT; i++)
    {
        path[i] = nullptr;
    }
    pathSize = 0;
    pivotIndex = -1;
}

//Evan Swanson, Ryan Hays, Patrick Seminatore, Mason Dellutri, and Dr. Y

//Inserts a new item and assigns the search path and its size
//Pre: newitem has been assigned. treeptr is assigned root or
//     assigned another pointer in the AVL tree along the search path
//Post: if newitem's phone number is not already in the tree, then
//      newitem has been placed as in binary search tree and
//    search's pathSize is the number of nodes in the path and
//    search's path has been assigned to all the nodes in the search path
//Usage: BSTinsertAndMakeSearchPath(newitem, root, search);
void BSTinsertAndMakeSearchPath(const Item& newitem, TreeNode*& treeptr,  SearchPath& search) throw (Exception)
{
    search.path[search.pathSize] = treeptr;
    search.pathSize = search.pathSize + 1;

    if(treeptr == nullptr)
    {
        treeptr = new (nothrow) TreeNode(newitem, nullptr, nullptr);
        search.path[search.pathSize - 1] = treeptr;
        if (treeptr == nullptr)
            throw Exception("No room in memory");
        }
    else if (newitem == treeptr -> item)
        throw Exception("Phone number already exists in the dictionary");
    else if (newitem < treeptr -> item)
        BSTinsertAndMakeSearchPath(newitem, treeptr -> leftChild, search);
    else
        BSTinsertAndMakeSearchPath(newitem, treeptr -> rightChild, search);
    }

//Hunter Congress, Dylan Hay, Ryan Schoenlein, and Dr. Y

//checks to see if the search path has a pivot
//pre: AVL tree exists search's path has been
//     set to the nodes in the tree that formed the search path
//     also, search's pathSize >= 1
// post: if there is a pivot, then sets search's pivotIndex
//       so that search.path[search.pivotIndex]
//       points to the pivot node and returns false
//         it will return true
// usage: if (hasNoPivot(search))
bool hasNoPivot(SearchPath& search)
{
    const int TOP = 0;
    for (int k = search.pathSize - 1 ; k >= TOP ; k--)
    {
        if(search.path[k] -> balance  != 0)
        {
            search.pivotIndex = k;
            return false;
        }
    }
    return true;
}

// fixBalances.cpp
// Authors: Maxwell Chehab, Michael Fontanilla, Michael Newell

// Changes the balances along the provided search path
// from start to the parent of the inserted node.
// pre search has to exist, start is greater than or equal to 0.
// post the balances of the search path are incremented or decremented
// depending if they have a left or right child.
// usage fixBalances(search, 0);
void fixBalances(const SearchPath& search, int start) {
    for(int k = start; k < search.pathSize; k++) {
        if(search.path[k + 1] != nullptr and search.path[k]->leftChild == search.path[k + 1]){
            search.path[k]->balance -= 1;
        } else if(search.path[k + 1] != nullptr and search.path[k]->rightChild == search.path[k + 1]){
            search.path[k]->balance += 1;
        }
    }
}


// group members: Drew Bies, Andrew Flagstead,
//                Kevin Mattappally, Bo Volwiler, Dr. Y

// checks to see if a node
// was added to the "short side",the side with the
// lesser height
// pre: search's path has been assigned to the nodes in the tree
//      of the search path with nonzero pathSize.
//      it has been determined that there is
//      a pivot along the path so search.pivotIndex >= 0
// post: returns whether or not the node was
//       added to the short side
// usage: if(isAddedToShortSide(theSearchPath))
bool isAddedToShortSide(const SearchPath& search)
{
    // if the right side is the tall side
    if(search.path[search.pivotIndex] -> balance == 1)
    {
        // check to see if the path goes to the short side (to the left)
        if(search.path[search.pivotIndex + 1] == search.path[search.pivotIndex] -> leftChild)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    // if the left side is the tall side
    else // if (search.path[search.pivotIndex] -> balance == -1)
    {
        // check to see if the path goes to the short side (to the right)
        if(search.path[search.pivotIndex + 1] == search.path[search.pivotIndex] -> rightChild)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
}

//By Christian Kruep, Davis Fairchild, Sam Atkinson, Dr. Y

//Checks the search path of an AVLTree to see if the search path goes right
//    from the pivot node twice.
//PRE: search has been assigned: it has been determined that there is a pivot
//     so search.pivotIndex >= 0. search.pathSize > 0 and large enough to
//     have search.pivotIndex + 2 to have a non-nullptr.
//POST: returns true if the search path goes right from the pivot twice.
//        else returns false.
//USAGE: if(isSingleRotateLeft(search)
bool isSingleRotateLeft(const SearchPath& search)
{
    int pivot = search.pivotIndex;

    if(search.path[pivot] -> rightChild != nullptr and search.path[pivot] -> rightChild == search.path[pivot + 1])
    {
        if(search.path[pivot + 1] -> rightChild != nullptr and
           search.path[pivot + 1] -> rightChild == search.path[pivot + 2])
        {
            return true;
        } else {
            return false;
        }
    }
    else
        return false;
}

// Brett Barinaga, Alli Fellger, Amy Larson

// Determines whether or not there is the necessity of a single right
// rotation in order to restore balance in an AVL tree.

// pre:    - search is assigned and filled with pointers to each node in the order that they were
//           traversed to place the new Item.
//         - pivotIndex is assigned the index value for the pointer in search that is directed at the first
//           unbalanced node along the search path starting with the newly inserted Item.
//            - pathsize is large enough to have a search.pivotIndex + 2
// post: returns true if search indicates that the pivot is followed by two left paths, and false otherwise.
// usage: if(isSingleRightRotate(aPath)) { doSingleRightRotate(); }
bool isSingleRotateRight(const SearchPath& search)
{
    if (search.path[search.pivotIndex] -> leftChild != nullptr and
        search.path[search.pivotIndex] -> leftChild == search.path[search.pivotIndex + 1])
    {
        if (search.path[search.pivotIndex + 1] -> leftChild != nullptr and
            search.path[search.pivotIndex + 1] -> leftChild == search.path[search.pivotIndex + 2])
            return true;
        else
            return false;
    }
    else
        return false;
}

//authors: Andrew Abbott, John Distinti, Michael Hepburn, Kevin Shaw, Dr. Y

// tells whether or not the tree will need a double left right rotation
//pre: search exists, search.pivotIndex must be assigned to a non-negative number
//            search.path[search.pivotIndex}is assigned to the pivot
//     search.pathSize is large enough so search.path[search.pivotIndex + 2] is not
//     the nullptr
//post: returns true if search path goes left from the pivot and then right
//            Otherwise, is false
//usage: if (isDoubleRotateLeftRight(search))
bool isDoubleRotateLeftRight (const SearchPath& search){
    bool isRotation = false;
    int pivot = search.pivotIndex;

    if(search.path[pivot] -> leftChild == search.path[pivot + 1]){
        if(search.path[pivot + 1] != nullptr &&
           search.path[pivot + 1] -> rightChild == search.path[pivot + 2]){
            isRotation = true;
        }
    }
    return isRotation;
}

// helps to print out the tree in a pretty display format
// pre: treep is a treeNode and level is the treeNode level
// post: the tree is printed out to the console
// usage: writePrettyAVL(treep, level);
void writePrettyAVL (TreeNode* treep, int level, ofstream& outfile)
{
    if (treep != nullptr)
    {
        Key akey;
        writePrettyAVL(treep -> rightChild, level + 1, outfile);
        if (treep -> rightChild != nullptr)
        {
            for (int i = 0; i < level; i++)
            {
                outfile << "            ";
            }
            outfile << "/" << endl;
        }
        if (level == 1)
        {
            outfile << "root -> ";
        }
        else
        {
            for (int i = 0; i < level - 1; i++)
            {
                outfile << "            ";
            }
        }
        akey = treep -> item;
        outfile << akey << treep -> balance << endl;
        if (treep -> leftChild != nullptr)
        {
            for (int i = 0; i < level; i++)
            {
                outfile << "            ";
            }
            outfile << "\\" << endl;
            writePrettyAVL(treep -> leftChild, level + 1, outfile);
        }
    }
}

//************************ Helper Functions **********************************//

// Helper function that performs a Single Left Rotation on an AVLTree
// Pre: A SearchPath exists which follows an AVLTree. The AVLTree has a pivot
//      who's balance is 1, and a new node is inserted to the AVLTree as a right
//      child of pivot.
//      Example Pre insert(777):
//                  777:0 <- newguy
//                  /
//                666:0
//                /
//      root -> 555:1
//
// Post: The AVLTree will be rotated with correct node locations to satisfy
//       the definition of ADT AVLTree,
//       but with incorrect balances (fixed later in fixedBalances).
//      Example Post:
//                777:0
//                /
//      root -> 666:0
//                \
//                555:1
// Usage:  doSingleLeftRotate(search, root);
void doSingleLeftRotate(SearchPath& search, TreeNode*& treep)
{
    TreeNode* childOfPivot;
    TreeNode* pivot;
     pivot = search.path[search.pivotIndex];
     childOfPivot = search.path[search.pivotIndex] -> rightChild;
     pivot -> rightChild = childOfPivot -> leftChild;
     childOfPivot -> leftChild = pivot;
     if (search.path[0] != search.path[search.pivotIndex])
     {
         if (search.path[search.pivotIndex - 1] -> item < search.path[search.pivotIndex + 1] -> item)
         {
             search.path[search.pivotIndex - 1] -> rightChild = search.path[search.pivotIndex + 1];
         }
        else
        {
            search.path[search.pivotIndex - 1] -> leftChild = search.path[search.pivotIndex + 1];
        }
    }
    else
    {
        treep = childOfPivot;
    }
    pivot -> balance = 0;
    childOfPivot -> balance = 0;
}

// Helper function that performs a Single Right Rotation on an AVLTree
// Pre: A SearchPath exists which follows an AVLTree. The AVLTree has a pivot
//      who's balance is -1, and a new node is inserted to the AVLTree as a left
//      child of pivot.
//      Example Pre insert(777):
//      root -> 777:-1
//                \
//                666:0
//                  \
//                  555:0 <- newguy
//
// Post: The AVLTree will be rotated with correct node locations to satisfy
//       the definition of ADT AVLTree,
//        but with incorrect balances, fixed later in fixedBalances.
//      Example Post:
//                777:-1
//                /
//      root -> 666:0
//                \
//                555:0
// Usage:  doSingleRightRotate(search, root);
void doSingleRightRotate(SearchPath& search, TreeNode*& treep)
{
    TreeNode* childOfPivot;
    TreeNode* pivot;
    pivot = search.path[search.pivotIndex];
    childOfPivot = search.path[search.pivotIndex] -> leftChild;
    pivot -> leftChild = childOfPivot -> rightChild;
    childOfPivot -> rightChild = pivot;
    if (search.path[0] != search.path[search.pivotIndex])
    {
        if (search.path[search.pivotIndex - 1] -> item < search.path[search.pivotIndex + 1] -> item)
        {
            search.path[search.pivotIndex - 1] -> rightChild = search.path[search.pivotIndex + 1];
        }
        else
        {
            search.path[search.pivotIndex - 1] -> leftChild = search.path[search.pivotIndex + 1];
        }
    }
    else
    {
        treep = childOfPivot;
    }
    pivot -> balance = 0;
    childOfPivot -> balance = 0;
}

// Helper function that performs a Double Left Right Rotation on an AVLTree
// Pre: A SearchPath exists which follows an AVLTree. The AVLTree has a pivot.
//      Example Pre insert(510):
//             550:0
//             /
// root -> 530:-1
//             \
//             525:-1
//                 \
//                        510 <-newguy
//                        /
//                   505:0
//
// Post: The AVLTree will be rotated twice with correct node locations to satisfy
//       the definition of ADT AVLTree, but with incorrect balances fixed later
//        in fixedBalances.
//      Example Post:
//          550:0
//             /
// root -> 530:-1
//             \
//                 525:-1
//                   /
//             510:0
//                   \
//                   505:0
// Usage:  doDoubleLeftRightRotate(search, root);
void doDoubleLeftRightRotate(SearchPath& search, TreeNode*& treep)
{
    TreeNode* childOfPivot;
    TreeNode* pivot;
    TreeNode* grandChild;

    pivot = search.path[search.pivotIndex];
    childOfPivot = search.path[search.pivotIndex] -> leftChild;
    grandChild = search.path[search.pivotIndex + 2];

    childOfPivot -> rightChild = grandChild -> leftChild;
    pivot -> leftChild = grandChild -> rightChild;
    grandChild -> leftChild = childOfPivot;
    grandChild -> rightChild = pivot;

    if (search.path[0] != search.path[search.pivotIndex])
    {
        if (search.path[search.pivotIndex - 1] -> item < search.path[search.pivotIndex + 1] -> item)
        {
            search.path[search.pivotIndex - 1] -> rightChild = search.path[search.pivotIndex + 2];
        }
        else
        {
            search.path[search.pivotIndex - 1] -> leftChild = search.path[search.pivotIndex + 2];
        }
    }
    else
    {
        treep = grandChild;
    }
    if (childOfPivot -> leftChild == nullptr)
    {
        childOfPivot -> balance = 0;
        pivot -> balance = 0;
    }
    else if (search.path[search.pivotIndex + 3] == childOfPivot -> rightChild)
    {
        childOfPivot -> balance = 0;
        pivot -> balance = 1;
    }
    else if (search.path[search.pivotIndex + 3] == pivot -> leftChild)
    {
        childOfPivot -> balance = -1;
        pivot -> balance = 0;
    }
    grandChild -> balance = 0;
}

// Helper function that performs a Double Right Left Rotation on an AVLTree
// Pre: A SearchPath exists which follows an AVLTree. The AVLTree has a pivot.
//      Example Pre insert(680):
//               685:0
//                    \
//                     680:0
//             /
//           675:1
//           /
// root -> 670:1
//           \
//           650:0
//
// Post: The AVLTree will be rotated twice with correct node locations to satisfy
//       the definition of ADT AVLTree, but with incorrect balances fixed later
//        in fixedBalances.
//      Example Post:
//                 685:0
//                 /
//           680:0
//                 \
//                 675:1
//           /
// root -> 670:1
//           \
//           650:0
// Usage:  doDoubleRightLeftRotate(search, root);
void doDoubleRightLeftRotate(SearchPath& search, TreeNode*& treep)
{
    TreeNode* childOfPivot;
    TreeNode* pivot;
    TreeNode* grandChild;

    pivot = search.path[search.pivotIndex];
    childOfPivot = search.path[search.pivotIndex] -> rightChild;
    grandChild = search.path[search.pivotIndex + 2];

    childOfPivot -> leftChild = grandChild -> rightChild;
    pivot -> rightChild = grandChild -> leftChild;
    grandChild -> rightChild = childOfPivot;
    grandChild -> leftChild = pivot;

    if (search.path[0] != search.path[search.pivotIndex])
    {
        if (search.path[search.pivotIndex - 1] -> item < search.path[search.pivotIndex + 1] -> item)
        {
            search.path[search.pivotIndex - 1] -> rightChild = search.path[search.pivotIndex + 2];
        }
        else
        {
            search.path[search.pivotIndex - 1] -> leftChild = search.path[search.pivotIndex + 2];
        }
    }
    else
    {
        treep = grandChild;
    }
    if (childOfPivot -> rightChild == nullptr)
    {
        childOfPivot -> balance = 0;
        pivot -> balance = 0;
    }
    else if (search.path[search.pivotIndex + 3] == childOfPivot -> leftChild)
    {
        childOfPivot -> balance = 0; //0
        pivot -> balance = -1; //1
    }
    else if (search.path[search.pivotIndex + 3] == pivot -> rightChild)
    {
        childOfPivot -> balance = 1; //-1
        pivot -> balance = 0; //0
    }
    grandChild -> balance = 0;
}

AVLTree::AVLTree()
{
  // inherited from BST
}

AVLTree::~AVLTree()
{
  // inherited from BST
}

// Inserts a newItem into the AVLTree, fixing the AVLTree with various
// methods when needed, and fixes Tree balances.
// Pre: An AVLTree exists, and a newItem is passed
// Post: A node is inserted into the tree, and the tree is rotated if needed
//      and the balances are fixed.
// usage myAVLTree.insert(newguy);
void AVLTree::insert(const Item& newItem) throw (Exception)
{
    SearchPath search;
    BSTinsertAndMakeSearchPath(newItem, root, search);
    if(hasNoPivot(search))
        fixBalances(search, 0);
    else if (isAddedToShortSide(search))
        fixBalances(search, search.pivotIndex);
    else if (isSingleRotateLeft(search))
    {
        doSingleLeftRotate(search, root);
        fixBalances(search, search.pivotIndex + 2);
    }
    else if (isSingleRotateRight(search))
    {
        doSingleRightRotate(search, root);
        fixBalances(search, search.pivotIndex + 2);
    }
    else if (isDoubleRotateLeftRight (search))
    {
        doDoubleLeftRightRotate(search, root);
        fixBalances(search, search.pivotIndex + 3);
    }
    else
    {
        doDoubleRightLeftRotate(search, root);
        fixBalances(search, search.pivotIndex + 3);
    }
}

// Prints the tree to the outfile in a readable manner
// Pre: an outfile is open, and a root exists pointing to an AVLTree
// Post: the root and AVLTree are printed in a nice manner to the outfile
// usage: myAVLTree.prettyDisplay(outfile);
void AVLTree::prettyDisplay(ofstream& outfile)
{
    writePrettyAVL(root, 1, outfile);
}
