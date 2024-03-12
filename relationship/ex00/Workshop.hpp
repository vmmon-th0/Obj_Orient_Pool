#ifndef WORKSHOP
#define WORKSHOP

#include "Worker.hpp"

class Workshop
{
    public:

        Workshop()
        {
            std::cout << "Workshop constructor called" << std::endl;
        }

        ~Workshop()
        {
            std::cout << "Workshop destructor called" << std::endl;
        }

        void subscribeWorker(Worker* worker)
        {
			std::list<Tool *>::iterator it = std::find(_workers.begin(), _workers.end(), worker);
			if (it != tools.end())
			{
				std::cerr << "Attempt to add a duplicate worker to the workshop" << std::endl;
				return ;
			}
			else
			{
				_workers.push_back(worker);
				std::cout << "The worker has been successfully added to the tool list" << std::endl;
			}
        }

        void unsubscribeWorker(Worker* worker)
        {
			std::list<Tool *>::iterator it = std::find(_workers.begin(), _workers.end(), tool);
			if (it == _workers.end())
			{
				std::cerr << "Attempt to remove unexistant worker of the workshop" << std::endl;
				return ;
			}

			_workers.erase(it);
            std::cout << "The worker was successfully removed" << std::endl;
        }

		void clearWorkers() const
		{
			_workers.clear();
		}

    private:
        
        std::list<Worker *> _workers;
};

#endif