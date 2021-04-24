#include <iostream>
#include "memberType.h"
using namespace std;
memberType::memberType()
{
 }
void memberType::printMemberID()
{
     cout<<ID<<"\t"<<fName<<" "<<lName<<endl;
 }      
void memberType::setMemberInfo(string n_ID,string n_fName,string n_lName, int n_bookCount,double n_amount)
{
     ID=n_ID;
     fName=n_fName;
     lName=n_lName;
     bookCount=n_bookCount;
     amount=n_amount;
}
void memberType::printInfo()
{
     cout<<"ID               : "<<ID<<endl;
     cout<<"Name             : "<<fName<<" "<<lName<<endl;
     cout<<"#of books bought : "<<bookCount<<endl;
     cout<<"Amount spend     : "<<amount<<endl<<endl;
}
int memberType::getBooksPurchased()
{
    return bookCount;
 }
double memberType::getTotalAmountSpent()      
{
       return amount;
 } 
void memberType::resetbooksBoughtAndAmount()
{
     amount=0;
     bookCount=0;
 }
void memberType::purchaseBook(double price)
{
     amount+=price;
     bookCount+=1;
 }
bool memberType::isMemberID(string n_ID)
{
     if(ID==n_ID)
       return 1;
     else
       return 0;  
 }
        
   
     
