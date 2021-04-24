
#include <fstream>
#include <string>
#include "queueAsArray.h"

using namespace std;


  //**************** customerType  ****************

class customerType
{
public:
    customerType(int customerN = 0, int arrvTime = 0, 
                 int wTime = 0, int tTime = 0);
	  //constructor to initialize the data members 
	  //according to the parameters
	  //In the object declaration if no value is specified, 
	  //the default is assigned.
	  //Postcondition: customerNumber = customerN;
	  //	             arrivalTime = arrvTime;
	  //               waitingTime = wTime;
	  //	             transactionTime = tTime
    void setCustomerInfo(int customerN, int arrvTime, 
				         int wTime, int tTime);
	  //Function to set the data members according 
        //to the parameters.
	  //Postcondition: customerNumber = customerN;
	  //	             arrivalTime = arrvTime;
	  //               waitingTime = wTime;
	  //	             transactionTime = tTime
    int getWaitingTime() const;
	  //Function to return the waiting time of a customer.
	  //Postcondition: The value of waitingTime is returned.
    void setWaitingTime(int time);
	  //Function to set the waiting time of a customer.
	  //Postcondition: waitingTime = time
    void incrementWaitingTime();
	  //Function to increment the waiting time. 
	  //Postcondition: waitingTime++
    int getArrivalTime();
	  //Function to return the arrival time of a customer.
	  //Postcondition: The value of arrivalTime is returned.
    int getTransactionTime();
	  //Function to return the transaction time of a customer.
 	  //Postcondition: The value of transactionTime is returned.
    int getCustomerNumber();
	  //Function to return the customer number.
	  //Postcondition: The value of customerNumber is returned.

private:
    int customerNumber;
    int arrivalTime;
    int waitingTime; 
    int transactionTime;
};


	//*************  serverType  ****************

class serverType
{
public:
    serverType();
        //default constructor
        //Set the values of the data members to their default
        //values.
        //Postcondition: currentCustomer is initialized by its
        //               default constructor; status = "free";
        //               the transaction time is initialized to 0. 
    bool isFree() const;
        //Function to determine whether a server is free.
        //Postcondition: Returns true if the server is free; 
		//               otherwise, returns false.
    void setBusy();
		//Function to set the status of a server to "busy".
		//Postcondition: status = "busy"
    void setFree();
		//Function to set the status of a server to "free".
		//Postcondition: status = "free"
    void setTransactionTime(int t);
		//Function to set the transaction time according 
        //to the parameter t.
		//Postcondition: transactionTime = t
    void setTransactionTime();
		//Function to set the transaction time according 
        //to the transaction time of the current customer.
		//Postcondition: 
        //   transactionTime = currentCustomer.transactionTime
    int getRemainingTransactionTime();
		//Function to return the remaining transaction time.
		//Postcondition: The value of the data member 
        //               transactionTime is returned.
    void decreaseTransactionTime();
		//Function to decrease the transaction time by 1.
		//Postcondition: transactionTime--
    void setCurrentCustomer(customerType cCustomer);
		//Function to set the info of the current customer 
		//according to the parameter cCustomer.
		//Postcondition: currentCustomer = cCustomer
    int getCurrentCustomerNumber();
		//Function to return the customer number of the 
        //current customer.
        //Postcondition: The value of the data member 
        //               customerNumber of the current customer 
        //               is returned.
    int getCurrentCustomerArrivalTime();
		//Function to return the arrival time of the current customer.
		//Postcondition: The value of the data member arrivalTime 
		//               of the current customer is returned.
    int getCurrentCustomerWaitingTime();
		//Function to return the current waiting time of the 
        //current customer.
		//Postcondition: The value of the data member 
        //               waitingTime of the current 
        //               customer is returned.
    int getCurrentCustomerTransactionTime();
		//Function to return the transaction time of the 
        //current customer. 
		//Postcondition: The value of the data member  
		//               transactionTime of the current customer
        //               is returned.

private:
    customerType currentCustomer;
    string status;
    int transactionTime; 
};


class serverListType
{
public:
   serverListType(int num = 1);
		//constructor to initialize a list of servers
		//Postcondition: numOfServers = num
		//   A list of servers, specified by num, is created
		//   If no value is specified for num, its default 
		//   value is assumed
   ~serverListType();
		//destructor
		//Postcondition: The list of servers is destroyed.
   int getFreeServerID();
		//Function to search the list of servers. 
		//Postcondition: If a free server is found, return its ID; 
		//   otherwise, return -1.
   int getNumberOfBusyServers();
		//Function to return the number of busy servers.
		//Postcondition: The number of busy servers is returned.
   void setServerBusy(int serverID, customerType cCustomer,
			          int tTime);
		//Function to set a server to "busy".
		//Postcondition: To serve the customer specified by
		//    cCustomer the server specified by serverID is set 
		//    to busy, and the transaction time is set according 
		//    to the parameter tTime. 
   void setServerBusy(int serverID, customerType cCustomer);
		//Function to set a server to busy.
		//Postcondition: To serve the customer specified by
		//    cCustomer, the server specified by serverID is 
		//    set to "busy", and the transaction time is set
		//    according to the customer’s transaction time.
   void updateServers();
		//Function to update the transaction time of each 	
		//busy server. 
 		//Postcondition: The transaction time of each busy 
		//   server is decremented by one time unit. If the
		//   transaction time of a busy server is reduced to
		//   zero, the server is set to free and a message
		//   indicating which customer was served, together
		//   with the customer's departing time, is printed
		//   on the screen.
   void updateServers(ofstream& outFile);
		//Function to update the transaction time of each 
		//busy server. 
		//Postcondition: The transaction time of each busy 
		//   server is decremented by one time unit. If the
		//   transaction time of a busy server is reduced to
		//   zero, the server is set to free and a message
		//   indicating which customer was served, together
		//   with the customer's departing time, is sent to
		//   a file.

private:
    int numOfServers;
    serverType *servers;
};


//**************** waitQueue  *************

class waitingCustomerQueueType: public queueType<customerType>
{
public:
    waitingCustomerQueueType(int size = 100);
		//constructor
        //Postcondition: The queue is initialized 
 		//   according to the parameter size. The value of
		//   size is passed to the constructor of queueType.
        //   If no value is specified for size, its default
        //   value is assumed
    ~waitingCustomerQueueType();
		//destructor
        //Postcondition: The queue is destroyed
    void updateWaitingQueue();
		//Function to increment the waiting time of each 
		//customer in the queue by one time unit.
        //Postcondition: The waiting time of each customer in
        //   the queue is incremented by one time unit.
};


