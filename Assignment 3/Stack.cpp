// stack.cpp
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

#include "Stack.h"
#include <iostream>
using namespace std;


struct Node
{
	Item item;
	Node* next;
};

// creates an empty stack 
// post: an empty Stack object exists
// usage: Stack aStack;
Stack::Stack()
{
   topptr = nullptr;
}
 
// creates and copies a stack
// pre: rhsStack has been assigned
// post: Stack object has the same items in the same order as rhsStack
// usage: passing by value
Stack::Stack (const Stack& rhsStack)
{
	Node* rhsPtr;
	Node* currPtr;
	
	topptr = nullptr;
    operator=(rhsStack);
}
 
// releases memory for the stack
// pre: a Stack object exists
// post: the memory for Stack object has been released
Stack:: ~Stack()
{
   while (not isEmpty())
   {
	  pop();
   }
}
   
// adds a new item as the most-recently added or top item
// pre: newItem has been assigned; Stack object exists
// post: if the Stack object is not full, newItem is added at the top
//          and isAdded is true; else isAdded is false
// usage: aStack.push(newguy, isAdded);
void Stack:: push (const Item& newItem, bool& isAdded)
{   
    Node* newNodeptr;
	   
	newNodeptr = new (nothrow) Node;
	if (newNodeptr != nullptr)
	{
	   newNodeptr -> item = newItem;
	   newNodeptr -> next = topptr;
	   topptr = newNodeptr;
	   isAdded = true;
	} else {
		isAdded = false;
	}
} 
   
// removes the most-recently-added or top item
// pre: Stack object exists and is not empty
// post: most-recently added or top item has been removed from the Stack object
// usage: if( not aStack.isEmpty()) aStack.pop();
void Stack::pop()
{
   Node* delptr;
   delptr = topptr;
   topptr = topptr -> next;
   delete delptr;
   delptr = nullptr;
}
   
// copies the most-recently added or top item from the stack
// pre: Stack object exists and is not empty
// post: top item has been copied into topItem. Stack object is unchanged.
// usage: aStack.getTop(topguy);
void Stack::getTop(Item& topItem) const
{
	topItem = topptr -> item;
}
   
// checks whether or not a stack is empty
// pre: Stack object exists
// post: if Stack object is empty then returns true; else returns false
// usage: if(aStack.isEmpty())
bool Stack::isEmpty() const
{
	return (topptr == nullptr);
}

// copies a stack
// pre: rhsStack is an existing Stack object
// post: Stack object is a copy of rhsStack
// usage: mystk = yourstk;
Stack& Stack::operator=(const Stack& rhsStack)
{
   Node* rhsPtr;
   Node* currPtr;
   
   if(this != &rhsStack)
   {
      while (not isEmpty())
      {
	     pop();
      }
      topptr = nullptr;
      if(not rhsStack.isEmpty())
      {
         topptr = new Node;
	     rhsPtr = rhsStack.topptr;
	     topptr -> item = rhsPtr -> item;
	     topptr -> next = nullptr;
	     currPtr = topptr;
	     rhsPtr = rhsPtr -> next;
	     while (rhsPtr != nullptr)
	     {
	        currPtr -> next = new Node;
		    currPtr = currPtr -> next;
		    currPtr -> item = rhsPtr -> item;
		    currPtr -> next = nullptr;
		    rhsPtr = rhsPtr -> next;
	      }
	   }
   }
   return *this;
}
   
 