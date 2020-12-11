#pragma once

#include <string>
#include <iostream>
#include <iomanip>
#include <functional>
#include <vector>
#include <exception>

// Component
class Menu {
public:
	//virtual ~Menu();
	virtual void display() = 0;
	virtual std::string get_title() = 0;
	virtual void execute() = 0;
};


//================ Leafs ==============================================
/*
	BasicMenuOption is a single option on a menu, it has a display() method and 
	and execute() method.
*/
class BasicMenuOption : public Menu {
protected:
	std::function<void()> action;
	std::string label;
public:
	BasicMenuOption(const std::string& _name, std::function<void()> _action)
	: label(_name), action(_action){}
	void display();

	void execute();

	std::string get_title();
};



//===================== Composites =====================================

/*
	Basic Menu is a single screen menu. It can contain BasicMenuOptions but not 
	BasicNestedMenu objects.
*/
class BasicMenu: public Menu{
protected:
	std::string menu_title;
	std::vector<Menu*> options;
	Menu* current_option;
public:
	BasicMenu(const std::string& _title);

	std::string get_title();

	virtual void display();

	void switch_options(int index);

	void execute();

	void addOption(Menu* _option);

	Menu* get_current();

	void removeOption(int index);
};


/*
	BasicestedMenu is a multi-screen menu, It can contain menu BasicMenu objects, locally
	called windows.
*/

class BasicNestedMenu: public Menu{
protected:
	std::string window_title;
	std::vector<BasicMenu*> windows;
	BasicMenu* current_window;
public:
	BasicNestedMenu(const std::string& _title);

	void display();

	std::string get_title();

	void execute();

	void switchWindow(int index);

	void addWindow(BasicMenu* _window);

	BasicMenu* get_current();

	void removeWindow(int index);
};