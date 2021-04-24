//Nirajan Mandal 01/28/2008
//this is a small program to see the inhertance charcter between a point and a circle
//because all circle has a center(point) and a radius
//this is implemented here using a composition function
#include <iostream>
#include <iomanip>
#include "circleType.h"

using namespace std;

int main()
{
	circleType circle1(3, 2.5, 4);     //call to the default constructor of circleType with three parameters
	circleType circle2;

	cout<<fixed<<showpoint;            //these two lines declares the decimal point to be displayed on the screen  
	cout<<setprecision(2);             //the decimal point is set to 2

	cout<<"***** Circle 1 *****"<<endl;
	circle1.print();                   //prints out the point (center) and the radius
	cout<<endl;


	circle2.setPoint(-2.5, 7);         //fucntion call to set the point 
	circle2.setRadius(4);              //function call to set the radius

	cout<<"***** Circle 2 *****"<<endl;
	circle2.print();
	cout<<endl;

	double x, y;
	double r;

	circleType circle3;

	cout<<"Enter x Coordinates of the center: ";
	cin>>x;
	cout<<endl;

	cout<<"Enter y Coordinate of the center: ";
	cin>>y;
	cout<<endl;

	cout<<"Enter radius: ";
	cin>>r;
	cout<<endl;

	circle3.setPoint(x,y);
	circle3.setRadius(r);

	cout<<"***** Circle 3 *****"<<endl;
	circle3.print();
	cout<<endl;
    system("pause");
	return 0;
}
