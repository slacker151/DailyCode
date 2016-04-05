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
	void addEdge(int v, int w);
	void DFT();
	void DFT(int start);
private:
	int size;
	std::list<int> *obj;
	void DFTUtil(int v, bool *visited);
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

void Graph::addEdge(int v, int w)
{
	obj[v].push_back(w);
}

void Graph::DFT()
{
	bool *visited = new bool [size];
	std::fill_n(visited, size, false);

	for(int i(0); i < size; ++i)
	{
		if(!visited[i])
			DFTUtil(i, visited);
	}

	std::cout << std::endl;
}

void Graph::DFT(int start)
{
	bool *visited = new bool [size];
	std::fill_n(visited, size, false);

	DFTUtil(start, visited);

	std::cout << std::endl;
}

void Graph::DFTUtil(int v, bool *visited)
{
	visited[v] = true;
	std::cout << std::setw(4) << v;

	std::list<int>::iterator it;

	for(it = obj[v].begin(); it != obj[v].end(); ++it)
	{
		if(!visited[*it])
		{
			DFTUtil(*it, visited);
		}
	}
}

int main(int argc, char *argv[])
{
	Graph g(4);
  	g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);

    //DFT with a starting vertice
    	// Could be a partial graph	
    g.DFT(2);

    //DFT of the whole graph
    	// Guaranteed the complete graph
    g.DFT();

	return 0;
}