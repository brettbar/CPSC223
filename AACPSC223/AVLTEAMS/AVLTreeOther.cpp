// AVLTree.cpp

#include "AVLTree.h"


struct SearchPath
{
  TreeNode* path[MAXHEIGHT]
  int pathSize;
  int pivotIndex; // to be explained later
  SearchPath();
}

SearchPath::SearchPath() // contructor for the struct
{
  AVLTree::AVLTree();
  {
    pathSize = 0;
    pivotIndex = -1;
    for (int i = 0; i < MAXHEIGHT; i++)
    {
      path[i] = nullptr;
    }
  }

  AVLTree::~AVLTree();
  {
    delete[] path;
    path = nullptr;
    size = 0;
    pivotIndex = 0; // determine later
  }

  void AVLtree::insert(const Item& newItem) throw (Exception)
  {
    SearchPath search;
    BSTinsertAndMakeSearchPath(root, newItem, search);
    if (hasNoPivot(search))
      fixBalances(search, 0);
    else if (isAddedToShortSide(search))
      fixBalances(search, search.pivotIndex);

  }
}
