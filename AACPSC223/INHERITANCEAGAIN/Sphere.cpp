// ADT Sphere implementation: class csphere
//    data object: a sphere (represented by its radius)
//    data structure: an integer location for the radius
//    operations: constructors, destructor, copy constructor
//        member functions: setRadius, getRadius, getArea, getVolume,
//                          displayStats
// filename: Sphere.cpp

#include <iostream>
using namespace std;
#include "Sphere.h"

// post: an empty Sphere object exists
// usage: Sphere plato;
Sphere::Sphere(): radius(0.0)
{
}

// Creates a sphere of a given radius
// pre: initialRadius is assigned.
// post: a Sphere object  of radius initialRadius exists
// usage: Sphere plato (2.0);
Sphere::Sphere(double initialRadius)
{
   radius = 0.0;
   if (initialRadius > 0.0)
      setRadius (initialRadius);
}

// Creates a copy of a given sphere
// pre: object rhsSphere exists. 
// post: object is a copy of rhsSphere
// usage: Sphere mySphere (yourSphere);
Sphere::Sphere (const Sphere& rhsSphere)   
{ 
   radius = 0.0; 
   setRadius (rhsSphere.radius);
}

// Destroys a sphere
// pre: object exists
// post: object does not exist
// usage: automatically called at the end of object's scope
Sphere::~Sphere()
{
   radius = -1;
}

// ******************** member functions or methods *****

// pre-condition for all: object exists

// Sets the radius of a sphere
// pre: newRadius is assigned.
// post: object has radius equal to newRadius 
// usage: mysphere.setRadius(3.0);
void Sphere::setRadius(double newRadius)
{
   radius = newRadius;
}

// Gets the radius of a sphere
// post: returns the object's radius
// usage: cout << "the radius is " << yoursphere.getRadius();
double Sphere::getRadius() const
{
   return radius;
}

// Finds the surface area of a sphere   
// post: returns the surface area of the object
//       outputs a message at beginning of call
// usage: surfaceArea = mySphere.getArea();
double Sphere::getArea() const
{
   cout << "inside Sphere's getArea " << endl;
   return (4 * PI * radius * radius);
}

// Finds the volume of a sphere
// post: returns the volume of the object
//       outputs a message of class name upon entry
// usage: thisVolume = mySphere.getVolume();
double Sphere::getVolume() const
{
   cout << "inside Sphere's getVolume" << endl;
   return ((radius / 3.0) * getArea());
}

// Displays all of the statistics about a sphere
// post: On separate lines with labels,
//       the object's radius, surface area, and volume
//       are printed to the output device. Following
//       the volume, a newline is output.
//       Outputs a message at beginning of the call of its name
// usage: redSphere.displayStats();
void Sphere::displayStats() const
{
   cout << "inside Sphere's displayStats" << endl;
   cout << "Radius = " << getRadius() << endl;
   cout << "Surface Area = " << getArea() << endl;
   cout << "Volume = " << getVolume() << endl;
}

