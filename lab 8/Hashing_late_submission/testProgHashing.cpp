//This program runs fine.
//The hash table is only used for searching state's name and keeping track of the data base
//The state's info is stored in the class stateData..
//This program could be improved a lot... this is not the best program...
#include <iostream>
#include <fstream>
#include <cassert>
#include <string>
#include "hashT.h"
#include "stateData.h"

using namespace std;
int hashFunc(string name);
int main()
{
	hashT <string> state(101);
	string name, capital, temp1;
	stateData temp[50];
    int area, year, order, h=0, p=0;
    bool found;
    ifstream infile;
    infile.open("Ch9_Ex8_data.txt");   //open the input file
	if(!infile)
	{
		cerr<<"Input file does not exist"<<endl;
		
	}
	getline(infile, temp1);
    while(infile)
	{
         h=hashFunc(temp1);
         //cout<<h<< " " <<name<<endl;
         getline(infile, capital);
         //cout<<capital<<endl;
         infile>>area>>year>>order;
         //cout<<area<<" "<<year<<" "<<order<<endl;
         infile.ignore();
         temp[p].setStateInfo(temp1, capital, area, year, order);
         state.insert(h, temp1);
         //temp[p].getStateInfo();
         //state.print();
         getline(infile, temp1); 
         p++;
     }  
     string input;
     char response, opt;
     do
     {
       cout<<"\nEnter 1 to search state: "<<endl;
       cout<<"Enter 2 to delete state: "<<endl;
       cout<<"Enter 3 to see a state's info: "<<endl;
       cout<<"Enter 4 to see all state's name:"<<endl;
       cout<<"Enter 5 to see all state's info:      ";
       cin>>opt;
       if(opt=='1')
       {
            cout<<"Enter state to search: ";
            cin>>input;
            h=hashFunc(input);
            state.search(h,input,found);
            if(found)
               cout<<input<<"'s info is avilable  "<<endl;
            else
                cout<<input<<" not in database"<<endl; 
          }
        else if(opt=='2')
        {
             cout<<"Enter state to delete: ";
            cin>>input;
            h=hashFunc(input);
            state.remove(h, input);    
          } 
        else if(opt=='3')
        {
             cout<<"Enter state's name: ";
             cin>>input;
             h=hashFunc(input);
             state.search(h,input,found);
             if(found)
             { 
                 cout<<"test"<<endl;
                 for(int i=0; i<50; i++)
                 {
                     if(temp[i].getName()==input) 
                     {       
                             temp[i].getStateInfo(); 
                             break;
                          }     
                   }      
              }
              else
                cout<<input<<" not found in the database"<<endl;       
                        
          } 
        else if(opt=='4')
        {
             state.print();  
          }
         else if(opt=='5')
        {
                cout<<"good"<<endl;
                for(int i=0; i<50; i++)
                {
                        input=temp[i].getName();
                        h=hashFunc(input);
                        state.search(h,input,found);
                        if(found)
                            temp[i].getStateInfo();
                     }
          }  
         else      
         { 
              cout<<"BAD choice...."<<endl;
           }    
         cout<<"Enter 'q' to quit or press any key to continue: ";
         cin>>response;
               
      }while((response !='q')&&(response !='Q'));   
        
	//system("pause");
	//return 0;
}

int hashFunc(string name)
{
    int i, k, sum, len;
    i=0;
    sum= 0;
    len = name.length();
    for(k=0; k<15-len; k++)
       name=name+' ';
    for(k=0; k<5; k++)
    {
        sum=sum+static_cast<int>(name[i])*128*128
        +static_cast<int>(name[i+1])*128*+static_cast<int>(name[i+2]);
        i=i+3;
     }             
     return sum%50;
}     
    
   
