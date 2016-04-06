#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <iomanip>
#include <limits.h>
#include <string>
#include <list>

#define V 4
#define INF 9999

void printResult(int result[V][V])
{
	for(int i(0); i < V; ++i)
	{
		for(int j(0); j < V; ++j)
		{
			if(result[i][j] == INF)
			{
				std::cout << std::setw(4) << "INF";
			}
			else
			{
				std::cout << std::setw(4) << result[i][j];
			}
		}
		std::cout << std::endl;
	}
}

void FloydWarshallAllShortestPaths(int graph[V][V])
{
	int result[V][V];
	for(int i(0); i < V; ++i)
	{
		for(int j(0); j < V; ++j)
		{
			result[i][j] = graph[i][j];
		}
	}

	for(int k(0); k < V; ++k)
	{
		for(int i(0); i < V; ++i)
		{
			for(int j(0); j < V; ++j)
			{
				// Think of it as, if from i to k + k to j 
				// is shorter than from i to j, then we 
				// reassign the distance
				if(result[i][k] + result[k][j] < result[i][j])
				{
					result[i][j] = result[i][k] + result[k][j];
				}
			}
		}
	}

	printResult(result);
}

int main(int argc, char *argv[])
{
	int graph[V][V] = {
						{0,   5,  INF, 10},
                        {INF, 0,   3, INF},
                        {INF, INF, 0,   1},
                        {INF, INF, INF, 0}
					  };

	FloydWarshallAllShortestPaths(graph);

	return 0;
}