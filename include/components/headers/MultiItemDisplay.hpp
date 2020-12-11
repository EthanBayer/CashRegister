#ifndef MULTIITEMDISPLAY_HPP
#define MULTIITEMDISPLAY_HPP

#include "IDisplayStrategy.hpp"

class MultiDisplay : public IDisplayBehavior
{
    public:
        virtual void display(Item* i);
};

#endif