#include <gtest/gtest.h>
#include "../include/components/headers/moneyclass.h"
#include "../include/components/headers/Item.h"
#include "../include/components/headers/ItemCreator.hpp"


TEST(MoneyandItemclassTest, GetPriceTest){
    std::string name = "water";
	double money = 0.0;
   
	ItemCreator itemCreator;
	Item* item = itemCreator.CreateItem(SINGLE_ITEM_T, name, money);
    
    MoneyClass* test = new MoneyClass();
    EXPECT_EQ(item->getPrice(), *test);

    test->setMoney(123.45);
    EXPECT_EQ(item->getPrice(), *test);
}

TEST(MoneyandItemclassTest2, GetPriceTest){
    std::string name = "water";
    double money = 987.65;

    ItemCreator itemCreator;
    Item* item2 = itemCreator.CreateItem(SINGLE_ITEM_T, name, money);

    MoneyClass* test2 = new MoneyClass(987.65);
    EXPECT_EQ(item2->getPrice(), *test2);

    test2->setMoney(1.78);
    EXPECT_EQ(item2->getPrice(), *test2);
}

int main(int argc, char** argv){
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
 
