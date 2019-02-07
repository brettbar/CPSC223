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

}

AVLTree::AVLTree();
{
}

AVLTree::~AVLTree();
{
}

void insert(const Item& newItem) throw (Exception)
{

}
