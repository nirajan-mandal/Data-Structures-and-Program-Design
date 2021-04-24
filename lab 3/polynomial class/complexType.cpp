
//Implementation file complexType.cpp

#include <iostream>
#include <cmath>
using namespace std;

#include "complexType.h"
//the normal mathematical farmulas are used to calculate the real and complex parts of the complex numbers

ostream& operator<<(ostream& osObject, const complexType& complex)
{
	osObject<<"(";						//Step a
	osObject<<complex.realPart;			//Step b
	osObject<<", ";						//Step c
	osObject<<complex.imaginaryPart;	//Step d
	osObject<<")";						//Step e

	return osObject;			
}

istream& operator>> (istream& isObject, complexType& complex)
{
	char ch;

	isObject>>ch;                     //Step a
	isObject>>complex.realPart;       //Step b
	isObject>>ch;                     //Step c
	isObject>>complex.imaginaryPart;  //Step d
	isObject>>ch;                     //Step e

	return isObject;			
}


bool complexType::operator==(const complexType& otherComplex) const
{
	return(realPart == otherComplex.realPart && 
	      imaginaryPart == otherComplex.imaginaryPart);
}

void complexType::setComplex(const double& real, const double& imag)
{
	realPart = real;
	imaginaryPart = imag;
}

	//constructor 
complexType::complexType(double real, double imag)
{
     setComplex(real, imag);
}

	//Overload the operator +	
complexType complexType::operator+
 	                (const complexType& otherComplex) const
{
	complexType temp;

	temp.realPart = realPart + otherComplex.realPart;
	temp.imaginaryPart = imaginaryPart 
	                     + otherComplex.imaginaryPart;

	return temp;
}

	//Overload the operator *
complexType complexType::operator*
 				 (const complexType& otherComplex) const
{
   complexType temp;

   temp.realPart = (realPart * otherComplex.realPart) -
                   (imaginaryPart * otherComplex.imaginaryPart);
   temp.imaginaryPart = (realPart * otherComplex.imaginaryPart)  
	                  + (imaginaryPart * otherComplex.realPart);
   return temp;
}
//Overload the operator -	
complexType operator-(const complexType& c1,const complexType& c2)
{
	complexType temp;

	temp.realPart = c1.realPart- c2.realPart;
	temp.imaginaryPart = c1.imaginaryPart- c2.imaginaryPart;

	return temp;
}
//Overload the operator -	
complexType operator/(const complexType& c1,const complexType& c2)
{
	double k=(c2.realPart*c2.realPart+ c2.imaginaryPart*c2.imaginaryPart);
    if (k==0)   //if loop to check if the division is possible or not
	{   
       cout<<"undefined division"<<endl;
	   return (0,0);
    }
    complexType temp;
    temp.realPart = (c1.realPart*c2.realPart+ c1.imaginaryPart*c2.imaginaryPart)/k;
	temp.imaginaryPart =(-c1.realPart* c2.imaginaryPart+ c1.imaginaryPart*c2.realPart)/k;

	return temp;
}
//void complexType operator =(const complexType& C)
//{
     //realPart=C.realPart;
     //imaginaryPart=C.imaginaryPart;
//}
complexType complexType::operator~()
{
     complexType temp;

	temp.realPart = realPart ;
	temp.imaginaryPart = -imaginaryPart;       
    return temp;
}

double complexType::operator!()
{
            return (sqrt(realPart*realPart+imaginaryPart*imaginaryPart));
}            
