#include "../headers/Singleitem.h"

SingleItem::SingleItem() : Item() {}

SingleItem::SingleItem(std::string name, IDisplayBehavior* displayType, double money)
{
    this->name = name;
    this->displayType = displayType;
    price.setMoney(money);
}

SingleItem::SingleItem(std::string name, IDisplayBehavior* displayType)
{
    this->name = name;
    this->displayType = displayType;
}

void SingleItem::addModifications(std::string mod)
{
    modifications.push_back(mod);
}

void SingleItem::removeModifications(std::string mod)
{
    for (int i = 0; i < modifications.size(); i++)
    {
        if (modifications.at(i) == mod)
        {
            modifications.erase(modifications.begin() + i);
        }
    }
}
