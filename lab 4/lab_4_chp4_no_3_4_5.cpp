//Nirajan Mandal 02/12/2008
//This program manipulates vectors and iterators
//it can faind average, maximim, minimum and reverse teh entries in a vector
#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;
double max(vector<double> a);
//function to find the maximum from a vecton of type double
//precondition: requires a vector of type double
//postcondition: returns the maximum (type double) of the data stored in the vector               
double min(vector<double> a);
//function to find the minimum from a vecton of type double
//precondition: requires a vector of type double
//postcondition: returns the mimimum (type double)of the data stored in the vector
double average(vector<double> a);
//function to find the average from a vecton of type double
//precondition: requires a vector of type double
//postcondition: returns the average (type double) of the data stored in the vector
template < class elemType>
void reverseVector(vector<elemType> &list);
//function 
//precondition: requires a vector
//postcondition: reverses the order of the vector
template < class elemType>
int seqSearch(const vector<elemType> &list, const elemType &item);
//function to search a data type in a vector
//precondition: requires a vector and another data type
//postcondition: if the search itemis found it returns the location of the searched item in the vector
                   //else returns -1
int main()
{
vector<double> v;  //vector to store data of type double
//arrayListType<double> c(100);

cout<<"Enter q to quit entering. \n";
cout<<"Enter the real number:\n";
double x=0.0;
char num [256];    //this is required to get the data from th user in an efficient method
do                 //loop to get data from the user
{
    cin>>num;      //takes the data from the user and stores it as character
    if(!(num[0]=='q' || num[0]=='Q'))   //if the entered character is not 'q' or 'Q' it enters into if
    {
       x = atof ( num );    //converts the charcters into double                
       v.push_back(x);      //stores the double in the vector
       }
       
}while (num[0]!='q' && num[0]!='Q');   //loop stops if 'q' or 'Q' is entered
cout<<"\nYou entered:\n";
for(int i=0; i<v.size(); i++)          //loop to display the entered data
      cout<<v[i]<<"\t";
cout<<"\nThe maximum is: "<<max(v)<<endl;     //call to the function to find the maximum in the vector
cout<<"The minimum is: "<<min(v)<<endl;       //call to the function to find the minimum in the vector
cout<<"The average is: "<<average(v)<<endl;   //call to the function to find the average of the vector
double s;
cout<<"\nEnter the search item: ";
cin>>s;                                       //gets the data to be searched from the user       
cout<<"\nThe item is located at: ";
cout<<seqSearch(v, s)<<endl;                  //call to the funtion to search the entered data in the vector         
cout<<"\nAfter reversing the vector: \n\n";
reverseVector(v);                             //call to the function to reverse the elements of the vector
for(int i=0; i<v.size(); i++)                 //loop to display the reversed loop
      cout<<v[i]<<"\t";
cout<<endl<<endl;
system("PAUSE");
return 0;
}

double max(vector<double> a)
{
       double ma=a[0];                            //variable to store the maximum and stores the first item as maximum   
       for(int i=1; i<a.size(); i++)              //loop to find the maximum           
       {                                          //if the item in the vector is greater than the current maximum
               if(a[i]>ma)
                 ma=a[i];                         //maximum is assigned the new maximum value
        }
  return ma;      
}   
double min(vector<double> a)                      //the definition is similar to the max function
{
       double ma=a[0];
       for(int i=1; i<a.size(); i++)
       {
               if(a[i]<ma)
                 ma=a[i];
        }
  return ma;      
}       
double average(vector<double> a)                  //average function
{
       double total=0.0;                          //variable to store the sum of all the data
       for(int i=0; i<a.size(); i++)              //loop to add all the elements of the vector
            total+=a[i];
    return (total/a.size());                      //calulates teh average and returns it
}       

template < class elemType>
void reverseVector(vector<elemType> &list)        //reverse function

{
vector<double> temp(list.size());
temp=list;                                        //temporary copy of the vector is made
typename vector<elemType> :: iterator Itr1,Itr2;  //two iterators are defined
Itr1=temp.begin();                                
Itr2=temp.end();
reverse_copy (Itr1, Itr2, list.begin());          //function copies from Itr1 to Itr end in list in reverse order

} 
template < class elemType>
int seqSearch(const vector<elemType> &list, const elemType &item)   //search function
{
    for(int i=0; i<list.size(); i++)                                //loop to find the searched item
    {
            if(item==list[i])                                     //if the item is found            
              return i;                                           //returns the location in the vector      
     }
    return -1;                                                    //else returns -1
            
}
