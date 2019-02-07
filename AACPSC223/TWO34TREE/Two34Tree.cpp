// Brett Barinaga, Kevin Mattappally
// Implementation of ADT 2-3-4 Tree
//     data object: a 2-3-4 tree (a tree containing 2-nodes,
//                  3-nodes, and 4-nodes) where a k-node has
//                  k children
// note: this is not the formal definition that takes 2 pages in textbook
//     operations: create, destroy, insert, display
// Programmer: dr y     Date: April 16, 2002
// Filename: Two34Tree.h
//

#include <stdio.h>
#include <iostream>
#include "Two34Tree.h"

// frees the heap memory of a tree
// pre: treep is assigned but may be empty
// post: all nodes in the tree with root treep
//       have been released back to the heap and
//       treep is empty
// usage: destroyTree (mroot);
void destroyTree(Two34TreeNode* treep)
{
    if (treep != nullptr)
    {
        for (int i = 0; i < 4; i++)
        {
            destroyTree(treep -> kids[i]);
        }
        delete treep;
        treep = nullptr;
    }
}

// shows the data in the tree in inorder
// pre: treep is assigned but may be empty
//      output is open
// post: the data items in the nodes of treep's tree
//       are printed to output in inorder
void inorder(ostream& output, Two34TreeNode* treep)
{
    if (treep != nullptr)
    {
        if (treep -> kids[0] == nullptr)
        {
            for (int i = 0; i < 3; i++)
            {
                if (!(treep -> keys[i].isEmpty()))
                    output << treep -> keys[i] << " ";
            }
        }
        else if (treep -> keys[1].isEmpty())
        {
            inorder(output, treep -> kids[0]);
            output << treep -> keys[0] << " ";
            inorder(output, treep -> kids[1]);
        }
        else if (treep -> keys[2].isEmpty())
        {
            inorder(output, treep -> kids[0]);
            output << treep -> keys[0] << " ";
            inorder(output, treep -> kids[1]);
            output << treep -> keys[1] << " ";
            inorder(output, treep -> kids[2]);
        }
        else
        {
            inorder(output, treep -> kids[0]);
            output << treep -> keys[0] << " ";
            inorder(output, treep -> kids[1]);
            output << treep -> keys[1] << " ";
            inorder(output, treep -> kids[2]);
            output << treep -> keys[2] << " ";
            inorder(output, treep -> kids[3]);
        }
    }
}

// shows the data in the tree in its tree structure
// pre: output is open. treep is assigned a tree.
//      level is assigned
// post: the data items of the nodes of treep at level
//       in the tree are printed to output with spacing
//       to denote the level.
// usage: pretty (output, mroot, 1);
void pretty(ostream& output, Two34TreeNode* treep, int level)
{
  if (treep != nullptr)
  {
    if (treep -> kids[3] == nullptr && treep -> kids[2] == nullptr)
    {
      pretty(output, treep -> kids[1], level + 1);
    }
    else
    {
      pretty(output, treep -> kids[3], level + 1);
      pretty(output, treep -> kids[2], level + 1);
    }

    if (level == 1)
      output << "root-> ";
    else
      for (int i = 0; i < level; i++)
        output << "        ";
    output << "(";
    if (!treep->keys[0].isEmpty())
      output << treep->keys[0];
    if (!treep->keys[1].isEmpty())
      output << "," << treep->keys[1];
    if (!treep->keys[2].isEmpty())
      output << "," << treep->keys[2];
    output << ")" << endl;

    if (treep -> kids[3] == nullptr && treep -> kids[2] == nullptr)
    {
      pretty(output, treep -> kids[0], level + 1);
    }
    else
    {
      pretty(output, treep -> kids[1], level + 1);
      pretty(output, treep -> kids[0], level + 1);
    }
  }
}

// inserts a Key into a two34 treenode that already has one
// key in it (twoNode)
// pre: newKey is assigned to a number and treep object exists
// post: newKey is added to treep, number order is preserved
// usage: insertIntoTwoNode(newKey, treep);
void insertIntoTwoNode(const Key& newKey, Two34TreeNode*& treep)
{
    if (treep -> keys[0] < newKey)
    {
        treep -> keys[1] = newKey;
    }
    else
    {
        treep -> keys[1] = treep -> keys[0];
        treep -> keys[0] = newKey;
    }
}

// inserts a Key into a two34 treenode that already has two
// keys in it (threeNode)
// pre: newKey is assigned to a number and treep object exists
// post: newKey is added to treep, number order is preserved
// usage: insertIntoThreeNode(newKey, treep);
void insertIntoThreeNode(const Key& newKey, Two34TreeNode*& treep)
{
    if (treep -> keys[0] < newKey && treep -> keys[1] < newKey)
    {
        treep -> keys[2] = newKey;
    }
    else if (treep -> keys[0] < newKey && newKey < treep -> keys[1])
    {
        treep -> keys[2] = treep -> keys[1];
        treep -> keys[1] = newKey;
    }
    else
    {
        treep -> keys[2] = treep -> keys[1];
        treep -> keys[1] = treep -> keys[0];
        treep -> keys[0] = newKey;
    }
}

// inserts a Key into a two34 treenode that already has three
// keys in it (fourNode)
// pre: newKey is assigned to a number and treep object exists
// post: newKey is added to treep, number order is preserved
// usage: insertIntoFourNodeLeft(newKey, treep);
void insertIntoFourNodeLeft(const Key& newKey, Two34TreeNode*& parent)
{
    if (parent -> keys[1].isEmpty())
    {
        insertIntoTwoNode(parent -> kids[0] -> keys[1] , parent);
    }
    else
    {
        insertIntoThreeNode(parent -> kids[0] -> keys[1] , parent);
        parent -> kids[3] = parent -> kids[2];
    }
    parent -> kids[2] = parent -> kids[1];
    parent -> kids[1] = new Two34TreeNode(parent -> kids[0] -> keys[2]);
    parent -> kids[0] -> cleanUpNode();
    if (newKey < parent -> keys[0])
        insertIntoTwoNode(newKey, parent -> kids[0]);
    else
        insertIntoTwoNode(newKey, parent -> kids[1]);
}

// inserts a Key into a two34 treenode that already has three
// keys in it (fourNode)
// pre: newKey is assigned to a number and treep object exists
// post: treep object is split, newKey is added to corresponding location
// usage: insertIntoFourNodeMiddle(newKey, treep);
void insertIntoFourNodeMiddle(const Key& newKey, Two34TreeNode*& parent)
{
    insertIntoThreeNode(parent -> kids[1] -> keys[1] , parent);
    parent -> kids[3] = parent -> kids[2];
    parent -> kids[2] = new Two34TreeNode(parent -> kids[1] -> keys[2]);
    parent -> kids[1] -> cleanUpNode();
    if (newKey < parent -> keys[1])
        insertIntoTwoNode(newKey, parent -> kids[1]);
    else
        insertIntoTwoNode(newKey, parent -> kids[2]);
}

// inserts a Key into a two34 treenode that already has three
// keys in it (fourNode)
// pre: newKey is assigned to a number and treep object exists
// post: treep object is split, newKey is added to corresponding location
// usage: insertIntoFourNodeRight(newKey, treep);
void insertIntoFourNodeRight(const Key& newKey, Two34TreeNode*& parent)
{
    if (parent -> keys[1].isEmpty())
    {
        insertIntoTwoNode(parent -> kids[1] -> keys[1] , parent);
        parent -> kids[2] = new Two34TreeNode(parent -> kids[1] -> keys[2]);
        parent -> kids[1] -> cleanUpNode();
        if (newKey < parent -> keys[1])
            insertIntoTwoNode(newKey, parent -> kids[1]);
        else
            insertIntoTwoNode(newKey, parent -> kids[2]);
    }
    else
    {
        insertIntoThreeNode(parent -> kids[2] -> keys[1] , parent);
        parent -> kids[3] = new Two34TreeNode(parent -> kids[2] -> keys[2]);
        parent -> kids[2] -> cleanUpNode();
        if (newKey < parent -> keys[2])
            insertIntoTwoNode(newKey, parent -> kids[2]);
        else
            insertIntoTwoNode(newKey, parent -> kids[3]);
    }
}

// creates an empty 2-3-4 Tree
// post: object is empty
Two34Tree::Two34Tree()
{
    root = new Two34TreeNode();
}

// destroys a 2-3-4 Tree
// pre: object exists
// post: object does not exist, all pre-memory released
Two34Tree::~Two34Tree()
{
    destroyTree(root);
}

// inserts a new key into the tree
// pre: tree object exists. newKey is assigned.
// post: newKey is placed in the appropriately sorted
//       position in the 2-3-4 tree object
// usage: tree.insert(mykey);
void Two34Tree::insert(const Key& newKey)
{
    // INSERTS INTO ROOT NODE
    // root is empty
    if (root -> keys[0].isEmpty() && root -> kids[0] == nullptr)
    {
        root -> keys[0] = newKey;
    }
    // root has one key
    else if (root -> keys[1].isEmpty() && root -> kids[0] == nullptr)
    {
        insertIntoTwoNode(newKey, root);
    }
    // root has 2 keys
    else if (root -> keys[2].isEmpty() && root -> kids[0] == nullptr)
    {
        insertIntoThreeNode(newKey, root);
    }
    else
    {
        if (root -> kids[0] == nullptr)
        {
            // split the root node, shit's going down
            root -> kids[0] = new Two34TreeNode(root -> keys[0]);
            root -> kids[1] = new Two34TreeNode(root -> keys[2]);
            root -> keys[0] = root -> keys[1];
            root -> cleanUpNode();
        }
        if (root -> keys[1].isEmpty())
        {
            if (newKey < root -> keys[0]) // insert to left of root (it's good)
            {
                if (root -> kids[0] -> keys[1].isEmpty())
                    insertIntoTwoNode(newKey, root -> kids[0]);
                else if (root -> kids[0] -> keys[2].isEmpty())
                    insertIntoThreeNode(newKey, root -> kids[0]);
                else
                    insertIntoFourNodeLeft(newKey, root);
            }
            else if (root -> keys[0] < newKey) // insert to right of root
            {
                if (root -> kids[1] -> keys[1].isEmpty())
                    insertIntoTwoNode(newKey, root -> kids[1]);
                else if (root -> kids[1] -> keys[2].isEmpty())
                    insertIntoThreeNode(newKey, root -> kids[1]);
                else
                    insertIntoFourNodeRight(newKey, root);
            }
        }
        else if (root -> keys[2].isEmpty())
        {
            if (newKey < root -> keys[0]) // insert to left of root (it's good)
            {
                if (root -> kids[0] -> keys[1].isEmpty())
                    insertIntoTwoNode(newKey, root -> kids[0]);
                else if (root -> kids[0] -> keys[2].isEmpty())
                    insertIntoThreeNode(newKey, root -> kids[0]);
                else
                    insertIntoFourNodeLeft(newKey, root);
            }
            else if (root -> keys[0] < newKey && newKey < root -> keys[1] )// insert to middle of root
            {
                if (root -> kids[1] -> keys[1].isEmpty())
                    insertIntoTwoNode(newKey, root -> kids[1]);
                else if (root -> kids[1] -> keys[2].isEmpty())
                    insertIntoThreeNode(newKey, root -> kids[1]);
                else
                    insertIntoFourNodeMiddle(newKey, root);
            }
            else
            {
                if (root -> kids[2] -> keys[1].isEmpty())
                    insertIntoTwoNode(newKey, root -> kids[1]);
                else if (root -> kids[2] -> keys[2].isEmpty())
                    insertIntoThreeNode(newKey, root -> kids[1]);
                else
                    insertIntoFourNodeRight(newKey, root);
            }
        }
        else // root has 3 keys, gotta split this big boy at the root, XC
        {

        }
    }
}

// displays a tree in one of two formats
// pre: which is either 'i' or 'p'
//      output is open
// post: if which is 'i' the tree is displayed inorder
//       else the tree is displayed showing its tree
//       structure
// usage: tree.display (cout, 'p');
void Two34Tree::display(ostream& output, char which)
{
    if (which == 'i')
    {
        inorder(output, root);
    }
    else if (which == 'p')
    {
        pretty(output, root, 1);
    }
}
