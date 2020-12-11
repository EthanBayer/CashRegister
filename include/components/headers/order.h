#ifndef ORDER_H
#define ORDER_H

#include "Item.h"
#include <string>
#include "moneyclass.h"
#include <vector>

class Order : public Item
{
    public:
        Order();
        Order(std::string name, IDisplayBehavior* displayType);
        void addPlate(Item* item);
        void removePlate(int i);
};

#endif