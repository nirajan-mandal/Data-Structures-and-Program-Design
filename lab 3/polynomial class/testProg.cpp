//Nirajan Mandal 02/05/2008
//This program computes the lagebra of complex polynomials
//the program can: add, subtract, multiply, evaluate and differntiate

#include <iostream>

#include "polynomialType.h"

using namespace std;

int main()
{
	polynomialType p(4);			
	polynomialType q(3);			
	polynomialType t;				
    cout<<"Enter a+bi in the form (a,b) \n";
	cin>>p;							
	cout<<endl<<"Line 5: p(x) : "<<p<<endl<<endl;
	cout<<"p'(x) : "<<~p<<endl<<endl;   						
    complexType c;
    cout<<"Enter a complex to evalate at p(x) :";
    cin>>c; 
	cout<<"p("<<c<<") : "<<p(c)<<endl<<endl;	
    	
	cin>>q;							
	cout<<endl<<"q(x) : "<<q<<endl<<endl;				
    cout<<"p(x) + q(x) : "<<p+q<<endl<<endl;					
	cout<<"p(x) - q(x) : " <<p - q<<endl<<endl;
    cout<<"P(x) * q(x) : "<<p*q<<endl<<endl;				
   
	system("PAUSE");
    return 0;
}
