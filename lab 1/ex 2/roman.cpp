//Nirajan Mandal 01/21/2008
//This program basically converts roman numerial into decimal
#include <iostream>
#include "romanType.h"
using namespace std;


int main()
{
 romanType rome;                    //object of type romanType class
 string s;                          //temp string to store the input         
 cout<<"Use CAPITAL letters to input the roman numeral. \n";
 cout<<"Enter a valid Roman Numeral : ";
 getline(cin, s);                   //gets the input from the user
 rome.setRoman(s);                  //call to the member function to store the string 
 int a=rome.makeDecimal(s);         //member function converts the decimal and stores it in a
 rome.setDecimal(a);                //member function sets stores the decimal in the private variable
 rome.choice();                     //member function to get the choces from the user
 
 

system("PAUSE");
return 0;
}
