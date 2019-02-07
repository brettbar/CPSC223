// Abstract Data Type Stack: 
//    data object is a stack where the most-recently-added (or top) item
//                is most-easily accessible
//    operations on a stack:
//        create an empty stack
//        delete memory or "destroy" the stack
//        add a new item as the most-recently-added or top item
//        retrieve the most-recently-added or top item from the stack and copy
//        remove the most-recently-added or top item from the stack
//        check if the stack is empty
#ifndef STACK_H
#define STACK_H

#include "Item.h"

struct Node;

class Stack
{
public: // methods or member functions

   // creates an empty stack 
   // post: an empty Stack object exists
   // usage: Stack aStack;
   Stack();
   
   // releases memory for the stack
   // pre: a Stack object exists
   // post: the memory for Stack object has been released
   ~Stack();
   
   // creates and copies a stack
   // pre: rhsStack has been assigned
   // post: Stack object has the same items in the same order as rhsStack
   // usage: passing by value
   Stack (const Stack& rhsStack);
   
   // adds a new item as the most-recently added or top item
   // pre: newItem has been assigned; Stack object exists
   // post: if the Stack object is not full, newItem is added at the top
   //          and isAdded is true; else isAdded is false
   // usage: aStack.push(newguy, isAdded);
   void push (const Item& newItem, bool& isAdded);
   
   // removes the most-recently-added or top item
   // pre: Stack object exists and is not empty
   // post: most-recently added or top item has been removed from the Stack object
   // usage: if( not aStack.isEmpty()) aStack.pop();
   void pop();
   
   // copies the most-recently added or top item from the stack
   // pre: Stack object exists and is not empty
   // post: top item has been copied into topItem. Stack object is unchanged.
   // usage: aStack.getTop(topguy);
   void getTop(Item& topItem) const;
 
   // checks whether or not a stack is empty
   // pre: Stack object exists
   // post: if Stack object is empty then returns true; else returns false
   // usage: if(aStack.isEmpty())
   bool isEmpty() const;

   // copies a stack
   // pre: rhsStack is an existing Stack object
   // post: Stack object is a copy of rhsStack
   // usage: mystk = yourstk;
   Stack& operator=(const Stack& rhsStack);
   
private:

   Node* topptr;
};
#endif