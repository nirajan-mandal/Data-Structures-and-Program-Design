#ifndef pointType_H
#define pointType_H
using namespace std;
class pointType
{
      public:
             pointType();
             //default constructor function 
             //postcondition: assigns X and Y coordiante to 0               
             pointType(double X, double Y);
             //default constuctor with two doubles
             //precondtion: takes two doubles
             //postcondtion: assings X and Y to the x and the y coordinate respectively
             void setPoint(double X, double Y);
             //mutator function to set the point 
             //precondition: takes two double
             //postcondtion: assings X and Y to the x and the y coordinate respectively
             void print();
             //function to display the point
             //postcndition: displays the x and y coordiantes on the screen
      protected:
              double x;   //varibale to store the x coordinate
              double y;   //vvariable to store the y coordinate
};       
#include "pointType.h"            
#endif
