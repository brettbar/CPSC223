// AVLTree.h

#ifndef AVLTREE_H
#define AVLTREE_H

#include "BinarySearchTree.h"
#include "Exception.h"
#include "TreeNode.h"
#include "Item.h"


class AVLTree: public BinarySearchTree
{
public:
AVLTree();

~AVLTree();


void insert(const Item& newItem) throw (Exception);


};

#endif
