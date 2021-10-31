#include "item.h"

Item::Item(uint id)
	: id(id)
{
	update();
}

void Item::update()
{

}

ulong Item::getPrice(bool fresh)
{
	if (fresh)
		update();
	
	return price;
}

long Item::getPriceDelta(bool fresh)
{
	ulong newprice = getPrice(fresh);
	return lastprice < newprice ? newprice - lastprice : -static_cast<long>(lastprice - newprice);
}
