#include "../headers/ManagerWindow.hpp"
#include "../../components/headers/SingleItemDisplay.hpp"
#include "../../components/headers/MultiItemDisplay.hpp"
#include "../../components/headers/OrderDisplay.hpp"
#include "../../components/src/HelperFunctions.cpp"
#include "../../components/headers/Item.h"
#include <string>
#include <iostream>

ManagerWindow::ManagerWindow(const std::string& title, User* user, std::vector<Order*>* ordervector): BasicMenu(title) {
	this->orders = ordervector;
	current_user = user;
	_totalCost = 0;

	addOption(new BasicMenuOption("View Today's Total", [this](){PrintMenu();}));
    addOption(new BasicMenuOption("Return", [this](){Exit();}));
}

void ManagerWindow::PrintMenu(){ 
	//orders->back()->getDisplay();
	if(current_user->title == "Manager"){
		std::cout << std::left;
		for (int i = 0; i < orders->size(); i++){
			std::cout << "Order " << (*orders)[i]->getName() << std::setfill('-') << std::setw(35) << ": ";
			std::cout << " $ " << (*orders)[i]->getTotalPrice() << "\n";

			_totalCost += (*orders)[i]->getTotalPrice();
		}
		std::cout << "\n\n";
		std::cout << std::setw(25) << "Today's total ";
		std::cout << " $ " << _totalCost << std::endl;
		std::cout << std::setfill(' ');
		std::cout << std::right;
	}
	else{
		std::cout << "Not a manager.\nPlease login as a manager.\n\n";
	}
}

void ManagerWindow::Exit(){
	current_option = nullptr;
} 
