//Nirajan mandal 04/18/2007
//note arrays are call by reference
#include <iostream>
#include <fstream>
#include <ctime> 
using namespace std;
void prog(int x);  
//call to the program with array size 5000*x
void selection_sort(int a[], int s);
//precondition: takes an array of type int and its size
//postcondition: sorts the array using selection sort algorithmn
void insertion_sort(int a[], int n);
//precondition: takes an array of type int and its size
//postcondition: sorts the array using insertion sort algorithmn
void bubble_sort(int a[], int n);
//precondition: takes an array of type int and its size
//postcondition: sorts the array using bubble sort algorithmn

void merge_sort(int a[], int first, int last);
//precondition: takes an array of type int and its size
//postcondition: sorts the array using merge sort algorithmn
void merge(int a[], int first, int mid, int mid_1, int last);
// function to merge the two partioned arrays

void quick_sort_middle (int a[], int n);
//precondition: takes an array of type int and its size
//postcondition: sorts the array using quick sort algorithmn
//uses middle data as the pivot
int partition_middle(int a[], int first, int last);
//function to partion the array
void rec_quick_sort_middle(int a[], int first, int last);
//reccursive call fucntion to sort the array

void quick_sort_median (int a[], int n);                 //quick sort using median data as pivotr 
int partition_median(int a[], int first, int last);      //of first, last and the mid data
void rec_quick_sort_median(int a[], int first, int last);

void quick_sort_random (int a[], int n);                 //quick sort using a ramdom data as pivot
int partition_random(int a[], int first, int last);
void rec_quick_sort_random(int a[], int first, int last);

void swap(int a[], int p, int q);
//general swap function
int min_loc(int a[], int x, int y);
//function to locate the minimum data from the array
//returns the index of the minimum data
void print(int a[]);
void copy(int a[], int b[], int k);


int main()
{
    
    srand((unsigned)time(0)); 
    ofstream of;   
    of.open("output.txt");     //opens file to write
   if(of.fail())                  //contition to exit file if file fails to open
    {
        cout<<"failed to open the input data file.";
        exit(1);
    }
    of.close();
    of.open("output.txt", ios::app);
    cout<<"\n***************************************"<<endl;
    of<<"\n***************************************"<<endl;  
    prog(1);
    cout<<"\n***************************************"<<endl;
    of<<"\n***************************************"<<endl;  
    prog(2);
    cout<<"\n***************************************"<<endl;
    of<<"\n***************************************"<<endl;  
    prog(4);
    cout<<"\n***************************************"<<endl;
    of<<"\n***************************************"<<endl;  
    prog(6);
    cout<<"\n****************** end of file ******************"<<endl;
    of<<"\n****************** end of file ******************"<<endl;
system("PAUSE");
return 0;
}
            
void selection_sort(int a[], int s)
{
    ofstream of;   
    of.open("output.txt", ios::app);
    clock_t t1, t2;
    t1=clock();
    for(int i=0; i<s; i++)
         swap(a, i, min_loc(a, i, s));
    t2=clock();
    cout<<"CPU time for selection sort: "<<(t2-t1)<<endl;
    of<<"CPU time for selection sort: "<<(t2-t1)<<endl;
 }
void bubble_sort(int a[], int n)
{
    ofstream of;   
    of.open("output.txt", ios::app);
    clock_t t1, t2;
    t1=clock();
     for(int i=0; i<n; i++)
     {
         bool check=true; 
             for(int j=0; j<n-i-1; j++)
             {
                     if( a[j+1]<a[j])
                     {
                         check=false;
                         swap(a, j+1, j);
                       }
               }  
         if(check)
            break;             
      } 
    t2=clock(); 
    cout<<"CPU time for bubble sort: "<<(t2-t1)<<endl;  
    of<<"CPU time for bubble sort: "<<(t2-t1)<<endl;      
}
void insertion_sort(int a[], int n)
{
     ofstream of;   
    of.open("output.txt", ios::app);
     clock_t t1, t2;
     t1=clock();
     int first, loc, temp;
     for(int first=1; first<n; first++)
     {
          if(a[first]<a[first-1])
          { 
                temp=a[first];
                loc=first;
                do
                {
                     a[loc]=a[loc-1];
                     loc--;
                   }while(loc>0 && a[loc-1]>temp);
                 a[loc]=temp;
            }
      }
     t2=clock(); 
    cout<<"CPU time for insertion sort: "<<(t2-t1)<<endl;
    of<<"CPU time for insertion sort: "<<(t2-t1)<<endl;    
}//end insertion_sort
void merge_sort(int a[], int first, int last)
{
   
     if(first<last)
     {
              int mid=(first+last)/2;
              merge_sort(a, first, mid);
              merge_sort(a, mid+1, last);
              merge(a, first, mid, mid+1, last);
        }
      
}                   
void merge(int a[], int first, int mid, int mid_1, int last)
{
  int i, j, k;
  int temp[last];

   for (i=first; i<=last; i++)
        temp[i]=a[i];
   i=first; j=mid_1; k=first;
   while (i<=mid && j<=last)
        if (temp[i]<=temp[j])
            a[k++]=temp[i++];
        else
            a[k++]=temp[j++];
   
    while (i<=mid)
        a[k++]=temp[i++];
}   
void quick_sort_middle (int a[], int n)
{
     ofstream of;   
    of.open("output.txt", ios::app);
     clock_t t1, t2;
     t1=clock();
     rec_quick_sort_middle(a, 0, n-1);
     t2=clock(); 
     cout<<"CPU time for quick sort with pivot at middle element: "<<(t2-t1)<<endl; 
     of<<"CPU time for quick sort with pivot at middle element: "<<(t2-t1)<<endl;   
 }
int partition_middle(int a[], int first, int last)
{
    int piv;
    int index, lit_index;
    swap(a, first, (first+last)/2);
    piv=a[first] ;
    lit_index=first;
    for( index=first+1; index<=last; index++)
      if(a[index]<piv)
      {
             lit_index++;
             swap(a, lit_index, index);
         }
     swap( a, first, lit_index);
     return lit_index;
}                      
void rec_quick_sort_middle(int a[],int first, int last)
{
   int piv_loc;
   if(first<last)  
   {
          piv_loc=partition_middle(a, first, last);
          rec_quick_sort_middle(a, first, piv_loc-1);
          rec_quick_sort_middle(a, piv_loc+1, last);
      }   
} 
void quick_sort_median (int a[], int n)
{
     ofstream of;   
    of.open("output.txt", ios::app);
     clock_t t1, t2;
     t1=clock();
     rec_quick_sort_median(a, 0, n-1);
     t2=clock(); 
     cout<<"CPU time for quick sort with pivot at median element: "<<(t2-t1)<<endl; 
     of<<"CPU time for quick sort with pivot at median element: "<<(t2-t1)<<endl;    
 }
int partition_median(int a[], int first, int last)
{
    int piv, median, mid=(first+last)/2;
    int index, lit_index;
    //median=mid;
    if(a[first]<=a[last] && a[first]>=a[mid])
      median=first;
    else if(a[mid]<=a[last] && a[mid]>=a[first])
      median=mid;
    else 
      median=last;
    //cout<<"test "<<first<<" "<<last<<" "<<mid<<" "<<median<<endl;  
    swap(a, first, median);
    piv=a[first] ;
    lit_index=first;
    for( index=first+1; index<=last; index++)
      if(a[index]<piv)
      {
             lit_index++;
             swap(a, lit_index, index);
         }
     swap( a, first, lit_index);
     return lit_index;
}                      
void rec_quick_sort_median(int a[],int first, int last)
{
   int piv_loc;
   if(first<last)  
   {
          piv_loc=partition_median(a, first, last);
          rec_quick_sort_median(a, first, piv_loc-1);
          rec_quick_sort_median(a, piv_loc+1, last);
      }   
}       
void quick_sort_random (int a[], int n)
{
     ofstream of;   
    of.open("output.txt", ios::app);
     clock_t t1, t2;
     t1=clock();
     rec_quick_sort_random(a, 0, n-1);
     t2=clock(); 
     cout<<"CPU time for quick sort with pivot at random element: "<<(t2-t1)<<endl;  
     of<<"CPU time for quick sort with pivot at random element: "<<(t2-t1)<<endl;    
 }
int partition_random(int a[], int first, int last)
{
    int piv;
    int index, lit_index;
    swap(a, first, rand()%(last-first+1)+first);
    piv=a[first] ;
    lit_index=first;
    for( index=first+1; index<=last; index++)
      if(a[index]<piv)
      {
             lit_index++;
             swap(a, lit_index, index);
         }
    swap( a, first, lit_index);
     return lit_index;
}                      
void rec_quick_sort_random(int a[],int first, int last)
{
   int piv_loc;
   if(first<last)  
   {
          piv_loc=partition_random(a, first, last);
          rec_quick_sort_random(a, first, piv_loc-1);
          rec_quick_sort_random(a, piv_loc+1, last);
      }   
}    
         
void swap(int a[], int p, int q)
{
     int temp;
     temp=a[p];
     a[p]=a[q];
     a[q]=temp;
}//end swap     
int min_loc(int a[], int x, int y)
{
    int min=a[x];
    int index=x;
    for(int i=x+1; i<y; i++)   
    {
            if(a[i]<min)
            { 
               min=a[i];
               index=i;
               }
      }
      return index;
}//end min_loc    
void print(int a[])
{
    ofstream of;   
    of.open("output.txt", ios::app);
     for(int i=0; i<20; i++)
     {
       cout<<a[i]<<" "; 
       of<<a[i]<<" "; 
      } 
     cout<<endl<<endl;; 
     of<<endl<<endl;
} 
void copy(int a[], int b[], int k)
{
     for(int i=0; i<k; i++)
        a[i]=b[i];
} 
void prog(int x)
{
    ofstream of;   
    of.open("output.txt", ios::app);
    int k=5000*x;
    int a[k];
    for(int i=0; i<k; i++)
       a[i]=rand();
    cout<<"First 20 data out of "<< k<<endl;
    of<<"First 20 data out of "<< k<<endl;
    print(a); 
    int b[k], c[k], d[k], e[k], f[k], g[k], h[k];   
    copy(b, a, k);
    copy(c, a, k);
    copy(d, a, k);
    copy(e, a, k);
    copy(f, a, k);
    copy(g, a, k);
    copy(h, a, k);
    selection_sort(b, k);
    print(b);
    bubble_sort(c, k);
    print(c);
    insertion_sort(d, k);
    print(d);
    clock_t t1, t2;
     t1=clock();  
    merge_sort(e, 0, k-1);
     t2=clock(); 
    cout<<"CPU time for merge sort: "<<(t2-t1)<<endl;  
   of<<"CPU time for merge sort: "<<(t2-t1)<<endl; 
    print(e);
    quick_sort_middle(f, k);
    print(f);
    quick_sort_median(g, k);
    print(g);
    quick_sort_random(h,k);
    print(h);       
 
}
