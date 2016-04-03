#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <assert.h>
#include <iomanip>
#include <string>

typedef struct Node
{
	Node *next;
	char data;
}Node;

int Compare(Node *LL1, Node *LL2)
{
	while(LL1 != NULL && LL2 != NULL)
	{
		if(LL1->data > LL2->data)
		{
			return 1;
		}
		if(LL1->data < LL2->data)
		{
			return -1;
		}

		LL1 = LL1->next;
		LL2 = LL2->next;
	}

	if(LL1 != NULL)
	{
		return 1;
	}
	if(LL2 != NULL)
	{
		return -1;
	}

	return 0;
}

int main(int argc, char * argv[])
{
	Node *LL1_0 = new Node;
	Node *LL1_1 = new Node;
	Node *LL1_2 = new Node;
	Node *LL1_3 = new Node;
	Node *LL1_4 = new Node;
	Node *LL1_5 = new Node;

	LL1_0->data = 'g';
	LL1_1->data = 'e';
	LL1_2->data = 'e';
	LL1_3->data = 'k';
	LL1_4->data = 's';
	LL1_5->data = 'a';

	LL1_0->next = LL1_1;
	LL1_1->next = LL1_2;
	LL1_2->next = LL1_3;
	LL1_3->next = LL1_4;
	LL1_4->next = LL1_5;
	LL1_5->next = NULL;

	Node *LL2_0 = new Node;
	Node *LL2_1 = new Node;
	Node *LL2_2 = new Node;
	Node *LL2_3 = new Node;
	Node *LL2_4 = new Node;
	Node *LL2_5 = new Node;

	LL2_0->data = 'g';
	LL2_1->data = 'e';
	LL2_2->data = 'e';
	LL2_3->data = 'k';
	LL2_4->data = 's';
	LL2_5->data = 'a';

	LL2_0->next = LL2_1;
	LL2_1->next = LL2_2;
	LL2_2->next = LL2_3;
	LL2_3->next = LL2_4;
	LL2_4->next = LL2_5;
	LL2_5->next = NULL;

	std::cout << Compare(LL1_0, LL2_0) << std::endl;

	while(LL1_0 != NULL)
	{
		Node *temp = LL1_0;
		LL1_0 = LL1_0->next;
		delete temp;
	}

	while(LL2_0 != NULL)
	{
		Node *temp = LL2_0;
		LL2_0 = LL2_0->next;
		delete temp;
	}

	return 0;
}
