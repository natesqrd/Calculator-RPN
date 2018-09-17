/*
Assignment Author: Nathaniel Tucker
Student ID: 0398463
Due Date: Sept 3 2018
Assignment: CSIS_ASSIGNMENT_3
Description: RPN Calculator using Stacks
*/
#pragma once
#include "DblyLinkedList.h"

template<class T>
class Stack : public DblyLinkedList<T>
{
public:
	
	/*
	Function: push
	Author: Nathaniel Tucker
	Description: adds node to end of stack/linked list
	Inputs: T element
	*/
	void push(T element)
	{
		this->addEnd(element);
	}

	/*
	Function: pop
	Author: Nathaniel Tucker
	Description: Stores data at top of stack, deletes top of stack, returns that data
	Outputs: data as <T>
	*/
	T pop() 
	{ 
		T var;
		if (this->size() > 0)
		{
			var = this->peek();
			if (!this->delEnd())
				exit(-3);
		}
		return var;
	}

	/*
	Function: peek
	Author: Nathaniel Tucker
	Description: returns data at top of stack
	Outputs: data as <T>
	*/
	T peek() 
	{ 
		return this->getTailData(); 
	}
};