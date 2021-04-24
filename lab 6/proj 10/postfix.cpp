#include <iostream>
#include <stack>

#include "postfix.h"
using namespace std;

void postfix::getInfix(string s)
{
     infix=s;                 //sets infix as s
 }
void postfix::showInfix()
{
     cout<<infix<<endl;       //displays infix
 }
void postfix::showPostfix()
{
     cout<<pofix<<endl;       //displays pofix
 }
void postfix::convertToPostfix()
{
     stack<char> stak;          //stack to store the characters in the expression
     for(int i=0; i<infix.length(); i++)   //loop to convert the expression
     {          
          if(infix[i]=='+' || infix[i]=='-' || infix[i]=='/' || infix[i]=='*')
          {                //if the read character is a operator we have to store it or 
                           //add it to the new expression
               while(!stak.empty() && stak.top()!='(' && precedence(stak.top(), infix[i]))
               {           //if the stack is not empty and if we dont read ( and 
                           //if the precedence of the the operators are equal or higher
                           //we add the character to pofix       
                         pofix+=stak.top();
                         stak.pop();    //remove the top of the stack      
                     }
                 stak.push(infix[i]);   //else we have to store the character
           }
           else if(infix[i]=='(')
              stak.push(infix[i]);  //if we read ( we go ahead and store it
           else if(infix[i]==')')   //if we read )
           {
                while(!stak.empty() && stak.top()!='(')
                {
                     pofix+=stak.top(); //stores all the  item from the stack until we reach (
                     stak.pop();
                   }
                 stak.pop();           //removes '('
              }                          
           else if(infix[i]==';')
              break;             //end of string
           else
             pofix+=infix[i];
        
       }      
     while(!stak.empty())        //loop to store the remaining part of the stack if it is not empty
      {
           pofix+=stak.top();
           stak.pop();
        }
       pofix+=';';                                            
         
 }
bool postfix::precedence(char op1, char op2)
{
                         // *and / are given same preecedence
                         //+and - are given same precedence
                         //(*and /) is given higher precedence than (+ and -)     
  int a, b;
  if(op1=='/')
     a=4;
  if(op1=='*')
     a=4;
  if(op1=='+')
     a=2;
  if(op1=='-')
     a=2;
  if(op2=='/')
     b=4;
  if(op2=='*')
     b=4;
  if(op2=='+')
     b=2;
  if(op2=='-')
     b=2;
   return (a>=b);                  
}
