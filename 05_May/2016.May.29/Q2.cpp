#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <iomanip>

int numberOfPathsUtil(int currN, int currM, int n, int m)
{
	if(currN == n && currM == m)
		return 1;

	if(currN > n || currM > m)
		return 0;

	return numberOfPathsUtil(currN + 1, currM, n, m) + 
		numberOfPathsUtil(currN, currM + 1, n, m); 	
}

int numberOfPaths(int n, int m)
{
	int res(0);
	res = numberOfPathsUtil(1, 1, n, m);
	return res;
}

int numberOfPathsDP(int n, int m)
{
	int DP[m][n];

	for(int i(0); i < m; ++i)
	{
		DP[i][0] = 1;
	}

	for(int i(0); i < n; ++i)
	{
		DP[0][i] = 1;
	}

	for(int i(1); i < m; ++i)
	{
		for(int j(1); j < n; ++j)
		{
			DP[i][j] = DP[i-1][j] + DP[i][j-1];
		}
	}

	return DP[m-1][n-1];
}

int main(int argc, char const *argv[])
{
	std::cout << numberOfPaths(3, 3) << std::endl;
	std::cout << numberOfPathsDP(3, 3) << std::endl;
	return 0;
}