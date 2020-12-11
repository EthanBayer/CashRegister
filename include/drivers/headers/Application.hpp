#pragma once

#include "../../components/headers/Menu.hpp"
#include "../../components/headers/Utilities.hpp"

#include "../../windows/headers/LoginWindow.hpp"
#include "../../windows/headers/Checkout.hpp"
#include "../../windows/headers/OrderWindow.hpp"
#include "../../windows/headers/EditOrderWindow.hpp"
#include "../../windows/headers/ExtraOrderWindow.hpp"
#include "../../windows/headers/ManagerWindow.hpp"

#include "../../components/headers/Item.h"
#include "../../components/headers/Singleitem.h"
#include "../../components/headers/plate.h"
#include "../../components/headers/order.h"
#include "../../components/headers/SingleItemDisplay.hpp"
#include "../../components/headers/MultiItemDisplay.hpp"
#include "../../components/headers/OrderDisplay.hpp"


class Application{
private:
    std::string users, items;

    LoginWindow* login = new LoginWindow("LOGIN OR REGISTER", users);
    ManagerWindow* manWindow = new ManagerWindow("MANAGER FUNCTIONS", login->get_user(), &orders);

    BasicNestedMenu* menu = nullptr;
    std::vector<Order*> orders;
    User* current_user;
    MoneyClass balance;
public:
    Application(const std::string& usersfile, const std::string& itemsfile);

    void run();

    ~Application();
};