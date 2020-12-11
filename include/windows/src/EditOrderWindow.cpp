
// #include "../headers/EditOrderWindow.hpp"
// #include "../../components/headers/SingleItemDisplay.hpp"
// #include "../../components/headers/MultiItemDisplay.hpp"
// #include "../../components/headers/OrderDisplay.hpp"
// #include "../../components/src/HelperFunctions.cpp"
// #include <string>
// #include <limits>

// EditMenu::EditMenu(const std::string& _title, const std::string& fileName, Order* order) : BasicMenu(_title)
// {
//     this->order = order;
//     file = fileName;
//     addOption(new BasicMenuOption("Make a Plate", [this](){AddItem();}));
//     addOption(new BasicMenuOption("Remove a Plate", [this](){RemoveItem();}));
//     addOption(new BasicMenuOption("Return", [this](){Exit();}));

//     this->initialize();
// }

// void EditMenu::initialize()
// {
//     bool inMap = false;
//     std::ifstream inFile(file);
//     if (inFile.is_open())
//     {
//         std::string key, name, price;
//         while(inFile >> key)
//         {
//             inFile >> name;
//             inFile >> price;
//             if (choices.find(key) != choices.end())
//             {
//                 choices.find(key)->second.push_back(c.CreateItem(name, std::stod(price)));
//             }
//             else
//             {
//                 std::vector<Item*> temp = {c.CreateItem(name, std::stod(price))};
//                 choices.insert(std::pair<std::string, std::vector<Item*>>(key, temp));
//             } 
//         }
//     }
//     else
//     {
//         throw std::runtime_error("inFile Did Not Open");
//     }
// }

// void EditMenu::printItems(std::string key)
// { 
//     std::cout << std::endl << "Items: " << std::endl << "Name:   " << " | ";
//     for(int i = 0; i < choices.find(key)->second.size(); i++)
//     {
//         std::cout << choices.find(key)->second.at(i)->getName() << " | ";
//     }
//     std::cout << std::endl << "Price:  " << " | ";
//     for(int i = 0; i < choices.find(key)->second.size(); i++)
//     {
//         printAtCenterCont(choices.find(key)->second.at(i)->getPrice().getTotal(), ' ', choices.find(key)->second.at(i)->getName().size());
//         std::cout << " | ";
//     }
//     std::cout << std::endl << "Choice: " << " | ";
//     for(int i = 0; i < choices.find(key)->second.size(); i++)
//     {
//         printAtCenterCont(std::to_string(i), ' ', choices.find(key)->second.at(i)->getName().size());
//         std::cout << " | ";
//     }
//     std::cout << std::endl;
// }

// void EditMenu::AddItem()
// {
//     if (order->getItemSize() > 0)
//     {
//         std::string c, n;
//         std::cin.ignore();
//         std::cout << std::endl << std::endl << "Choose a Plate to add an Item to (select q to leave): ";
//         std::cin >> n;

//         if (n == "q" || n == "Q")
//         {
//             std::cout << "No plate Available." << std::endl;
//         }

//         std::cin.clear();
//         int input = std::stoi(checkUserInput(n, order->getItemSize()));
//         if (order->getItem(input)->getItemSize() > 0)
//         {
//             std::cin.ignore();
//             std::cout << std::endl << std::endl << "Choose an Item for your plate: ";
//             std::cin >> n;

//             std::cin.clear();
//             order->getItem(input)->addItem(choices.find("mixed")->second.at(std::stoi(checkUserInput(n, choices, "mixed"))));
//         }
//         else
//         {
//             std::cout << "That is not a Plate." << std::endl;
//         }
        
//     }
//     else
//     {
//         std::cout << "You must first make a plate before you can add an item to one." << std::endl;
//     }
    
// }

// void EditMenu::RemoveItem()
// {
//     if (order->getItemSize() > 0)
//     {
//         std::string c, n;
//         std::cin.ignore();
//         std::cout << std::endl << std::endl << "Choose a Plate to remove an Item from (select q to leave): ";
//         std::cin >> n;

//         if (n == "q" || n == "Q")
//         {
//             std::cout << "No plate Available." << std::endl;
//         }

//         std::cin.clear();
//         int input = std::stoi(checkUserInput(n, order->getItemSize()));
//         if (order->getItem(input)->getItemSize() > 0)
//         {
//             std::cin.ignore();
//             std::cout << std::endl << std::endl << "Choose an Item to remove from your plate: ";
//             std::cin >> n;

//             std::cin.clear();
//             order->getItem(input)->removeItem(std::stoi(checkUserInput(n, order->getItem(input)->getItemSize())));
//         }
//         else
//         {
//             std::cout << "That is not a Plate." << std::endl;
//         }
        
//     }
//     else
//     {
//         std::cout << "You must first make a plate before you can remove an item from one." << std::endl;
//     }
    
// }

// void EditMenu::AddMod()
// {
//     std::string plateOrNo;
//     std::string c, n;
//     std::cout << "Are you modifying a Plate's Items (y/n): ";
//     std::cin >> plateOrNo;
//     std::cin.clear();

//     if (order->getItemSize() > 0)
//     {
//         if (plateOrNo != "n")
//         {
//             std::cin.ignore();
//             std::cout << std::endl << std::endl << "Choose a Plate to add an Item Modifcation to (select q to leave): ";
//             std::cin >> n;

//             if (n == "q" || n == "Q")
//             {
//                 std::cout << "No plate Available." << std::endl;
//             }

//             std::cin.clear();
//             int input = std::stoi(checkUserInput(n, order->getItemSize()));
//             if (order->getItem(input)->getItemSize() > 0)
//             {
//                 std::cin.ignore();
//                 std::cout << std::endl << std::endl << "Choose an Item from your plate to modify: ";
//                 std::cin >> n;

//                 std::cin.clear();
//                 int itemInput = std::stoi(checkUserInput(n, order->getItem(input)->getItemSize())); 
//                 std::string modification;
//                 std::cout << "Enter the Item modification you wish to add: ";
//                 std::getline(std::cin, modification);
//                 order->getItem(input)->getItem(itemInput)->addModifications(modification);
//             }
//             else
//             {
//                 std::cout << "That is not a Plate." << std::endl;
//             }
//         }
//         else
//         {
//             std::cin.ignore();
//             std::cout << std::endl << std::endl << "Choose an Item from your plate to modify: ";
//             std::cin >> n;

//             std::cin.clear();
//             int itemInput = std::stoi(checkUserInput(n, order->getItemSize()));

//             if (order->getItem(itemInput)->getItemSize() == 0)
//             {
//                 std::string modification;
//                 std::cout << "Enter the Item modification you wish to add: ";
//                 std::getline(std::cin, modification);
//                 order->getItem(itemInput)->addModifications(modification);
//             }
//             else
//             {
//                 std::cout << "That is not a singularItem." << std::endl;
//             }
//         }
//     }
//     else
//     {
//         std::cout << "You must first make a plate before you can add an item modification." << std::endl;
//     }
// }

// void EditMenu::RemoveMod()
// {
//     std::string plateOrNo;
//     std::string c, n;
//     std::cout << "Are you modifying a Plate's Items (y/n): ";
//     std::cin >> plateOrNo;
//     std::cin.clear();

//     if (order->getItemSize() > 0)
//     {
//         if (plateOrNo != "n")
//         {
//             std::cin.ignore();
//             std::cout << std::endl << std::endl << "Choose a Plate to remove an Item Modifcation from (select q to leave): ";
//             std::cin >> n;

//             if (n == "q" || n == "Q")
//             {
//                 std::cout << "No plate Available." << std::endl;
//             }

//             std::cin.clear();
//             int input = std::stoi(checkUserInput(n, order->getItemSize()));
//             if (order->getItem(input)->getItemSize() > 0)
//             {
//                 std::cin.ignore();
//                 std::cout << std::endl << std::endl << "Choose an Item from your plate to modify: ";
//                 std::cin >> n;

//                 std::cin.clear();
//                 int itemInput = std::stoi(checkUserInput(n, order->getItem(input)->getItemSize())); 
//                 std::string modInput;
//                 std::cout << "Please enter the modification you wish to remove: ";
//                 std::cin >> modInput;
//                 int modindex = std::stoi(checkUserInput(modInput, order->getItem(input)->getItem(itemInput)->getItemSize()));
//                 order->getItem(input)->getItem(itemInput)->removeModifications(modindex);
//             }
//             else
//             {
//                 std::cout << "That is not a Plate." << std::endl;
//             }
//         }
//         else
//         {
//             std::cin.ignore();
//             std::cout << std::endl << std::endl << "Choose an Item from your plate to modify: ";
//             std::cin >> n;

//             std::cin.clear();
//             int itemInput = std::stoi(checkUserInput(n, order->getItemSize()));

//             if (order->getItem(itemInput)->getItemSize() == 0)
//             {
//                 std::string modInput;
//                 std::cout << "Please enter the modification you wish to remove: ";
//                 std::cin >> modInput;
//                 int modindex = std::stoi(checkUserInput(modInput, order->getItem(itemInput)->getItemSize()));
//                 order->getItem(itemInput)->removeModifications(modindex);
//             }
//             else
//             {
//                 std::cout << "That is not a singularItem." << std::endl;
//             }
//         }
//     }
//     else
//     {
//         std::cout << "You must first make a plate before you can add an item modification." << std::endl;
//     }
// }

// void EditMenu::Exit()
// {
//     current_option = nullptr;
// }