#include "Builder.h"
#include <limits.h>
#include <string.h>

AbstractBuilder::AbstractBuilder()
{
	capacity = 16;
	count = 0;
	value = new char[capacity];
}

void AbstractBuilder::append(char c)
{
	ensureCapacityInternal(count + 2);
	value[count++] = c;
	value[count] = '\0';
}

void AbstractBuilder::ensureCapacityInternal(int minCapacity)
{
	if (capacity < minCapacity)
	{
		expandCapacity(minCapacity);
	}
}

void AbstractBuilder::expandCapacity(int minCapacity)
{
	int newCapacity = 2 * (capacity + 1);
	if (newCapacity < minCapacity)
	{
		newCapacity = minCapacity;
	}
	if (newCapacity < 0)
	{
		if (minCapacity < 0)
		{
			/*cout << "out of memory error" << endl;*/
		}
		newCapacity = INT_MAX;
	}
	capacity = newCapacity;
	char *newValue = new char[newCapacity];
	strcpy_s(newValue, count + 1,value);
	delete value;
	value = newValue;
}

Builder::Builder(int _capacity)
{
	if (_capacity != 16)
	{
		capacity = _capacity;
		delete value;
		value = new char[capacity];
	}
}

string Builder::getResult()
{
	return string(value);
}
