//Header file QueueAsArray

#ifndef H_QueueAsArray
#define H_QueueAsArray

#include <iostream>
#include <cassert>

using namespace std;

template<class Type>
class queueType
{
public:
    const queueType<Type>& operator=(const queueType<Type>&); 
        // overload the assignment operator
    void initializeQueue();
		//Function to initialize the queue to an empty state
		//Postcondition: count = 0, queueFront = 0;
		//               queueRear = maxQueueSize - 1;
    void destroyQueue();
		//Function to remove all elements from the queue
		//Postcondition: count = 0, queueFront = 0;
		//               queueRear = maxQueueSize - 1;

    bool isEmptyQueue();
		//Function to determine if the queue is empty.
		//Postcondition: returns true if the queue is empty;
		//               otherwise, it returns false.

    bool isFullQueue();
		//Function to determine if the queue is full.
		//Postcondition: returns true if the queue is full;
		//               otherwise, it returns false.

    void addQueue(const Type& queueElement);
		//Function to add queueElement to the stack
		//Precondition: queue exists and is not full
		//Postcondition: queue is changed and the queueElement
   		//               is added to the queue

    Type front();
		//Function to returns the first element of the queue
		//Precondition: queue must exist and is not empty
 		//Postcondition: If queue is empty, program terminates;
 		//               otherwise the first element of the queue
 		//               is returned  
    Type back();
		//Function to returns the last element of the queue
		//Precondition: queue must exist and is not empty
 		//Postcondition: If queue is empty, program terminates;
 		//               otherwise the last element of the queue
		//               is returned
	void deleteQueue();
		//Function  to remove the first element of the queue
		//Precondition: queue exists and is not empty
		//Postcondition: queue is changed and the first element 
		//               is removed from the queue.

    queueType(int queueSize = 100); 
		//constructor
    queueType(const queueType<Type>& otherQueue); 
 		// copy constructor
    ~queueType(); 
 		//destructor

private:
    int maxQueueSize;
    int count;
    int queueFront;
    int queueRear;
    Type *list;  	//pointer to the array that holds 
     			//the queue elements 
};


template<class Type>
void queueType<Type>::initializeQueue()
{
	queueFront = 0;
    queueRear = maxQueueSize - 1;
	count = 0;
}


template<class Type>
void queueType<Type>::destroyQueue()
{
	queueFront = 0;
    queueRear = maxQueueSize - 1;
	count = 0;
}


template<class Type>
bool queueType<Type>::isEmptyQueue()
{
   return(count == 0);
}

template<class Type>
bool queueType<Type>::isFullQueue()
{
   return(count == maxQueueSize);
}


template<class Type>
void queueType<Type>::addQueue(const Type& newElement)
{
   if(!isFullQueue())
   {   
		queueRear = (queueRear + 1) % maxQueueSize; //use mod operator 
						 //to advance queueRear because 
 						 //the array is circular
   		count++;
   		list[queueRear] = newElement;
   }
   else
  		cerr<<"Cannot add to a full queue"<<endl; 
}

template<class Type>
Type queueType<Type>::front()
{
   assert(!isEmptyQueue());
   return list[queueFront]; 
}


template<class Type>
Type queueType<Type>::back()
{
     assert(!isEmptyQueue());
     return list[queueRear];
}


template<class Type>
void queueType<Type>::deleteQueue()
{
   if(!isEmptyQueue())
   {   
		count--;
   		queueFront = (queueFront + 1) % maxQueueSize; //use the mod 
						//operator to advance queueFront 
 						//because the array is circular 
   }
   else
		cerr<<"Cannot remove from an empty queue"<<endl;
}

	//constructor
template<class Type>
queueType<Type>::queueType(int queueSize)   
{
    if(queueSize <= 0)
    {
		cerr<<"Size of the array to hold the queue must "
			<<"be positive."<<endl;
		cerr<<"Creating an array of size 100."<<endl;

		maxQueueSize = 100;
    }
    else
   		maxQueueSize = queueSize;  //set maxQueueSize to queueSize

    queueFront = 0; 	   		   //initialize queueFront
    queueRear = maxQueueSize - 1; 	   //initialize queueRear
    count = 0;
    list = new Type[maxQueueSize];  //create the array to
				            //hold the queue elements
	assert(list != NULL);
}

template<class Type>
queueType<Type>::~queueType()   //destructor
{
   delete [] list;
}

template<class Type>
const queueType<Type>& queueType<Type>::operator=
	                   (const queueType<Type>& otherQueue)
{
	cout<<"Write the definition of the function "
		<<"to overload the assignment operator"<<endl;
}

template<class Type>
queueType<Type>::queueType(const queueType<Type>& otherQueue)
{
	cout<<"Write the definition of the copy constructor"<<endl;
}


#endif
