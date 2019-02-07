// sorts.cpp: This purpose of this program is to provide experimental
//    data on the number of operations to do one of 3 kinds of sorts:
//    Selection, Insertion, Merge, Quicksort
// inputs: user enters the size of the arrays and menu option
// outputs: the number of operations to run that sort

// date: April 16, 2005

#include <cstdlib>
#include <iostream>
#include <ctime>
using namespace std;

const int MAXSIZE = 10000;

// Sorts a list into ascending order
// pre: data[0..n-1] is assigned values
// post: data[0..n-1] has values in ascending order
//       numops is the number of operations performed
//       prints intermediate steps for educational value
// usage: SelectionSort (data, n);
void SelectionSort (int data[], int n, int& numops);

// Sorts a list into ascending order
// pre: data[0..n-1] is assigned values
// post: data[0..n-1] has values in ascending order
//       numops is the number of operations performed
//       prints intermediate steps for educational value
// usage: InsertionSort (data, n);
void InsertionSort (int data[], int n, int& numops);

// merges two sorted halves of an array together
// pre: array1[first..mid], array1[mid+1..last] are sorted
// post: array1[first..last] are sorted
// usage: merge (data, first, mid, last);
void merge(int array1[], int first, int mid, int last, int& numops);

// Sorts a list into ascending order
// pre: data[first..last] is assigned values
// post: data[first..last] has values in ascending order
//       numops is the number of operations performed
//       prints intermediate steps for educational value
void MergeSort (int data[], int first, int last, int& numops);

// Fills a list with random values
// pre: n > 0
// post: data[0..n-1] has assigned values
// usage: fill(data,n);
void fill(int data[], int n);

// Fills a list with sorted values
// pre: n > 0
// post: data[0..n-1] have values in sorted order
// usage: sortfill(data,n);
void sortfill (int data[], int n);

// Prints a list in forward order
// pre: data[0..n-1] has assigned values
// post: the numbers are output with array subscript values
// usage: print(data,n);
void print (int data[], int n);

// Gets the size of the list from the user
// post: returns the size input by the user
// usage: cout << getSize();
int getSize();

// copies one list to another list
// pre: oldlist[0..n-1] has values
// post: newlist[0..n-1] has the same values as oldlist
// usage: copy (newlist, oldlist, n);
void copy (int newlist[], int oldlist[], int n);

// sorts a section of an array
// pre: data[first..last] are assigned values
// post: data[first..last] are in ascending order
// usage: quicksort (data, 1, 4);
void Quicksort(int data[], int first, int last, int& numops);

// sorts a list of numbers
// pre: data[0..n-1] are assigned values
// post: data[0..n-1] are in increasing order
// usage: quicksort (data, num);
void Quicksort (int data[], int n, int& numops);

// Prints a menu of options for the user
// post: menu is shown on the screen
// usage: doMenu(); 
void doMenu();

// Gets an option from the user
// post: returns a menu option
// usage: opt = getOption();
int getOption();

// asks the user if she wants to continue with the program

void ToContinue();

int main()
{
   int dataSelection[MAXSIZE];
   int dataInsertion[MAXSIZE];
   int dataMergesort[MAXSIZE];
   int dataQuicksort[MAXSIZE];
 
   int option, numberOfItems;
   doMenu();
   option = getOption();
   srand(time(0));

   for (numberOfItems = 1000; numberOfItems < 11000; numberOfItems += 1000) {  
      if (option == 1)
         fill (dataSelection, numberOfItems);
      else if (option == 2)
         sortfill (dataSelection, numberOfItems);
   
      copy (dataInsertion, dataSelection, numberOfItems);
      copy (dataMergesort, dataSelection, numberOfItems);
      copy (dataQuicksort, dataSelection, numberOfItems);
   
      int numberOperationsSelectionSort = 0; 
      int numberOperationsInsertionSort = 0; 
      int numberOperationsMergeSort = 0; 
      int numberOperationsQuickSort = 0;
      
      cout << endl << numberOfItems << endl << endl;
      
      SelectionSort (dataSelection, numberOfItems, numberOperationsSelectionSort);
      cout << "# of operations for Selection Sort = " << numberOperationsSelectionSort << endl;

      InsertionSort (dataInsertion, numberOfItems, numberOperationsInsertionSort);
      cout << "# of operations for Insertion Sort = " << numberOperationsInsertionSort << endl;
   
      MergeSort (dataMergesort, 0, numberOfItems - 1, numberOperationsMergeSort);
      cout << "# of operations for MergeSort      = " << numberOperationsMergeSort << endl;
   
      Quicksort (dataQuicksort, 0, numberOfItems, numberOperationsQuickSort);
      cout << "# of operations for QuickSort      = " << numberOperationsQuickSort << endl;
   
      cout << endl << endl;
      ToContinue();
   }
}


// Sorts a list into ascending order
// pre: data[0..n-1] is assigned values
// post: data[0..n-1] has values in ascending order
//       numops is the number of operations performed
//       prints intermediate steps for educational value
// usage: SelectionSort (data, n);
void SelectionSort (int data[], int n, int& numops)
{
   int least;
   numops = 3;  // i = 0 and i = n-1
   for (int i = 0; i < n - 1; i++)
   {
      numops += 3; // <, (i+1, i= at bottom)
      numops += 2; // j=i+1, j=n
      least = i; numops++;
      for (int j = i + 1; j < n; j++) // find smallest from i to n - 1
      {
         numops += 3; // <, j++
         numops += 5; // two array accesses and <
         if (data[j] < data[least])
         {
            least = j;
            numops++;
         }
      }
      int temp = data[least];    // swap smallest with data[i]
      data[least] = data[i];
      data[i] = temp;
      numops = numops + 11;
   }
}

// Sorts a list into ascending order
// pre: data[0..n-1] is assigned values
// post: data[0..n-1] has values in ascending order
//       numops is the number of operations performed
//       prints intermediate steps for educational value
// usage: InsertionSort (data, n);
void InsertionSort (int data[], int n, int& numops)
{
   numops = 2; // i=1, i=n
   for (int i = 1, j; i < n; i++)
   {
      numops += 3; // <, ++
      int tmp = data[i]; numops += 3;
      numops += 2;
      for ( j = i; j > 0 && tmp < data[j - 1]; j--)
      {
         numops = numops + 8;
         data[j] = data[j - 1];   numops += 6;
      }
      data[j] = tmp; numops += 3;
   }
}

// merges two sorted halves of an array together
// pre: array1[first..mid], array1[mid+1..last] are sorted
// post: array1[first..last] are sorted
// usage: merge (data, first, mid, last);
void merge(int array1[], int first, int mid, int last, int& numops)
{
   int temp[MAXSIZE];
   int i1 = 0, i2 = first, i3 = mid + 1; numops += 4;
   numops += 5; // last while
   while (i2 <= mid && i3 <= last)
   {        
      numops += 3; // while cond
      numops += 5;
      if (array1[i2] < array1[i3])
      {
         numops += 9;
         temp[i1++] = array1[i2++];
      }        
      else
      {
         numops += 9; 
         temp[i1++] = array1[i3++];
      }
   }
   numops += 2;
   while (i2 <= mid)
   {
      numops += 11;
      temp[i1++] = array1[i2++];
   }
   numops += 2;
   while (i3 <= last)
   { 
      numops += 2;
      numops += 9;
      temp[i1++] = array1[i3++];
   }
   numops += 4;
   i1 = 0; i2 = first;
   while (i2 <= last)
   {   
      numops += 2;
      array1[i2++] = temp[i1++]; numops += 9;
   }
}

// Sorts a list into ascending order
// pre: data[first..last] is assigned values
// post: data[first..last] has values in ascending order
//       numops is the number of operations performed
//       prints intermediate steps for educational value
void MergeSort (int data[], int first, int last, int& numops)
{
   numops++;
   if (first < last)
   {
      int mid = (first + last) / 2;  numops += 3;
      MergeSort (data, first, mid, numops);
      MergeSort (data, mid + 1, last, numops); numops++;
      merge (data, first, mid, last, numops);
   }
}

// Fills a list with random values
// pre: n > 0
// post: data[0..n-1] has assigned values
// usage: fill(data,n);
void fill(int data[], int n)
{
   for (int k = 0; k < n; k++)
      data[k] = rand() % MAXSIZE;
}

// Fills a list with sorted values
// pre: n > 0
// post: data[0..n-1] have values in sorted order
// usage: sortfill(data,n);
void sortfill (int data[], int n)
{
   for (int k = 0; k < n; k++)
      data[k] = k;
}


// Prints a list in forward order
// pre: data[0..n-1] has assigned values
// post: the numbers are output with array subscript values
// usage: print(data,n);
void print (int data[], int n)
{
   for (int k = 0; k < n; k++)
   {
      cout << data[k] << " ";
   }
   cout << endl;
}

// Gets the size of the list from the user
// post: returns the size input by the user
// usage: cout << getSize();
int getSize()
{
   cout << "Enter size of list -> ";
   int size;
   cin >> size;
   return size;
}

// copies one list to another list
// pre: oldlist[0..n-1] has values
// post: newlist[0..n-1] has the same values as oldlist
// usage: copy (newlist, oldlist, n);
void copy (int newlist[], int oldlist[], int n)
{
   for (int k = 0; k < n; k++)
      newlist[k] = oldlist[k];
}

// swaps the contents of two items
// pre: left and right are assigned
// post: the contents of left and right have been interchanged
// usage: swap (a, b);
void swap (int& left, int& right)
{
   int temp = right;
   right = left;
   left = temp;
}

// sorts a section of an array
// pre: data[first..last] are assigned values
// post: data[first..last] are in ascending order
// usage: quicksort (data, 1, 4);
void Quicksort(int data[], int first, int last, int& numops) {
    int lower = first + 1, upper = last;               numops += 3;
    swap(data[first], data[(first + last) / 2]);     numops += 9;
    int bound = data[first];                         numops += 4;
    while (lower <= upper) {
                                                     numops += 3;
        while (data[lower] < bound) {
             lower++;                                numops += 5;
        }
                                                     numops += 3;   
        while (bound < data[upper]) {
             upper--;                                numops += 5;
        }
                                                     numops++;
        if (lower < upper) {
             swap(data[lower++],data[upper--]);      numops += 11;
        }
        else {
            lower++;                                 numops += 2;
        }
    }
    swap(data[upper],data[first]);                   numops += 7;
                                                     numops += 3;
    if (first < upper - 1)
        Quicksort (data,first,upper - 1, numops);
                                                     numops += 3;
    if (upper + 1 < last)
        Quicksort (data,upper + 1,last, numops);
}

// sorts a list of numbers
// pre: data[0..n-1] are assigned values
// post: data[0..n-1] are in increasing order
// usage: quicksort (data, num);
void Quicksort (int data[], int n, int& numops)
{  
   numops++;
   Quicksort (data, 0, n - 1, numops);
}

// Prints a menu of options for the user
// post: menu is shown on the screen
// usage: doMenu(); 
void doMenu()
{
   cout << endl << endl;
   cout << "*******************************************" << endl;
   cout << "*  1) Do Tests with Random Lists          *" << endl;
   cout << "*  2) Do Tests with Sorted Lists          *" << endl;
   cout << "*  3) Exit                                *" << endl;
   cout << "*******************************************" << endl;
}

// Gets an option from the user
// post: returns a menu option
// usage: opt = getOption();
int getOption()
{
   cout << endl << endl;
   int option; char newline;
   cout << "Input Option -> ";
   cin >> option;
   cin.get(newline);
   cout << endl << endl;
   return option;
}

void ToContinue()
{
   char newline;
   cout << endl << endl;
   cout << "press <enter> ";
   cin.get(newline);
   cout << endl << endl;
}
