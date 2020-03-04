#include "ProtoType.h"

ConcreteProtoType::ConcreteProtoType(int status)
{
	this->someStatus = status;
}

ProtoType* ConcreteProtoType::myClone()
{
	return new ConcreteProtoType(someStatus);
}
