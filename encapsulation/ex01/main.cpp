#include "Idkwid.hpp"

int main()
{
    Graph myGraph = Graph();
	myGraph.addPosition(0, 0);
	myGraph.addPosition(2, 2);
	myGraph.addPosition(4, 2);
	myGraph.addPosition(2, 4);

	std::cout << myGraph << std::endl;
    return (0);
}
