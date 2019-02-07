// Brett Barinaga, Alli Fellger, Amy Larson
// 4/9/2018
// isSingleRotateRight.cpp
// Determines whether or not search indicates the necessity of a single right
// rotation in order to restore balance in an AVL tree.

// pre:    - search is assigned and filled with pointers to each node in the order that they were
//           traversed to place the new Item.
//         - pivotIndex is assigned the index value for the pointer in search that is directed at the first
//           unbalanced node along the search path starting with the newly inserted Item.
// 	       - pathsize is large enough to have a search.pivotIndex + 2
// post: returns true if search indicates that the pivot is followed by two left paths, and false otherwise.
// usage: if(isSingleRightRotate(aPath)) { doSingleRightRotate(); }
bool isSingleRotateRight(const SearchPath& search)
{
	if (search.path[search.pivotIndex] -> leftChild != nullptr and search.path[search.pivotIndex] -> leftChild == search.path[search.pivotIndex + 1])
	{
		if (search.path[search.pivotIndex + 1] -> leftChild != nullptr and search.path[search.pivotIndex + 1] -> leftChild == search.path[search.pivotIndex + 2])
			return true;
		else 
			return false;
	}
	else 
		return false;
}