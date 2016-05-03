#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <iomanip>
using namespace std;

void reverse(char str[])
{
	int size = strlen(str);
	int frontIndex = 0;
	int backIndex = size - 1;

	while(frontIndex < backIndex)
	{
		if(!(97 <= str[frontIndex] && str[frontIndex] >= 122) && 
			!(65 <= str[frontIndex] && str[frontIndex] >= 90) )
		{
			frontIndex++;
			continue;
		}

		if(!(97 <= str[backIndex] && str[backIndex] >= 122) && 
			!(65 <= str[backIndex] && str[backIndex] >= 90))
		{
			backIndex--;
			continue;
		}
		
		if(((97 <= str[frontIndex] && str[frontIndex] >= 122) || 
			(65 <= str[frontIndex] && str[frontIndex] >= 90)) 
			&& 
			((97 <= str[backIndex] && str[backIndex] >= 122) || 
			(65 <= str[backIndex] && str[backIndex] >= 90)))
		{
			swap(str[frontIndex], str[backIndex]);
			frontIndex++;
			backIndex--;
		}
	}
}

int main(int argc, char const *argv[])
{
	char str[] = "a!!!b.c.d,e'f,ghi";
    cout << "Input string: " << str << endl;
    reverse(str);
    cout << "Output string: " << str << endl;
	return 0;
}