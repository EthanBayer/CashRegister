#ifndef __ITEM_CREATOR_HPP__
#define __ITEM_CREATOR_HPP__

#include "Item.h"
#include "moneyclass.h"
#include <string>

enum ItemType{PLATE_ITEM_T, SINGLE_ITEM_T};

class ItemCreator{
	public:

		virtual Item* CreateItem(ItemType TypeId, std::string name, double price);
};

#endif
