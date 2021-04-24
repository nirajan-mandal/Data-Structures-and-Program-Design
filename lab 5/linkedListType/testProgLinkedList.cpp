//Nirajan Mandal 02/23/2008
//This program tests various operation of a linked list
//see the .h file for the functions

#include <iostream>
#include "linkedList.h"

using namespace std;

int main()
{   
linkedListType<int> list;    //list of type int
int num,item, K;
cout<<"the data in the list is :\n\n";
srand((unsigned)time(0)); //function so that rand() does not generates teh same numbers
for(int i=0; i<20; i++)   //loop fill 20 item in the list
{
  num=(rand()%10);        //generates integer from 0 to 9
  cout<<num<<" ";      
  list.insertLast(num);   //the generated integer is added to the end of the list
}
cout<<endl;
list.delsmallest();       //function call to delete the samllest info of the list (only once)
cout<<"data after deleting the minimum (once) the new list is : "<<endl;
cout<<list<<endl;             //displays the current list 
cout<<"\nenter the item to delete from the list : ";
cin>>item;
list.delall(item);         //function call to delete the occurence of the item from the list
cout<<"new data..\n";
cout<<list<<endl;               //displays the current list 
cout<<"\nenter the kth item you want to know: ";
cin>>K;
cout<<"the kth item is: "<<list.kth_element(K)<<endl;  //cunction call to display kth info
cout<<"\nenter the kth item you want to delete: ";
cin>>K;
list.del_kth_element(K);        //function call to delete the kth info
cout<<"new data...\n";
cout<<list<<endl;                 //displays the current list 
cout<<endl;
 
 system("PAUSE");
}


