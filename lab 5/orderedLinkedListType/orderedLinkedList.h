#ifndef H_orderedLinkedListType
#define H_orderedLinkedListType

#include <iostream>
#include <cassert>



using namespace std;

template <class Type>
struct nodeType
{
	Type info;
	nodeType<Type> *link;
};

template<class Type>
class orderedLinkedListType
{
	friend ostream& operator<<  (ostream& osObject, const orderedLinkedListType<Type>& list)
	{
		nodeType<Type> *current; //pointer to traverse the list

	    current = list.first;   //set current so that it points to 
					   //the first node
	       while(current != NULL) //while more data to print
	       {
	       osObject<<current->info<<" ";
	       current = current->link;
	       }

	 return osObject;
    }
public:
   void mergeList(orderedLinkedListType<Type> &list1, orderedLinkedListType<Type> &list2);  
        //function to merge two ordered list
        //precondtion: takes two lists
        //postcondion: copies data of the two lists into the new ordered list
                       //destroys the old lists
   void destroyList();
 		//Function to delete all the nodes from the list.
  		//Postcondition: first = NULL, last = NULL, 
		//               count = 0    
   bool search(const Type& searchItem);
     //Function to determine whether searchItem is in the list.
     //Postcondition: Returns true if searchItem is found in
     //               the list; otherwise, it returns false

   void insertNode(const Type& newItem);
     //Function to insert newItem in the list.
     //Postcondition: first points to the new list and newItem is 
     //               inserted at the proper place in the list.

   void deleteNode(const Type& deleteItem);
     //Function to delete deleteItem from the list.
     //Postcondition: If found, the node containing deleteItem
     //               is deleted from the list; first points 
     //               to the first node of the new list.
     //               If deleteItem is not in the list, an 
     //               appropriate message is printed.
     orderedLinkedListType();
       //default constructor
 		//Initializes the list to an empty state.
 		//Postcondition: first = NULL, last = NULL, 
		//               count = 0 
	 //~orderedLinkedListType(); 
        //destructor
   		//Deletes all the nodes from the list.
    	//Postcondition: The list object is destroyed. 	
protected:
    int count;		//variable to store the number of 
 					//elements in the list
    nodeType<Type> *first; //pointer to the first node of 
                           //the list
    nodeType<Type> *last;  //pointer to the last node of 
                           //the list 
};

template<class Type>
orderedLinkedListType<Type>::orderedLinkedListType() // default constructor
{
	first = NULL;
	last = NULL;
	count = 0;
}

template<class Type>
bool orderedLinkedListType<Type>::search(const Type& searchItem)
{
    bool found;
    nodeType<Type> *current; //pointer to traverse the list
	
    found = false;    //initialize found to false
    current = first;  //start the search at the first node

    while(current != NULL && !found)
       if(current->info >= searchItem)
          found = true;
       else
          current = current->link;

      if(found)       
         found = (current->info == searchItem); //test for equality

    return found;
}//end search


template<class Type>
void orderedLinkedListType<Type>::insertNode(const Type& newItem)
{
	nodeType<Type> *current; //pointer to traverse the list
	nodeType<Type> *trailCurrent; //pointer just before current
	nodeType<Type> *newNode;  //pointer to create a node

	bool  found;

	newNode = new nodeType<Type>; //create the node
 	assert(newNode != NULL);

	newNode->info = newItem;   //store newitem in the node
	newNode->link = NULL;      //set the link field of the node 
	                           //to NULL

	if(first == NULL)  //Case 1	
	{	
	   first = newNode;
	   count++;
 	}
	else
	{
	   current = first;
	   found = false;

	   while(current != NULL && !found) //search the list
			if(current->info >= newItem)
				found = true;
     		else
			{
				trailCurrent = current;
				current = current->link;
			}
		  
	   if(current == first)  	//Case 2
	   {
			newNode->link = first;
			first = newNode;
 			count++;
	   }
	   else				//Case 3
	   {
			trailCurrent->link = newNode;
			newNode->link = current;
 			count++;
	   }
	}//end else
}//end insertNode

template<class Type>
void orderedLinkedListType<Type>::deleteNode
                                    (const Type& deleteItem)
{
	nodeType<Type> *current; //pointer to traverse the list
	nodeType<Type> *trailCurrent; //pointer just before current
	bool found;

	if(first == NULL) //Case 1
		cerr<<"Cannot delete from an empty list."<<endl;
	else
	{
		current = first;
		found = false;

		while(current != NULL && !found)  //search the list
			if(current->info >= deleteItem)
				found = true;
			else
			{
				trailCurrent = current;
				current = current->link;
			}
		
		if(current == NULL)   //Case 4
			cout<<"The item to be deleted is not in the list."
			    <<endl;
		else
 			if(current->info == deleteItem) //item to be deleted  
											//is in the list
			{
  				if(first == current) 		//Case 2
				{
					first = first->link;

					delete current;
				}
				else     				//Case 3
				{
					trailCurrent->link = current->link;
					delete current;
				}
 				count--;
			}
			else  					//Case 4
				cout<<"The item to be deleted is not in the list."
				    <<endl;
	}
} //end deleteNode
template<class Type>
void orderedLinkedListType<Type>::destroyList()
{
	nodeType<Type> *temp;   //pointer to deallocate the memory 
							//occupied by the node
	while(first != NULL)    //while there are nodes in the list
	{
	   temp = first;        //set temp to the current node
	   first = first->link; //advance first to the next node
	   delete temp;         //deallocate memory occupied by temp
	}

	last = NULL;	//initialize last to NULL; first has already
                   //been set to NULL by the while loop
 	count = 0;
}

template<class Type>
void orderedLinkedListType<Type>::mergeList(orderedLinkedListType<Type> &list1, orderedLinkedListType<Type> &list2) 
{
     nodeType<Type> *p=list1.first; //pointer to traverse the list
     for(int i=1; i<=list1.count; i++)   //loop to copy the item from the first list    
     { 
        insertNode(p->info);             //info copied to the new list
        p=p->link;
        }
     list1.destroyList();   //function to destroy the fist list
     p=list2.first;
     for(int i=1; i<=list2.count; i++)   //loop to copy the item from the second lsit    
     { 
        insertNode(p->info);             //info copied to the new list
        p=p->link; 
         }
      list2.destroyList();     //function to destroy the fist list
}
     
#endif
