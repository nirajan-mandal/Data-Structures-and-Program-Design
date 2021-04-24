//Specification file complexType.h

#ifndef H_complexNumber
#define H_complexNumber
#include <cassert>
#include <iostream>
using namespace std;

class complexType
{
	   	 //Overload the stream insertion and extraction operators
    friend ostream& operator<< (ostream&, const complexType&);
    friend istream& operator>> (istream&, complexType&);
    friend complexType operator-(const complexType& c1,const complexType& c2); 
		//Overload the operator -
	friend complexType operator/(const complexType& c1,const complexType& c2); 
		//Overload the operator /	

public:
    void setComplex(const double& real, const double& imag); 
	    //Function to set the complex numbers according to 
 	    //the parameters.
	    //Postcondition: realPart = real; imaginaryPart = imag
	
    complexType(double real=0 , double imag=0 );  
		//constructor
		//Initializes the complex numbers according to 
		//the parameters.
		//Postcondition: realPart = real; imaginaryPart = imag

    complexType operator+(const complexType& otherComplex) const; 
		//Overload the operator +

    complexType operator*(const complexType& otherComplex) const;
		//Overload the operator *

    bool operator==(const complexType& otherComplex) const;
		//Overload the operator ==
	//void operator =(const complexType& C);	
	
   
          
    complexType operator~();   
        //Overload the operator ~ to find conjugate
    double operator!();
        //Overload the operator !    to find modulus
         	

private:
    double realPart;      //variable to store the real part
    double imaginaryPart; //variable to store the imaginary part
};


#endif
