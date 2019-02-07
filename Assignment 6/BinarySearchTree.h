// BinarySearchTree.h

#include "BinaryTree.h"
#include "Exception.h"

class BinarySearchTree: public BinaryTree
{
public:
  BinarySearchTree();
  BinarySearchTree(const BinarySearchTree& rhsBinarySearchTree);
  ~BinarySearchTree();

  // we get operator=, traversals for free

  // new operators: search, remove, insert

  void search(const Key& targetPhone, Item& theItem) throw (Exception);

  void insert(const Item& newItem) throw (Exception);

  void remove(const Key& targetPhone) throw (Exception);

  void inorderTraverse();
protected:
  int numberOfEntries;
};
