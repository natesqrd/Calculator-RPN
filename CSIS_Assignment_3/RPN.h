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
#include <stack>
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
	std::stack<double> stk;
	void deltaX(double a, double b, int n);
	double d, e;
	char plane[10][10];
    double pop_peek()
    {
        double d = this->stk.top();
        this->stk.pop();
        return d;
    }
	
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
    double g(double);
    double F(double x, double y)
    {
        std::stringstream ss, aa;
        ss << x;
        ss >> this->varX;
        aa << y;
        aa >> this->varY;
        return this->operate();
    }
	void printEq() { std::cout << this->expression << " = " << this->operate() << " when x = " << this->getX() << std::endl; }
	double DefIntegrate(double high_end, double low_end);//now using trap equation

	double d_dx(double x, double a) 
    { 
        if (a = x)
            a = 0.00000001;
		return (this->f(x) - this->f(a)) / x - a;
	}
    double NewtonRoot(double point)
    {
        if(point - (this->f(point) / this->d_dx(0, point) == 0))
            return point;
        else
        {
            this->NewtonRoot(point);
            return point;
        }
    }
    void E_method(double iter, double h_end, double x, double y)
    {
        while (x < h_end)
        {
            y += iter * F(x, y);
            y /*y_next*/ = y /*y_curr*/ + iter * F(x, y);
            x += iter;
            std::cout << x << ", " << y << "\n";
        }
    }
    void graph();
	void populate();
};