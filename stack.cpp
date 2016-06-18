#include "stack.h"
#include <iostream>

Stack::Stack( int m )
{
	stack = new int[m];
	size  = m;
	digit = 0;
}

Stack::Stack( const Stack & t )
{
	stack = new int[t.size];
	size = t.size;
	digit = t.digit;

	for (int i = 0; i < digit; i++)
		stack[i] = t.stack[i];
}


Stack & Stack::operator=( const Stack & t )
{
	if (this == &t)
		return *this;

	delete [] stack;

	stack = new int[t.size];

	for (int i = 0; i < digit; i++)
		stack[i] = t.stack[i];

	return *this;
}

Stack::~Stack()
{
	delete [] stack;
}

void Stack::push( int m ) {
	if ( digit == size )
		(*this).resize(size + 5);

	else if ( digit + 5 < size )
		(*this).resize( digit + 2 );

	stack[ digit ] = m;
	digit++;
}


void Stack::pop() {
	if ( stack == NULL || digit == 0 )
			throw "Cannot do this!";
	else
		digit--;
}

int Stack::top()
{
	if ( stack == NULL || digit == 0 )
		throw "Cannot do this!";

	return stack[ digit - 1 ];
}

bool Stack::isempty()
{
	if ( stack == NULL )
	    return true;
	else
	    return false;
}

void Stack::show()
{
	for ( int i = 0; i < digit; i++ )
	   std::cout << stack[i] << " ";
}


void Stack::resize(int a)
{
	int * temp;
	temp = new int[a];
	size = a;

	for ( int i = 0; i < digit; i++ )
	    temp[i] = stack[i];

	delete [] stack;
	stack = temp;
	delete [] temp;
}

