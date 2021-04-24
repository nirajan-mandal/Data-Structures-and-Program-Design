//Nirajan Mandal 02/24/2008
//This program similates a video store program.
//This is a menu driven program.
//Vidoes and customers cannot be added in this program
//the program keeps track of the video data and customers data
//a customer can check out a maximum of 9 videos. 
    //This limit can be changed by changing the size of rented_name[x] in file person.h
    

#include <iostream>
#include <fstream>
#include <string>
#include "videoType.h"
#include "videoLinkedListType.h"
#include "person.h"
#include "customerType.h"
#include "customerListType.h"

using namespace std;

void createVideoList(ifstream& infile, videoListType& videoList);
void displayMenu();
void createCustomList(ifstream& infile, customerListType& customList);

int main()
{
	
    videoListType  videoList;
    customerListType customerList;
	int choice;
	char ch;
	string title;
	int account;

	ifstream infile;

		//open the input file
	infile.open("videoDat.txt");
	if(!infile)
	{
		cerr<<"Input file does not exist"<<endl;
		return 1;
	}
		//create the video list
	createVideoList(infile, videoList);
	infile.close();
	ifstream infile2;
    	infile2.open("custDat.txt");
	if(!infile2)
	{
		cerr<<"Input file does not exist"<<endl;
		return 1;
	}
		//create the customer list
	createCustomList(infile2, customerList);
	infile2.close();
	
	displayMenu();				//show the menu
	cout<<"Enter your choice: ";		
	cin>>choice;				//get the request
	cin.get(ch);
	cout<<endl;

		//process the request
	while(choice != 0)
	{
		switch(choice)
		{
		case 1: cout<<"Enter the title: ";
				getline(cin,title);
				cout<<endl;
				if(videoList.videoSearch(title))
					cout<<"Title found"<<endl;
				else
					cout<<"The store does not carry this title."
					    <<endl;
				break;
		case 2: cout<<"Enter the title: ";
				getline(cin,title);
				cout<<endl;
				if(videoList.videoSearch(title))
				{
					if(videoList.isVideoAvailable(title))
					{
						cout<<"Enter your account # : ";
						cin>>account;
						if(customerList.checkAccount(account))
						   {
                           customerList.addVideo(account, title);
						   videoList.videoCheckOut(title);
                            }
						else
                           cout<<"Invalid account #"<<endl; 
						
					}
					else
						cout<<"The video is currently "
 		     				<<"out of stock."<<endl;
				}
				else
					cout<<"The video is not in the store"
					     <<endl;

				break;
		case 3: cout<<"Enter the title: ";
				getline(cin,title);
				cout<<endl;
				if(videoList.videoSearch(title))
				{
					cout<<"Enter your account # : ";
					cin>>account;
					if(customerList.checkAccount(account))
                    { 
                      if(customerList.checkTitle(account, title))
                         {
                         customerList.returnVideo(account, title);
                         videoList.videoCheckIn(title);
                         }
                       else
                          cout<<"You did not check out "<<title<<endl;  
                      }
                   	else
                       cout<<"Invalid account #"<<endl; 
					
				}
				else
					cout<<"This video is not from our store"
					    <<endl;

				break;
		case 4: cout<<"Enter the title: ";
				getline(cin,title);
				cout<<endl;
				if(videoList.videoSearch(title))
				{
					if(videoList.isVideoAvailable(title))
						cout<<"The video is currently in stock"
						    <<endl;
					else
						cout<<"The video is out of stock"
						    <<endl;
				}
 				else
					cout<<"The video is not in the store"
						<<endl;

				break;
		case 5: videoList.videoPrintTitle();
			    break;
		case 6: cout<<videoList<<endl;
			    break;
		case 7: cout<<"The customers are: "<<endl;
                customerList.customerPrintName();
		        break;
		case 8: customerList.customerID();
                break;  
        case 9: cout<<"Enter account # : ";
				cin>>account;
				if(customerList.checkAccount(account))
	                customerList.individual_info(account);
				else
                      cout<<"Invalid account #"<<endl; 
				break;              
        case 10: cout<<customerList<<endl;
                break;	    
		default: cout<<"Bad Selection"<<endl;
		}//end switch

		displayMenu();				//display the menu
	    cout<<"Enter your choice: ";
	    cin>>choice;				//get the next request
		cin.get(ch);
	    cout<<endl;
	}//end while

	return 0;
	system("PAUSE");
}

void createVideoList(ifstream& infile, videoListType& videoList)
{
	string Title;
	string Star1;
	string Star2;
	string Producer;
	string Director;
	string ProductionCo;
	char   ch;
	int   InStock;

	videoType newVideo;

	getline(infile, Title);
	while(infile)
	{
		getline(infile, Star1);
		getline(infile, Star2);
		getline(infile, Producer);
		getline(infile, Director);
		getline(infile, ProductionCo);
		infile>>InStock;
		infile.get(ch);
		newVideo.setVideoInfo(Title,Star1,Star2,Producer,
			                   Director,ProductionCo,InStock);
		videoList.insertLast(newVideo);

		getline(infile, Title);
	}//end for
}//end createVideoList
void createCustomList(ifstream& infile2, customerListType& customList)
{
	string fname;
	string lname;
	string rented_na;
	int v=0;
	int id;

	customerType newPerson;

	infile2>>fname;
	while(infile2)
	{
		infile2>>lname;
		infile2>>id;
		newPerson.setCustomerInfo(id, fname, lname, v, rented_na);
		customList.insertLast(newPerson);

		infile2>>fname;
	}//end for
}//end createcusotmList

void displayMenu()
{
    cout<<endl;
    cout<<"Select one of the following "<<endl;
    cout<<"1: To check whether a particular video is in stock"
        <<endl;
    cout<<"2: To check out a video"<<endl;
    cout<<"3: To check in a video"<<endl;
    cout<<"4: To check whether a particular video is in "
        <<"the store"<<endl;
    cout<<"5: To print the titles of all the videos"<<endl;
    cout<<"6: To print a list of all the videos"<<endl;
    cout<<"7: To print name of all customers"<<endl;
    cout<<"8: To print customer's account number"<<endl;
    cout<<"9: To print a paticular customer,s information"<<endl;
    cout<<"10: To Print all customers' data"<<endl;
    cout<<"0: To exit"<<endl;
}


