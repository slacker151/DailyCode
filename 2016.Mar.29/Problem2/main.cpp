#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <string>
#include <iomanip>

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

	// By default
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

void SplitInHalf(Node *Head, Node **A, Node **B)
{
	Node *slow(NULL);
	Node *fast(NULL);

	if(Head == NULL || Head->next == NULL)
	{
		*A = Head;
		*B = NULL;
	}
	else
	{
		slow = Head;
		fast = Head->next;

		while(fast != NULL)
		{
			fast = fast->next;

			if(fast != NULL)
			{
				slow = slow->next;
				fast = fast->next;
			}
		}

		*A = Head;
		*B = slow->next;
		slow->next = NULL;
	}
}

Node *Merge(Node *A, Node *B)
{
	Node *newNode = NULL;

	if(A == NULL)
		return B;
	else if(B == NULL)
		return A;

	if(A->data <= B->data)
	{
		newNode = A;
		newNode->next = Merge(A->next, B);
	}
	else
	{
		newNode = B;
		newNode->next = Merge(A, B->next);
	}
	return newNode;
}

void MergeSort(Node **Head)
{
	Node *H = *Head;
	Node *A = NULL;
	Node *B = NULL;

	if(*Head == NULL || (*Head)->next == NULL)
		return;

	SplitInHalf(H, &A, &B);

	MergeSort(&A);
	MergeSort(&B);

	*Head = Merge(A, B);
}

int main(int argc, char * argv[])
{
	//Declaration
	Node *LL1(NULL);

	//Initialization
	for(int i(10); i > 0; i--)
		Insert(&LL1, i);
	Display(LL1);

	//Sorting
	MergeSort(&LL1);
	Display(LL1);

	//Destruction
	Delete(&LL1);

	return 0;
}