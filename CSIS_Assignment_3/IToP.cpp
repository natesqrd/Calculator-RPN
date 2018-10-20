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
#include <stack>

using namespace std;

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

vector<string> IToP::split(string str)
{
	vector<string> token;
	string substr;
	istringstream SSstr(str);
	while (getline(SSstr, substr, ' '))
	{
        if (substr == "x" && this->varX != "NULL")
            substr = this->varX;
		token.push_back(substr);
	}
	return token;
}

bool IToP::isOperator(string c)
{
	//this returns true IF c is equal to an operator
	return c == "+" || c == "-" || c == "/"
		|| c == "*" || c == "%" || c == "^" || c == "root"
		|| c == "(" || c == ")" || c == "sin" 
		|| c == "cos" || c == "tan" || c == "sigma";
}

bool IToP::isOperand(string s)
{
	if (!isOperator(s) && s != ")" && s != "(")
		return true;
	else
		return false;
}

int IToP::prec(string x)
{
    if (x == "+" || x == "-")
        return 1;
    if (x == "*" || x == "/" || x == "%")
        return 2;
    if (x == "^" || x == "root")
        return 3;
    if (x == "sin" || x == "cos" || x == "tan")
        return 4;
    return 0;
}

string IToP::itop(string expression)
{
	string postfix;
	string tmp = expression + ' ';
	resize(tmp);
	vector <string> Tokens = split(tmp);
	
	for (string token : Tokens)
	{
        if (isOperand(token))
            postfix += token + " ";
		else if (token == "(")
			this->stk.push(token);
		else if (token == ")")
		{
			string topToken = pop_peek_ITOP();
			while (topToken != "(")
			{
				postfix += topToken + " ";
				topToken = pop_peek_ITOP();
			}
		}
		else
		{
            while (this->stk.size() > 0 && prec(this->stk.top()) >= prec(token))
            {
                postfix += pop_peek_ITOP() + " ";
            }
			this->stk.push(token);
		}
        
	}
    
	while (this->stk.size() > 0)
		postfix += pop_peek_ITOP() + " ";
	return postfix;
}

