#ifndef STACK_H_
#define STACK_H_

class Stack {

private:
	int * stack;
	int size;
	int digit;

public:
	Stack(int m = 5);					/* Default constructor */
	Stack(const Stack & t);				/* Copy constructor */
	~Stack();							/* Destructor */
	Stack & operator=(const Stack & t);	/* Assignment operator */

	void push(int);
	void pop();
	int  top();
	bool isempty();
	void show();
	void resize(int);

};


#endif /* STACK_H_ */
