
#include "../headers/order.h"

Order::Order() : Item() {}

Order::Order(std::string name, IDisplayBehavior* displayType)
{
    this->name = name;
    this->displayType = displayType;
    price.setMoney(0.0);
}

void Order::addPlate(Item* item)
{
    items.push_back(item);
    price.addMoney(item->getPrice().getRealMoney());
}

void Order::removePlate(int i)
{
    price.subMoney(items.at(i)->getPrice().getRealMoney());
    items.erase(items.begin() + i);
}