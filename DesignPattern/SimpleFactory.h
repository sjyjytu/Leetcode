#pragma once
#include<iostream>
using namespace std;
class Product
{
public:
	virtual void aboutMe()
	{
		cout << "I am product!" << endl;
	}
};

class Product1:public Product
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

class SimpleFactory
{
public:
	Product* createProduct(int type)
	{
		switch (type)
		{
		case 1:
			return new Product1();
		case 2:
			return new Product2();
		default:
			return new Product();
		}
	}
};

