#ifndef SINGLEITEMDISPLAY_HPP
#define SINGLEITEMDISPLAY_HPP

#include "IDisplayStrategy.hpp"

class SingleItemDisplay : public IDisplayBehavior
{
    public:
        virtual void display(Item* i);
};

#endif