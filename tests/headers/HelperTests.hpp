#ifndef HELPERTESTS_HPP
#define HELPERTESTS_HPP

#include <gtest/gtest.h>
#include "../../include/components/src/HelperFunctions.cpp"
#include <fstream>
#include <iostream>
#include <iomanip>
#include <map>


TEST (HelperFunctionTests, checkIfNumTest)
{
    EXPECT_EQ(checkIfNum("1"), true);

    EXPECT_EQ(checkIfNum("2"), true);

    EXPECT_EQ(checkIfNum("55"), true);

    EXPECT_EQ(checkIfNum("672"), true);

    EXPECT_EQ(checkIfNum("2319"), true);

    EXPECT_EQ(checkIfNum("1a"), false);

    EXPECT_EQ(checkIfNum("a"), false);

    EXPECT_EQ(checkIfNum("dd"), false);

    EXPECT_EQ(checkIfNum("12l5"), false);
}

TEST (HelperFunctionTests, checkUserInput)
{
    EXPECT_EQ(checkUserInput("1", 2), "1");

    EXPECT_EQ(checkUserInput("2", 2), "2");

    EXPECT_EQ(checkUserInput("3", 4), "3");

    EXPECT_EQ(checkUserInput("4", 4), "4");

    EXPECT_EQ(checkUserInput("45", 46), "45");

    EXPECT_EQ(checkUserInput("46", 46), "46");

    EXPECT_EQ(checkUserInput("123", 124), "123");

    EXPECT_EQ(checkUserInput("124", 124), "124");

}

#endif