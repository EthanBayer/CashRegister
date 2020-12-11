#ifndef ORDERDISPLAY_HPP
#define ORDERDISPLAY_HPP

#include "IDisplayStrategy.hpp"

class OrderDisplay : public IDisplayBehavior
{
    public:
        virtual void display(Item* i);
};

#endif