#ifndef H_customerType
#define H_customerType

#include <iostream>
#include <string>
#include "linkedList.h"
#include "person.h"
using namespace std;
class customerType: public personType
{
      public:
             void setCustomerInfo(int id, string fname, string lname, int v, string rented_na);
                //function to set the information of the customer 
     
};    




#endif
