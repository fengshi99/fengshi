#include <iostream>
using std::cout;
using std::endl;
using std::cin;
class Node
{
public:
	int data;
	Node* next;
	Node(int data,Node* node)
		:data(data)
		,next(node)
		{}
	~Node() = default;
};
class Queue
{
private:
	int size;
	Node* tail;
	Node* head;
public:
	Queue(int n)
	{
		tail = new Node(0,nullptr);
		head = tail;
		size = n;
	}
	~Queue() = default;
	void inqueue(int);
	void dequeue();
	int queue_head();
	int queue_tail();
	bool isempty();
	bool isfull();
	void print();
};
void Queue::print()
{
	Node* temp = head->next;
	int flag = 0;
	while(temp)
	{
		cout << temp->data << "\t" ;
		++flag;
		temp = temp->next;
	}
	cout << endl;
	cout << "↑ head";
	while(--flag)
	{
		cout << "\t";
	}
	cout << "↑ tail" << endl;
}
void Queue::inqueue(int n)
{
	if(!isfull())
	{
		Node* node = new Node(n,nullptr);
		tail->next = node;
		tail = node;
		--size;
	}
	else
	{
		cout << "The Queue is full!"<< endl;
	}
}
void Queue::dequeue()
{
	if(!isempty())
	{
		delete head;
		head=head->next;
		++size;
	}
	else
	{
		cout << "The Queue is empty!" << endl; 
	}
}
int Queue::queue_head()
{
	if(!isempty())
	{
		return head->next->data;
	}
	else
	{
		cout << "The Queue is empty!" << endl;
		return -1;
	}
}
int Queue::queue_tail()
{
	if(!isempty())
	{
		return tail->data;
	}
	else
	{
		cout << "The Queue is empty! " << endl;
	}
}
bool Queue::isempty()
{
	return size == 10;
}
bool Queue::isfull()
{
	return size == 0;
}

int main()
{
	Queue queue(10);
	queue.inqueue(10);
	queue.print();
	queue.inqueue(12);
	queue.print();
	queue.inqueue(14);
	queue.print();
	queue.dequeue();
	queue.print();
	cout << "The Queue head element is "<< queue.queue_head() << endl;
	cout << "The Queue tail element is " <<  queue.queue_tail() << endl;
	return 0;
}
