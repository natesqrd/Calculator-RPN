/*
Assignment Author: Nathaniel Tucker
Student ID: 0398463
Due Date: Sept 3 2018
Assignment: CSIS_ASSIGNMENT_3
Description: RPN Calculator using Stacks
*/
#include "IToP.h"
#include <string>
#include <sstream>
#include <vector>
#include <iostream>
#include "Stack.h"

using namespace std;

/*
Function: resize
Author:	GeeksforGeeks
Description: Taken from GeeksforGeeks site, removes excess spaces from string
Inputs: address of string
*/
void IToP::resize(string &str)
{
	int n = str.length();
	int i = 0, j = -1;
	bool spaceFound = false;
	while (++j < n && str[j] == ' ');
	while (j < n)
	{
		if (str[j] != ' ')
		{
			if ((str[j] == '.' || str[j] == ',' ||
				str[j] == '?') && i - 1 >= 0 && str[i - 1] == ' ')
				str[i - 1] = str[j++];
			else
				str[i++] = str[j++];
			spaceFound = false;
		}
		else if (str[j++] == ' ')
		{
			if (!spaceFound) 
			{
				str[i++] = ' ';
				spaceFound = true;
			}
		}
	}
	if (i <= 1)
		str.erase(str.begin() + i, str.end());
	else
		str.erase(str.begin() + i - 1, str.end());
}

/*
Function: split
Author: Nathaniel Tucker
Description: splits string into tokens that are placed in a vector
Inputs: string(the main equation)
Outputs: vector that holds eah part of the equation as tokens;
*/
vector<string> IToP::split(string str)
{
	vector<string> token;
	string substr;
	istringstream SSstr(str);
	while (getline(SSstr, substr, ' '))
	{
		token.push_back(substr);
	}
	return token;
}

/*
Function: isOperator
Translated and Modified: Nathaniel Tucker
Author: C# Code in Assignment
Description: checks if token is equal to an operator
Inputs: string token to be check
Outputs: if token is an operator; returns true; else returns false
*/
bool IToP::isOperator(string c)
{
	//this returns true IF c is equal to an operator
	return c == "+" || c == "-" || c == "/"
		|| c == "*" || c == "%" || c == "^" || c == "root"
		|| c == "(" || c == ")" || c == "sin" 
		|| c == "cos" || c == "tan";
}

/*
Function: isOperand
Translated: Nathaniel Tucker
Description: checks if token is an operand (a number or variable)
Inputs: string token
Outputs: true if operand, false if operator
*/
bool IToP::isOperand(string s)
{
	if (!isOperator(s) && s != ")" && s != "(")
		return true;
	else
		return false;
}

/*
Function: itop Main Algorithm
Translated and Modified: Nathaniel Tucker
Description: converts infix to RPN
Inputs: string expression (the equation)
Outputs: string as postfix
*/
string IToP::itop(string expression)
{
	string postfix;
	string tmp = expression + ' ';
	resize(tmp);
	vector <string> Tokens = split(tmp);
	stringstream ss;
	for (string token : Tokens)
	{
		if (isOperand(token))
		{
			if (token == "x")
			{
				if (varX != "NULL")
					postfix += varX + " ";
				else
					postfix += token + " ";
			}
			else
				postfix += token + " ";
		}
		else if (token == "(")
			stk.push(token);
		else if (token == ")")
		{
			string topToken = stk.pop();
			while (topToken != "(")
			{
				postfix += topToken + " ";
				topToken = stk.pop();
			}
		}
		else
		{
			while (stk.size() > 0 && prec(stk.peek()) >= prec(token))
				postfix += stk.pop() + " ";
			stk.push(token);
		}
	}
	while (stk.size() > 0)
		postfix += stk.pop() + " ";
	return postfix;
}

/*
Function: doPrec
Translated from C# file: Nathaniel Tucker
Description: organized tokens into postfix in order
Inputs: tokens, postfix
Outputs: postfix
*/
string IToP::doPrec(string token, string postfix)
{
	if (prec(token) > prec(stk.peek()))
		stk.push(token);
	else if (prec(token) == prec(stk.peek()))
	{
		postfix += stk.pop() + " ";
		stk.push(token);
	}
	else if (prec(token) < prec(stk.peek()))
		postfix += stk.pop() + " ";

	return postfix;
}

/*
Function: prec
Translated and Modified from C# file: Nathaniel Tucker
Description: checks operator token for precedence
Inputs: string token
Outputs: precenece as int
*/
int IToP::prec(string x)
{
	if (x == "+" || x == "-")
		return 1;
	if (x == "*" || x == "/" || x == "%")
		return 2;
	if (x == "^" || x == "root")
		return 3;
	if (x == "sin"|| x == "cos" || x == "tan")
		return 4;
	return 0; 
}