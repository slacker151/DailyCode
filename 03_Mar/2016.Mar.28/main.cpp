#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <iomanip>

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
		Node *temp = *Head;
		while(temp->next != NULL)
		{
			temp = temp->next;
		}
		temp->next = newNode;
		return true;
	}
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

bool Merge(Node **LL1, Node **LL2)
{
	Node *temp1 = *LL1;
	Node *temp2 = *LL2;

	//If both LL are non-empty
	if(temp1 != NULL && temp2 != NULL)
	{
		while(temp1->next != NULL && temp2 != NULL)
		{
			//Removing the node from LL2
			*LL2 = temp2->next;

			//Linking the removing node with the LL1
			temp2->next = temp1->next;
			temp1->next = temp2;

			//Increment both LLs
			temp1 = temp2->next;
			temp2 = *LL2;
		}

		if(temp1->next == NULL && temp2 != NULL)
		{
			*LL2 = temp2->next;
			temp2->next = NULL;
			temp1->next = temp2;
		}

		return true;
	}

	return false;
}

int main(int argc, char *argv[])
{
	Node *LL1(NULL);

//Test Case1
	// Insert(&LL1, 5);
	// Insert(&LL1, 7);
	// Insert(&LL1, 17);
	// Insert(&LL1, 13);
	// Insert(&LL1, 11);

//Test Case 2
	Insert(&LL1, 1);
	Insert(&LL1, 2);
	Insert(&LL1, 3);

	Display(LL1);

	Node *LL2(NULL);

//Test Case 1
	// Insert(&LL2, 12);
	// Insert(&LL2, 10);
	// Insert(&LL2, 2);
	// Insert(&LL2, 4);
	// Insert(&LL2, 6);

//Test Case 2
	Insert(&LL2, 4);
	Insert(&LL2, 5);
	Insert(&LL2, 6);
	Insert(&LL2, 7);
	Insert(&LL2, 8);

	Display(LL2);

	Merge(&LL1, &LL2);
	std::cout << std::endl;
	Display(LL1);
	Display(LL2);

	Delete(&LL1);
	Delete(&LL2);
	return 0;
}