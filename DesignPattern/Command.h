#include <string>
#include <iostream>

using namespace std;

class Receiver
{
	//命令的真正执行者
public:
	Receiver() {};
	virtual ~Receiver()
	{

	}
	void run() {
		cout << "do some thing!" << endl;
	}
};


class Command
{
public:
	Command(Receiver* receiver) :m_receiver(receiver) {};
	virtual ~Command(){};
	virtual void execute() = 0;
private:
	Receiver* m_receiver;
};

class ConcreteCommand : public Command
{
public:
	ConcreteCommand(Receiver* receiver) :Command(receiver) {};
	virtual ~ConcreteCommand() {};
	void execute() { cout << "Concrete Command Execute()" << endl; m_receiver->run(); };
private:
	Receiver* m_receiver;
};



class Invoker
{
public:
	Invoker(Command* command) :m_command(command) {};
	~Invoker() {};
	void call() { m_command->execute(); };
private:
	Command *m_command;
};