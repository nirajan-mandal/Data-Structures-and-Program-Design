#include <iostream>
#include "romanType.h"
using namespace std;

romanType::romanType()
{
     //roman=" ";               //this line created problem while compiling 
     decimal=0;
     }                          
void romanType::setRoman(string s)
{
     roman=s;                   //takes the string and sets it to private variable roman
     }
void romanType::setDecimal(int x)
{
     decimal=x;                //takes the int and sets it to private variable decimal
     }
string romanType::getRoman()
{
     return roman;             //returns the stored roman numeral  
     }
int romanType::getDecimal()
{
    return decimal;        //returns the stored decimal numeral
     }
int romanType::makeDecimal(string s)
{
    int s_new[s.length()];        //defines a new int array of size that of the characters in the roman numeral
    int k=-(s.length()-1);        //int variable needed to reverse the order of data stored in the new array
    for(int i=s.length()-1; i>=0; i--) //loop to store the individual charcters of the roman numeral
    {
            
            if(s[i]=='I')         //condition to store the corresponding numerical value in the new array
                        s_new[i+k]=1;
            if(s[i]=='V')
                        s_new[i+k]=5;
            if(s[i]=='X')
                        s_new[i+k]=10;
            if(s[i]=='L')
                        s_new[i+k]=50;
            if(s[i]=='C')
                        s_new[i+k]=100;
            if(s[i]=='D')
                        s_new[i+k]=500;
            if(s[i]=='M')
                        s_new[i+k]=1000;
                  k+=2;          //k is increased by two because the loop is decresing by 1 and we want the new array to increase by 1
        }
        int dec=s_new[0];        //new int varaiable to store the decimal
                                 //the last charcter f the roman numeral is stored in it
                                 
        // the following loop calculates the roman value in reverse order
        //this is why we needed the new array 
     for(int i=1; i<s.length(); i++)
     {
             
             if(s_new[i]>=s_new[i-1]) //if the previous number is not less it adds the value
                dec+=s_new[i];
             else                     //else it decreases it
                 dec-=s_new[i];
       }
     return dec;  
}
void romanType::choice()
{
     char c;
     cout<<"\nEnter r to view roman numerial. \n";
     cout<<"Enter d to view decimal numerial.   ";
     cin>>c;
     if ((c=='r')||(c=='R'))
      cout<<"\nYou entered "<<getRoman()<<"."<<endl<<endl;
     else if ((c=='d')||(c=='D'))
       cout<<endl<<getRoman()<<" converted into decimal is "<<getDecimal()<<"."<<endl<<endl;
     else
       cout<<"Invalid input. \n\n";
                
      }
               
          

