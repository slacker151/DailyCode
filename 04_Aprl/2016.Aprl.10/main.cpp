#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <iomanip>
#include <limits.h>

#define V 5

int minDistance(int *dist, bool *visited)
{
	int min (INT_MAX);
	int min_index(0);

	for(int i(0); i < V; ++i)
	{
		if(dist[i] <= min && !visited[i])
		{
			min = dist[i];
			min_index = i;
		}
	}

	return min_index;
}

void displayMST(int *dist, int *parent)
{
	for(int i(0); i < V; ++i)
	{
		std::cout << "From : " << std::setw(3) << parent[i] 
				  << " To: " << std::setw(3) << i  << " = "
				  << std::setw(3) << dist[i] << std::endl;
	}
}

void PrimMST(int graph[V][V])
{
	int dist[V];
	bool visited[V];
	int parent[V];

	std::fill_n(dist, V, INT_MAX);
	std::fill_n(visited, V, false);

	dist[0] = 0;
	parent[0] = -1;

	for(int count(0); count < V; ++count)
	{
		int u = minDistance(dist, visited);

		visited[u] = true;

		for(int i(0); i < V; ++i)
		{
			if(!visited[i] && graph[u][i]
				&& graph[u][i] <= dist[i])
			{
				dist[i] = graph[u][i];
				parent[i] = u;
			}
		}
	}

	displayMST(dist, parent);
}

typedef struct Edge
{
	int src;
	int des;
	int weight;
}Edge;

typedef struct Graph
{
	int 	V
	int 	E;
	Edge 	*edge;
}Graph;

int main(int argc, char *argv[])
{
	int graph[V][V] = {
						{0, 2, 0, 6, 0},
						{2, 0, 3, 8, 5},
						{0, 3, 0, 0, 7},
						{6, 8, 0, 0, 9},
						{0, 5, 7, 9, 0}
					};

	PrimMST(graph);

	Graph *G = new graph;
	G->V = 4;
	G->E = 5;
	G->edge = new Edge [5];

	// add edge 0-1
	graph->edge[0].src = 2;
	graph->edge[0].dest = 3;
	graph->edge[0].weight = 4;

	// add edge 0-2
	graph->edge[1].src = 0;
	graph->edge[1].dest = 3;
	graph->edge[1].weight = 5;

	// add edge 0-3
	graph->edge[2].src = 0;
	graph->edge[2].dest = 2;
	graph->edge[2].weight = 6;

	// add edge 1-3
	graph->edge[3].src = 0;
	graph->edge[3].dest = 1;
	graph->edge[3].weight = 10;

	// add edge 2-3
	graph->edge[4].src = 1;
	graph->edge[4].dest = 3;
	graph->edge[4].weight = 15; 

	

	delete [] G->edge;
	delete G;
	return 0;
}