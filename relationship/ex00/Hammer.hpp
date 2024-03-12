#ifndef HAMMER_HPP
#define HAMMER_HPP

#include "Tool.hpp"

class Hammer: public Tool
{
    public:

        Hammer(): _numberOfUses(10), _title("Hammer")
        {
            std::cout << "Hammer constructor called" << std::endl;
        }

        ~Hammer()
        {
            std::cout << "Hammer destructor called" << std::endl;
        }

        void use()
        {
            if (_numberOfUses <= 0)
            {
                std::cout << _title << " is broken" << std::endl;
                return ;
            }
            --_numberOfUses;
            std::cout << _title << " tool still has " << _numberOfUses << " uses" << std::endl;
        }
}

#endif