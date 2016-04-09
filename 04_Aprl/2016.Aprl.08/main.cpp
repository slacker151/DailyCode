#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <iomanip>
#include <limits.h>

#define V 5

int minDistance(int *dist, bool *visited)
{
	int min(INT_MAX);
	int min_index(0);
	for(int i(0); i < V; ++i)
	{
		if(!visited[i] && dist[i] <= min)
		{
			min = dist[i];
			min_index = i;
		}
	}
	return min_index;
}

void printMST(int *edgeSrc, int *dist)
{
	for(int i(0); i < V; ++i)
	{
		std::cout << "From V : "
				  << std::setw(3) << edgeSrc[i] 
				  << " to "
				  << std::setw(3) << i 
				  << " = "
				  << std::setw(3) << dist[i]
				  << std::endl;
	}
}

void primsMST(int graph[V][V])
{
	int edgeSrc[V];
	int dist[V];
	bool visited[V];

	std::fill_n(dist, V, INT_MAX);
	std::fill_n(visited, V, false);

	dist[0] = 0;
	edgeSrc[0] = -1;

	for(int count(0); count < V-1; ++count)
	{
		int u = minDistance(dist, visited);

		visited[u] = true;

		for(int i(0); i < V; ++i)
		{
			if(graph[u][i] && !visited[i] && graph[u][i] < dist[i])
			{
				edgeSrc[i] = u;
				dist[i] = graph[u][i];
			}
		}
	}

	printMST(edgeSrc, dist);
}

int main(int argc, char *argv[])
{

	// Prim's minimum spanning tree (MST) uses 
	// Dijkstra's shortest path finding algorithm.
	// However, the difference between this and 
	// a previous question - the shortest path between 
	// a source vertext to every other vertices, is that
	// we are not comparing nor assign the sum between 
	// the connecting vertices but only updating the
	// lowest weight. Because of which, we need to record 
	// the src vertex of the lowest weight in a seperate 
	// container, so we know the full edge and full graph.

	int graph[V][V] = {
						{0, 2, 0, 6, 0},
						{2, 0, 3, 8, 5},
						{0, 3, 0, 0, 7},
						{6, 8, 0, 0, 9},
						{0, 5, 7, 9, 0}
					};

	primsMST(graph);

	return 0;
}