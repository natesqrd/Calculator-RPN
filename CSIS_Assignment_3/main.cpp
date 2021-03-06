/*
Assignment Author: Nathaniel Tucker
Student ID: 0398463
Due Date: Sept 3 2018
Assignment: CSIS_ASSIGNMENT_3
Description: RPN Calculator using Stacks
*/
/*
1. Approximate the derivative of an arbitrary function at a point (this one's pretty easy).

2. You could program further integral-approximating methods, like the Trapezoidal rule or 
Simpson's method. We haven't covered these yet, but we (probably) will soon.

3. You could try some root-finding methods, like the Bisection Method, Newton's Method, 
or the Secant Method. We haven't talked a whole lot about these in class, but you know 
everything you need to know to learn about it. Once you have a root finding algorithm, 
we can develop it further to turn it into a way to find the square root of any number.

4. You can write a program that solves differential equations using Euler's method 
(we haven't covered it yet, but we will soon).
*/
#define _USE_MATH_DEFINES
#include <iostream>
#include "RPN.h"
/*
	0.	DblyLL ----->> Queue   (Base Structure DLL --> Stack and Queue)
		\
		 \
		  \
		   V
           Stack //from previous integration, testing with built-in stack
           ______________
	1. std::stack   3. main      (std::stack accessed by IToP and RPN) , (main accesses RPN)
		  \     \     ^
		   \     \    | 
		    \     \   |
	2.		IToP ->> RPN       (IToP private class accessed by RPN)
*/
/*
For Stack and Queue I used inheritance to structure them as special methods 
to access the Doubley Linked List. They operate on functions already defined in 
the Linked List.

	          __Stack__               |            __Queue__
push - adds node to end of LinkedList | enqueue - adds node to end of list
    uses addEnd() from DblyLL         |		uses addEnd() from DblyLL        
									  |
pop - returns the value at top of     | dequeue - returns the value at front 
stack and deletes node at end         | of queue and deletes node at front
uses peek() form Stack and delEnd()   | uses peek() form Queue and delFront() 
from DblyLL                           | from DblyLL

peek - returns the value at top of    | peek - returns value at top of queue
stack                                 | uses getHeadData() form DblyLL
uses getTailData() form DblyLL        | 
*/
/*
Key:
	sin cos tan --> sin a | cos a | tan a prec: 4 highest precedence
	^ root      --> a ^ b | a root b	  prec: 3
	* /  %      --> a * b | a / b | a % b prec: 2
	+ -         --> a + b | a - b		  prec: 1 lowest precedence
Place expression as string
RPN ex("2 + 2");
cout << ex.operate() << endl; //prints 4
cout << ex.convert() << endl; // prints 2 2 +
ex.changeExpression(someMath); // changes ex's string to a different string

*/

using namespace std;

int main()
{
	RPN dx("3 + x ^ 2 / 1");
    dx.f(4);
    cout << dx.getExpression() << endl;
    cout << dx.operate() << endl;
	
    return 0;
}

/*
Editing Notes:
create a variable to hold modified varX equation for
edit -math operations- and doOperation() to run faster
...
*/