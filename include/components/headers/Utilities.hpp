#pragma once

#include <string>


struct User{
    std::string title;
    std::string name;
    std::string password;
};

std::string asciiencrypt(const std::string& text);
