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

static Node *front;

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

void RemoveLoop(Node *Head, Node *LoopNode)
{
	Node *ptr1(Head);
	Node *ptr2(NULL);

	while(1)
	{
		ptr2 = LoopNode;
		while(ptr2->next != LoopNode && ptr2->next != ptr1)
		{
			ptr2 = ptr2->next;
		}

		//Found the end
		if(ptr2->next == ptr1)
			break;

		ptr1 = ptr1->next;
	}

	ptr2->next = NULL;
	front->next = NULL;
}

bool detectAndRemoveLoop(Node *Head)
{
	//If empty or 1-element list
	if(Head == NULL || Head->next == NULL)
		return false;

	Node *slow(Head);
	Node *fast(Head);

	while(slow && fast && fast->next)
	{
		slow = slow->next;
		fast = fast->next->next;

		//Found loop
		if(slow == fast)
		{
			//Remove loop
			RemoveLoop(Head, slow);
		}
	}

	//list does not have a loop 
	return false;
}

int main(int argc, char *argv[])
{
	Node *LL1(NULL);

	for(int i(0); i < 10; ++i)
	{
		assert(Insert(&LL1, i) == true);
	}
	Display(LL1);

	//Setup
	Node *sixthNode = LL1;
	for(int i(0); i < 6; ++i)
	{
		sixthNode = sixthNode->next;
	}

	//Making a loop
	front->next = sixthNode;

	bool res = detectAndRemoveLoop(LL1);


	Display(LL1);

	//Destruction
	assert(Delete(&LL1) == true);
	return 0;
}
















