#include "Singleton.h"

Singleton *Singleton::instance = NULL;
std::mutex Singleton::singleLock;

Singleton* Singleton::getSingleton()
{
	std::cout << "getSingleton()" << std::endl;
	if (instance==NULL)
	{
		std::unique_lock<std::mutex> lock(singleLock);
		if (instance==NULL)
		{
			instance = new Singleton();
		}
		lock.unlock();
	}
	return instance;
}

void Singleton::nonStaticMehthod()
{
	std::cout << "non static method invoked" << std::endl;
}
