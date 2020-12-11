#ifndef __MANAGER_WINDOW_HPP__
#define __MANAGER_WINDOW_HPP__

#include "../../components/headers/Menu.hpp"
#include "../../components/headers/order.h"
#include "../../components/headers/Utilities.hpp"

class Order;

class ManagerWindow : public BasicMenu{
private:
	std::vector<Order*>* orders;
	User* current_user;
	double _totalCost;
public:
	ManagerWindow(const std::string& title, User* user, std::vector<Order*>* orders);
	void PrintMenu();
	void Exit();	

//Not shown ====================

	User*& get_user(){ return current_user;}
};
#endif
