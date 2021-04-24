#ifndef H_personType
#define H_personType

#include <string>
using namespace std;

class personType
{
public:
       friend ostream& operator<<(ostream& os, const personType& person)
	
{
	os<<endl;
	os<<"Account#: "<<person.ID<<endl;
	os<<"Name \t: "<<person.firstName<<" "<<person.lastName<<endl;
	os<<"Rented \t: "<<person.rented_num<<endl;
	os<<"Videos \t: ";
	if(person.rented_num>0)
	{
         for(int i=1; i<=person.rented_num; i++)
             {
               os<<person.rented_name[i]<<endl;
               os<<"\t  ";
               }
      }
    else
       os<<"NONE... "<<endl; 
    os<<endl;                         
	os<<"_____________________________________"<<endl;
	return os;
}
    void print() const;
		//Function to output the first name and last name
		//in the form firstName lastName
    void printID();
         //Function to print ID (account #) and name
    int getID();
        //function to return the ID
    void addRentVideo(string);
        //function to update customer's info after renting video
    void returnRentVideo(string);
        //function to update customer's info after returning video
    bool searchRentedVideo(string , int& );
        //function fo search a video in a customers account
    void setName(string first, string last);
		//Function to set firstName and lastName according to 
 		//the parameters
		//Postcondition: firstName = first; lastName = last

    void getName(string& first, string& last);
		//Function to return firstName and lastName via the 
		//parameters
		//Postcondition: first = firstName; last = lastName

    personType(string first = "", string last = "");
		//Constructor
		//Set firstName and lastName according to the parameters
 		//The default values of the parameters are empty strings
 		//Postcondition: firstName = first; lastName = last  

 protected:
    string firstName; //stores the first name
    string lastName;  //stores the last name
    string rented_name[10]; //stores name of checked out videos
                            //a customer can check out a maximim of 9 videos
                            //the size of the array can be changed to increase limit
                            //this will not affect the rest of the program
    int ID;                 //stores the account number of customer 
    int rented_num;         //stores the number of videos checked out
    
};

#endif
