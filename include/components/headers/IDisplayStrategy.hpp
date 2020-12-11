
#ifndef IDISPLAYSTRATEGY_HPP
#define IDISPLAYSTRATEGY_HPP

#include "Item.h"

class Item;

class IDisplayBehavior
{
    public:
        IDisplayBehavior(){};
        virtual void display(Item* i) = 0;
};

#endif