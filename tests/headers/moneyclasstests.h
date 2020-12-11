#ifndef MONEYCLASSTESTS_H
#define MONEYCLASSTESTS_H

#include <gtest/gtest.h>
#include "../../include/components/headers/moneyclass.h"
#include <cstring>

TEST(MoneyclassTest, GetDollarTest)
{
    MoneyClass* test = new MoneyClass();
    EXPECT_EQ(test->getDollar(), 00);

    test->setMoney(123.45);
    EXPECT_EQ(test->getDollar(), 123);

    MoneyClass* test2 = new MoneyClass(987.65);
    EXPECT_EQ(test2->getDollar(), 987);

    test2->setMoney(1.78);
    EXPECT_EQ(test2->getDollar(), 1);
}

TEST(MoneyclassTest, GetCentTest)
{
    MoneyClass* test = new MoneyClass();
    EXPECT_EQ(test->getCent(), 00);

    test->setMoney(123.45);
    EXPECT_EQ(test->getCent(), 45);

    MoneyClass* test2 = new MoneyClass(987.65);
    EXPECT_EQ(test2->getCent(), 65);

    test2->setMoney(1.78);
    EXPECT_EQ(test2->getCent(), 78);
}

TEST(MoneyclassTest, GetTotalTest)
{
    MoneyClass* test = new MoneyClass();
    bool string = test->getTotal() == "0.00";
    EXPECT_TRUE(string);

    test->setMoney(123.45);
    EXPECT_EQ(test->getTotal(), "123.45");

    MoneyClass* test2 = new MoneyClass(987.65);
    EXPECT_EQ(test2->getTotal(), "987.65");

    test2->setMoney(1.78);
    EXPECT_EQ(test2->getTotal(), "1.78");

    test2->setMoney(1.70);
    EXPECT_EQ(test2->getTotal(), "1.70");

    MoneyClass* test3 = new MoneyClass(0.07);
    EXPECT_EQ(test3->getTotal(), "0.07");
}

TEST(MoneyclassTest, RealMoneyTest)
{
    MoneyClass* test = new MoneyClass();

    test->setMoney(123.45);
    EXPECT_EQ(test->getRealMoney(), 123.45);

    test->setMoney(34.76);
    EXPECT_EQ(test->getRealMoney(), 34.76);

    test->setMoney(987.65);
    EXPECT_EQ(test->getRealMoney(), 987.65);

    test->setMoney(20);
    EXPECT_EQ(test->getRealMoney(), 20.00);
}

TEST(MoneyclassTest, AddMoneyTest)
{
    MoneyClass* test = new MoneyClass();

    test->setMoney(123.45);
    EXPECT_EQ(test->getRealMoney(), 123.45);

    test->addMoney(34.76);
    EXPECT_EQ(test->getRealMoney(), 158.21);

    test->addMoney(987.65);
    EXPECT_EQ(test->getRealMoney(), 1145.86);

    test->addMoney(20);
    EXPECT_EQ(test->getRealMoney(), 1165.86);
}

TEST(MoneyclassTest, SubMoneyTest)
{
    MoneyClass* test = new MoneyClass();

    test->setMoney(987.65);
    EXPECT_EQ(test->getRealMoney(), 987.65);

    test->subMoney(34.76);
    EXPECT_EQ(test->getRealMoney(), 952.89);

    test->subMoney(123.45);
    EXPECT_EQ(test->getRealMoney(), 829.44);

    test->subMoney(20);
    EXPECT_EQ(test->getRealMoney(), 809.44);
}


#endif