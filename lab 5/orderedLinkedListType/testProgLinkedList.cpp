//Nirjan Mandal 02/23/2008
//Program to test merge operations on an ordered linked list


#include <iostream> 
#include "orderedLinkedList.h"

using namespace std;
void reversePrint(nodeType<int>* current);
int main()
{
cout<<"This program generates random numbers for the list.\n";
cout<<"This is just a test program to test the merge function. \n\n";    
orderedLinkedListType<int> list_a, list_b, newlist;	//Line 1
int num;     
srand((unsigned)time(0)); //function so that rand() does not generates teh same numbers
for(int i=0; i<3; i++)   //loop fill 3 item in the list
{
  num=(rand()%20);        //generates integer from 0 to 19
  list_a.insertNode(num);   //the generated integer is added to the end of the list
}
cout<<"\nlist_a has: "<<list_a<<endl;
for(int i=0; i<5; i++)   //loop fill 5 item in the list
{
  num=(rand()%20);        //generates integer from 0 to 19
  list_b.insertNode(num);   //the generated integer is added to the end of the list
}
cout<<"\nlist_b has: "<<list_b<<endl;
newlist.mergeList(list_a, list_b);          //function call to merge two list into one
cout<<"\nafter merge function is called \n";
cout<<"\nnow list_a has: "<<list_a<<endl;
cout<<"\nnow list_b has: "<<list_b<<endl;
cout<<"\nnewlist has: "<<newlist<<endl<<endl;
//OrderedLinkedListType<int> current;
//current=newlist.start;
     system("PAUSE");
     return 0;					
}

void reversePrint(nodeType<int>* current)
{
  if(current->link!=NULL)
     reversePrint(current->link);
   cout<<current->info<<" ";  
 }



