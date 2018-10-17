//Reilek CAS
/*Retrovised 
  Enhanced 
  Integrated 
  Living 
  Experimental 
  Komputer*/
#pragma once
#include <string>
#include <iostream>
#include <vector>
#include <string>
#include <stack>

using std::string;
using std::vector; // make into a dynamic array
//Infix.h will hold both the infix calculator and the IToP algorithm
//I've created this class to only be accessed by RPN.h
class IToP
{
private:
	std::stack<string> stk; //instance of the Stack to help with converting infix to postfix
	bool isOperator(string c); // determines if token is an operator or not
	int prec(string x); // returns the precedence of an operator, the higher the number, the higher the precedence
	string doPrec(string token, string postfix); //returns token with modified precedence determined by prec
	void resize(string &std); // handles excess space in string
    string pop_peek_ITOPn()
    {
        string s = this->stk.top();
        this->stk.pop();
        return s;
    }
	
protected:
	string varX = "NULL";
    string varY = "NULL";
	string itop(string MathExpression); // main algorithm, utilizes all other functions to convert infix to postfix
	vector<string> split(string str); // splits string into tokens to be anlyzed by algorithm
	bool isOperand(string s); // determines if token is an operand
public:
	
};
