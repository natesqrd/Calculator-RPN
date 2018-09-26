/*
Assignment Author: Nathaniel Tucker
Student ID: 0398463
Due Date: Sept 3 2018
Assignment: CSIS_ASSIGNMENT_3
Description: RPN Calculator using Stacks
*/
#pragma once
#define _USE_MATH_DEFINES
#include "IToP.h"
#include "Stack.h"
#include <string>
#include <vector>
#include <cmath>
#include <iostream>
#include <sstream>

using std::string;

class RPN : public IToP
{
private:
	double dX;
	string expression;
	Stack<double> stk;
	void deltaX(double a, double b, int n);
	double d, e;
	char plane[10][10];
	
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
	string getExpression() { return this->expression;  }
	string getX() { return this->varX;  }
	void changeExpression(string); // changes private string to string
	double operate(); // takes private string and performs operation defined in private
	double operate(string); //takes string and performs operation defined in private
	string convert(); // returns the equation as Reverse Polish Notation (RPN)
	double f(double);
	void printEq() { std::cout << this->expression << " = " << this->operate() << " when x = " << this->getX() << std::endl; }
	double DefIntegrate(double high_end, double low_end, int iteration);
	void graph();
	void populate();
};