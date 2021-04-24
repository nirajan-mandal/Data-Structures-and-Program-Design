//Nirajan Mandal 03/25/2008
//This program changes infix expression to postfix expression
#include <iostream>
#include <fstream>
#include "postfix.h"

using namespace std;

int main()
{
   string s;
    ifstream infile;
	infile.open("infix_expression.txt");   //file opened to read the expressions

	if(!infile)
	{
		cerr<<"Cannot open the input file. "
			<<"Program terminates!"<<endl;
		return 1;
	}
    while(!infile.eof())                  //while loop until the end of the file is reached
    {
         postfix  expression;             //class of type postfix
         getline(infile, s);              //gets the first line from the file
         expression.getInfix(s);          //stores teh infix expression
         expression.showInfix();          //displays the infix expression
         expression.convertToPostfix();   //converts the infix expression into postfix expression
         expression.showPostfix();        //displays the postfix expression
         
      }        



system("PAUSE");
return 0;
}
