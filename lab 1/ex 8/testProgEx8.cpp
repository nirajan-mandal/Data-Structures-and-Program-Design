//Nirajan Mandal 01/21/2008
//This program simulates a book store
#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include "bookType.h"
#include "memberType.h"

using namespace std;

void getBookData(bookType books[], int& noOfBooks);
     //function to get the books' data from the text file
     //precondition: parameters are a object of type book and and int
     //postcondition: stores the books information in the object of type bookType
void printBookData(bookType books[], int noOfBooks);
     //function to print the list of books available
     //preconditon: parameters are object of type book and int the total number of books
     //postcondition: displays the list of the books on the screen                   
void setMembersData(memberType members[], int& count);
     //function to get the member data from the text file 
     //preconditon: takes a object of type member and an int variable, the total number of members
     //postcondition: stores the members variable in the object of type memberType
void printMembersData(memberType members[], int count);
     //the fucntion prints the list of the members
     //preconditon: takes a object of type memberType and int, the total number of members
     //postcondition: displays the information of the members
void showMenu();
     //the function displays the menu of of the book store
     //preconditon:
     //postcondition: displays a menu

void makeSale(bookType books[], int bookCount,
			  memberType members[], int memberCount);
	 //function to sell a book
     //preconditon: takes a variety of parameter
     //postcondition: decreases the book count by 1 and makes necessary change to the member's info   		  
void searchBookData(bookType books[], int bookCount, string ISBN,
					int& loc);
     //function to search for the book if the customer wants to buy the book
     //preconditon:takes a variety of parameters
     //postcondition: changes the value of the location variabel to 1 else does nothing
void searchMemberData(memberType members[], int memberCount, 
					  string ID, int& loc);
     //function to find if the customer is a memeber of the function or not
     //preconditon:takesa variety of variables
     //postcondition:changes the value of the location variabel to 1 else does nothing				  
					  

int main()
{
	bookType books[1000];    //object of booktype class to store upto 1000 books
	int numberOfBooks = 0;   //variable needed to store the number of books

	memberType storeMembers[500];       //object of type memberType to store 500 memers
	int numberOfMembers = 0;            //variable needed to store the total number of members 

	int choice;
	int i;

	getBookData(books, numberOfBooks);

	setMembersData(storeMembers, numberOfMembers);

	showMenu();
	cin>>choice;

	while(choice != 99)          //loop to do the job accordingly to the choice
	{
		switch(choice)
		{
		case 1: for(i = 0; i <numberOfBooks; i++)
					books[i].printbookTitle();    
				cout<<endl;
				break;
		case 2: for(i = 0; i <numberOfBooks; i++)
					books[i].printbookTitleAndISBN();
				cout<<endl;
				break;
		case 3: for(i = 0; i <numberOfMembers; i++)
					storeMembers[i].printMemberID();
				cout<<endl;
				break;
		case 4: makeSale(books, numberOfBooks,
						 storeMembers, numberOfMembers);
				break;
		case 5: printMembersData(storeMembers, numberOfMembers);
				break;
		case 6: printBookData(books, numberOfBooks);
				break;		
				
		default: cout<<"Bad selection:"<<endl;
		}

		showMenu();
		cin>>choice;
	}
    system("pause");
	return 0;
}


void getBookData(bookType books[], int& noOfBooks)
{
	string title;
	string ISBN;
	string Publisher;
	int PublishYear;
	string auth[4];
	double cost;
	int copies;
	int authorCount;

	int i, j;

	ifstream infile;
	char ch;

	infile.open("bookData.txt");

	if(!infile)
	{
		cout<<"Cannot open Input file"<<endl;
		cout<<"Exit the program"<<endl;
		return;
	}

	infile>>noOfBooks;
	infile.get(ch);

	for(i = 0; i < noOfBooks; i++)
	{
		getline(infile, title);
		getline(infile,ISBN);
		getline(infile,Publisher);
		infile>>PublishYear>>cost>>copies>>authorCount;
		infile.get(ch);

		for(j = 0; j < authorCount; j++)
			getline(infile,auth[j]);

		books[i].setBookInfo(title, ISBN, Publisher, 
						PublishYear, auth, cost, copies, 
						authorCount);
	}
}


void printBookData(bookType books[], int noOfBooks)
{
	int i;

	for(i = 0; i < noOfBooks; i++)
	{
		books[i].printInfo();
		cout<<endl<<"---------------------------------"<<endl;
	}
}


void setMembersData(memberType members[], int& count)
{
	int i;
	
	string ID;
	string fName;
	string lName;
	int bookCount;
	double amount;

	ifstream infile;

	infile.open("memberData.txt");

	infile>>count;

	for(i = 0; i < count; i++)
	{
		infile>>ID>>fName>>lName>>bookCount>>amount;
		members[i].setMemberInfo(ID,fName,lName,bookCount,amount);
	}
}

void printMembersData(memberType members[], int count)
{
	int i;
	
	for(i = 0; i < count; i++)
		members[i].printInfo();
}


void showMenu()
{
	cout<<"Welcome to Rock's Book Store"<<endl;
	cout<<"To make a selection enter the number and press enter"<<endl;
	cout<<"1: Print a list of books"<<endl;
	cout<<"2: Print a list of books and ISBN numbers"<<endl;
	cout<<"3: Print a list of members by ID"<<endl;
	cout<<"4: Purchase a book"<<endl;
	cout<<"5: Print all Member's Data"<<endl;
	cout<<"6: Print all Books' Data"<<endl;
	cout<<"99: Exit the program"<<endl;
}

void makeSale(bookType books[], int bookCount,
			  memberType members[], int memberCount)
{
	string ISBN;
	string ID;

	double amountDue = 0;
	double bookPrice = 0;
	int booksBought;
	double discount = 0;

	int memberLoc;
	int bookLoc;

	cout<<fixed<<showpoint;
	cout<<setprecision(2);

	cout<<"Enter book ISBN: ";
	cin>>ISBN;
	cout<<endl;

	searchBookData(books, bookCount, ISBN, bookLoc);
	if(bookLoc != -1)
	{
		if(books[bookLoc].isInStock())
		{
			bookPrice = books[bookLoc].getBookPrice();
			cout<<"Enter member ID: ";
			cin>>ID;
			cout<<endl;

			char isMember;

			cout<<"Customer member (Y/N): ";
			cin>>isMember;
			cout<<endl;

			if(isMember == 'Y' || isMember == 'y')
			{
				searchMemberData(members, memberCount, ID, memberLoc);
				if(memberLoc != -1)
				{
					booksBought = members[memberLoc].getBooksPurchased();
					if(booksBought >= 10)
					{
						bookPrice = bookPrice * 0.95;
						discount = members[memberLoc].getTotalAmountSpent() / 10;
						amountDue = bookPrice - discount;
						members[memberLoc].resetbooksBoughtAndAmount();
						cout<<"Please pay: $"<<amountDue<<endl;
					}
					else
					{
						members[memberLoc].purchaseBook(bookPrice * 0.95);
						cout<<"Please pay: $"<<bookPrice * 0.95<<endl;
					}
				}
				else
					cout<<"Please pay: $"<<bookPrice<<endl;
			}
			else
				cout<<"Please pay: $"<<bookPrice<<endl;

			books[bookLoc].makeSale();
		}
		else
			cout<<"This book is currently out of stock"<<endl;
	}
	else
		cout<<"Sorry: The store does not carry this book"<<endl;

}


void searchBookData(bookType books[], int bookCount, string ISBN,
					int& loc)
{
	int i;
	loc = -1;

	for(i = 0; i <= bookCount; i++)
		if(books[i].isISBN(ISBN))
		{
			loc = i;
			break;
		}

}

void searchMemberData(memberType members[], int memberCount, 
					  string ID, int& loc)
{
	int i;
	loc = -1;

	for(i = 0; i <= memberCount; i++)
		if(members[i].isMemberID(ID))
		{
			loc = i;
			break;
		}

}
