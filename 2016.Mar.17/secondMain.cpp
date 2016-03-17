#include <iostream>
#include <iomanip>
#include <algorithm>
#include <cstdlib>

typedef struct Node
{
	Node *next;
	int data;
}Node;

bool insert(Node **head, int val)
{
	Node *temp = *head;

	if(temp == NULL)
	{
		return false;
	}

	while(temp->next != NULL)
	{
		temp = temp->next; 
	}

	temp->next = new Node;
	temp->next->data = val;

	return true;
}

bool SortedInsert(Node **head, int val)
{
	Node *temp = *head;

	if(temp == NULL)
		return false;

	if(val <= temp->data)
	{
		Node *newHead = new Node;
		newHead->data = val;
		newHead->next = *head;
		*head = newHead;
		return true;
	}

	while(temp->next != NULL)
	{
		if(temp->next->data < val)
		{
			temp = temp->next;
		}
		else
			break;
	}

	Node *newNode = new Node;
	newNode->data = val;
	newNode->next = temp->next;
	temp->next = newNode;
	return true;
}


void DisplayLL(Node *head)
{
	Node *temp = head;
	while(temp != NULL)
	{
		std::cout << std::setw(4) << temp->data;
		temp = temp->next;
	}
	std::cout << std::endl;
}

int main(int argc, char *argv[])
{	
	Node *head = new Node;
	head->data = 2;

	insert(&head, 5);
	insert(&head, 7);
	insert(&head, 10);
	insert(&head, 15);

	DisplayLL(head);

	SortedInsert(&head, 108);

	DisplayLL(head);

	return 0;
}