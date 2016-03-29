#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <iomanip>
#include <string>
#include <assert.h>

typedef struct Node
{
	Node 	*next;
	int 	data;
}Node;

bool Insert(Node **Head, int data)
{
	Node *newNode = new Node;
	newNode->next = NULL;
	newNode->data = data;

	if(*Head == NULL)
	{
		*Head = newNode;	
		return true;
	}
	else
	{
		//Queue style
		Node *temp = *Head;
		while(temp->next != NULL)
		{
			temp = temp->next;
		}
		temp->next = newNode;
		return true;
	}

	return false;
}

bool Delete(Node **Head)
{
	while(*Head != NULL)
	{
		Node *temp = *Head;
		*Head = (*Head)->next;
		delete temp;
	}

	if(*Head == NULL)
		return true;

	return false;
}

void Display(Node *Head)
{
	while(Head != NULL)
	{
		std::cout << std::setw(4) << Head->data;
		Head = Head->next;
	}
	std::cout << std::endl;
}

bool ReverseByGroupSize(Node **Head, int groupSize)
{
	if(*Head == NULL)
		return false;

	int counter(1);
	Node *frontIt = *Head;
	Node *backIt = *Head;
	Node *tail(NULL);

	while(frontIt != NULL)
	{
		if(counter == groupSize)
		{
			counter = 1;
			Node *nextFrontIt = frontIt->next;

			//Beginning of the LL
			if(backIt == *Head)
			{
				*Head = frontIt;
				for(int i(groupSize - 1); i >= 1; --i)
				{
					int j(i);
					Node *temp = backIt;
					while(j-->1)
					{
						temp = temp->next;
					}
					frontIt->next = temp;
					frontIt = frontIt->next;
				}
				frontIt = nextFrontIt;
				backIt->next = nextFrontIt;
			}
			//Middle of the LL
			else
			{
				Node *groupHead = frontIt;
				for(int i(groupSize - 1); i >= 1; --i)
				{
					int j(i);
					Node *temp = backIt;
					while(j-->0)
					{
						temp = temp->next;
					}
					frontIt->next = temp;
					frontIt = frontIt->next;
				}
				backIt->next = groupHead;
				backIt = frontIt;
				frontIt->next = nextFrontIt;
				frontIt = nextFrontIt;
			}
		}

		if(frontIt != NULL)
		{
			if(frontIt->next == NULL)
			{
				tail = frontIt;
			}
			frontIt = frontIt->next;
			counter++;
		}
	}

	//End of the LL
	if(counter != 1)
	{
		Node *groupHead = tail;
		for(int i(counter - 1); i >= 1; --i)
		{
			int j(i);
			Node *temp = backIt;
			while(j-->0)
			{
				temp = temp->next;
			}
			tail->next = temp;
			tail = tail->next;
		}
		backIt->next = groupHead;
		tail->next = NULL;
	}

	return true;
}


int main(int argc, char *argv[])
{
	int groupSize(5);

	Node *LL1(NULL);

	for(int i(1); i <= 8; i++)
	{
		assert(Insert(&LL1, i) == true);
	}	
	Display(LL1);

	ReverseByGroupSize(&LL1, groupSize);
	Display(LL1);

	Delete(&LL1);
	return 0;
}