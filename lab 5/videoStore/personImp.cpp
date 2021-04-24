#include <iostream>
#include "person.h"

using namespace std;


void personType::print() const
{
	cout<<firstName<<" "<<lastName<<endl;
}
void personType::printID()
{
	cout<<ID<<" "<<firstName<<" "<<lastName<<endl;
}
int personType::getID()
{
    return ID;
}
void personType::addRentVideo(string title)
{
    rented_num++;
    rented_name[rented_num]=title;
}
void personType::returnRentVideo(string title)
{
    int loc=0;
    if(searchRentedVideo(title, loc))
    { 
      for(int i=loc; i<rented_num; i++)
       rented_name[i]=rented_name[i+1];
      rented_num--;
      cout<<"Thanks for returning "<<title<<endl;
     }
     else
        cout<<"you did not rent "<<title<<" "<<endl;
} 
bool personType::searchRentedVideo(string title, int& loc)
{
     for(int i=0; i<=rented_num; i++)
     {
             if(title==rented_name[i])
             {
                 loc=i;
                 return true;
                 }
       }        
     return false;
}                                          

void personType::setName(string first, string last)
{
	firstName = first;
	lastName = last;
}

void personType::getName(string& first, string& last)
{
	first = firstName;
	last = lastName;
}

//constructor 
personType::personType(string first, string last) 

{ 
	firstName = first;
	lastName = last;
}
