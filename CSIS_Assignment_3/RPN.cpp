/*
Assignment Author: Nathaniel Tucker
Student ID: 0398463
Due Date: Sept 3 2018
Assignment: CSIS_ASSIGNMENT_3
Description: RPN Calculator using Stacks
*/
#include "RPN.h"
using namespace std;

/*
Function: RPN constructor
Author: Nathaniel Tucker
Description: Creates instance of RPN, sets string to "0"
*/
RPN::RPN()
{
	this->changeExpression("0");
}

/*
Function: RPN working constructor
Author: Nathaneil Tucker
Description: Creates instance of RPN, sets string to expression
Inputs: string
*/
RPN::RPN(string expression)
{
	this->changeExpression(expression);
}

/*
Function: convert
Author: Nathaniel Tucker
Description: converts infix to postfix
Outputs: string postfix
*/
string RPN::convert()
{
	return itop(this->expression);
}

/*
Function: changeExpression
Author: Nathaniel Tucker
Description: changes expression in private data
Inputs: string expression
*/
void RPN::changeExpression(string str)
{
	this->expression = str;
}

/*
Function: operate
Author: Nathaniel Tucker
Description: resets expression then returns operated value
Inputs: string expression to operate on
Outputs: operated value
*/
double RPN::operate(string str)
{
	this->expression = str;
	return this->operate();
}

/*
Function: operate
Author: Nathaniel Tucker
Description: operates string set in private string var
Outputs: operated value
*/
double RPN::operate()
{
	string rpn = itop(this->expression);
	vector<string> tokens = split(rpn);
	for (string token : tokens)
	{
		if (isOperand(token)) //if number, push into stack
			stk.push(stod(token));

		else //if operator, pop, do operation
			doOperation(token);
	}
	//one number left, final answer
	return stk.pop();
}
void RPN::deltaX(double right, double left, int n)
{
	this->dX = (right - left) / n;
}
double RPN::f(double top)
{
	stringstream ss;
	ss << top;
	ss >> this->varX;
	return this->operate();
}
double RPN::DefIntegrate(double left, double right, int iteration)
{
	if (left == right)
		return 0;
	else
	{
		double area = 0.0;
		deltaX(right, left, iteration);
		for (int i = 0; i < iteration; i++)
		{
			area += f(left + (i + 0.5) * dX) * dX;
		}
		return abs(area);
	}
}
/*
Function: add, sub, mult, div ...
Author: Nathaniel
Description: Each function is designed to pop the top two variables
in the stack and perform a specific operation eqaul to the operand
there are no inputs or outputs, only functions to operate on the data in the stack
*/
// -math operations-{ Maybe make this into an operation tree? see if
//using a hash table helps. Make each token equal to the precidence and mod to go straight to function??
void RPN::add()
{
	stk.size() >= 2 ? stk.push(stk.pop() + stk.pop()) : exit(-1);
}
void RPN::sub()
{
	if (stk.size() >= 2)
	{
		this->d = stk.pop();
		stk.push(stk.pop() - d);
	}
	else
	{
		cout << "Too many operators" << endl;
		exit(-1);
	}
}
void RPN::mult()
{
	stk.size() >= 2 ? stk.push(stk.pop() * stk.pop()) : exit(-1);
}
void RPN::div()
{
	if (stk.size() >= 2)
	{
		this->d = stk.pop();
		stk.push(stk.pop() / d);
	}
	else
	{
		cout << "Too many operators" << endl;
		exit(-1);
	}
}
void RPN::power()
{

	if (stk.size() >= 2)
	{
		this->d = stk.pop();
		stk.push(std::pow(stk.pop(), d));
	}
	else
	{
		cout << "Too many operators" << endl;
		exit(-1);
	}
}
void RPN::root()
{
	if (stk.size() >= 2)
	{
		this->d = stk.pop();
		stk.push(std::pow(d, 1/stk.pop()));
	}
	else
	{
		cout << "Too many operators" << endl;
		exit(-1);
	}
}
void RPN::mod()
{
	if (stk.size() >= 2)
	{
		this->d = stk.pop();
		stk.push(std::fmod(stk.pop(), d));
	}
	else
	{
		cout << "Too many operators" << endl;
		exit(-1);
	}
}
void RPN::sine()
{
	stk.size() >= 1 ? stk.push(std::sin(stk.pop())) : exit(-1);
}
void RPN::cosine()
{
	stk.size() >= 1 ? stk.push(std::cos(stk.pop())) : exit(-1);
}
void RPN::tangent()
{
	stk.size() >= 1 ? stk.push(std::tan(stk.pop())) : exit(-1);
}
//}

/*
Function: doOperation
Author: Nathaniel Tucker
Description: this funciton looks at the operand that is passed in by the token and 
performs the operation associated with that token
Inputs: string token
*/
void RPN::doOperation(string token)
{
	if (token == "+")
		add();
	else if (token == "-")
		sub();
	else if (token == "*")
		mult();
	else if (token == "/")
		div();
	else if (token == "%")
		mod();
	else if (token == "^")
		power();
	else if (token == "root")
		root();
	else if (token == "sin")
		sine();
	else if (token == "cos")
		cosine();
	else if (token == "tan")
		tangent();
	else
	{
		cout << "Invalid Operater: Operator Unavailable" << endl;
		exit(-2);
	}
	
}

void RPN::graph()
{
	this->populate();
	for (int i = 0; i < 100; i++)
	{
		int j = this->f(i);
		this->plane[i][j] = '*';
	}
	for (int i = 100; i >= 0; i--)
	{
		for (int j = 100; j >= 0; j--)
			cout << this->plane[i][j];
		cout << endl;
	}
}
void RPN::populate()
{
	for (int i = 0; i <= 100; i++)
	{
		for (int j = 0; j <= 100; j++)
			this->plane[i][j] = '+';
	}
}