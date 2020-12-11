#ifndef SINGLEITEM_H
#define SINGLEITEM_H

#include "Item.h"
#include <string>
#include "moneyclass.h"
#include <vector>

class SingleItem : public Item
{   
    public:
        SingleItem();
        SingleItem(std::string name, IDisplayBehavior* displayType);
        SingleItem(std::string name, IDisplayBehavior* displayType, double money);
        void addModifications(std::string mod);
        void removeModifications(std::string mod);
};

#endif