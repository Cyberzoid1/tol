/* stack.h
 * CS383 Group 4
 * Created October 22, 2016
 * 
 * Definition of a stack Class
 */
 
#ifndef STACK_H
#define STACK_H

#include "list.h"

class Stack {

public:
	Stack();	// Constructor
	~Stack();	// Destructor

	void Push( int n );	// Push onto the stack
	int Pop();		// Pop off the stack
	int IsEmpty();		// Is the Stack empty
	void Print();		// Print the Stack

private:
	nodeptr top_ofStack;	// Top

};

#endif

