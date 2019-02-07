// ModFunction.cpp
#include <iostream>

using namespace std;

int ModFunction(int a, int b);

int main()
{
	int a,b;
	cout << "a...";
	cin >> a;
	cout << endl;
	cout << "b...";
	cin >> b;
	cout << endl;

	cout << "The remainder is..." << ModFunction(a,b) << endl;
	return 0;
}

int ModFunction(int a, int b)
{
	return a % b;
}