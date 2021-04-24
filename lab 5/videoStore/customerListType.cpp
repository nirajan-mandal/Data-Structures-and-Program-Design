#include <iostream>
#include <string>
#include "customerListType.h"
using namespace std;
void customerListType::customerPrintName()
{
	nodeType<personType>* current;

	current = first;
	while(current != NULL)
	{
		current->info.print();
		current = current->link;
	}
}
void customerListType::customerID()
{
	nodeType<personType>* current;

	current = first;
	while(current != NULL)
	{
		current->info.printID();
		current = current->link;
	}
}
void customerListType::addVideo(int acc, string title)
{
    nodeType<personType>* current;
    current = first;
	while(current != NULL)
	{
		if(current->info.getID()==acc)
		{
            current->info.addRentVideo(title);
            cout<<"Enjoy your movie: "<<title<<endl;
        }
        current = current->link;
	}
}
void customerListType::returnVideo(int acc, string title)
{
	
    nodeType<personType>* current;
    current = first;
	while(current != NULL)
	{
		if(current->info.getID()==acc)
		{
            current->info.returnRentVideo(title);
        }
        current = current->link;
	}
	
}
void customerListType::individual_info(int acc)
{
	nodeType<personType>* current;
    current = first;
	while(current != NULL)
	{
		if(current->info.getID()==acc)
		{
            cout<<current->info<<endl;
        }
        current = current->link;
	}
}
bool customerListType::checkAccount(int acc)
{
    nodeType<personType>* current;
    current = first;
     while(current != NULL)
	{
		if(current->info.getID()==acc)
		   return true;
        current = current->link;
	}
	return false;
}
bool customerListType::checkTitle(int acc, string title)
{
    nodeType<personType>* current;
    current = first;
     while(current != NULL)
	{
		if(current->info.getID()==acc)
		   return(current->info.searchRentedVideo(title, acc));
        current = current->link;
	}
	return false;
}
