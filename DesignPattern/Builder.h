#include <string>
#include <iostream>

using namespace std;

class AbstractBuilder
{
protected:
	char *value;
	int count;
	int capacity;
public:
	AbstractBuilder();
	void append(char c);
private:
	void ensureCapacityInternal(int minCapacity);
	void expandCapacity(int minCapacity);
};

class Builder : public AbstractBuilder
{
public:
	Builder(int capacity = 16);
	string getResult();
};

