
#include "../headers/OrderWindow.hpp"
#include "../../components/headers/SingleItemDisplay.hpp"
#include "../../components/headers/MultiItemDisplay.hpp"
#include "../../components/headers/OrderDisplay.hpp"
#include "../../components/src/HelperFunctions.cpp"
#include <string>
#include <limits>

OrderMenu::OrderMenu(const std::string& _title, const std::string& fileName, std::vector<Order*>* orders) : BasicMenu(_title)
{
    this->orders = orders;
    file = fileName;
    addOption(new BasicMenuOption("Make a Plate", [this](){AddItem();}));
    addOption(new BasicMenuOption("Remove a Plate", [this](){RemoveItem();}));
    addOption(new BasicMenuOption("Return", [this](){Exit();}));

    this->initialize();
}

void OrderMenu::initialize()
{
    orders->push_back(new Order(std::to_string(orders->size() + 1), new OrderDisplay()));
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

void OrderMenu::printItems(std::string key)
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
    std::cout << "\n";
}

void OrderMenu::AddItem()
{
    printItems("mixed");
    std::string c, n;
    Plate* test = new Plate("Plate", new MultiDisplay());
    std::cin.ignore();
    std::cout << "\n\nChoose an Item for your plate: ";
    std::cin >> n;

    test->addItem(choices.find("mixed")->second.at(std::stoi(checkUserInput(n, choices, "mixed"))));
    bool cont = false;
     while (!cont)
    {
        std::cout << "Do you want to add another Item for the plate (y/n): ";
        std::cin >> c;
        if (c != "n")
        {
            std::cout << "Choose an Item for your plate: ";
            std::cin >> n;
            
            test->addItem(choices.find("mixed")->second.at(std::stoi(checkUserInput(n, choices, "mixed"))));
        }
        else
        {
            cont = true;
        }
        
    }
    orders->back()->addPlate(test);
    orders->back()->getDisplay();
}

void OrderMenu::RemoveItem()
{
    std::cin.ignore();
    if (orders->back()->getItemSize() == 0)
    {
        std::cout << "No Plate to Remove." << std::endl;
    }
    else
    {
        std::cout << std::endl << std::endl << "Choose a plate to remove: ";
        std::string n;
        std::cin >> n;

        std::cin.clear();
        orders->back()->removePlate((std::stoi(checkUserInput(n, orders->back()->getItemSize())) - 1));
        orders->back()->getDisplay();
    }
    
}

void OrderMenu::Exit()
{
    current_option = nullptr;
}