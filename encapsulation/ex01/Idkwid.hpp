#ifndef IDKWID_HPP
#define IDKWID_HPP

#include <iostream>
#include <list>
#include <vector>

class Graph
{
  private:
    struct Vector2
    {
        float x;
        float y;

        Vector2(float x, float y) : x(x >= 0 ? x : 0), y(y >= 0 ? y : 0)
        {
        }

        ~Vector2()
        {
        }

        friend std::ostream &operator<<(std::ostream &os, const Vector2 &v)
        {
            os << "(" << v.x << ", " << v.y << ")";
            return os;
        }
    };

    int _size;
    std::list<Vector2> _vecs;

  public:
    Graph() : _size(5)
    {
    }

    Graph(int size) : _size(size)
    {
    }

    ~Graph()
    {
    }

    bool vecExists(float x, float y)
    {
        for (std::list<Vector2>::iterator it = _vecs.begin(); it != _vecs.end(); it++)
        {
            if ((*it).y == y && (*it).x == x)
            {
                return true;
            }
        }
        return false;
    }

    void addPosition(float x, float y)
    {
        if (x > _size || y > _size)
        {
            std::cerr << "You cannot add a vector size larger than the graph size." << std::cout;
        }
        else if (vecExists(x, y) == true)
        {
            std::cerr << "Duplicate Vector2 are not allowed" << std::endl;
        }
        else
        {
            Vector2 vec = Vector2(x, y);
            _vecs.push_back(vec);
            std::cout << "New Vector2 has been added to the list: " << vec << std::endl;
        }
    }

    void clearPositions()
    {
        _vecs.clear();
    }

    const std::list<Vector2> &getVecsList() const
    {
        return _vecs;
    }

    const int &getGraphSize() const
    {
        return _size;
    }

    friend std::ostream &operator<<(std::ostream &p_os, Graph &graph)
    {
        p_os << "Graph : " << std::endl;
        for (int y = graph._size; y >= 0; --y)
        {
            std::cout << "& " << y << " ";
            for (int x = 0; x <= graph._size; ++x)
            {
                if (graph.vecExists(x, y) == true)
                {
                    std::cout << 'X' << " ";
                }
                else
                {
                    std::cout << '.' << " ";
                }
            }
            std::cout << std::endl;
        }
        std::cout << "&  " << " ";
        for (int i = 0; i <= graph._size; ++i)
        {
            std::cout << i << " ";
        }
        std::cout << std::endl;
        return (p_os);
    }
};

#endif
