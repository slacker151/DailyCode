#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <iomanip>

typedef struct Edge
{
	int src;
	int dst;
}Edge;

typedef struct Graph
{	
	Graph(int V, int E);
	~Graph();
	int find(int *parent, int i);
	void Union(int *parent, int src, int dst);
	bool IsCycle();

	int V;
	int E;
	Edge *edge;
}Graph;

Graph::Graph(int V, int E)
	: V(V)
	, E(E)
	, edge(0)
{
	edge = new Edge [E];
}

Graph::~Graph()
{
	delete [] edge;
}

int Graph::find(int *parent, int i)
{
	if(parent[i] == -1)
		return i;
	return find(parent, parent[i]);
}

void Graph::Union(int *parent, int src, int dst)
{
	int x = find(parent, src);
	int y = find(parent, dst);

	parent[x] = y;
}

bool Graph::IsCycle()
{
	int parent[E];

	std::fill_n(parent, E, -1);

	for(int i(0); i < E; ++i)
	{
		int x = find(parent, edge[i].src);
		int y = find(parent, edge[i].dst);

		if(x == y)
			return true;

		Union(parent, x, y);
	}

	return false;
}

int main(int argc, char *argv[])
{
	Graph *G = new Graph(2, 1);

	G->edge[0].src = 0;
	G->edge[0].dst = 1;
	
	G->edge[1].src = 1;
	G->edge[1].dst = 2;	
	
	G->edge[2].src = 0;
	G->edge[2].dst = 2;

	bool isCycle = G->IsCycle();

	std::cout << isCycle << std::endl;

	delete G;
	
	return 0;
}