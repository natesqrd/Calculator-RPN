/*
Assignment Author: Nathaniel Tucker
Student ID: 0398463
Due Date: Sept 3 2018
Assignment: CSIS_ASSIGNMENT_3
Description: RPN Calculator using Stacks
*/
#pragma once
#include <string>
#include <iostream>
#include <vector>
#include <string>
#include "Stack.h"

using std::string;
using std::vector;
//Infix.h will hold both the infix calculator and the IToP algorithm
//I've created this class to only be accessed by RPN.h
class IToP
{
private:
	Stack<string> stk; //instance of the Stack to help with converting infix to postfix
	bool isOperator(string c); // determines if token is an operator or not
	int prec(string x); // returns the precedence of an operator, the higher the number, the higher the precedence
	string doPrec(string token, string postfix); //returns token with modified precedence determined by prec
	void resize(string &std); // handles excess space in string
	
protected:
	string itop(string MathExpression); // main algorithm, utilizes all other functions to convert infix to postfix
	vector<string> split(string str); // splits string into tokens to be anlyzed by algorithm
	bool isOperand(string s); // determines if token is an operand
	
};
