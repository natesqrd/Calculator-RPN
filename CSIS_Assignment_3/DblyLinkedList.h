/*
Assignment Author: Nathaniel Tucker
Student ID: 0398463
Due Date: Sept 3 2018
Assignment: CSIS_ASSIGNMENT_3
Description: RPN Calculator using Stacks
*/
#pragma once
#include <iostream>
/*
Traversing a list

node *p = head;
while(p->next != NULL)
p = p->next;

by setting the pointer to head, we begin at the first node in the list
to traverse we must set p to next. So long as p != NULL the pointer will move until the
last node in the section, which will be set to NULL. This is because there is no gauntee
that each node sits next to eachother in memory.
*/

/*
Struct: Node
Author: Nathaniel Tucker
Description: Structure that DblyLinkedList manipuates to create its structure
Variables: T data (any data type), 
node *next(points to the next node),
node *prev(points to previous node)
*/
template<class T>
struct node
{
	T data;
	node* next;
	node* prev;
};

/*
Class: Doubly Linked List
Author: Nathaniel Tucker
Description: Data Structure that containes functions and data that
manipulates node
Variables: node *head(points to first node in structure)
node *tail(points to last node in structure
int linkSize(holds number of links in structure)
*/
template<class T>
class DblyLinkedList
{
	
private:
	int linkSize = 0;
	node<T> *head;
	node<T> *tail;
public:

	/*
	Function: Constructor DblyLinkedList
	Author: Nathaniel Tucker
	Description: Creates instance of a node, sets it to NULL
	*/
	DblyLinkedList()
	{
		this->head = NULL;
	}

	/*
	Function: Working Constructor DblyLinkedList
	Author: Nathaniel Tucker
	Description: Creates instance of a node and sets the data to element
	Inputs: T element
	*/
	DblyLinkedList(T element)
	{
		this->addEnd(element);
	}

	/*
	Function: addEnd
	Author: Nathaniel Tucker
	Description: Creates instance of node if none has been made
	else a new node is added to the end
	Inputs: T data
	*/
	void addEnd(T data)
	{
		if (head == NULL)
		{
			head = new node<T>;
			head->data = data;
			head->next = NULL;
			head->prev = NULL;
			tail = head;
			this->linkSize++;
		}
		else
		{
			node<T> *p = this->head;

			while (p->next != NULL)
				p = p->next;

			node<T> *n = new node<T>;
			n->data = data;
			n->next = NULL;

			p->next = n;
			n->prev = p;
			tail = n;
			this->linkSize++;
		}
	}

	/*
	Function: addFront
	Author: Nathaniel Tucker
	Description: Look at addEnd description, adds to front instead
	Inputs: T data
	*/
	void addFront(T data)//enqueue
	{
		if (head == NULL)
		{
			head = new node<T>;
			head->data = data;
			head->next = NULL;
			head->prev = NULL;
			tail = head;
			this->linkSize++;
		}
		node<T> *p = this->head;
		while (p->prev != NULL)
			p = p->prev;
		
			node<T> *n = new node<T>;
			n->data = data;
			n->prev = NULL;
			p->prev = n;
			n->next = p;
			p = p->prev;
			this->linkSize++;
	}

	/*
	Function: delEnd
	Author: Nathaniel Tucker
	Description: deletes tail of structure, moves tail pointer to previous node
	Outputs: returns true if deletion is successful, false if not successfull
	*/
	bool delEnd()//pop
	{
		if (this->size() == 0)
			return false;
		if (this->head->next == NULL)
			return delFront();

		node<T> *d = this->tail;
		
		this->tail->prev->next = NULL;
		this->tail = this->tail->prev;

		delete d;

		this->linkSize--;
		return true;
	}

	/*
	Function: delFront
	Author: Nathaniel Tucker
	Description: deletes head, moves head to next node
	Outputs: true if successfull, false if not successful
	*/
	bool delFront() //dequeue
	{
		if (this->size() == 0)
			return false;

		node<T> *d = this->head;
		this->head = this->head->next;

		delete d;

		this->linkSize--;
		return true;
	}

	/*
	Function: size()
	Author: Nathaniel Tucker
	Description: returns size of Linked List
	Outputs: size as int
	*/
	int size() 
	{
		return linkSize;
	}

	/*
	Function: getHeadData
	Author: Nathaniel Tucker
	Description: returns data from head node
	Outputs: head data as <T>
	*/
	T getHeadData() 
	{
		return head->data;
	}

	/*
	Function: getTailData
	Author: Nathaniel Tucker
	Description: returns data from tail node
	Outputs: tail data as <T>
	*/
	T getTailData() 
	{  
		return tail->data;
	}
	
};