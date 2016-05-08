#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <iomanip>
#include <string>

bool isPalindrom(std::string str)
{
	int frontIndex(0);
	int backIndex(str.size() - 1);

	while(frontIndex < backIndex)
	{
		if(str[frontIndex] != str[backIndex])
		{
			return false;
		}
		frontIndex++;
		backIndex--;
	}

	return true;
}

void PrintAllPalindromicPartitions(std::string str)
{	
	int size(2);
	int index(0);
	int numOfPalindrom(0);
	bool palindromed[str.size()];

	{
		for(int i(0); i < str.size(); ++i)
		{
			std::cout << str[i] << " ";
		}
		std::cout << std::endl;
	}

	for(; size <= str.size(); ++size)
	{
		index = 0;
		numOfPalindrom = 0;
		std::fill_n(palindromed, str.size(), false);

		// Determine how many and where palindrom partitions in str
		while((index + size) <= str.size())
		{
			std::string partitionStr (str.substr(index, size));
			
			if(isPalindrom(partitionStr))
			{
				palindromed[index] = true;
				numOfPalindrom ++;
			}

			index++;
		}

		// Printing out all the possible palindrom partition with str
		for(int i(1); i <= numOfPalindrom; ++i)
		{
			int counter(0);

			for(int j(0); j < str.size(); ++j)
			{
				if(palindromed[j] == true)
				{
					counter++;
					if(counter == i)
					{
						std::cout << str.substr(j, size) << " ";
						j += size - 1;
					}
					else
					{
						std::cout << str[j] << " ";
					}
				}
				else if(palindromed[j] == false)
				{
					std::cout << str[j] << " ";
				}
				else
				{
					std::cout << "Something went wrong \n";
				}
			}
			std::cout << std::endl;
		}
	}
}

int main(int argc, char const *argv[])
{
    std::string str = "jititim";
    PrintAllPalindromicPartitions(str);
	return 0;
}