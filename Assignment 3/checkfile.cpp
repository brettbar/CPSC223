// checkfile ASCII chars

#include <fstream>
#include <iostream>
using namespace std;

int main()
{
   ifstream infile;
   infile.open("Input.dat");
   char ch; int ich;
   infile.get(ch);
   while (not infile.eof())
   {
      ich = ch;
      cout << ich << ",";
      infile.get(ch);
   }
}