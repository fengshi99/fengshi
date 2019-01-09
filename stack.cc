#include <iostream>
#include <stdlib.h>
#include <string.h>
using std::cout;
using std::endl;
using std::cin;

class Stack
{
public:
	Stack()
	{
		Top = 0;
		memset(stack,0,sizeof(stack));
	}
	~Stack() = default;
	void push(int);
	void pop();
	int top();
	bool isempty();
	bool isfull();
	void print();
private:
	int Top;
	int stack[10];
};
void Stack::print()
{
	cout << "Stack: ";
	for(auto&c:stack)
		cout << c << "\t";
	cout << endl;
	if(Top)
	{
		cout << "       ";
		for(int top = Top;top>0;--top)
			cout << "\t";
		cout <<"↑Top";
	}
	else
		cout << "  ↑Top ";
	cout << endl;
}
void Stack::push(int n)
{
	if(!isfull())
		stack[Top++] = n;
	else
		cout << "The Stack is full!" << endl;
}
void Stack:: pop()
{
	if(!isempty())
	{
		stack[Top-1] = 0;
		--Top;
	}
	else
		cout << "The Stack is empty!" << endl;
}
int Stack::top()
{
	if(!isempty())
		return stack[Top-1];
	else
	{
		cout << "The Stack is empty!" << endl;
		return -1;
	}
}
bool Stack::isempty()
{
	return Top == 0;
}
bool Stack::isfull()
{
	return Top == 10;		
}

int main()
{
	Stack s;
	cout << "push:10" << endl;
	s.push(10);
	s.print();
	cout << endl;
	cout << "push:12" << endl;
	s.push(12);
	s.print();
	cout << endl;
	cout << "push:14" << endl;
	s.push(14);
	s.print();
	cout << "The top element of stack is " << s.top() << endl;
	cout << "pop:" << endl;
	s.pop();
	s.print();
	cout << endl;
	cout << "The top element of stack is " << s.top() << endl;
	return 0;
}
