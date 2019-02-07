// Brett Barinaga
// 4/23/2018
// Heap.cpp
// ADT Heap : a heap (max-heap) is a complete binary tree
// that is
// either empty
// or in the form
//          r
//        /   \
//       TL   TR
// such that the key in r >= keys in TL and TR
// and TL, TR are heaps.

// data structure:

// operations: create, destroy,
//             insert a new key, remove the maximum key,
//             copy the maximum key

// note: To simplify, we'll assume items are just the keys

#include "Heap.h"

// finds the height of a complete binary size given its number of nodes
// pre: size > 0
// post: returns the height of a complete binary tree
// usage: cout << findHeight (10);
int findHeight(int size)
{
	int height = 1;
	int powerOf2 = 2;
	while (powerOf2 <= 128)
	{
		if (size <= powerOf2 - 1)
			return height;
		powerOf2 = powerOf2 * 2;
		height++;
	}
}

// determines if an item in the heap is a leaf of the binary tree
// pre: rootIndex < keysCount, keysCount is assigned the number of keys in the heap
// post: returns true if the item at rootIndex is a left of the tree else returns false
// usage: if (isALeaf(2, 7)_
bool isALeaf(int rootIndex, int keysCount)
{
	int leftChildIndex = 2 * rootIndex + 1; // fix
	if (leftChildIndex < keysCount)
		return false;
	else
		return true;
}

// swaps two phone numbers
// pre: oneKey, otherKey are assigned as nonempty phone numbers
// post: oneKey is pre's otherKey and otherKey is pre's oneKey
// usage:
void swap(Key& oneKey, Key& otherKey)
{
	Key tempKey;
	tempKey = oneKey;
	oneKey = otherKey;
	otherKey = tempKey;
}

// converts a semiheap with a given root to a heap
// pre: rootIndex is an existing index in the heap (there is a tree node there)
//      heap contains the nodes of the tree. keysCount is the number of nodes in the tree
// post: the key at heap[rootIndex] trickles down one level in the process
//       of restoring the heap
// usage: heapRebuild(0, heapKeys, heapSize);
void heapRebuild(int rootIndex, Key heap[], int keysCount)
{
	int leftChildIndex, rightChildIndex, largerChildIndex;

	if (not isALeaf(rootIndex, keysCount))
	{
		leftChildIndex = 2 * rootIndex + 1; // fix
		rightChildIndex = leftChildIndex + 1; // fix
		if (rightChildIndex < keysCount) // right child exists
		{
			if (heap[rightChildIndex] < heap[leftChildIndex])
			{
				largerChildIndex = leftChildIndex;
			} else {
				largerChildIndex = rightChildIndex;
			}
		} else {
			largerChildIndex = leftChildIndex;
		}
		if (heap[rootIndex] < heap[largerChildIndex])
		{
			swap(heap[rootIndex], heap[largerChildIndex]);
			heapRebuild(largerChildIndex, heap, keysCount);
		}
	}
}

// prints a heap so that each level of the tree is on its own line in output
// pre: output is either cout, the screen, or a file opened for writing
//	    rightHandSideHeap is assigned
// post: rightHandSideHeap is printed on output level by level
//       For example,
//       9
//       6   4
//       3   2   1
// usage: cout << myheap;
ostream& operator<< (ostream& output, const Heap& rightHandSideHeap)
{
	int heightOfHeap, powerOf2, index;

	powerOf2 = 1;
	index = 0;
	heightOfHeap = findHeight(rightHandSideHeap.heapSize);

	for (int level = 1; level <= heightOfHeap; level++)
	{
		for (int number = 1; index < rightHandSideHeap.heapSize && number <= powerOf2; number++)
		{
			output << rightHandSideHeap.heapKeys[index++] << " ";
		}
		cout << endl;
		powerOf2 *= 2;
	}
}

// inputs data from a heap
// pre: input is either cin or a file opened for reading
//      rightHandSideHeap is empty
//      input's pointer is before the number of keys to be read
//      then
//      each level for the heap has keys separated by spaces and on separate line
// post: rightHandSideHeap has been initialized by contents of the file
// usage: infile >> myheap;
istream& operator>> (istream& input, Heap& rightHandSideHeap)
{
	input >> rightHandSideHeap.heapSize;
	int index = 0;

	while (index < rightHandSideHeap.heapSize and index < MAXSIZE)
	{
	   input >> rightHandSideHeap.heapKeys[index];
	   index++;
	}
}

// creates an empty heap
// post: an empty Heap object exists
Heap::Heap()
{
	heapSize = 0;
}

// destroys a heap
// pre: Heap object exists
// post: Heap object does not exist
Heap::~Heap()
{
	heapSize = 0;
}

// inserts a new key into a heap
// pre: newKey is assigned a 2-digit integer key
//      Heap object exists (may be empty)
// post: if there is enough memory, then
//          newKey has been inserted into the Heap object
//       else an exception is thrown
// usage: myheap.insert(mykey);
void Heap::insert (const Key& newKey) throw (Exception)
{
	if (heapSize < MAXSIZE)
	{
		heapKeys[heapSize] = newKey;
		int currIndex;
		currIndex = heapSize;
		int parentIndex;
		parentIndex = (currIndex - 1) / 2;
		while (heapKeys[parentIndex] < newKey)
		{
			swap(heapKeys[currIndex], heapKeys[parentIndex]);
			currIndex = parentIndex;
			parentIndex = (currIndex - 1) /2;
		}
		heapSize++;
	}
	else
	{
		throw Exception("No room in the heap...");
	}
}

// removes a key from a heap
// pre: maxKey object exists
//      Heap object exists (may be empty)
// post: if the Heap object is not empty, then
//          maxKey contains the largest key in the heap and
//          maxKey has been removed from the Heap object
//      else an exception is thrown
// usage: myheap.remove(myKey);
void Heap::remove (Key& maxKey) throw (Exception)
{
	if (heapSize > 0)
	{
		maxKey = heapKeys[0]; // removing the root
		// filling the root with the last key
		heapKeys[0] = heapKeys[heapSize - 1];
		heapSize--;
		heapRebuild(0, heapKeys, heapSize);
	}
	else
		throw Exception("the heap is empty");
}

// copies the maximum key in the heap
// pre: Heap object exists (may be empty)
// post: if the Heap object is not empty, then
//          maxKey contains the maximum key in the heap
//       else an exception is thrown
void Heap::getMaximum (Key& maxKey) throw (Exception)
{
	if (heapSize > 0)
		maxKey = heapKeys[0];
	else
		throw Exception("thea heap is empty");
}
