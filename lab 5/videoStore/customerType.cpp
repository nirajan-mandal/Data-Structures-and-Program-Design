#include <iostream>
#include <string>
#include "customerType.h"

using namespace std;

void customerType::setCustomerInfo(int id, string fname, string lname, int v, string rented_na)
{
       ID=id;
       firstName=fname;
       lastName=lname;
       rented_num=v;
       rented_name[0]=rented_na;
       
}       
                          

