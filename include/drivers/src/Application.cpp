#include "../headers/Application.hpp"

Application::Application(const std::string& usersfile, const std::string& itemsfile): users(usersfile), items(itemsfile){
    menu = new BasicNestedMenu("RESTAURANT");
    menu->addWindow(login);
    menu->addWindow(manWindow);
    menu->addWindow(new OrderMenu("MAKE ORDER", items, &orders));
    menu->addWindow(new ExtraMenu("EXTRA", items, &orders));
    menu->addWindow(new CheckoutWindow("CHECKOUT", &orders, &balance));
    menu->switchWindow(0);
}

void Application::run(){
    bool is_done = false;
    do{
        do{
            menu->display();
            menu->get_current()->display();
            int option_index;
            std::cout << "Enter option: ";
            std::cin >> option_index;
            menu->get_current()->switch_options(option_index - 1);
            menu->execute();
        }while(menu->get_current()->get_current());
        menu->display();
        std::cout << "Enter any letter to quit\nSelect Window: ";
        int window_index;
        std::cin >> window_index;

        if(std::cin.fail()){
            is_done = true;
        }
        else{
            if(login->get_user()){      //user is not nullptr, hence it exists
                manWindow->get_user() = login->get_user();
                menu->switchWindow(window_index - 1);
            }
            else{
                std::cout << "Please Login with a valid user.\n\n";
            }
        }
    }while(!is_done);
}

Application::~Application(){
    delete menu;
    for (int i = 0; i < orders.size(); i++){
        delete orders[i];
    }
}