// Implementation of ADT Ball
//    data object: a ball (is-a sphere with a name)
//    data structure: name is a string
//    operations: constructors, destructor
//                getName, resetName, getArea,
//                displayStats
// filename: Ball.cpp

#include "Ball.h"
#include <iostream>
using namespace std;

// Creates an empty ball
// post: an empty ball object exists
// usage: Ball zagBall;
Ball:: Ball()
{
   setName("");
}

// Creates a new ball with a given radius and name
// pre: initialRadius and initialName have been assigned
// post: a Ball object exists with radius initialRadius
//       and with name initialName
// usage: Ball zagBall(2.0, "J3");
Ball:: Ball(double initialRadius, string initialName):Sphere(initialRadius)
{
   setName (initialName);
}

// Creates a copy of a ball
// pre: rhsBall exists
// post: Ball object is a copy of rhsBall
// usage: Ball zagBall(florida);
Ball:: Ball (const Ball& rhsBall): Sphere(rhsBall)
{
   name = rhsBall.name;
}
    
// Finds the name of a ball 
// pre: currentName has been assigned
// post: currentName is the object's name
// usage: myball.getName(itsName);
void Ball::getName(string currentName) const   
{ 
   currentName = name;
};
  
// Sets the name of a ball
// pre: newName is assigned.
// post: Ball object has name newName
// usage: yourball.setName(itsName);
void Ball::setName(string newName)
{
   name = newName;
}
   
// Changes the balls parameters -- radius and name
// pre: newRadius and newName have been assigned.
// post: Ball object has a radius equal to newRadius
//       and a name equal to newName
// usage: soccer.resetBall (2.0, "Killian");
void Ball::resetBall(double newRadius,  string newName)
{
   setRadius (newRadius);
   setName (newName);
}
   
// Finds the cross-sectional area of a ball
// post: returns the cross-sectional area of a ball
//       outputs a message of class name upon entry
// usage: ballArea = myball.getArea();
double Ball::getArea()  const   
{
   cout << "Ball's getArea      ";
   return (PI * getRadius() * getRadius());
}

// Prints out the statistics of a ball
// post: On separate lines and with labels,
//       the radius, name, area, and volume are printed.
//       A newline appears after the volume is printed.
//       prints a message upon entry with class name
// usage: melson.displayStats();
void Ball::displayStats() const
{
   cout << "Ball's display          " << endl;
   cout << "For " << name << " Ball => " << endl;
   cout << "     Radius = " << getRadius() << endl;
   cout << "The next line will be the call to Sphere's getArea" << endl;
   cout << "     Surface-Area = " << Sphere::getArea() << endl;
   cout << "The next line will be the call to Ball's getArea()  " << endl;
   cout << "     Cross- Area = " << getArea() << endl;
   cout << "The next line will be the call Sphere's getVolume()  " << endl;
   cout << "     Volume = " << getVolume() << endl;
}
