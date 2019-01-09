#include <iostream>
using std::cout;
using std::endl;
using std::cin;
class Node
{
public:
	int data;
	Node* pre;
	Node* next;
	Node(int n,Node* ipre,Node* inext)
	{
		data = n;
		pre = ipre;
		next = inext;
	}
	~Node() = default;
};
class List
{
public:
	List()
	{
		size = 0;
		tail = new Node(0,nullptr,nullptr);
		head = tail;
	}
	~List() = default;
	void push_back(int);
	void push_front(int);
	void pop_back();
	void pop_front();
	void insert(Node*,int);
	void erase(Node*);
	void display();
private:
	Node* head;
	Node* tail;
	int size;
};
void List::push_back(int n)
{
	Node* node = new Node(n,nullptr,nullptr);
	if(size == 0)
	{
		head = node;
		tail = node;
	}
	else
	{	
		node -> pre = tail;
		tail -> next = node;
		tail = node;
	}
	++size;
}
void List::push_front(int n)
{
	Node* node = new Node(n,nullptr,nullptr);
	if(size == 0)
	{
		head = node;
		tail = node;
	}
	else
	{
		node ->next = head;
		head->pre = node;
		head = node;
	}
	++size;
}
void List::pop_back()
{
	if(size)
	{
		tail = tail -> pre;
		delete tail->next;
		tail -> next = nullptr;
		--size;
	}
	else
	{
		cout << "The List is empty! " << endl;	
	}
}
void List::pop_front()
{
	if(size)
	{
		head = head -> next;
		delete head -> pre;
		head -> pre = nullptr;
		--size;
	}
	else
	{
		cout << "The List is empty!" << endl;
	}
}
void List::insert(Node* node,int n)
{
	Node* temp = head;
	while(temp!=tail)
	{
		if(temp -> data == n)
			break;
		else
			temp = temp -> next;
	}
	if(temp -> pre)
	{
		if(temp == tail && temp->data != n)
		{
			cout << "Can not found the palce to insert!" << endl;
		}
		else
		{
			node -> next = temp;
			temp -> pre -> next = node;
			node -> pre = temp -> pre;
			temp ->pre = node;
			++size;
		}
	}
	else
	{
		push_front(node -> data);	
	}

}
void List::erase(Node *node)
{
	Node* temp = head;
	while(temp != tail)
	{
		if(temp -> data == node -> data)
			break;
		else
			temp = temp -> next;
	}

	if(temp == tail && temp->data != node -> data)
	{
		cout << "Can not found the palce to erase!" << endl;
	}
	else if(temp == head)
	{
		pop_front();
	}
	else if(temp == tail)
	{
		pop_back();
	}
	else
	{
		temp -> pre -> next = temp -> next;
		temp -> next -> pre = temp -> pre;
		delete temp;
		--size;
	}
}
void List::display()
{
	Node* temp = head;
	cout << "Queue(size:" << size << "):" << endl;
	while(temp)
	{
		cout << temp -> data << "\t";
		temp = temp -> next;
	}
	cout << endl;
}
int main()
{
	List list;
	cout << "push_back:10" << endl;
	list.push_back(10);
	list.display();
	cout << endl;
	cout << "push_back:12" << endl;
	list.push_back(12);
	list.display();
	cout << endl;
	cout << "push_front:14" << endl;
	list.push_front(14);
	list.display();
	cout << endl;
	cout << "pop_back" << endl;
	list.pop_back();
	list.display();
	cout << endl;
	cout << "pop_front" << endl;
	list.pop_front();
	list.display();
	cout << endl;
	cout << "insert new node 15 before 10" << endl;
	Node* node = new Node(15,nullptr,nullptr);
	list.insert(node,10);
	list.display();
	cout << endl;
	cout << "erase node 15" << endl;
	list.erase(node);
	list.display();	
	return 0;
}
