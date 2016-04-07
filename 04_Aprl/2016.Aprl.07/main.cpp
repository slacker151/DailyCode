#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <iomanip>
#include <string>
#include <list>

typedef struct Edge
{
	int src;
	int dest;
}Edge;

typedef struct Graph
{
	int 	V, E;
	Edge 	*edge;
}Graph;

Graph *CreateGraph(int V, int E)
{
	Graph *graph = new Graph();

	graph->V = V;
	graph->E = E;

	graph->edge = new Edge[E];

	return graph;
}

int Find(int *parent, int vertex)
{
	if(parent[vertex] == -1)
		return vertex;
	Find(parent, parent[vertex]);
}

int Union(int *parent, int x, int y)
{
	int xSet = find(parent, x);
	int ySet = find(parent, y);

	parent[xSet] = ySet;
}

bool isCycle(Graph *graph)
{
	int *parent = new int [graph->V];
	std::fill_n(parent, graph->V, -1);

	for(int i(0); i < graph->E; ++i)
	{
		int x = Find(parent, graph->edge[i].src);
		int y = Find(parent, graph->edge[i].dest);

		if(x == y)
			return true;

		Union(parent, x, y);
	}

	return false;
}

int main(int argc, char *argv[])
{
	int V(3);
	int E(3);

	Graph *graph = CreateGraph(V, E);

	graph->edge[0].src = 0;
	graph->edge[0].dest = 1;

	graph->edge[1].src = 1;
	graph->edge[1].dest = 2;

	graph->edge[2].src = 0;
	graph->edge[2].dest = 2;

	if(isCycle(graph))
		std::cout << "Graph contains cycle" << std::endl;
	else
		std::cout << "Graph doesnt contain cycle" << std::endl;

	return 0;
}