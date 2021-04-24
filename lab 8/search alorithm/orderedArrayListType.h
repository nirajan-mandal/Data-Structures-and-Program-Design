#ifndef H_OrderedListType
#define H_OrderedListType

#include <iostream>
#include "arrayListType.h"

using namespace std;

template<class elemType>
class orderedArrayListType: public arrayListType<int>
{
public:
	void insertOrd(const elemType&);
	
	void binarySearch(const elemType& item);
	void binSeqSearch(const elemType& item);

	orderedArrayListType(int size = 100);
};

template<class elemType>
void orderedArrayListType<elemType>::insertOrd(const elemType& item)
{
	int first = 0;
	int last = length - 1;
	int mid;

	bool found = false;

	if(length == 0)   //list is empty
    {
        list[0] = item;
        length++;
    }
	else
		if(length == maxSize)
			cerr<<"Cannot insert into a full list."<<endl;
		else
		{
			while(first <= last && !found)
			{
				mid = (first + last) / 2;

				if(list[mid] == item)
					found = true;
				else
					if(list[mid] > item)
						last = mid - 1;
					else
						first = mid + 1;
			}//end while

			if(found)
	   			cerr<<"The insert item is already in the list. "
					<<"Duplicates are not allowed.";
			else
			{
				if(list[mid] < item)
					mid++;

				insertAt(mid, item);
			}
		}
}//end insertOrd

template<class elemType> 
void orderedArrayListType<elemType>::binarySearch(const elemType& item)
{
	int first = 0;
	int last = length - 1;
	int mid, count=0;

	bool found = false;

	while(first <= last && !found)
	{
        count++;        
		mid = (first + last) / 2;

		if(list[mid] == item)
		   found = true;
		else
		   if(list[mid] > item)
			last = mid - 1;
		   else
			first = mid + 1;
	}

	if(found) 
   	   cout<<"BinSearch    : "<<item<<" found at location "<<mid<<". Steps = "<<count<<endl;
	else
	   cout<<"BinSearch    : "<<item<<" could not be found. Steps = "<<count<<endl;;
}//end binarySearch
template<class elemType> 
void orderedArrayListType<elemType>::binSeqSearch(const elemType& item)
{
	int first = 0;
	int last = length - 1;
	int mid, count=0;

	bool found = false;

	while(first <= last && !found)
	{
        count++;        
	  if((last-first+1)<15)
	  {
           while(first <= last && !found)
           {
             if(list[first] == item)
	         {
		        found = true;
		        mid=first;
		      }
	          first++;
	          count++;
             }                      
         }
       else
       {                      
        mid = (first + last) / 2;

		if(list[mid] == item)
		   found = true;
		else
		   if(list[mid] > item)
			last = mid - 1;
		   else
			first = mid + 1;
       }	
	}

	if(found) 
   	   cout<<"BinSeqSearch : "<<item<<" found at location "<<mid<<". Steps = "<<count<<endl;
	else
	   cout<<"BinSeqSearch : "<<item<<" could not be found. Steps = "<<count<<endl;;
}//end binarySearch


template<class elemType>
orderedArrayListType<elemType>::orderedArrayListType(int size)
   : arrayListType<elemType>(size)
{
}

#endif
