
#include "../headers/Item.h"
#include <string>
#include "../headers/moneyclass.h"

Item::Item()
{
    displayType = nullptr;
    name = "";
}

Item::Item(std::string name, IDisplayBehavior* displayType)
{
    this->name = name;
    this->displayType = displayType;
}

void Item::setPrice(MoneyClass price)
{
	this->price = price;
}

MoneyClass Item::getPrice()
{
	return this->price;
}

void Item::setName(std::string name)
{
    this->name = name;
}

std::string Item::getName()
{
    return name;
}

void Item::setTotalPrice(double money)
{
    price.setMoney(money);
}

std::string Item::getModification(int i)
{
    return modifications.at(i);
}

Item* Item::getItem(int i)
{
    return items.at(i);
}

int Item::getModSize()
{
    return modifications.size();
}

int Item::getItemSize()
{
    return items.size();
}

void Item::getDisplay()
{
    displayType->display(this);
}

double Item::getTotalPrice()
{
    double totalprice = 0.0;
    if(items.size() > 0)
    {
        for (int i = 0; i < items.size(); i++)
        {
            totalprice += items.at(i)->getPrice().getRealMoney();
        }
    }
    return totalprice;
}

