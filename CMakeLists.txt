CMAKE_MINIMUM_REQUIRED(VERSION 2.8.12)

ADD_SUBDIRECTORY(googletest)

INCLUDE_DIRECTORIES(googletest/include)

SET(CMAKE_CXX_STANDARD 11)

ADD_EXECUTABLE(restaurant
    restaurant.cpp
    include/components/src/Menu.cpp
    include/components/src/Utilities.cpp
    include/windows/src/LoginWindow.cpp
    include/windows/src/Checkout.cpp
    include/windows/src/OrderWindow.cpp
    include/windows/src/ExtraOrderWindow.cpp
    include/windows/src/ManagerWindow.cpp
    
    include/components/src/item.cpp
    include/components/src/Singleitem.cpp
    include/components/src/SingleItemDisplay.cpp
    include/components/src/moneyclass.cpp
    include/components/src/MultiItemDisplay.cpp
    include/components/src/plate.cpp
    include/components/src/order.cpp
    include/components/src/OrderDisplay.cpp
    include/components/src/HelperFunctions.cpp
    include/components/src/ItemCreator.cpp

    include/drivers/src/Application.cpp
)

ADD_EXECUTABLE(unit_tests
    tests/unit_tests.cpp
    include/components/src/moneyclass.cpp
    include/components/src/item.cpp
    include/components/src/Singleitem.cpp
    include/components/src/SingleItemDisplay.cpp
    include/components/src/plate.cpp
    include/components/src/ItemCreator.cpp
    include/components/src/MultiItemDisplay.cpp
    include/components/src/HelperFunctions.cpp
)

ADD_EXECUTABLE(OrderDisplayTest
    tests/testDisplay.cpp
    include/components/src/item.cpp
    include/components/src/Singleitem.cpp
    include/components/src/SingleItemDisplay.cpp
    include/components/src/moneyclass.cpp
    include/components/src/MultiItemDisplay.cpp
    include/components/src/plate.cpp
    include/components/src/order.cpp
    include/components/src/OrderDisplay.cpp
    include/components/src/HelperFunctions.cpp
)

TARGET_LINK_LIBRARIES(unit_tests gtest)
TARGET_COMPILE_DEFINITIONS(unit_tests PRIVATE gtest_disable_pthreads=ON)
