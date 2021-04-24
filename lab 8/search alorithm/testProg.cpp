#include <ctime> 
#include <iostream>
//Nirajan Mandal
//Program to test steps for different search algorithms....
#include "arrayListType.h"
#include "orderedArrayListType.h"

using namespace std;

int main()
{
	srand((unsigned)time(0)); 
	arrayListType<int>norm(1000);
	orderedArrayListType <int> ord(1000);
	int k;
	while (!norm.isFull())
    {
        k=(47*2743+(rand()%1000)*5923)%100000;
        if(norm.seqSearch(k)==-1)
        {
            norm.insertEnd(k);
            ord.insertOrd(k); 
          }
      }
    //norm.print(); 
    //cout<<endl;
    //ord.print(); 
    cout<<"These nembers are stored somewhere..... \n";
    for(int i=0; i<10; i++)
    {
      norm.retrieveAt(rand()%1000, k);
      cout<<k<<"\t";       
      }
              
    char response;
    do
    {
          cout<<"\nEnter an integer : ";
          cin>>k;
          norm.newSeqSearch(k);
          ord.binarySearch(k);
          ord.binSeqSearch(k);
          cout<<"Enter 'q' to quit or press any key to continue: ";
          cin>>response;
          
          
      }while((response !='q')&&(response !='Q'));
           
    system("pause");
	return 0;
}
