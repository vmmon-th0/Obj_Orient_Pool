#ifndef WORKER_HPP
#define WORKER_HPP

#include <list>
#include <iostream>
#include <algorithm>
#include "Tool.hpp"
#include "Workshop.hpp"

struct Position
{
	Position(int x_, int y_, int z_) : x(x_), y(y_), z(z_) {}

	int x;
	int y;
	int z;
};

struct Statistic
{
	Statistic(int exp_, int level_) : exp(exp_), level(level_) {}

	int exp;
	int level;
};

class Worker
{
	public:
		Worker(): _stat(0, 1), _coordonnee(0, 0, 0)
		{
			std::cout << "Worker constructor called" << std::endl;
		}

		~Worker()
		{
			std::cout << "Worker destructor called" << std::endl;
		}

		void giveTool(Tool* tool)
		{
			std::list<Tool *>::iterator it = std::find(_tools.begin(), _tools.end(), tool);
			if (it != _tools.end())
			{
				std::cerr << "Attempt to add a duplicate object to the inventory tools" << std::endl;
				return ;
			}
			else
			{
				Worker* owner = tool->getOwner();
				if (owner != NULL)
				{
					owner->removeTool(tool);
					std::cout << "The ownership of the tool has been switched to the present one" << std::endl;
				}
				tool->setOwner(this);
				_tools.push_back(tool);
				std::cout << "The tool: " << tool->getTitle() << " has been successfully added to the tool list" << std::endl;
			}
		}

		void removeTool(Tool* tool)
		{
			std::list<Tool *>::iterator it = std::find(_tools.begin(), _tools.end(), tool);
			if (it == _tools.end())
			{
				std::cerr << "Attempt to remove unexistant object of the inventory tools" << std::endl;
				return ;
			}

			tool->setOwner(NULL);
			std::cout << "Ownership has been removed" << std::endl;
			
			_tools.erase(it);
			std::cout << "The tool: " << tool->getTitle() << " was successfully removed" << std::endl;
		}

		void subscribeWorkshop(Workshop* workshop)
		{
			std::list<Workshop *>::iterator it = std::find(_workshops.begin(), _workshops.end(), workshop);
			if (it != _workshops.end())
			{
				std::cerr << "Attempt to subscribe twice to the same workshop" << std::endl;
				return ;
			}
			(*it)->subscribeWorker(this);
			_workshops.push_back(workshop);
			std::cout << "The workshop was successfully subscribed" << std::endl;
		}

		void unsubscribeWorkshop(Workshop* workshop)
		{
			std::list<Workshop *>::iterator it = std::find(_workshops.begin(), _workshops.end(), workshop);
			if (it == _workshops.end())
			{
				std::cerr << "Attempt to unsubscribe unexistant workshop" << std::endl;
				return ;
			}
			(*it)->unsubscribeWorker(this);
			_workshops.erase(it);
			std::cout << "The workshop was successfully removed & unsubscribed" << std::endl;
		}

		void clearTools() const
		{
			_tools.clear();
			std::cout << "The tools were successfully cleared" << std::endl;
		}

		void clearWorkshops() const
		{
			_workshops.clear();
			std::cout << "The workshops were successfully cleared" << std::endl;
		}

		void work() const
		{
			for (std::list<Tool *>::iterator it = _tools.begin(); it != _tools.end(); ++it)
			{
				(*it)->use();
			}
		}

	private:
		Statistic _stat;
		Position _coordonnee;

		std::list<Tool* > _tools;
		std::list<Workshop *> _workshops;
};

#endif
