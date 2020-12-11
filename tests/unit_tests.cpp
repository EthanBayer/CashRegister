#include <gtest/gtest.h>

#include "headers/itemtests.hpp"
#include "headers/moneyclasstests.h"
#include "headers/itemfunctiontests.hpp"
#include "headers/CreatorClass.hpp"
#include "headers/HelperTests.hpp"

int main(int argc, char **argv){
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}