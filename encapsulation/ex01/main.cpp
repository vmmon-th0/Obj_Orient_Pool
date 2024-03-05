#include "Idkwid.hpp"

int main()
{
    Graph myGraph = Graph();
	Vector2 vec1 = Vector2(0, 0);
	Vector2 vec2 = Vector2(2, 2);
	Vector2 vec3 = Vector2(4, 2);
	Vector2 vec4 = Vector2(2, 4);

	myGraph += vec1;
	myGraph += vec2;
	myGraph += vec3;
	myGraph += vec4;
    
	std::cout << myGraph << std::endl;
    return (0);
}
