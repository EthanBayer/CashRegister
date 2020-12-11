#ifndef ITEM_H
#define ITEM_H

#include <string>
#include <vector>
#include "moneyclass.h"
#include "IDisplayStrategy.hpp"

class IDisplayBehavior;

class Item
{
    protected:
        IDisplayBehavior* displayType;
        MoneyClass price;
        std::vector<Item*> items;
        std::vector<std::string> modifications;
        std::string name;

    public:
        Item();
        Item(std::string name, IDisplayBehavior* displayType);
        void setPrice(MoneyClass price);    //Tested
        MoneyClass getPrice();              //Tested
        void setName(std::string name);     //Tested
        std::string getName();              //Tested
        void setTotalPrice(double money);   //
        std::string getModification(int i); //Tested
        Item* getItem(int i);               //Tested
        int getModSize();                   //Tested
        int getItemSize();                  //Tested
        void getDisplay();                  //Tested
        double getTotalPrice();             //Tested
        std::string displayItem();
};

#endif
