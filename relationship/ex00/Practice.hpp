#ifndef PRACTICE_HPP
#define PRACTICE_HPP

#include <iostream>

struct Position
{
	int x;
	int y;
	int z;
};

struct Statistic
{
	int exp;
	int level;
};

class Shovel
{
	private:

		int _numberOfUses;

	public:

		Shovel(): _numberOfUses(0)
		{
		}

		~Shovel()
		{
		}

		void use()
		{
			std::cout << "Digging tool" << std::endl;
		}
};

class Worker
{
	private:
		// Composition
		Statistic _stat;
		Position _coordonnee;

		// Aggregation
		Shovel* _shovel;

	public:
		Worker()
		{
		}

		~Worker()
		{
		}

		void giveShovel(Shovel* shovel)
		{
			_shovel = shovel;
			std::cout << "The worker got a shovel" << std::endl;
		}

		void takeAwayShovel()
		{
			_shovel = nullptr;
			std::cout << "The shovel is taken away from the Worker" << std::endl;
		}
};

#endif