#include "TreeNode.h"

TreeNode::TreeNode()
{
  leftChild = nullptr;
  rightChild = nullptr;
  balance = 0;
}

TreeNode::TreeNode(const Item& newItem, TreeNode* theLeft, TreeNode* theRight)
{
  item = newItem;
  leftChild = theLeft;
  rightChild = theRight;
  balance = 0;
}
