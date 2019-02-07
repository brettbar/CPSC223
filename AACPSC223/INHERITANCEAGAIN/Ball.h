// Specification of ADT Ball
//    data object: a ball (is-a sphere with a name)
//    operations: constructors, destructor
//                getName, resetName, getArea,
//                displayStats
// filename: Ball.h

#ifndef CBALL_H
#define CBALL_H

#include "Sphere.h"
#include <string>
using namespace std;

class Ball: public Sphere
{
public:                     
       
   // Creates an empty ball
   // post: an empty ball object exists
   // usage: Ball zagBall;
   Ball();

   // Creates a new ball with a given radius and name
   // pre: initialRadius and initialName have been assigned
   // post: a Ball object exists with radius initialRadius
   //       and with name initialName
   // usage: Ball zagBall(2.0, "J3");
   Ball(double initialRadius, string initialName);

   // Creates a copy of a ball
   // pre: rhsBall exists
   // post: Ball object is a copy of rhsBall
   // usage: Ball zagBall(florida);
   Ball (const Ball& rhsBall);

   // Finds the name of a ball 
   // pre: currentName has been assigned
   // post: currentName is the object's name
   // usage: myball.getName(itsName);
   void getName(string currentName) const;
  
   // Sets the name of a ball
   // pre: newName is assigned.
   // post: Ball object has name newName
   // usage: yourball.setName(itsName);
   void setName(string newName);
   
   // Changes the balls parameters -- radius and name
   // pre: newRadius and newName have been assigned.
   // post: Ball object has a radius equal to newRadius
   //       and a name equal to newName
   // usage: soccer.resetBall (2.0, "Killian");
   void resetBall(double newRadius, string newName);
   
   // Finds the cross-sectional area of a ball
   // post: returns the cross-sectional area of a ball
   //       outputs a message of class name upon entry
   // usage: ballArea = myball.getArea();
   double getArea() const;

   // Prints out the statistics of a ball
   // post: On separate lines and with labels,
   //       the radius, name, area, and volume are printed.
   //       A newline appears after the volume is printed.
   //       prints a message upon entry with class name
   // usage: myball.displayStats();
   void displayStats() const;

private:
   string name;
}; 
#endif
