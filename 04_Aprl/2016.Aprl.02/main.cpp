#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <iomanip>
#include <string>
#include <ctime>

typedef struct Node
{
	Node 	*next;
	int 	data;
}Node;

static Node * front;

bool Insert(Node **Head, int data)
{
	Node *newNode = new Node;
	newNode->next = NULL;
	newNode->data = data;

	if(*Head == NULL)
	{
		*Head = newNode;
		front = newNode;
		return true;
	}
	else
	{
		front->next = newNode;
		front = front->next;
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

void GetRandomNode(Node *Head)
{
	Node *temp = Head;
	int res = temp->data;
	srand(time(NULL));

	if(Head == NULL || Head->next == NULL)
		return;

	for(int n(2); temp != NULL; ++n)
	{
		if(rand() % n == 0)
			res = temp->data;

		temp = temp->next;
	}

	std::cout << res << std::endl;
}

int main(int argc, char * argv[])
{
	Node *LL1(NULL);
	for(int i(9); i > 0; --i)
		Insert(&LL1, i);
	Display(LL1);

	GetRandomNode(LL1);

	Delete(&LL1);
	return 0;
}