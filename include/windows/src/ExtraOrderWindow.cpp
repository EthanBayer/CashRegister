

#include "../headers/ExtraOrderWindow.hpp"
#include "../../components/headers/SingleItemDisplay.hpp"
#include "../../components/headers/MultiItemDisplay.hpp"
#include "../../components/headers/OrderDisplay.hpp"
#include "../../components/src/HelperFunctions.cpp"
#include <string>

ExtraMenu::ExtraMenu(const std::string& _title, const std::string& fileName, std::vector<Order*>* order) : BasicMenu(_title)
{
    this->orders = order;
    file = fileName;
    addOption(new BasicMenuOption("Add a Drink", [this](){AddDrink();}));
    addOption(new BasicMenuOption("Add a Side", [this](){AddSide();}));
    addOption(new BasicMenuOption("Add a Dessert", [this](){AddDesert();}));
    addOption(new BasicMenuOption("Add a Sauce", [this](){AddSauce();}));
    addOption(new BasicMenuOption("Remove an Item or Plate", [this](){RemoveItem();}));
    addOption(new BasicMenuOption("Return", [this](){Exit();}));

    this->initialize();
}

void ExtraMenu::initialize()
{
    bool inMap = false;
    std::ifstream inFile(file);
    if (inFile.is_open())
    {
        std::string key, name, price;
        while(inFile >> key)
        {
            inFile >> name;
            inFile >> price;
            if (choices.find(key) != choices.end())
            {
                choices.find(key)->second.push_back(c.CreateItem(SINGLE_ITEM_T, name, std::stod(price)));
            }
            else
            {
                std::vector<Item*> temp = {c.CreateItem(SINGLE_ITEM_T, name, std::stod(price))};
                choices.insert(std::pair<std::string, std::vector<Item*>>(key, temp));
            } 
        }
    }
    else
    {
        throw std::runtime_error("inFile Did Not Open");
    }
}

void ExtraMenu::printItems(std::string key)
{ 
    std::cout << std::endl << "Items: " << std::endl << "Name:   " << " | ";
    for(int i = 0; i < choices.find(key)->second.size(); i++)
    {
        std::cout << choices.find(key)->second.at(i)->getName() << " | ";
    }
    std::cout << std::endl << "Price:  " << " | ";
    for(int i = 0; i < choices.find(key)->second.size(); i++)
    {
        printAtCenterCont(choices.find(key)->second.at(i)->getPrice().getTotal(), ' ', choices.find(key)->second.at(i)->getName().size());
        std::cout << " | ";
    }
    std::cout << std::endl << "Choice: " << " | ";
    for(int i = 0; i < choices.find(key)->second.size(); i++)
    {
        printAtCenterCont(std::to_string(i), ' ', choices.find(key)->second.at(i)->getName().size());
        std::cout << " | ";
    }
    std::cout << std::endl;
}


void ExtraMenu::AddDrink()
{
    printItems("drink");
    std::string c, n;
    std::cin.ignore();
    std::cout << std::endl << std::endl << "Choose a drink for your order: ";
    std::cin >> n;

    std::cin.clear();
    orders->back()->addPlate(choices.find("drink")->second.at(std::stoi(checkUserInput(n, choices, "drink"))));
    std::cout << std::endl;
    orders->back()->getDisplay();
}

void ExtraMenu::AddSide()
{
    printItems("side");
    std::string c, n;
    std::cin.ignore();
    std::cout << std::endl << std::endl << "Choose a side for your order: ";
    std::cin >> n;

    std::cin.clear();
    orders->back()->addPlate(choices.find("side")->second.at(std::stoi(checkUserInput(n, choices, "side"))));
    std::cout << std::endl;
    orders->back()->getDisplay();
}

void ExtraMenu::AddDesert()
{
    printItems("dessert");
    std::string c, n;
    std::cin.ignore();
    std::cout << std::endl << std::endl << "Choose a dessert for your order: ";
    std::cin >> n;

    std::cin.clear();
    orders->back()->addPlate(choices.find("dessert")->second.at(std::stoi(checkUserInput(n, choices, "dessert"))));
    std::cout << std::endl;
    orders->back()->getDisplay();
}

void ExtraMenu::AddSauce()
{
    printItems("sauce");
    std::string c, n;
    std::cin.ignore();
    std::cout << std::endl << std::endl << "Choose a sauce for your order: ";
    std::cin >> n;

    std::cin.clear();
    orders->back()->addPlate(choices.find("sauce")->second.at(std::stoi(checkUserInput(n, choices, "sauce"))));
    std::cout << std::endl;
    orders->back()->getDisplay();
}

void ExtraMenu::RemoveItem()
{
    std::cin.ignore();
    if (orders->back()->getItemSize() == 0)
    {
        std::cout << "No Plate to Remove." << std::endl;
    }
    else
    {
        std::cout << std::endl << std::endl << "Choose an Item to remove: ";
        std::string n;
        std::cin >> n;

        std::cin.clear();
        orders->back()->removePlate((std::stoi(checkUserInput(n, orders->back()->getItemSize())) - 1));
        orders->back()->getDisplay();
    }
}

void ExtraMenu::Exit()
{
    current_option = nullptr;
}