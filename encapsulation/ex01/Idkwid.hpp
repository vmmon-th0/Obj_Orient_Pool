#ifndef IDKWID_HPP
#define IDKWID_HPP

#include <iostream>
#include <list>
#include <vector>

struct Vector2
{
    float _x;
    float _y;

    Vector2() : _x(0), _y(0)
    {
    }

    Vector2(float x, float y) : _x(x), _y(y)
    {
    }

    void print()
    {
        std::cout << "(" << _x << ", " << _y << ")" << std::endl;
    }

    float getX() const
    {
        return _x;
    }

    float getY() const
    {
        return _y;
    }

    Vector2 operator+(const Vector2 &other) const
    {
        return Vector2(_x + other._x, _y + other._y);
    }

    Vector2 operator-(const Vector2 &other) const
    {
        return Vector2(_x - other._x, _y - other._y);
    }

    Vector2 operator*(float scalar) const
    {
        return Vector2(_x * scalar, _y * scalar);
    }

    friend std::ostream &operator<<(std::ostream &os, const Vector2 &v)
    {
        os << "(" << v._x << ", " << v._y << ")";
        return os;
    }
};

class Graph
{
  private:
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

	Graph &operator+=(const Vector2 &vec)
	{
        _vecs.push_back(vec);
		return *this;
	}

	friend std::ostream &operator<<(std::ostream &p_os, Graph &graph)
    {
        p_os << "Graph : " << std::endl;
		for (int y = graph._size; y >= 0; --y) 
		{
			std::cout << "& " << y << " ";
			for (int x = 0; x <= graph._size; ++x)
			{
				bool vecExists = false;
				for (std::list<Vector2>::iterator it = graph._vecs.begin(); it != graph._vecs.end(); it++)
				{
					if ((*it).getY() == y && (*it).getX() == x)
					{
						vecExists = true;
					}
				}
				if (vecExists == true)
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
