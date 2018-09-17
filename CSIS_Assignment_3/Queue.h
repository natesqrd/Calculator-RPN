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
class Queue : public DblyLinkedList<T>
{
	/*
	Function List:
	void enqueue(T); line 28
	void dequeue(); line 39
	T peek(); line line 56
	*/
public:
	/*
	I made addEnd get called to other function to maintain normal wording for Queue
	Function: enqueue
	Author: Nathaniel Tucker
	Description: adds node to end of node
	Inputs: T element to add to queue
	*/
	void enqueue(T element)
	{ 
		this->addEnd(element);
	}

	/*
	Function: dequeue
	Author: Nathaniel Tucker
	Description: stored peek as <T> value, deletes front node then returns <T>
	Outputs: <T> value from peek
	*/
	T dequeue()
	{
		T val;
		if (this->size() > 0)
		{
			val = this->peek();
			this->delFront();
		}
		return val;
	}

	/*
	Function: peek
	Author: Nathaniel Tucker
	Description: returns data from head node
	Outputs: <T> data
	*/
	T peek()
	{ 
		return this->getHeadData();
	}
};