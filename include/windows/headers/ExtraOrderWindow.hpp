#ifndef EXTRAORDERWINDOW_HPP
#define EXTRAORDERWINDOW_HPP

#include "../../components/headers/Menu.hpp"
#include "../../components/headers/Utilities.hpp"
#include "../../components/headers/Item.h"
#include "../../components/headers/order.h"
#include "../../components/headers/plate.h"
#include "../../components/headers/Singleitem.h"
#include "../../components/headers/ItemCreator.hpp"
#include <fstream>
#include <map>
#include <vector>

class ExtraMenu : public BasicMenu
{
    private:
        std::map<std::string, std::vector<Item*>> choices;
        std::vector<Order*>* orders;
        std::string file;
        ItemCreator c;
        void printItems(std::string key);
        void initialize();

    public:
        ExtraMenu(const std::string& _title, const std::string& fileName, std::vector<Order*>* order);

        void AddDrink();
        
        void AddSide();

        void AddDesert();

        void AddSauce();

        void RemoveItem();

        void Exit();
};

#endif