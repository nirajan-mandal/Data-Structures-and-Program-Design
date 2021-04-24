//Nirajan Mandal 03/25/2008
//this program finds the prime factors in decending order
#include <iostream>
#include <stack>
using namespace std;
bool isPrime(int n);
//function to find weather an integer is prime or not
//preconditon: takes an integer
//postcondition: returns true if the integer is prime else returns false
void factor(int n);
//function to find the prime factors
//precondition:takes a integer
//postcondition:displays the primes factorazation

int main()
{
char c;
do        //loop to test the program several times/ until the user wants to quit
{         
int n;
cout<<"Enter a positive number: ";
cin>>n;
if(n>0)
factor(n);
else
cout<<"invalid input";
cout<<endl;
cout<<"Enter q to quit or press any key to try again: ";
cin>>c;
}while(c!='q' || c!='Q');
system("PAUSE");
return 0;
}
void factor(int n)
{
     stack<int> result;         //stack to hold the result temporarily
     cout<<"Factor(s): ";
     for(int i=2; i<=n; i++)    //loop to find the prime factor
     {
             if(isPrime(i))     //if i is prime we go ahead and see if i is a factor
             {
                           while(n%i==0)  //if i is a factor, we store it in the stack
                           {
                                     result.push(i);
                                     n=n/i;         //reduce the number by factor just found
                               }
                 }
          }
    while(!result.empty())  //loop to print the stack
	{
		cout<<result.top()<<" ";
	    result.pop();
	}    
} //end factor            
bool isPrime(int n)
{
     for (int i=2; i<n ; i++)   //loop to check if the integer is prime
     {
        if ((n%i)==0)
           return false;
           
           }    
     return true;
}  //end isPrime                           
                        
                          
