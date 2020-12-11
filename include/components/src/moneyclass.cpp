
#include "../headers/moneyclass.h"

MoneyClass::MoneyClass()
{
    Dollars = 00;
    Cents = 00;
}

MoneyClass::MoneyClass(double tempMoney)
{
    this->setMoney(tempMoney);
}

void MoneyClass::setMoney(double tempMoney)
{
    double tempDollar;
    double tempCent;
    tempCent = modf(tempMoney, &tempDollar);  // separates the whole and the fractional part of a double.
    Dollars = static_cast<int>(tempDollar + ERROR);
    Cents = static_cast<int>((tempCent + ERROR) * 100);
}

long int MoneyClass::getDollar()
{
    return Dollars;
}

int MoneyClass::getCent()
{
    return Cents;
}

std::string MoneyClass::getTotal()
{
    std::ostringstream stream;
    stream << Dollars << ".";
    //stream.precision(3);
    stream << std::setw(2) << std::setfill('0') << std::right << Cents;
    return stream.str();
}

double MoneyClass::getRealMoney()
{
    return std::stod(getTotal());
}

void MoneyClass::addMoney(double tempMoney)
{
    double realPrice = tempMoney + this->getRealMoney();
    this->setMoney(realPrice + ERROR);
}

void MoneyClass::subMoney(double tempMoney)
{
    double realPrice = this->getRealMoney() - tempMoney;
    this->setMoney(realPrice + ERROR);
}
