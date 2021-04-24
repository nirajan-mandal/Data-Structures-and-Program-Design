#ifndef H_customerListType
#define H_customerListType

#include <iostream>
#include <string>
#include "linkedList.h"
#include "person.h"
using namespace std;

class customerListType: public linkedListType<personType>
{
       
      public:
             void customerPrintName();
                  //fucntion to print out customers name
             void customerID();
                  //function to print customer account number with name
             void addVideo(int, string);
                  //function to update the node data after a video is checked out
             void returnVideo(int, string);
                  //function to update the node data after a video is returned
             void individual_info(int acc);
                  //function to get information of an individual customer
             bool checkAccount(int);
                  //function to check the input account number 
             bool checkTitle(int, string);  
                 //function to check if  a customer has checked an video or not       
      
};              
#endif
