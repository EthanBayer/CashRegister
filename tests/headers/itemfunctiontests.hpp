#ifndef ITEMFUNCTIONTESTS_HPP
#define ITEMFUNCTIONTESTS_HPP

#include <gtest/gtest.h>
#include "../../include/components/headers/Item.h"
#include "../../include/components/headers/Singleitem.h"
#include "../../include/components/headers/plate.h"
#include "../../include/components/headers/SingleItemDisplay.hpp"

TEST(ItemFunctionTests, getModificationsTest)
{
    SingleItem* si = new SingleItem();
    si->addModifications("mod1");
    si->addModifications("mod2");
    si->addModifications("mod3");

    EXPECT_EQ(si->getModification(0), "mod1");
    EXPECT_EQ(si->getModification(1), "mod2");
    EXPECT_EQ(si->getModification(2), "mod3");
}

TEST(ItemFunctionTests, getModSizeTest)
{
    SingleItem* si = new SingleItem();

    EXPECT_EQ(si->getModSize(), 0);

    si->addModifications("mod1");
    si->addModifications("mod2");
    si->addModifications("mod3");

    EXPECT_EQ(si->getModSize(), 3);

    si->addModifications("mod4");

    EXPECT_EQ(si->getModSize(), 4);
}

TEST(ItemFunctionTests, getItemTest)
{
    Plate* p = new Plate();
    SingleItem* si1 = new SingleItem("Item1", new SingleItemDisplay(), 12.36);
    SingleItem* si2 = new SingleItem("Item2", new SingleItemDisplay(), 13.36);
    SingleItem* si3 = new SingleItem("Item3", new SingleItemDisplay(), 14.36);

    p->addItem(si1);
    p->addItem(si2);
    p->addItem(si3);

    EXPECT_EQ(p->getItem(0)->getName(), "Item1");
    EXPECT_EQ(p->getItem(1)->getName(), "Item2");
    EXPECT_EQ(p->getItem(2)->getName(), "Item3");
}

TEST(ItemFunctionTests, getItemSizeTest)
{
    Plate* p = new Plate();

    EXPECT_EQ(p->getItemSize(), 0);

    SingleItem* si1 = new SingleItem("Item1", new SingleItemDisplay(), 12.36);
    SingleItem* si2 = new SingleItem("Item2", new SingleItemDisplay(), 13.36);
    SingleItem* si3 = new SingleItem("Item3", new SingleItemDisplay(), 14.36);

    p->addItem(si1);
    p->addItem(si2);
    p->addItem(si3);

    EXPECT_EQ(p->getItemSize(), 3);

    SingleItem* si4 = new SingleItem("Item4", new SingleItemDisplay(), 15.36);

    p->addItem(si4);

    EXPECT_EQ(p->getItemSize(), 4);
}

TEST(ItemFunctionTests, getTotalPriceTest)
{
    Plate* p = new Plate();

    EXPECT_EQ(p->getTotalPrice(), 0.0);

    SingleItem* si1 = new SingleItem("Item1", new SingleItemDisplay(), 12.36);
    p->addItem(si1);
    
    EXPECT_EQ(p->getTotalPrice(), 12.36);

    SingleItem* si2 = new SingleItem("Item2", new SingleItemDisplay(), 13.36);
    p->addItem(si2);

    EXPECT_EQ(p->getTotalPrice(), 25.72);

    SingleItem* si3 = new SingleItem("Item3", new SingleItemDisplay(), 14.36);
    p->addItem(si3);

    EXPECT_EQ(p->getTotalPrice(), 40.08);
}

#endif