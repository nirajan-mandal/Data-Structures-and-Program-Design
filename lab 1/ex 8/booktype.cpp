#include <iostream>
#include "bookType.h"
using namespace std;
bookType::bookType()
{
 }
void bookType::setBookInfo(string n_title, string n_ISBN, string n_Publisher, int n_PublishYear, string n_auth[], double n_cost, int n_copies, int n_authorCount)
{
         title=n_title;
         ISBN=n_ISBN;
         Publisher=n_Publisher;
         PublishYear=n_PublishYear;
         for(int i=0; i<4; i++)
            auth[i]=n_auth[i];
         cost=n_cost;
         copies=n_copies;
         authorCount=n_authorCount;
 }   
void bookType::printInfo()       
{
         cout<<"Title        : "<<title<<endl;
         cout<<"ISBN         : "<<ISBN<<endl;
         cout<<"Publisher    : "<<Publisher<<endl;
         cout<<"Publish Year : "<<PublishYear<<endl;
         //cout<<"Auth = "<<auth<<endl;
         for(int i=0; i<4; i++)
               cout<<"Author       : "<<auth[i]<<endl;
                 
         cout<<"Cost         : "<<cost<<endl;
         cout<<"Copies       : "<<copies<<endl;
         cout<<"authorCount  : "<<authorCount<<endl;
 }         
void bookType::printbookTitle()
{
     cout<<title<<endl;
 }
void bookType::printbookTitleAndISBN() 
{
     cout<<title<<endl;
     cout<<ISBN<<endl;
}     
bool bookType::isInStock()                             
{
     if(copies>0)
     return 1;
     else
     return 0;
 }
double bookType::getBookPrice()
{
       return cost;
 }             
void bookType::makeSale()
{
     copies--;
 }
bool bookType::isISBN(string n_ISBN)
{
     if(ISBN==n_ISBN)
       return 1;
     else
       return 0;
 }
        
                    
