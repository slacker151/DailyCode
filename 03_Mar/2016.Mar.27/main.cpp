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

bool Insert(Node **head, int data)
{
	Node *newNode = new Node;
	newNode->next = NULL;
	newNode->data = data;

	if(*head == NULL)	
	{
		*head = newNode;
	}
	else
	{
		Node *temp = *head;
		while(temp->next != NULL)
		{
			temp = temp->next;
		}
		temp->next = newNode;
	}

	return true;
}

void Display(Node *head)
{
	while(head != NULL)
	{
		std::cout << std::setw(4) << head->data;
		head = head->next;
	}

	std::cout << std::endl;
}

bool Delete(Node **head)
{
	while(*head != NULL)
	{
		Node *temp = *head;
		*head = (*head)->next;
		delete temp;
	}
	return true;
}

bool Add_add(Node *LL1, Node *LL2, Node **LLoutput)
{
	//Base condition
	if(LL1 == NULL || LL2 == NULL)
	{
		return false;
	}

	bool carryOn = Add_add(LL1->next, LL2->next, LLoutput);

	int thisLvlSum(0);

	thisLvlSum = carryOn ? 
					LL1->data + LL2->data + 1 : 
					LL1->data + LL2->data;

	Node *newNode = new Node;
	newNode->next = *LLoutput;

	if(thisLvlSum > 9)
	{
		newNode->data = thisLvlSum % 10;
		*LLoutput = newNode;
		return true;
	}
	else
	{
		newNode->data = thisLvlSum;
		*LLoutput = newNode;
		return false;
	}
}

int Add_getSize(Node *Head)
{
	int res(0);
	while(Head != NULL)
	{
		res++;
		Head = Head->next;
	}
	return res;
}

int Add_getAt(Node *Head, int index)
{
	for(int i(0); i < index-1; ++i)
	{
		Head = Head->next;
	}
	return Head->data;
}

bool Add(Node *LL1, Node *LL2, Node **LLoutput)
{
	//Check for size
	int size1 = Add_getSize(LL1);
	int size2 = Add_getSize(LL2);

	//Algorithm Core
	if(size1 == size2)
	{
		//If carry-on
		if(Add_add(LL1, LL2, LLoutput))
		{
			Node *newNode = new Node;
			newNode->next = *LLoutput;
			newNode->data = 1;
			*LLoutput = newNode;
		}
	}
	else if(size1 > size2)
	{
		//Backup LL1
		Node *temp1 = LL1;
		
		//Travese
		int differece = size1 - size2;
		for(int i(0); i < differece; ++i)
		{
			LL1 = LL1->next;
		}

		//Process
		if(Add_add(LL1, LL2, LLoutput))
		{
			Node *newNode = new Node;
			newNode->next = *LLoutput;
			newNode->data = 1;
			*LLoutput = newNode;
		}

		//Append
		int outputSize = Add_getSize(*LLoutput);
	
		if(outputSize != size2)
		{
			int tempSum = Add_getAt(temp1, differece--) + (*LLoutput)->data;
			if(tempSum > 9)
			{
				(*LLoutput)->data = tempSum % 10;
				Node *newNode = new Node;
				newNode->next = *LLoutput;
				newNode->data = 1;
				*LLoutput = newNode;
			}
			else
			{
				(*LLoutput)->data = tempSum;
			}
		}

		while(differece != 0)
		{
			Node *newNode = new Node;
			newNode->data = Add_getAt(LL1, differece);
			newNode->next = *LLoutput;
			*LLoutput = newNode;
			differece--;
		}
	}
	else if(size1 < size2)
	{
		//Backup LL2
		Node *temp2 = LL2;

		//Travese
		int differece = size2 - size1;
		for(int i(0); i < differece; ++i)
		{
			LL2 = LL2->next;
		}

		//Process
		if(Add_add(LL1, LL2, LLoutput))
		{
			Node *newNode = new Node;
			newNode->next = *LLoutput;
			newNode->data = 1;
			*LLoutput = newNode;
		}

		//Append
		int outputSize = Add_getSize(*LLoutput);
	
		if(outputSize != size1)
		{
			int tempSum = Add_getAt(temp2, differece--) + (*LLoutput)->data;
			if(tempSum > 9)
			{
				(*LLoutput)->data = tempSum % 10;
				Node *newNode = new Node;
				newNode->next = *LLoutput;
				newNode->data = 1;
				*LLoutput = newNode;
			}
			else
			{
				(*LLoutput)->data = tempSum;
			}
		}

		while(differece != 0)
		{
			Node *newNode = new Node;
			newNode->data = Add_getAt(LL2, differece);
			newNode->next = *LLoutput;
			*LLoutput = newNode;
			differece--;
		}
	}

	return true;
}


int main(int argc, char *argv[])
{
	Node *LL1(NULL);
	Node *LL2(NULL);

 	Insert(&LL1, 9);
 	Insert(&LL1, 9);
 	Insert(&LL1, 9);

 	Display(LL1);

 	Insert(&LL2, 1);
 	Insert(&LL2, 8);
 	Display(LL2); 	

 	Node *LLoutput(NULL);
 	Add(LL1, LL2, &LLoutput);
 	Display(LLoutput);

 	Delete(&LL1);
 	Delete(&LL2);
 	Delete(&LLoutput);

	return 0;
}