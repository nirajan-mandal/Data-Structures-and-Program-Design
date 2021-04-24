#ifndef circleType_H
#define circleType_H
#include "pointType.h"
using namespace std;
class circleType: public pointType
{
      public:
             circleType();
             //default constructor
             //postcondtition: sets r=0;
             circleType(double X, double Y, double R); 
             //default constructer 
             //precondition: all three parameters should be double
             //postcondition: sets X and  Y to point by callig function set point and sets R as the radius 
             void print();
             //function to print out the point and the radius
             //poscondition:returns the point and the radius on the screen
             void setPoint(double X, double Y);
             //funcion to set point of the circle
             //percondition: takes two double
             //postcondition: calls function setPoint and sets the points
             void setRadius(double R);
             //fucntion to set the radius
             //precondtion: the parameter should be a double
             //postcondition: it assigns r to the radius
      
      
      private:
              double r; //private variable to store the radius
              pointType p; //cpmposite function: point type is declared here
};              
#include "circleType.h"
#endif
