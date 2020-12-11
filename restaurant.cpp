#include "include/drivers/headers/Application.hpp"


int main(){
    Application app("../files/users.txt", "../files/items.txt");
    app.run();
    return 0;
}