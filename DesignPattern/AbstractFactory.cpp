#include "AbstractFactory.h"

void AbstractFactory::doSomething()
{
	Product* product = createProduct();
	AnotherProduct* anotherProduct = createAnotherProduct();
	product->aboutMe();
	anotherProduct->aboutMe();
}
