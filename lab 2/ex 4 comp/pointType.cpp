#include "pointType.h"
#include <iostream>

pointType::pointType()
{
         x=0;
         y=0;             
}
pointType::pointType(double X, double Y)
{
     x=X;
     y=Y;
}
void pointType::setPoint(double X, double Y)
{
     x=X;
     y=Y;
}
void pointType::print()
{
     cout<<"x-coordinate : "<<x<<endl;
     cout<<"y-coordinate : "<<y<<endl;
     //cout<<"center :  ("<<x<<","<<y<<")"<<endl;
}         
