//Nirajan Mandal 04/02/2008
//This is a simulation program for customers and servers
#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <cmath>

#include "Simulation.h"
#include "queueAsArray.h"

using namespace std;

void setSimulationParameters(int& sTime, int& numOfServers,
							 int& transTime,
							 int& tBetweenCArrival);
//Function to get simulation parameters
//Postcondition: The sumulation parameters are set accordingly							 
bool isCustomerArrived(double arvTimeDiff);
//Function to decide if a customer arrived or not
//Returns true if the probabilty is greater than the random number

void runSimulation();
//Function to simulate the program

int main()
{
	srand((unsigned)time(0)); //seed for the random generator
    runSimulation();
    system("pause");
	return 0;
}

void setSimulationParameters(int& sTime, int& numOfServers,
							 int& transTime,
							 int& tBetweenCArrival)
{
	cout<<"Enter simulation time: "<<flush;
	cin>>sTime;
	cout<<endl;

	cout<<"Enter number of servers: "<<flush;
	cin>>numOfServers;
	cout<<endl;

	cout<<"Enter transaction time: "<<flush;
	cin>>transTime;
	cout<<endl;

	cout<<"Enter time between customer arrivals: "<<flush;
	cin>>tBetweenCArrival;
	cout<<endl;
}



bool isCustomerArrived(double arvTimeDiff)
{
    return ((double)rand()/RAND_MAX) > exp(-1.0/arvTimeDiff);
    //random generate is between 0 and 1; which is compared with the probalilty
}


void runSimulation()
{
    int sTime, numOfServers, transTime, tBetweenCArrival;
	int customer_number=0, clock=0, total=0, avg_waiting_time=0;
    int cust_arrived=0, cust_served=0, cust_wait_queue=0;
    setSimulationParameters(sTime, numOfServers, transTime, tBetweenCArrival);
    serverListType serverList(numOfServers);
    waitingCustomerQueueType custqueue(100);  //max number of person in the queue is set to 100
    customerType cust;
    for(clock=1; clock<=sTime; clock++)  //loop for unit time
    { 
       serverList.updateServers();       //server is updated
       custqueue.updateWaitingQueue();   //the que is updated         
       
       if(isCustomerArrived(tBetweenCArrival)) //checks the arrival of a customer
       {
          if(!custqueue.isFullQueue())         //checks if the queue is full
          {
           cust_arrived++;                     //customer arrived is increased
           cout<<"Customer number "<<cust_arrived<<" arrived at time unit "<<clock<<endl;
           cust.setCustomerInfo(cust_arrived, clock, 0, transTime);  //sets customer's info
           cust_wait_queue++;                 //customer in queue is increased
           custqueue.addQueue(cust);
           
           }
        }
        while(serverList.getFreeServerID()!=-1)  //checks if a server is free
        {
            if(!custqueue.isEmptyQueue())     //checks if the queue is empty
            {
               cust=custqueue.front();        //gets the front customer
               custqueue.deleteQueue();       //updates the queue
               serverList.setServerBusy(serverList.getFreeServerID(), cust, transTime);
                                              //sets server's info                        
               total+=cust.getWaitingTime();  //updates the waiting time
               cust_served++;                 //increased the customer served
               cust_wait_queue--;             //decreases the customer in the queue
             }
             else
              break;
         }
         
            
            
    }          
                 
    cout<<"\n\nSimulation ran for "<<sTime<<" time units"<<endl;
    cout<<"Number of servers: "<<numOfServers<<endl;
    cout<<"Average trasaction time: "<<transTime<<endl;
    cout<<"Average arrival time difference between customers : "<<tBetweenCArrival<<endl;
    cout<<"Total wait time: "<<total<<endl;
    cout<<"Numbers of customres arrived : "<<cust_arrived<<endl;
    cout<<"Numbers of customers who completed a transaction : "<<cust_served-serverList.getNumberOfBusyServers()<<endl;
    cout<<"Numbers of customers left in the servers: "<<serverList.getNumberOfBusyServers()<<endl; //busy servers 
    cout<<"Numbers of customers left in the queue : "<<cust_wait_queue<<endl;
    setprecision(3);
    cout<<"Average wait time: "<<setprecision(2)<<(double)total/(cust_arrived)<<endl;
    cout<<"************END SIMULATION************"<<endl;
    
}

