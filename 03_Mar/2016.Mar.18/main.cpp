#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <iomanip>
#include <string>

typedef struct Node
{
	Node	*next;
	int 	data;
}Node;

bool DeleteNode(Node **head, Node *deletingNode)
{
	// If deletingNode is the first in LL
	if(deletingNode == *head)
	{
		*head = (*head)->next;
		delete deletingNode;
		return true;
	}
	
	// If the deletingNode is in the LL
	Node *temp = *head;

	while(temp->next != NULL)
	{
		if(temp->next == deletingNode)
		{
			temp->next = deletingNode->next;
			delete deletingNode;
			return true;
		}

		temp = temp->next;
	}

	// If the deletingNode doesn't exist in LL
	return false;
}

void PrintLL(Node *head)
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
	//LL Setup
	Node *head = new Node;
	Node *second = new Node;
	Node *third = new Node;
	Node *forth = new Node;
	Node *fifth = new Node;
	Node *sixth = new Node;
	Node *seventh = new Node;

	head->data = 1;
	second->data = 2;
	third->data = 3;
	forth->data = 4;
	fifth->data = 5;
	sixth->data = 6;
	seventh->data = 7;

	head->next = second;
	second->next = third;
	third->next = forth;
	forth->next = fifth;
	fifth->next = sixth;
	sixth->next = seventh;

	//Print
	PrintLL(head);

	//Deletion
	std::cout << DeleteNode(&head, sixth) << std::endl;

	//Print
	PrintLL(head);

	return 0;
}









