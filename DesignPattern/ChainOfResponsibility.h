#include <string>
#include <iostream>

using namespace std;

class Manager
{
protected:
	Manager* m_manager;
	string m_name;
public:
	Manager(Manager* manager, string name) :m_manager(manager), m_name(name) {  };
	virtual void handleRequest(string requestName, int num) {};
};

class Manager1 : public Manager
{
public:
	Manager1(Manager* manager, string name) :Manager(manager, name) {  }
	void handleRequest(string requestName, int num)
	{
		if (num < 500)
		{
			cout << m_name << "handle request: " << requestName << endl;
		}
		else
		{
			m_manager->handleRequest(requestName, num);
		}
	}
};

class Manager2 : public Manager
{
public:
	Manager2(Manager* manager, string name) :Manager(manager, name) {  }
	void handleRequest(string requestName, int num)
	{
		if (num < 1500)
		{
			cout << m_name << "handle request: " << requestName << endl;
		}
		else
		{
			m_manager->handleRequest(requestName, num);
		}
	}
};

class Boss : public Manager
{
public:
	Boss(Manager* manager, string name) :Manager(manager, name) {  }
	void handleRequest(string requestName, int num)
	{
		cout << m_name << "handle request: " << requestName << endl;
	}
};

