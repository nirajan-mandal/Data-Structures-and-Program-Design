using namespace std;
class memberType
{
      public:
             memberType();
             void printMemberID();
                  //function to display the member's ID and name
                  //preconditon:
                  //postcondition: displays the members ID and name
             void setMemberInfo(string ID,string fName,string lName, int bookCount,double amount);
                  //mutator function to store the information of the member
                  //preconditon: takes a variety of private variables
                  //postcondition: assigns variables to the corresponding variables
             void printInfo();
                  //function to display the information of the members
                  //preconditon:
                  //postcondition: displays the information of the member
             int getBooksPurchased();
                  //function to know how many book was purchsed by a member
                  //preconditon:
                  //postcondition:returns a int, the t=number of book purchased
             double getTotalAmountSpent();
                  //function to find the total amount spend by a member
                  //preconditon:
                  //postcondition:returns a double, the total amount spent
             void resetbooksBoughtAndAmount();
                  //function to reset the book count to 0 after the 11th book
                  //preconditon:
                  //postcondition:resets teh book count to 0
             void purchaseBook(double price);
                  //function to add the amount to the total purchased amount
                  //preconditon:takes a double
                  //postcondition:adds the price to the total amount purchased
             bool isMemberID(string n_ID);
                  //function to check if a customer is a member or not
                  //preconditon:takes a string, the ID
                  //postcondition:returns true if the customer is a member
      private:    //private variables to store the information of the members
              string ID;
	          string fName;
           	  string lName;
	          int bookCount;
	          double amount;       
};
