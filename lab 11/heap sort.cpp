//Nirajan Mandal 05/02/2008
//This program uses heap sort to short the integers in the array
#include <iostream>
#include <ctime> 
using namespace std;
void heapSort(int a[], int k);
//precondition: takes an array of type integer and k is the size of the array
//post condition: the array is sorted
void buildHeap(int a[], int k);
//precondition: takes an array of type integer and k is the size of the array
//postcondition:heap tree is build using data from a[]
void heapify(int a[], int low, int high);
//precondition:takes an array of type integer and the lower and higher index of the array
//postcondition: the heap tree is heapified from low to high
int main()
{
    srand((unsigned)time(0));               //seed for random generator
    cout<<"The array will contain integers <1000\n";
    int k;           //size of the array
    char r;          //character to store response
    do
    {
    cout<<"\nEnter size of array: ";
    cin>>k;
    int a[k];
    cout<<"The array contains.....\n\n";
    for(int i=0; i<k; i++)
       a[i]=rand()%1000;                  //random integer <1000 is stored in the array
    for(int i=0; i<k; i++)
       cout<<a[i]<<" ";
    heapSort(a, k);   
    cout<<endl<<endl;
    cout<<"The sorted array contains.....\n\n";
    for(int i=0; i<k; i++)
       cout<<a[i]<<" "; 
    cout<<endl<<endl;
    cout<<"Enter 'q' to quit or press any key: ";
    cin>>r;   
         
     }while(r!='q' && r!='Q');  

//system("PAUSE");
return 0;
}
void heapSort(int a[], int k)
{
     int  l;
     int temp;
     buildHeap(a, k);        //heap tree is build
     for(l=k-1; l>=0; l--)
     {
          temp=a[l];
          a[l]=a[0];
          a[0]=temp;
          heapify(a, 0, l-1);   //the tree is heapified
       }   
} 
void buildHeap(int a[], int k)
{
     int index;
     for(index=k/2-1; index>=0; index--)
       heapify(a, index, k-1);
     
}
void heapify(int a[], int low, int high)
{
     int largeIndex;
     int temp=a[low];
     largeIndex=2*low+1;
     while(largeIndex<=high)
     {
          if(largeIndex<high)
             if(a[largeIndex]<a[largeIndex+1])
                largeIndex=largeIndex+1;
          if(temp>a[largeIndex])
             break;
          else
          {
              a[low]=a[largeIndex];
              low=largeIndex;
              largeIndex=2*low+1;
           }
       }
      a[low]=temp;
}           
                    
                                
                
     
