
#ifndef ITEMTESTS_HPP
#define ITEMTESTS_HPP

#include <gtest/gtest.h>
#include "../../include/components/headers/Item.h"

class TestItem : public ::testing::Test
{
    public:
        Item* testItem;
        TestItem(): testItem(new Item) {}
        ~TestItem()
        {
            delete testItem;
        }
};

TEST_F (TestItem, NameTests)
{
    testItem->setName("Billy");

    EXPECT_EQ(testItem->getName(), "Billy");

    testItem->setName("Billy Bob");

    EXPECT_EQ(testItem->getName(), "Billy Bob");
}

TEST_F (TestItem, PriceTests)
{
    testItem->setPrice(123.67);

    EXPECT_EQ(testItem->getPrice().getTotal(), "123.67");

    testItem->setPrice(00.00);

    EXPECT_EQ(testItem->getPrice().getTotal(), "0.00");

    testItem->setPrice(1.234);

    EXPECT_EQ(testItem->getPrice().getTotal(), "1.23");

    testItem->setPrice(17894.56);

    EXPECT_EQ(testItem->getPrice().getTotal(), "17894.56");

}

#endif