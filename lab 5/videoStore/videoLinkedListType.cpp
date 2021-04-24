#include <iostream>
#include <string>
#include "videoLinkedListType.h"

using namespace std;

bool videoListType::isVideoAvailable(string vTitle) 
{
	bool found;
	nodeType<videoType> *location;

	searchVideoList(vTitle, found, location);

	if(found)
		found = (location->info.getNoOfCopiesInStock() > 0);
	else 
		found = false;

	return found;
}

void videoListType::videoCheckIn(string vTitle)
{
	bool found = false;
	nodeType<videoType> *location;

	searchVideoList(vTitle, found, location);

	if(found)
		location->info.checkIn();
	else
		cout<<"This video is not in the store."<<endl;
}

void videoListType::videoCheckOut(string vTitle)
{
	bool found = false;
	nodeType<videoType> *location;

	searchVideoList(vTitle, found, location);

	if(found)
		location->info.checkOut();
	else
		cout<<"This video is not in the store."<<endl;
}

bool videoListType::videoCheckTitle(string vTitle)
{
	bool found = false;
	nodeType<videoType> *location;

	searchVideoList(vTitle, found, location);

	return found;
}

void videoListType::videoUpdateInStock(string vTitle, int num)
{
	bool found = false;
	nodeType<videoType> *location;

	searchVideoList(vTitle, found, location);

	if(found)
		location->info.updateInStock(num);
	else
		cout<<"This video is not in the store."<<endl;
}

void videoListType::videoSetCopiesInStock(string vTitle, int num)
{
	bool found = false;
	nodeType<videoType> *location;

	searchVideoList(vTitle,found,location);

	if(found)
		location->info.setCopiesInStock(num);
	else
		cout<<"This video is not in the store."<<endl;
}

bool videoListType::videoSearch(string vTitle)
{
	bool found = false;
	nodeType<videoType> *location;

	searchVideoList(vTitle, found, location);

	return found;
}

void videoListType::searchVideoList(string vTitle, bool& found,
                                nodeType<videoType>* &current)
{
    found = false;   //set found to false
   
    if(first == NULL)  //list is empty
       cerr<<"Cannot search an empty list. "<<endl;
    else
    {
       current = first;  //set current point to first 
                         //node in the list.
       found = false;       // set found to false

       while(!found && current != NULL) //search the list
           if(current->info.checkTitle(vTitle)) //the item is 
                                                //found
              found = true;
           else
              current = current->link; //make current point
                                       //to the next node
    } //end else
}


void videoListType::videoPrintTitle()
{
	nodeType<videoType>* current;

	current = first;
	while(current != NULL)
	{
		current->info.printTitle();
		current = current->link;
	}
}
