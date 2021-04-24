#include <iostream>
#include <cmath>
#include "polynomialType.h"


using namespace std;

polynomialType::polynomialType(int size) 
          : arrayListType<complexType>(size)
{
	length = size;
	for(int i = 0; i < size; i++)
		list[i] = (0,0);
}

complexType polynomialType::operator() (complexType x)
{
	complexType value=list[0];        //first coefficient is stored
	complexType p=x;                  
	for(int i = 1; i < length; i++)   //loop to evaluate the polynomial
	{
		if(!list[i] != (0,0))
		{
			
            value = value + p*list[i];  //computes C*x^n
			
         }	
         p=p*x;                       //changes the value of p by one poer of x each time
	}

	return value;

}


polynomialType polynomialType::operator+
               (const polynomialType& right)
{
	int size = max(length, right.length);
	int i;

	polynomialType temp(size);

	for(i = 0; i < min(length, right.length); i++)
		temp.list[i] = list[i] + right.list[i];

	if(size == length)
		for(i = min(length, right.length); i < length; i++)
			temp.list[i] = list[i];
	else
		for(i = min(length, right.length); i < right.length; i++)
			temp.list[i] = right.list[i];

	return temp;

}

polynomialType polynomialType::operator-
               (const polynomialType& right)
{
	int size = max(length, right.length);
	int i;

	polynomialType temp(size);

	for(i = 0; i < min(length, right.length); i++)
		temp.list[i] = list[i] - right.list[i];

	if(size == length)
		for(i = min(length, right.length); i < length; i++)
			temp.list[i] = list[i];
	else
		for(i = min(length, right.length); i < right.length; i++)
			temp.list[i] =(0,0) -right.list[i];

	return temp;

}

polynomialType polynomialType::operator*
               (const polynomialType& right)
{
	int size=length+right.length;
    polynomialType temp(size);
	for(int i=0; i<size; i++)
	    temp.list[i]=(0,0);
	for(int i=0; i<length; i++)    
	{ 
      for(int j=0; j<right.length; j++)
	  {
            temp.list[i+j]=temp.list[i+j]+list[i]*right.list[j];
       }  
	
    }

	return temp;
}
polynomialType polynomialType::operator~()
{
    polynomialType temp(length);  //temorary variable to store the P'(x)
    for(int i=1; i<length; i++) //loop to compute p'(x)
    {
            complexType c(i,0);  
            temp.list[i-1]=c*list[i];   //use of the formula P'(x)=nx^n-1 and so on
             }
     return temp;
}            
    
/*
int polynomialType::min(int x, int y)
{
	if(x <= y)
		return x;
	else
		return y;
}

int polynomialType::max(int x, int y)
{
	if(x >= y)
		return x;
	else
		return y;
}
*/
ostream& operator<<(ostream& os, const polynomialType& p)
{
	int i;
	int indexFirstNonzeroCoeff = 0;

	for(i = 0; i < p.length; i++)
		if(!p.list[i] != 0)
		{
			indexFirstNonzeroCoeff = i;
			break;
		}

	if(indexFirstNonzeroCoeff < p.length)
	{
		if(indexFirstNonzeroCoeff == 0)
			os<<p.list[indexFirstNonzeroCoeff]<<" ";
		else
			os<<p.list[indexFirstNonzeroCoeff]<<"x^"
			  <<indexFirstNonzeroCoeff<<" ";

		for(i = indexFirstNonzeroCoeff + 1; i < p.length; i++)
		{
			if(!p.list[i] != 0.0)
				
					os<<"+ "<<p.list[i]
						<<"x^"<<i<<" ";
			
		}
	}
    else
		os<<"0";

	return os;
}

istream& operator>>(istream& is, polynomialType& p)
{
	cout<<"The degree of the polynomial is: "
		<<p.length - 1<<endl;
	for(int i = 0; i < p.length; i++)
	{
		cout<<"Enter the coefficient of x^"<<i<<": ";
		is>>p.list[i];
	}

	return is;
}

