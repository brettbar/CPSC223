// gcd.cpp

#include <iostream>

using namespace std;

int gcd(int a, int b);
void enter(int& a, int& b);

int main()
{
	int a, b;
	enter(a,b);
	cout << "The gcd of " << a << " and " << b << " is " << gcd(a,b) << endl;
	return 0;
}

int gcd(int a, int b)
{
	if (a == b)
		return a;
	if (a == 0 || b == 0)
		return 0;
	if (a > b)
		return gcd(a - b, b);
	return gcd(a, b - a);
}

void enter(int& a, int& b)
{
	cout << "a...";
	cin >> a;
	cout << endl;
	cout << "b...";
	cin >> b;
	cout << endl;
}