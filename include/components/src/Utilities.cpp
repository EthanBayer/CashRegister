#include "../headers/Utilities.hpp"



std::string asciiencrypt(const std::string& text){
    int key = text[0];
    std::string cypher;

    for(int i = 0; i < text.size(); i++){
        cypher += static_cast<char>((static_cast<int>(text[i]) + key)%256);
    }
    return cypher;
}