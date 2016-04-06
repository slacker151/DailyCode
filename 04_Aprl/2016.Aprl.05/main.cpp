#include <iostream>
#include <algorithm>
#include <iomanip>
#include <cstdlib>
#include <list>
#include <limits.h>

#define V 9

int minDistance(int *dist, bool *visited)
{
	int min(INT_MAX);
	int min_index(0);

	for(int i(0); i < V; ++i)
	{
		if(visited[i] == false && dist[i] <= min)
		{
			min = dist[i];
			min_index = i;
		}
	}

	return min_index;
}

void printShortestPaths(int *dist)
{
	for (int i(0); i < V; ++i)
	{
		std::cout << std::setw(4) << i << ": " <<
		std::setw(4) << dist[i] << std::endl;
	}
}

void dijkstraShortestPathAlgo(int graph[V][V], int src)
{
	int dist[V];
	bool visited[V];

	std::fill_n(dist, V, INT_MAX);
	std::fill_n(visited, V, false);

	dist[src] = 0;

	for(int count(0); count < V; ++count)
	{
		int u = minDistance(dist, visited);

		visited[u] = true;

		for (int i(0); i < V; ++i)
		{
			if(!visited[i] && graph[u][i] && dist[u] != INT_MAX
				&& dist[u] + graph[u][i] < dist[i])
			{
				dist[i] = dist[u] + graph[u][i];
			}
		}
	}
	printShortestPaths(dist);
}

int main(int argc, char *argv[])
{
	//Each row represents a "from" vertex
	//Each col represents a "to" vertex
	int Graph[V][V] = {
						{0,  4,  0,  0,  0,  0,  0,  8,  0},
                      	{4,  0,  8,  0,  0,  0,  0,  11, 0},
                      	{0,  8,  0,  7,  0,  4,  0,  0,  2},
                      	{0,  0,  7,  0,  9,  14, 0,  0,  0},
                      	{0,  0,  0,  9,  0,  10, 0,  0,  0},
                      	{0,  0,  4,  0,  10, 0,  2,  0,  0},
                      	{0,  0,  0,  14, 0,  2,  0,  1,  6},
                      	{8,  11, 0,  0,  0,  0,  1,  0,  7},
                      	{0,  0,  2,  0,  0,  0,  6,  7,  0}
                    };

	dijkstraShortestPathAlgo(Graph, 0);

	return 0;
}