#ifndef TOOL_HPP
#define TOOL_HPP

class Worker;

class Tool
{
    public:

        Tool()
        {
            std::cout << "Tool constructor called" << std::endl;
        }

        virtual ~Tool()
        {
            std::cout << "Virtual Tool destructor called" << std::endl;
        }

        const std::string& getTitle() const
        {
            return _title;
        }

        void setOwner(Worker* worker)
        {
            _owner = worker;
        }

        Worker* getOwner() const
        {
            return _owner;
        }

        virtual void use() = 0;

    protected:

        Worker* _owner;
        std::string _title;
        unsigned int _numberOfUses;
};

#endif
