#include <iostream>
#include <algorithm>
#include <iomanip>
#include <cstdlib>
#include <list>

class Graph
{
public:
	Graph(int size);
	~Graph();
private:
	int size;
	std::list<int> *obj;
};

Graph::Graph(int size)
	: size(size)
	, obj(NULL)
{
	obj = new std::list<int> [size];
}

Graph::~Graph()
{
	if(obj != NULL)
		delete [] obj;
}

int main(int argc, char *argv[])
{
	return 0;
}