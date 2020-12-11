
#include "../headers/MultiItemDisplay.hpp"
#include <iostream>
#include <iomanip>


void MultiDisplay::display(Item* i)
{
    std::cout << std::right << i->getName() << std::setfill(' ') << ": " << std::endl;
    for(int j = 0; j < i->getItemSize(); j++)
    {
        std::cout << std::setw(10);
        i->getItem(j)->getDisplay();
        std::cout << std::endl;
    }
    std::string totalName = i->getName() + " Total";

    std::cout << std::left << std::setw(49) << std::setfill('.') << totalName << "$" << i->getTotalPrice() << std::endl << std::endl;

    std::cout << std::setfill(' ');
}