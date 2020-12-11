#pragma once

#include "../../components/headers/Menu.hpp"
#include "../../components/headers/order.h"
#include "../../components/headers/OrderDisplay.hpp"
#include "../../components/headers/Utilities.hpp"

class Order;

class CheckoutWindow: public BasicMenu{
private:
    std::vector<Order*>* orders;
    MoneyClass* balance;
public:
    CheckoutWindow(const std::string& _title, std::vector<Order*>* _orders, MoneyClass* _balance);

    void display();

    void pay();

    void cancel();

    void Exit();
};
