
#include "../headers/Item.h"
#include "../headers/ItemCreator.hpp"
#include <fstream>
#include <iostream>
#include <iomanip>
#include <map>

static void printAtCenter(std::string name, char fill, int sizeSet)
{
    sizeSet = sizeSet - name.size();
    int left, right;
    if  (sizeSet % 2 == 0)
    {
        left = sizeSet / 2;
        right = sizeSet / 2;
    }
    else
    {
        left = (sizeSet / 2) + 1;
        right = sizeSet / 2;
    }

    while(left > 0)
    {
        std::cout << fill;
        left--;
    }
    std::cout << " " << name << " ";
    while(right > 0)
    {
        std::cout << fill;
        right--;
    }
    std::cout << std::endl;
}

static void printAtCenterCont(std::string name, char fill, int sizeSet)
{
    sizeSet = sizeSet - name.size();
    int left, right;
    if  (sizeSet % 2 == 0)
    {
        left = sizeSet / 2;
        right = sizeSet / 2;
    }
    else
    {
        left = (sizeSet / 2) + 1;
        right = sizeSet / 2;
    }

    while(left > 0)
    {
        std::cout << fill;
        left--;
    }
    std::cout << name;
    while(right > 0)
    {
        std::cout << fill;
        right--;
    }
}

static void printVector(std::vector<Item*> v)
{
    for (int i = 0; i < v.size(); i++)
    {
        std::cout << v.at(i)->getName() << ": " << v.at(i)->getPrice().getTotal() << "  ";
    }
}

static int checkIntSelection(int i, int size)
{
    while(i >= size)
    {
        std::cout << "You have entered an incorrect choice, choose again: ";
        std::cin >> i;
        std::cin.clear();
    }
    return i;
}

static bool checkIfNum(std::string s)
{
    for (int i = 0; i < s.size(); i++)
    {
        if (std::isdigit(s[i]) == false)
        {
            return false;
        }
    }
    return true;
}

static std::string checkUserInput(std::string input, std::map<std::string, std::vector<Item*>> choices, std::string key)
{
    while(1)
    {
        if (checkIfNum(input))
        {
            if ((std::stoi(input) < choices.find(key)->second.size()) && (std::stoi(input) != choices.find(key)->second.size()))
            {
                return input;
            }
            else
            {
                std::cout << "You have entered an incorrect choice, choose again: ";
                std::cin >> input;
                std::cin.clear();
            } 
        }
        else
        {
            std::cout << "You have entered an incorrect value, choose again: ";
            std::cin >> input;
            std::cin.clear();
        }
    }
}

static std::string checkUserInput(std::string input, int size)
{
    while(1)
    {
        if (checkIfNum(input))
        {
            if ((std::stoi(input) <= size) && ((std::stoi(input) != 0)))
            {
                return input;
            }
            else
            {
                std::cout << "You have entered an incorrect choice, choose again: ";
                std::cin >> input;
                std::cin.clear();
            } 
        }
        else
        {
            std::cout << "You have entered an incorrect value, choose again: ";
            std::cin >> input;
            std::cin.clear();
        }
    }
}