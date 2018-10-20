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
	this->RPN_expression = itop(this->expression);
    return RPN_expression;
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
    this->convert();
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
double RPN::operate(double x)
{
    stringstream ss;
    ss << x;
    ss >> this->varX;
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
    string rpn = RPN_expression;
    
	vector<string> tokens = split(rpn);
	for (string token : tokens)
	{
		if (isOperand(token)) //if number, push into stack
			this->stk.push(stod(token));

		else //if operator, pop, do operation
			doOperation(token);
	}
	//one number left, final answer
	return pop_peek();
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
double RPN::g(double top)
{
    stringstream ss;
    ss << top;
    ss >> this->varY;
    return this->operate();
}
//integ[a,b f(x)dx| = (b-a)/2n [[f(a) + 2{sum[n-1,i=1 f(a+ih)} + f(b)]]
double RPN::DefIntegrate(double left, double right)
{
	if (left == right)
		return 0;      //if there is no distance between left and right, there is no area
	else
	{
        int iteration = 10000; //default iteration
		deltaX(right, left, iteration);//gets delta_x (b-a)/n
        double area_prime = f(left) + f(right); //gets y_0
        double area = 0;
		for (int i = 0; i < iteration; i++)
        {   
		    area += f((left + i)*dX); //starts with y_0 (area) and y_n+1 (f(x)), iterates through to get next y_n
		}
        return (dX / 2)*(area_prime + (2 * area));
		//return (dX/2)*area;//area is equal to the sum * dx/2 (b-a/2n). First area holds sum, new area is returned
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
	this->stk.size() >= 2 ? this->stk.push(pop_peek() + pop_peek()) : exit(-1);
}
void RPN::sub()
{
	if (this->stk.size() >= 2)
	{
		this->d = pop_peek();
		this->stk.push(pop_peek() - d);
	}
	else
	{
		cout << "Too many operators" << endl;
		exit(-1);
	}
}
void RPN::mult()
{
	this->stk.size() >= 2 ? this->stk.push(pop_peek() * pop_peek()) : exit(-1);
}
void RPN::div()
{
	if (this->stk.size() >= 2)
	{
		this->d = pop_peek();
		this->stk.push(pop_peek() / d);
	}
	else
	{
		cout << "Too many operators" << endl;
		exit(-1);
	}
}
void RPN::power()
{

	if (this->stk.size() >= 2)
	{
		this->d = pop_peek();
		this->stk.push(std::pow(pop_peek(), d));
	}
	else
	{
		cout << "Too many operators" << endl;
		exit(-1);
	}
}
void RPN::root()
{
	if (this->stk.size() >= 2)
	{
		this->d = pop_peek();
		this->stk.push(std::pow(d, 1/pop_peek()));
	}
	else
	{
		cout << "Too many operators" << endl;
		exit(-1);
	}
}
void RPN::mod()
{
	if (this->stk.size() >= 2)
	{
		this->d = pop_peek();
		this->stk.push(std::fmod(pop_peek(), d));
	}
	else
	{
		cout << "Too many operators" << endl;
		exit(-1);
	}
}
void RPN::sine()
{
	this->stk.size() >= 1 ? this->stk.push(std::sin(pop_peek())) : exit(-1);
}
void RPN::cosine()
{
	this->stk.size() >= 1 ? this->stk.push(std::cos(pop_peek())) : exit(-1);
}
void RPN::tangent()
{
	this->stk.size() >= 1 ? this->stk.push(std::tan(pop_peek())) : exit(-1);
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
		int j = static_cast<int>(this->f(i));
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