#include "../headers/ItemCreator.hpp"
#include "../headers/Item.h"
#include "../headers/plate.h"
#include "../headers/Singleitem.h"
#include "../headers/MultiItemDisplay.hpp"
#include "../headers/SingleItemDisplay.hpp"
#include <string>


Item* ItemCreator::CreateItem(ItemType TypeId, std::string name, double price){
    if(TypeId == PLATE_ITEM_T){
        MultiDisplay* multDisp = new MultiDisplay();
        Plate* item = new Plate(name, multDisp);
        item->setPrice(price);
        return item;
    }

    if(TypeId == SINGLE_ITEM_T){
        SingleItemDisplay* singDisp = new SingleItemDisplay();
        SingleItem* item = new SingleItem(name, singDisp);
        item->setPrice(price);
        return item;
    }
}


