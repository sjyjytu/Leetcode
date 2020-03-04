#include "Factory.h"

void Factory::doSomething()
{
	Product* product = createProduct();
	product->aboutMe();
}
