
// ADT Heap : a heap (max-heap) is a complete binary tree
// that is
// either empty
// or in the form
//          r
//        /   \
//       TL   TR
// such that the key in r >= keys in TL and TR
// and TL, TR are heaps.
// operations: create, destroy,
//             insert a new key, remove the maximum key,
//             copy the maximum key

// note: To simplify, we'll assume items are just the keys

#ifndef HEAP_H
#define HEAP_H

#include "Key.h"
#include "Exception.h"
#include <iostream>
using namespace std;

const int MAXSIZE = 20;

class Heap
{
// prints a heap so that each level of the tree is on its own line in output
// pre: output is either cout, the screen, or a file opened for writing
//	    rightHandSideHeap is assigned
// post: rightHandSideHeap is printed on output level by level
//       For example,
//       9
//       6   4
//       3   2   1
// usage: cout << myheap;
friend ostream& operator<< (ostream& output, const Heap& rightHandSideHeap);

// inputs data from a heap
// pre: input is either cin or a file opened for reading
//      rightHandSideHeap is empty
// post: each level for the heap is on a separate line
//       each key is separated by a blank line
// usage: infile >> myheap;
friend istream& operator>> (istream& input, Heap& rightHandSideHeap);

public:

// creates an empty heap
// post: an empty Heap object exists
Heap();

// destroys a heap
// pre: Heap object exists
// post: Heap object does not exist
~Heap();

// inserts a new key into a heap
// pre: newKey is assigned a 2-digit integer key
//      Heap object exists (may be empty)
// post: if there is enough memory, then
//          newKey has been inserted into the Heap object
//       else an exception is thrown
// usage: myheap.insert(mykey);
void insert (const Key& newKey) throw (Exception);

// removes a key from a heap
// pre: maxKey object exists
//      Heap object exists (may be empty)
// post: if the Heap object is not empty, then
//          maxKey contains the largest key in the heap and
//          maxKey has been removed from the Heap object
//      else an exception is thrown
// usage: myheap.remove(myKey);
void remove (Key& maxKey) throw (Exception);

// copies the maximum key in the heap
// pre: Heap object exists (may be empty)
// post: if the Heap object is not empty, then
//          maxKey contains the maximum key in the heap
//       else an exception is thrown
void getMaximum (Key& maxKey) throw (Exception);

private:

   Key heapKeys[MAXSIZE];
   int heapSize;

};
#endif
