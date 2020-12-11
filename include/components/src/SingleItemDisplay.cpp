
#include "../headers/SingleItemDisplay.hpp"
#include <iostream>
#include <iomanip>
#include <string>

void SingleItemDisplay::display(Item* i)
{
    std::cout << std::right << std::setw(15) << i->getName() << std::setfill('.') << std::setw(35) << "$" << i->getPrice().getTotal() << std::endl;
    std::cout << std::setfill(' ');
  
    if (i->getModSize() != 0)
    {
        std::cout << std::setw(25) << "Modifications: " << std::endl;
        for (int j = 0; j < i->getModSize(); j++)
        {
            std::cout << std::setw(30) << i->getModification(j) << std::endl;
        }
    }
}