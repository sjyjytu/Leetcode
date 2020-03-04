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

class AnotherProduct
{
public:
	virtual void aboutMe() = 0;
};

class AnotherProduct1 :public AnotherProduct
{
public:
	void aboutMe()
	{
		cout << "I am AnotherProduct1!" << endl;
	}
};

class AnotherProduct2 :public AnotherProduct
{
public:
	void aboutMe()
	{
		cout << "I am AnotherProduct2!" << endl;
	}
};

class AbstractFactory
{
public:
	virtual Product* createProduct() = 0;
	virtual AnotherProduct* createAnotherProduct() = 0;
	void doSomething();
};

class Factory1 : public AbstractFactory
{
public:
	Product* createProduct() { return new Product1(); }
	AnotherProduct* createAnotherProduct() { return new AnotherProduct1(); }
};

class Factory2 : public AbstractFactory
{
public:
	Product* createProduct() { return new Product2(); }
	AnotherProduct* createAnotherProduct() { return new AnotherProduct2(); }
};


