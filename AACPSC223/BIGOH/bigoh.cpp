// Brett Barinaga
// yes I want labs to count for homework
// three functions for big-oh analysis by experimentation
// bigoh.cpp
// poor names for functions and variables on purpose
//    so as to hide their identity

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <fstream>
using namespace std;

const int MAXSIZE = 30001;

void fillArray(int a[], int n);
void openOutputFile(ofstream& outfile);
void f(int a[], int n, long int& count);
int g(int a[], int n, int& count);

int main()
{
   int a[MAXSIZE];
   long int countf;
   int countg;
   ofstream outfile;

   openOutputFile(outfile);

   countf = 0; countg = 0;
   outfile << endl << endl;

/*
   outfile << setw(10) << left << "count of f" << endl << endl;
   for (int n = 1000; n <= MAXSIZE - 1; n += 1000)
   {
	   fillArray(a, n);
	   f(a, n, countf);
	   // there is a reason we are not printing n
	   outfile << right << countf << endl;
   }
*/
    outfile << setw(10) << left << "count of g" << endl << endl;
    for (int n = 1000; n <= MAXSIZE - 1; n += 1000)
    {
      fillArray(a, n);
      g(a, n, countg);
      // there is a reason we are not printing n
      outfile << right << countg << endl;
    }
   outfile << endl << endl;
   return 0;
}

void fillArray(int a[], int n)
{
	for (int k = 0; k < n; k++)
	{
		a[k] = n - k;
	}
}

void openOutputFile(ofstream& outfile)
{
	outfile.open("oh.dat");
	if (outfile.fail())
	{
		cout << "output file failed to open" << endl;
		exit(1);
	}
}

void f(int a[], int n, long int& count)
{
	int b;
	for (int k = 1; k < n; k++)
	{
		for(int j = 0; j < n - k; j++)
		{
      count++;
			if(a[j] > a[j + 1]) // basic operation
			{
				b = a[j + 1];
				a[j + 1] = a[j];
				a[j] = b;
			}
		}
	}
}

int g(int a[], int n, int& count)
{
	int b, c, d, e;

	b = 0; c = n - 1;
	e = a[n - 1] + 5;
	while (b <= c) // basic operation is <=
	{
    count++;
		d = (b + c) / 2; // or basic operation /
		if (e < a[d])
		{
			c = d - 1;
		} else if (e > a[d])
		{
			b = d + 1;
		} else {
			return d;
		}
	}
	return -1;
}
