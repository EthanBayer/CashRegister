#ifndef PLATE_H
#define PLATE_H

#include "Item.h"
#include <string>
#include "moneyclass.h"
#include <vector>

class Plate : public Item
{
    public:
        Plate();
        Plate(std::string name, IDisplayBehavior* displayType);
        void addItem(Item* item);
        void removeItem(int i);

};

#endif