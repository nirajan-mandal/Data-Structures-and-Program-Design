#ifndef H_stateData
#define H_stateData

#include <iostream>

using namespace std;

class stateData
{
     public:
             void getStateInfo();
             void setStateInfo(string n, string c, int a, int y, int o);
             string getName();
      private:
              string name, capital;
              int area, year, order;        
};
void stateData::getStateInfo()
{
     cout<<"Name    : "<<name<<endl;
     cout<<"Capital : "<<capital<<endl;
     cout<<"Area    : "<<area<<endl;
     cout<<"Year of admission to Union  : "<<year<<endl;
     cout<<"Order of admission          : "<<order<<endl<<endl;
}

void stateData::setStateInfo(string n, string c, int a, int y, int o)
{
     name=n;
     capital=c;
     area=a;
     year=y;
     order=o;
}  

string stateData::getName()
{
       return name;
}       

#endif
