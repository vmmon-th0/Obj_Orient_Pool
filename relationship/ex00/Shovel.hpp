#ifndef SHOVEL_HPP
#define SHOVEL_HPP

#include "Tool.hpp"

class Shovel: public Tool
{
	public:

		Shovel(): _numberOfUses(5), _title("Shovel")
		{
			std::cout << "Shovel constructor called" << std::endl;
		}

		~Shovel()
		{
			std::cout << "Shovel destructor called" << std::endl;
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
};

#endif