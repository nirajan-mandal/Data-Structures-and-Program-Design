#include "circleType.h"
#include <iostream>

circleType::circleType()
{
         r=0;
}                     
void circleType::print() 
{
     pointType::print();
     cout<<"radius       : "<<r<<endl;
     cout<<"circumference: "<<2*3.1415*r<<endl;
     cout<<"area         : "<<3.1415*r*r<<endl;  
} 
circleType::circleType(double X, double Y, double R) :pointType(X , Y)  
{
     r=R;
}                               
void circleType::setPoint(double X, double Y) 
{
     pointType::setPoint(X, Y);
}    
void circleType::setRadius(double R)
{
     r=R;
}     
