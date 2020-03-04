#pragma once
#pragma once
#include<iostream>
using namespace std;

class Product
{
public:
	virtual void aboutMe() = 0;
};

class Product1 :public Product
{
public:
	void aboutMe()
	{
		cout << "I am product1!" << endl;
	}
};

class Product2 :public Product
{
public:
	void aboutMe()
	{
		cout << "I am product2!" << endl;
	}
};

class Factory
{
public:
	virtual Product* createProduct() = 0;
	void doSomething();
};

class Factory1 : public Factory
{
public:
	Product1* createProduct() { return new Product1(); }
};

class Factory2 : public Factory
{
public:
	Product2* createProduct() { return new Product2(); }
};
