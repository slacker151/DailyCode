#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <iomanip>
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

void SplitList(Node *Head, Node **First, Node **Second)
{
	Node *slow = Head;
	Node *fast = Head->next;

	while(fast != NULL)
	{
		fast = fast->next;
		if(fast)
		{
			slow = slow->next;
			fast = fast->next;
		}
	}
	*First = Head;
	*Second = slow->next;
	slow->next = NULL;
}

Node * Merge(Node *First, Node *Second)
{
	if(First == NULL)
		return Second;
	else if(Second == NULL)
		return First;

	Node *res;

	if(First->data < Second->data)
	{
		res = First;
		res->next = Merge(First->next, Second);
	}
	else
	{
		res = Second;
		res->next = Merge(First, Second->next);
	}

	return res;
}

void MergeSort(Node **Head)
{
	Node *tempHead = *Head;
	Node *A(NULL);
	Node *B(NULL);

	if(tempHead == NULL || tempHead->next == NULL)
		return;

	SplitList(tempHead, &A, &B);

	// std::cout << std::setw(4) << A->data;
	// std::cout << std::setw(4) << B->data;
	// std::cout << std::endl;

	MergeSort(&A);
	MergeSort(&B);

	*Head = Merge(A, B);
}

int main(int argc, char * argv[])
{
	Node *LL1;

	for (int i(9); i > 0; --i)
		Insert(&LL1, i);

	Display(LL1);	

	//Sorting Call
	MergeSort(&LL1);

	Display(LL1);	

	Delete(&LL1);
	return 0;
}








