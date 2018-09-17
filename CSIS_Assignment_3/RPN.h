/*
Assignment Author: Nathaniel Tucker
Student ID: 0398463
Due Date: Sept 3 2018
Assignment: CSIS_ASSIGNMENT_3
Description: RPN Calculator using Stacks
*/
#pragma once
#include "IToP.h"
#include "Stack.h"
#include <string>
#include <vector>
#include <cmath>
#include <iostream>

using std::string;

class RPN : public IToP
{
private:
	string expression;
	Stack<double> stk;
	void add(); //pops two numbers and pushes the added value
	void sub(); // pops two numbers and pushes the difference value
	void mult(); // pops two numbers and pushes the product value
	void div(); // pops two numbers and pushes the quotient value
	void power(); // pops two numbers and pushes the exponential value
	void root(); // pops two numbers and pushes the root value
	void mod(); // pops two numbers and pushes the moded value
	void sine(); // pops one number and pushes the sin of 'x'
	void cosine(); //pops one number and pushes the cos of 'x'
	void tangent(); // pops one number and pushes the tan of 'x'
	void doOperation(string); //if token is operator, the token is pushed into the 
	//doOperation function to perform the associated value stated above
public:
	RPN(); // default constructor sets private string to "0"
	RPN(string);// working constructor sets private string to string
	void changeExpression(string); // changes private string to string
	double operate(); // takes private string and performs operation defined in private
	double operate(string); //takes string and performs operation defined in private
	string convert(); // returns the equation as Reverse Polish Notation (RPN)
};