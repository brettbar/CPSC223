// ADT Sphere specification:
//    data object: a sphere
//         (a 3-dimensional set of points equidistant from a center point)
//    operations: constructors, destructor, copy constructor
//        member functions: setRadius, getRadius, getArea, getVolume,
//                          displayStats

#ifndef SPHERE_H
#define SPHERE_H

const double PI = 3.14159265359;
class Sphere
{
public:
   // ****************** constructors and destructor *******************

   // Creates an empty sphere
   // post: an empty Sphere object exists
   // usage: Sphere plato;
   Sphere();

   // Creates a sphere of a given radius
   // pre: initialRadius is assigned.
   // post: a Sphere object  of radius initialRadius exists
   // usage: Sphere plato (2.0);
   Sphere(double initialRadius);

   // Creates a copy of a given sphere
   // pre: object rhsSphere exists. 
   // post: object is a copy of rhsSphere
   // usage: Sphere mySphere (yourSphere);
   Sphere (const Sphere& rhsSphere);   

   // Destroys a sphere
   // pre: object exists
   // post: object does not exist
   // usage: automatically called at the end of object's scope
    ~Sphere();

   // ******************** member functions or methods ******************
   // pre-condition for all: object exists

   // Sets the radius of a sphere
   // pre: newRadius is assigned.
   // post: object has radius equal to newRadius 
   // usage: mysphere.setRadius(3.0);
   void setRadius(double newRadius);

   // Gets the radius of a sphere
   // post: returns the object's radius
   //       outputs a message at beginning of call
   // usage: cout << "the radius is " << yoursphere.getRadius();
   double getRadius() const;

   // Finds the surface area of a sphere   
   // post: returns the surface area of the object
   // usage: surfaceArea = sphere.getArea();
   double getArea() const;

   // Finds the volume of a sphere
   // post: returns the volume of the object
   //       outputs a message of class name upon entry
   // usage: thisVolume = mysphere.getVolume();
   double getVolume() const;

   // Displays all of the statistics about a sphere
   // post: On separate lines with labels,
   //       the object's radius, surface area, and volume
   //       are printed to the output device. Following
   //       the volume, a newline is output.
   //       Outputs a message at beginning of the call of its name
   // usage: mySphere.displayStats();
   void displayStats() const;

private:
   double radius; 
}; 
#endif
