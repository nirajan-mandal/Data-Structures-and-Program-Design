#ifndef postfix_H
#define postfix_H
#include <iostream>
using namespace std;
class postfix
{
    public:   
      void getInfix(string s);
      //function to store the infix expression
      //precondition: takes a string 
      //postcondition: stores it in infix, private variable              
      void showInfix();
      //function to display the infix expression
      //precondition: takes no argument
      //postcondition: displays the value of infix, private variable
      void showPostfix();
      //function to display the postfix expression
      //precondition:takes no arguement
      //postcondition: displays the value of pofix, private variabble
      void convertToPostfix();
      //function to canvert infix to postfix expression
      //precondition: takes no arguement
      //postcondition: converts infix and strores it into pofix
      bool precedence(char op1, char op2);
      //function to check the precedence of two operator
      //precondition: takes two characters
      //postcondition: returns true or false accordingly
    private:
      string pofix, infix;     //variables to store the expressions
};              
#endif
