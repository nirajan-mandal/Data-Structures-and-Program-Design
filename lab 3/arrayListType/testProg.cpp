//Nirajan Mandal 02/04/2008
//This program manipulates the items in the list of type integer and string 
//this program finds the minimum, maximum and deletes item from the list
#include <iostream>

#include "newString.h"
#include "arrayListType.h"

using namespace std;

int main()
{
    arrayListType<int> intList(100);			 			
    arrayListType<newString> stringList;					

    int counter;										
    int number;												
    cout<<"Enter the size of the integer list: ";
    cin>>counter;             
    cout<<"Processing the integer list"
		<<endl;												
    cout<<"Enter "<< counter<<" integers: ";					
										
    for(int i = 0; i < counter; i++)			
    {	
		cin>>number;						 				
		intList.insertAt(i, number);		 		
    }
    cout<<endl;												
    cout<<"The list you entered is: ";			
    intList.print();									
    cout<<endl;	
    cout<<"The minimum value of the list is: ";
    intList.min(counter);											
    cout<<"The maximum value of the list is: ";
    intList.max(counter);
    cout<<"Enter the item to be deleted once: ";
    cin>>number;
    intList.remove(number);	
    cout<<"After removing "<<number
		<<", the list is:"<<endl;							
    intList.print();										
    cout<<endl;
    cout<<"Enter the item to be deleted from the list: ";		
    cin>>number;											
    intList.removeAll(number, counter);								
    cout<<"After removing "<<number
		<<", the list is:"<<endl;							
    intList.print();										
    cout<<endl;												

    newString str;						 					

    cout<<"Processing the string list"
		<<endl;											
	
    cout<<"Enter the size of the string list: ";
    cin>>counter;				
    cout<<"Enter "<< counter<<" integers: ";
    for(int i = 0; i < counter; i++)			
    {
		cin>>str;										
		stringList.insertAt(i, str);		 			
    }

    cout<<endl;											
    cout<<"The list you entered is: "
	  	  <<endl;											
    stringList.print();									
    cout<<endl;												
    cout<<"The minimum value of the list is: ";
    stringList.min(counter);											
    cout<<"The maximum value of the list is: ";
    stringList.max(counter);
    cout<<"Enter the string to be deleted one time: ";		
    cin>>str;
    stringList.remove(str);	
    cout<<"After removing "<<str
	  	 <<", the list is:"<<endl;				 			
    stringList.print();										
    cout<<endl;	
    cout<<"Line Enter the string to be deleted from the list: ";
    cin>>str;
    stringList.removeAll(str, counter);						
    								
    cout<<"After removing "<<str
	  	 <<", the list is:"<<endl;				 			
    stringList.print();									
    cout<<endl;													

   

    											
    system("pause");
    return 0;
}
