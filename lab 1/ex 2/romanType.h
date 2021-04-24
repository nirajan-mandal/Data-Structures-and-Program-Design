using namespace std;
class romanType                     //class definition
{
      public:
             romanType();
                   //default constructor                               
             void setRoman(string s);
                  //mutator function to store the roman numeral
                  //Precondtion: takes a string
                  //postcodition: assigns the string to the private variable                     
             void setDecimal(int x);
                  //mutator function to store the decimal numeral
                  //preconditon: take int 
                  //postcondtion: assigns the int to the private variable
             string getRoman();
                  //accessor function to access the roman numeral
                  //preconditon: 
                  //postcondtion:returns a string variable                 
             int getDecimal();
                  //acccessor function to access the decimal numeral
                  //precondtion:
                  //postcondtion: returns a int variable              
             int makeDecimal(string s);
                  //function to convert from roman to decimal
                  //precondtion: takes a string
                  //postcondtion: returns an integer                  
             void choice(); 
                  //function to give user a choice to diaplay what??
                  //precondition:
                  //postcondtion: gets a character from the user               
      private:
             string roman;        //string to store roman numeral
              int decimal;        //string to store the decimal numeral
};
      
      
