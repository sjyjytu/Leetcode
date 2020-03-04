#include <iostream>
//#include "Singleton.h"
//#include "SimpleFactory.h"
//#include "Factory.h"
//#include "AbstractFactory.h"
//#include "Builder.h"
//#include "ProtoType.h"
//#include "ChainOfResponsibility.h"
#include "Command.h"
using namespace std;


int main()
{
	////单例模式
	//Singleton* p1 = Singleton::getSingleton();
	//Singleton* p2 = p1->getSingleton();
	//cout << p1 << " " << p2 << endl;

	////简单工厂
	//SimpleFactory simpleFactory;
	//for (int i = 0; i < 3; i++)
	//{
	//	simpleFactory.createProduct(i)->aboutMe();
	//}
	
//	//工厂方法
//	Factory1 factory1;
//	Factory2 factory2;
//	factory1.doSomething();
//	factory2.doSomething();

	////抽象工厂
	//Factory1 factory1;
	//Factory2 factory2;
	//factory1.doSomething();
	//factory2.doSomething();

	////生成器Builder
	////可以让部分构建，最后通过整体获得
	//Builder builder;
	//for (int i = 0; i < 26; i++)
	//{
	//	builder.append('a' + i);
	//}
	//cout << builder.getResult() << endl;

	////原型模式
	////类似复制构造函数，好处是可以动态获得要复制对象当前的状态，且更高效；生成的新对象还可以是派生类
	//ProtoType* p1 = new ConcreteProtoType(3);
	//ProtoType* p2 = p1->myClone();

	////责任链模式
	//Manager* boss = new Boss(NULL, "Big Boss");
	//Manager* m2 = new Manager2(boss, "m2");
	//Manager* m1 = new Manager1(m2, "m1");
	//m1->handleRequest("D", 300);
	//m1->handleRequest("E", 1300);
	//m1->handleRequest("F", 3300);
	//delete m1;
	//delete m2;
	//delete boss;

	//命令模式
	/*Receiver* receiver = new Receiver();
	Command* concreteCommand = new ConcreteCommand(receiver);
	Invoker* someone = new Invoker(concreteCommand);
	someone->call();*/
	while (true)
	{
		cout << "hah" << endl;
	}
	return 0;
}