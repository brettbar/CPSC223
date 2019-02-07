// client of Sphere and Ball: this program is exploring
//    additional items about inheritance

#include "Sphere.h"
#include "Ball.h"
#include <iostream>
using namespace std;

int main()
{
   Sphere norvell;
   cout << "111111111111111111111111111111111111111111111111111111" << endl;
   cout << "Sphere norvell" << endl;
   norvell.displayStats(); // Sphere's

   Sphere perkins(3.0);
   cout << "Sphere perkins" << endl;
   perkins.displayStats(); // Sphere's

   norvell.setRadius(5.0);
   cout << "Sphere norvell" << endl;
   norvell.displayStats(); // Sphere's

   cout << "222222222222222222222222222222222222222222222222222222" << endl;
   Ball j3;
   j3.setName("soccer");
   j3.setRadius (4.0);
   cout << "Ball j3 " << endl;

   // which getArea should be called?

   cout << j3.getArea() << endl; // ball's

   // what if you want to call Sphere's getArea on j3?
   cout << j3.Sphere::getArea() << endl;


   j3.displayStats(); // ball's



   cout << "333333333333333333333333333333333333333333333333333333" << endl;
   cout << "Pointer stuff" << endl;
   Sphere* ruiptr;
   ruiptr = &norvell;
   cout << "points to sphere norvell" << endl;
   ruiptr -> displayStats();

   cout << "444444444444444444444444444444444444444444444444444444" << endl;
   ruiptr = &j3;
   cout << "sphere ptr points to a ball object" << endl;
   ruiptr -> displayStats();

   cout << "555555555555555555555555555555555555555555555555555555" << endl;
   Ball* kispertptr;
   kispertptr = &j3;
   cout << "ball ptr points to a ball object" << endl;
   kispertptr -> displayStats();


   return 0;
}
