/*
Assignment Author: Nathaniel Tucker
Student ID: 0398463
Due Date: Sept 3 2018
Assignment: CSIS_ASSIGNMENT_3
Description: RPN Calculator using Stacks
*/
#include <iostream>
#include "RPN.h"
/*
	1.	DblyLL ----->> Queue   (Base Structure DLL --> Stack and Queue)
		\
		 \
		  \
		   V
	2.	  Stack   4. main      (Stack accessed by IToP and RPN) , (main accesses RPN)
		  \     \     ^
		   \     \    | 
		    \     \   |
	3.		IToP ->> RPN       (IToP private class accessed by RPN)
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
	RPN num1("tan ( cos ( sin ( x root 81 ) ) ) + 12");
	cout << num1.convert() << endl;
	cout << num1.operate() << endl;

    return 0;
}

