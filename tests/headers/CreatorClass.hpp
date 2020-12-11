#include "gtest/gtest.h"

#include "../../include/components/headers/Item.h"
#include "../../include/components/headers/moneyclass.h"
#include "../../include/components/headers/ItemCreator.hpp"
#include "../../include/components/headers/plate.h"
#include "../../include/components/headers/Singleitem.h"

TEST(ItemCreatorTest, GetSingleItemTest){
    std::string name = "water";

    // MoneyClass* money = new MoneyClass();
    // money->setMoney(0.75);
    double money = 0.75;

    ItemCreator itemCreator;
    Item* item = itemCreator.CreateItem(SINGLE_ITEM_T, name, money);
    EXPECT_EQ(item->getName(), "water");
    EXPECT_EQ(item->getPrice().getTotal(), "0.75");
}

TEST(ItemCreatorTest, GetPlateTest){
    std::string name = "burrito";

    // MoneyClass* money = new MoneyClass();
    // money->setMoney(12.45);
    double money = 12.45;

    ItemCreator itemCreator;
    Item* item = itemCreator.CreateItem(PLATE_ITEM_T, name, money);
    EXPECT_EQ(item->getName(), "burrito");
    EXPECT_EQ(item->getPrice().getTotal(), "12.45");
}


TEST(ItemCreatorTest, GetSingleItemTest2){
    std::string name = "orange juice";

    // MoneyClass* money = new MoneyClass();
    // money->setMoney(1.75);
    double money = 1.75;

    ItemCreator itemCreator;
    Item* item = itemCreator.CreateItem(SINGLE_ITEM_T, name, money);
    EXPECT_EQ(item->getName(), "orange juice");
    EXPECT_EQ(item->getPrice().getTotal(), "1.75");
}

TEST(ItemCreatorTest, GetPlateTest2){
    std::string name = "burger";

    // MoneyClass* money = new MoneyClass();
    // money->setMoney(12.95);
    double money = 12.95;

	ItemCreator itemCreator;
	Item* item = itemCreator.CreateItem(PLATE_ITEM_T, name, money);
	EXPECT_EQ(item->getName(), "burger");
	EXPECT_EQ(item->getPrice().getTotal(), "12.95");
}
