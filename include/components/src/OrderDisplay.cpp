
#include "../headers/OrderDisplay.hpp"
#include "HelperFunctions.cpp"
#include <iostream>
#include <iomanip>
#include <ios>

void OrderDisplay::display(Item* i)
{
    printAtCenter("Order: " + i->getName(), '=', 57);
    for(int j = 0; j < i->getItemSize(); j++)
    {
        std::cout << j + 1 << " " << std::setw(10);
        i->getItem(j)->getDisplay();
        std::cout << std::endl;
    }
    std::string totalName = i->getName() + " Total";
    std::string endName = "End of order: " + i->getName();
    std::cout << std::left << std::setw(49) << std::setfill('.')<< totalName << "$" << i->getTotalPrice() << std::endl;
    std::cout << std::setfill(' ');
    printAtCenter(endName, '=', 57);
}