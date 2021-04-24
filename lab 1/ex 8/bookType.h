using namespace std;

class bookType
{
      public:
             bookType();
                  //default constructor does nothing      
             void setBookInfo(string n_title, string n_ISBN, string n_Publisher, int n_PublishYear, string n_auth[], double n_cost, int n_copies, int n_authorCount);
                  //mutator function to store the information of the book
                  //preconditon: takes a variety of private variables
                  //postcondition: assigns variables to the corresponding variables
             void printInfo();
                  //function to print the book's information
                  //preconditon: 
                  //postcondition: displays the informationof the books
             void printbookTitle();
                  //function to print the books title only
                  //preconditon:
                  //postcondition: displays the title of the books only            
             void printbookTitleAndISBN();
                  //function to print the title and the ISBN number of the books
                  //preconditon:
                  //postcondition: displays the title and the ISBN numbers of the books
             bool isInStock();
                  //function to check if the book is in stock
                  //preconditon:
                  //postcondition: returns true if the book is available to sell if not returns false
             double getBookPrice();
                   //function to get the price of the book
                  //preconditon:
                  //postcondition: returns the price of the book, a double variable
             void makeSale();
                  //function to sell a book
                  //preconditon:
                  //postcondition: sels the book and meets the requirement of the question
             bool isISBN(string n_ISBN);
                  //check if the seacrched ISNB numbered book is in the store or not
                  //preconditon: takes a string, the ISBN number
                  //postcondition: returns true if the book is found else returns false
      private:    //private variable to store the information of the books
              string title;
	          string ISBN;
	          string Publisher;
	          int PublishYear;
	          string auth[4];
	          double cost;
	          int copies;
	          int authorCount;
};
