#include <iostream>
#include <string.h>
using std::cout;
using std::endl;
using std::cin;
using std::string;
class Singleton
{
private:
	static Singleton * _sl;
	string _name;
	int _age;
	Singleton(string name,int age)
		:_name(name)
		,_age(age)
		{}
public:
	static Singleton * _GetSingleton()
	{
		if(nullptr == _sl)
			_sl = new Singleton("Lucky",2);
		return _sl;
	}
	static void destory()
	{
		delete _sl;
	}
	~Singleton(){}
	void set(string name)
	{
		_name = name;
	}
	void set(int age)
	{
		_age = age;
	}
	void set(string name,int age)
	{
		_name = name;
		_age = age;
	}
	void print()
	{
		cout << "name:" << _name << endl
			<< "age: " << _age << endl;
	}
};
Singleton* Singleton::_sl = nullptr;

int main()
{
	Singleton* sl = Singleton::_GetSingleton();
	sl->set("Bubbd");
	sl->print();
	sl->set(5);
	sl->print();
	sl->set("Tom",3);
	sl->print();

	printf("sl = %p\n",sl);
	Singleton *s2 = Singleton::_GetSingleton();
	printf("s2 = %p\n",s2);
	Singleton::destory();
	return 0;
}
