#include "../headers/plate.h"

Plate::Plate() : Item() {}

Plate::Plate(std::string name, IDisplayBehavior* displayType)
{
    this->name = name;
    this->displayType = displayType;
}

void Plate::addItem(Item* item)
{
    items.push_back(item);
    price.addMoney(item->getPrice().getRealMoney());
}

void Plate::removeItem(int i)
{
    price.subMoney(items.at(i)->getPrice().getRealMoney());
    items.erase(items.begin() + i);
}