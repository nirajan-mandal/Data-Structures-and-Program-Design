//Nirajan Mandal 03/30/2008
//This program sorts 50 random numbers of maximum of 'd' digits using radix sort algorithm
#include <iostream>
#include <cmath>
#include <queue>
using namespace std;
//arrays are used in these functions. By default arrays are call by reference
void radix_sort(int v[], int d);
//function to sort the array
//precondition: takes an array and the maximum digit
//postcondition: the array is sorted in ascending order
void distribute(int v[], queue<int> digitqueue[], int power);
//function to distribute all the numbers in different 10 bins
//precondition: 
//postcondition: distributes the numbers in the vecters in the queues
void collect(queue<int> digitqueue[], int v[]);
//function to collect the numbers from the queues to the vector
//precondition: takes a queus and a vector
//postcondition: collects the numbers from the queue to the vector
int main()
{
srand((unsigned)time(0)); 
int d, a[50];                 //variables for the max digits and an array to store 50 numbers
cout<<"Enter the maximum number of digit: ";
cin>>d;
for(int i=0; i<50; i++)
{
        a[i]=rand()*rand()%(int)pow(10.0, d); //loop to store 50 random numbers of max of 'd' digits
}
cout<<endl<<endl<<"50 generated random numbers of maximum "<<d<<" digits are...."<<endl<<endl;
for(int i=0; i<50; i++)         //loop to display the 50 numbers
{
        cout.width(d+2);        //this fixes the width of the cout to the number of digit
                                //and 2 explt spaces before it
        if(i%(10-(d/2))==0)     //this dictates how may numbers to put in a line
         cout<<endl;
        cout<<a[i]; 
}    
radix_sort(a, d);
cout<<endl<<endl<<"numbers sorted ....."<<endl<<endl;
for(int i=0; i<50; i++)    //same loop to display the SORTED numbers
{
        cout.width(d+2);
        if(i%(10-(d/2))==0) 
         cout<<endl;
        cout<<a[i]; 
} 
cout<<endl<<endl;      

  system("PAUSE");
  return 0;
}
void radix_sort(int v[], int d)
{
     int power=1;
     queue<int> digitqueue[10]; //10 queue are needed for the sorting algorithm
     for(int i=0; i<d; i++)     // 'd' loops are needed to sort the numbers     
     {
             distribute(v, digitqueue, power);   //distributes the numbers into bins
             collect(digitqueue, v);             //collects the numbers from the bins
             power*=10;
      }     
}
void distribute(int v[], queue<int> digitqueue[], int power)
{
       for(int i=0; i<50; i++)
           digitqueue[(v[i]/power)%10].push(v[i]);   //distribute the numbers to the assigned bins     
}
void collect(queue<int> digitqueue[], int v[])
{
         int k=0;
         for(int i=0; i<10; i++) //loop to collect all the numbers fromt eh ten bins
         {
                 while (!digitqueue[i].empty())
                 {
                        v[k]=digitqueue[i].front();
                        digitqueue[i].pop();
                        k++;
                   }
          }
}
          
   

