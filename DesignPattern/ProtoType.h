#pragma once
class ProtoType
{
public:
	virtual ProtoType* myClone() = 0;
};

class ConcreteProtoType : public ProtoType
{
private:
	int someStatus;
public:
	ConcreteProtoType(int status = 0);
	ProtoType* myClone();
};


