//@file Exception.h
//@author Dr Y
//@date Feb 8, 2011
//@Specification for ADT Exception Message
//    data object: a message explaining an exception
//    operations: constructor, What

#ifndef EXCEPTION_H
#define EXCEPTION_H

#include <string>
using namespace std;

class Exception
{
public:
   //creates an exception message
   //pre  theMessage passed may be a literal string
   //post exception message object is assigned theMessage
   //usage throw Exception ("BAD MOVE");
   Exception(string theMessage ) ;

   //outputs a message exception
   //pre message object has been assigned 
   //post returns the exception message when exception is thrown
   //usage cout << except.what() << endl;
   string What() const;
private:
    string message;
};
#endif
