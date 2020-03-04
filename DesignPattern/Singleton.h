#pragma once
#include<mutex>
#include<iostream>
class Singleton
{
private:
	Singleton() { std::cout << "Singleton()" << std::endl; };
	static Singleton* instance;
	static std::mutex singleLock;
public:
	static Singleton * getSingleton();
	void nonStaticMehthod();
};

